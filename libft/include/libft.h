/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <waon-in@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:14:37 by waon-in           #+#    #+#             */
/*   Updated: 2024/04/06 23:22:32 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>

# ifdef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

typedef struct s_gnl
{
	char			*memo;
	struct s_gnl	*next;
}	t_gnl;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			get_new_line(t_gnl *list);
int			len_memo(t_gnl *list);
int			ft_printf(const char *s, ...);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_check(va_list *args, char c);
int			ft_putnbr(long nb);
int			ft_putnbr_u(unsigned int nb);
int			ft_putnbr_x(unsigned long nb);
int			ft_putnbr_xb(unsigned int nb);
int			ft_putnbr_p(unsigned long nb);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char *s, char (*f)(unsigned int, char));
char		*ft_itoa(int c);
char		*get_next_line(int fd);
char		*ft_next_line(t_gnl *list);
char		create_list(t_gnl **list, int fd);

size_t		ft_strlen(const	char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		handle_errors(char *str);
void		get_str(t_gnl *list, char *str);
void		ft_append(t_gnl **list, char *buf);
void		free_node(t_gnl **list, t_gnl *clean_node, char *buf);
void		list_check(t_gnl **list);

/* BONUS PART*/

t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);

t_gnl		*find_last_node(t_gnl *list);

void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

int			ft_lstsize(t_list *lst);

#endif
