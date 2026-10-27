# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_sum_time.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:52:23 by doriani           #+#    #+#              #
#    Updated: 2023/12/11 15:54:07 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

seconds = int(input("Insert hours: ")) * 3600
seconds += int(input("Insert minutes: ")) * 60
seconds += int(input("Insert seconds: "))
print("Total seconds:", seconds)