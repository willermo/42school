#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <signal.h>

typedef struct s_client
{
	int fd;
	int id;
	char *buffer;
} t_client;

t_client *clients = NULL;
int max_clients = 0;
int max_fd = 0;
int max_id = 0;
int server_socket = -1;
int clients_init = 0;

void handle_sigint(int sig)
{
	(void)sig;
	if (server_socket != -1)
	{
		close(server_socket);
		server_socket = -1;
	}
	for (int i = 0; i < max_clients; i++)
	{
		if (clients[i].fd != -1)
		{
			if (clients[i].buffer)
				free(clients[i].buffer);
			close(clients[i].fd);
			clients[i].fd = -1;
		}
	}
	exit(0);
}

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char *newbuf;
	int len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void broadcast(int fd, char *message)
{
	for (int i = 0; i < max_clients; i++)
		if (clients[i].fd != -1 && clients[i].fd != fd)
			send(clients[i].fd, message, strlen(message), 0);
}

void add_client(int fd)
{
	if (!clients)
	{
		max_clients = fd + 128;
		clients = calloc(max_clients, sizeof(t_client));
		if (!clients)
			fatal_error();
		for (int i = 0; i < max_clients; i++)
		{
			clients[i].fd = -1;
			clients[i].id = -1;
			clients[i].buffer = NULL;
		}
	}
	else if (fd >= max_clients)
	{
		int old_max = max_clients;
		max_clients = fd + 128;
		clients = realloc(clients, max_clients * sizeof(t_client));
		if (!clients)
			fatal_error();
		for (int i = old_max; i < max_clients; i++)
		{
			clients[i].fd = -1;
			clients[i].id = -1;
			clients[i].buffer = NULL;
		}
	}
	clients[fd].fd = fd;
	clients[fd].id = max_id++;
	clients[fd].buffer = NULL;

	char msg[100];
	sprintf(msg, "server: client %d just arrived\n", clients[fd].id);
	broadcast(fd, msg);
}

void remove_client(int fd)
{
	if (fd < 0 || fd > max_clients || clients[fd].fd == -1)
		return;

	char msg[100];
	sprintf(msg, "server: client %d just left\n", clients[fd].id);
	if (clients[fd].buffer)
		free(clients[fd].buffer);
	clients[fd].fd = -1;
	close(fd);
	broadcast(fd, msg);
}

void handle_client_message(int fd)
{
	char buffer[4096];
	int bytes = recv(fd, buffer, sizeof(buffer) - 1, 0);

	if (bytes <= 0)
	{
		remove_client(fd);
		return;
	}
	buffer[bytes] = 0;
	clients[fd].buffer = str_join(clients[fd].buffer, buffer);
	char *message = NULL;
	while (extract_message(&clients[fd].buffer, &message))
	{
		char *final_message = calloc(strlen(message) + 100, sizeof(char));
		if (!final_message)
			fatal_error();
		sprintf(final_message, "client %d: %s", clients[fd].id, message);
		broadcast(fd, final_message);
		if (message)
			free(message);
		free(final_message);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	// Set up signal handler for SIGINT (Ctrl+C)
	signal(SIGINT, handle_sigint);

	int port = atoi(argv[1]);

	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket < 0)
		fatal_error();

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	servaddr.sin_port = htons(port);

	if ((bind(server_socket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal_error();

	if (listen(server_socket, 128) != 0)
		fatal_error();

	max_fd = server_socket;
	fd_set active_fds, read_fds;
	FD_ZERO(&active_fds);
	FD_SET(server_socket, &active_fds);

	while (1)
	{
		read_fds = active_fds;
		if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &read_fds))
				continue;

			if (fd == server_socket)
			{
				struct sockaddr_in cli;
				socklen_t len = sizeof(cli);
				int client_fd = accept(server_socket, (struct sockaddr *)&cli, &len);
				add_client(client_fd);
				FD_SET(client_fd, &active_fds);
				if (client_fd > max_fd)
					max_fd = client_fd;
			}
			else
			{
				handle_client_message(fd);
				if (clients[fd].fd == -1)
					FD_CLR(fd, &active_fds);
			}
		}
	}
	return (0);
}
