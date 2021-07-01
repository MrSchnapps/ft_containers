# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 11:36:11 by judecuyp          #+#    #+#              #
#    Updated: 2021/05/11 11:36:11 by judecuyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	clang++ -Wall -Wextra -Werror testers/*.cpp -std=c++98

fclean:
	rm -rf a.out

re: fclean all
