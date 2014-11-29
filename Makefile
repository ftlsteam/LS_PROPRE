all:
	gcc -Wall -Wextra -Werror create_node.c ft_arguments.c insert_data.c main.c print_it.c print_lsl.c print_lsl1.c print_lsl2.c print_lsl3.c read.c read_stat.c recursive_v2.c set_up.c recursive_time.c recursive_stat.c  -L libft/ -lft -I includes/ -o ft_ls

easy:
	make -C libft/ fclean
	make -C libft/
	gcc *.c -L libft/ -lft -I includes/ -o ft_ls
debug:
	make -C libft/ fclean
	make -C libft/
	gcc -O0 -g *.c -L libft/ -lft -I includes/ -o ft_ls_debug
couli:
	gcc -Wall -Wextra -Werror -I includes -L libft -lft srcs/arguments.c srcs/binary_tree.c srcs/set_up.c srcs/test_btree.c srcs/print_it.c srcs/recursive.c -o ft_ls
coulieasy:
	gcc -I includes -L libft -lft srcs/arguments.c srcs/binary_tree.c srcs/set_up.c srcs/test_btree.c srcs/print_it.c srcs/recursive_v2.c srcs/time.c -o ft_ls 

ava:
	gcc -Wall -Wextra -Werror -I includes -L libft -lft avallete/arguments.c avallete/binary_ltree.c avallete/print_lsl.c avallete/binary_tree.c avallete/time.c avallete/set_up.c avallete/test_btree.c avallete/print_it.c -o ft_ls
