/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:45:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/21 14:19:22 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*------ Functions to find or identify a string*/
/* int */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_isspace(int c);
int			ft_check_doublequotes(char *command);
int			ft_find_char(char *str, char c);
/* char * */
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
/* void * */
void		*ft_memchr(const void *s, int c, size_t n);
/* size_t */
size_t		ft_strlen(const char *c);

/*------ Functions to change a string ------*/
/* between a char * and an int*/
int			ft_atoi(const char *str);
long		ft_atol(const char *str, bool *check);
char		*ft_itoa(int n);
/* change a char * itself*/
void		ft_bzero(void *s, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_quotes(char *value);

/*------ Printers (to an fd) ------*/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_error_msg(char *err);

/*------ Malloc and fd users ------*/
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_separate(char *target, char sep);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_free_strjoin(char *s1, char *s2, int flag);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		**ft_split(const char *s, char c);
void		ft_free(void *memory);
void		ft_protected_close(int fd, int fail, int def);

/*------ Linked list ------*/
t_list		*ft_lstnew(void	*content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del) (void *));
void		ft_lstclear(t_list **lst, void (*del) (void *));
void		ft_lstiter(t_list *lst, void (*f) (void *));
t_list		*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));
t_list		*ft_ln(void *content);
void		ft_laddb(t_list **lst, t_list *new);

int			ft_space(int c);
int			ft_firstoccur(const char *str, char c);
int			ft_lastoccur(const char *str, char c);
int			ft_strcmp(char *s1, char *s2);
int			spacecount(char *str, int i);

#endif
