/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:24:57 by doriani           #+#    #+#             */
/*   Updated: 2023/11/29 20:41:37 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

static inline bool
fileExists(const std::string &filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}

static int
checkArgs(int count, char **&args) {
    if (count != 4) {
        std::cout << "Usage: ./sedloser <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    if (!fileExists(std::string(args[1]))) {
        std::cout << "The specified filename does not exist." << std::endl;
        return 1;
    }
    return 0;
}

void
processLine(std::string &line, const std::string &oldString,
            const std::string &newString) {
    size_t startpos = 0;
    size_t curpos = 0;
    std::string outLine;

    while ((curpos = line.find(oldString, startpos)) != std::string::npos) {
        outLine.append(line.substr(startpos, curpos - startpos));
        outLine.append(newString);
        startpos = curpos + oldString.size();
    }
    outLine.append(line.substr(startpos));
    line = outLine;
}

int
main(int argc, char *argv[]) {
    if (checkArgs(argc, argv))
        return 1;

    std::ifstream infile(argv[1]);
    std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());
    std::string oldString(argv[2]);
    std::string newString(argv[3]);
    std::string line;
    while (std::getline(infile, line)) {
        processLine(line, oldString, newString);
        outfile << line << std::endl;
    }
    return 0;
}