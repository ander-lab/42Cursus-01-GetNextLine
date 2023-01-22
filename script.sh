# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 10:21:07 by ajimenez          #+#    #+#              #
#    Updated: 2023/01/22 10:41:02 by ajimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

curl https://raw.githubusercontent.com/ander-lab/42Cursus-01-GetNextLine/main/main.c -o main.c 2>/dev/null

curl https://raw.githubusercontent.com/ander-lab/42Cursus-01-GetNextLine/main/tests/large_file.txt -o large_file.txt 2>/dev/null
curl https://raw.githubusercontent.com/ander-lab/42Cursus-01-GetNextLine/main/tests/empty_test.txt -o empty_test.txt 2>/dev/null
curl https://raw.githubusercontent.com/ander-lab/42Cursus-01-GetNextLine/main/tests/lotr.txt -o lotr.txt 2>/dev/null
curl https://raw.githubusercontent.com/ander-lab/42Cursus-01-GetNextLine/main/tests/nl_and_eof_one.txt -o nl_and_eof_one.txt 2>/dev/null

echo "Elige una opcion para BUFFER_SIZE: \n 0 - '0' \n 1 - '1' \n 2 - '10000000'"
read option

if [ $option = '0' ]; then
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=0 main.c get_next_line.c get_next_line_bonus.c
elif [ $option = '1' ]; then
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_bonus.c
elif [ $option = '2' ]; then
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_bonus.c
fi
