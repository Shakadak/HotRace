/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_race.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 15:10:34 by cheron            #+#    #+#             */
/*   Updated: 2013/12/15 01:03:42 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOT_RACE_H
# define HOT_RACE_H

# ifndef STRING_H
#  define STRING_H
#  include <string.h>
# endif
# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif

typedef struct		s_btree
{
	char			*keyword;
	char			*value;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_btree	*ft_get_input(t_btree *root);
t_btree	*ft_create_tree(t_btree *root, char *keyword, char *value);
t_list	*ft_get_query(t_list *query);
void	ft_output_query(t_btree *root, t_list *query);

int		ft_read_txt(int fd, char **line, char *buff);
int		ft_check_line(char *buff);
int		ft_init_line(char **line);
int		ft_cp_buff(char **line, char *buff);
int		get_next_line(int const fd, char **line);

char	*ft_strcpy(char *copy, const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	ft_parkour(t_btree *current);
void	ft_memdel(void **ap);
int		ft_make_tree(t_btree **tree, char **keyword, char **value);
int		ft_get_search(t_list **lst);
int		ft_node_add(t_btree **root, char *keyword, char *value);
void	ft_find_search(t_btree *tree, t_list *lst);
void	*ft_memset(void *b, int c, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strdel(char **as);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
t_list	*ft_lstnew(char const *content);
t_btree	*ft_new_node(char *keyword, char *value);
t_btree	*ft_place_node(t_btree *current, t_btree *new);
t_btree	*ft_search_node(t_btree *current, char *clue);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst);
int		ft_lstadd(t_list **alst, char *content);
void	ft_del_tree(t_btree **current);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strfjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
int		ft_buff_leftover(char *buff, char **line);
int		ft_join_move(char **line, char *buff, char *next_line, int nbread);
int		ft_readfile(int const fd, char ** line, char *buff);
int		get_next_line(int const fd, char **line);

#endif
