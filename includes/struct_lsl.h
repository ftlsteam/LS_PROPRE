#ifndef STRUCT_LS_H
# define STRUCT_LS_H
# include <stdio.h>
typedef struct		s_llstat
{
	char			filetype;
	mode_t			accesright;
	int				nbhlink;
	char			*owner;
	char			*group;
	off_t			size;
	time_t			date;
	char			*filename;
}					t_llstat;

typedef struct		s_lltree
{
	struct s_lltree	*right;
	struct s_lltree	*left;
	t_llstat		stats;
}					t_lltree;
char			ft_oldtime(int32_t timefile);
unsigned char 	take_typefile(mode_t c);
void			test_sizeinfos(t_llstat *stats, size_t *infos, size_t block, char *choice);
void			takestats(struct stat *statsbase, t_llstat *statstree);
size_t          *ls_read_stat(t_lltree **tree, char *pathname, char *choice);
t_lltree		*create_node_stat(t_llstat datas);
void			ltree_insert_data_time(t_lltree **tree, t_llstat data);
void			ltree_insert_data(t_lltree **tree, t_llstat data);
void			print_error(char *filename);
void			print_total(int st_blksize);
void			print_typefile(unsigned char type);
void			print_usrmod(int st_mode);
void			print_groupmod(int st_mode);
void			print_othermod(int st_mode);
void			print_rights(int st_mode);
void			print_hlink(int nb, size_t maxcol);
void			print_owner(char *owner, size_t maxcol);
void			print_group(char *groupname, size_t maxcol);
void			print_size(off_t size, size_t maxcol);
void			print_time(time_t timefile, size_t oldtime);
void			print_linkpath(char *filename, off_t size);
void 			print_lsl(t_llstat *stats, size_t *infos, char option, char *pathname);
#endif
