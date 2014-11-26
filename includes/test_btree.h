
#ifndef TEST_BTREE_H
# define TEST_BTREE_H

/*
 **System libs--------------------
 */

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>

/*
 **Structures--------------------
 */

# include "struct_lsl.h"

typedef struct		s_btree
{
	char			*content;
	unsigned char	file_type;
	char			*dir_path;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef struct	  s_time
{
	char			*content;
	unsigned int	time;
	char			*dir_path;
	unsigned char	file_type;
	struct s_time	*left;
	struct s_time	*right;
}				   t_time;
/*
 **Prototypes--------------------
 */
int			ft_arguments(int argc, char const **argv, char *choice,\
		void (*f)(char *c, char e));
void		btree_print(t_btree *root, char *choice);
void		btree_print_time(t_time *root, char *choice);
void		ltree_print(t_lltree *root, size_t *infos, char *choice);
void			ft_arg(char *c, char e);
int			ft_choice(int n);
void		ls_read(t_btree **tree, char *pathname);
void		ls_read_time(t_time **tree, char *pathname);
t_btree		*create_node(char *content, unsigned char type);
t_time		*create_node_time(char *content, int time, unsigned char type);
void		btree_insert_data_time(t_time **tree, char *data, unsigned int time, unsigned char type);
void		btree_insert_data(t_btree **tree, char *data, unsigned char type);
void		btree_insert_data_alpha(t_time **tree, char *data, unsigned char type, unsigned int time);
void		set_up(char *argv, char *choice);
void		ls_read_rec(char *pathname, char *choice);
void		show_dir(char *pathname, char *choice);
//void    free_tree(t_btree *node);
void        ls_read_rec_time(char *pathname, char *choice);
void        show_dir_time(char *pathname, char *choice);
void		ft_printls(char *filename, char hide);
void		ls_grep_dir(t_btree **tree, char *options);
#endif


