/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:36:09 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/16 14:26:36 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str, int *nb);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_lstsize(t_list *lst);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcpy(char *restrict_dst, const char *restrict_src,
			size_t dstsize);
size_t	ft_strlcat(char *restrict_dst, const char *restrict_src,
			size_t dstsize);
void	ft_bzero(void *s, size_t n);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
int		ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_memcpy(void *restrict_dst, const void *restrict_src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strnstr(const char *str, const char *tofind, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
int		ft_findfirst(char *buf, char c);
void	readall(int fd, char **hay);
char	*ft_strjoinb2(char const *s1, char const *s2);
char	*ft_strchrb2(const char *str, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_strlenprotect(const char *str);
int		ft_printf(const char *input, ...);
int		ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		ft_convert_base_printf_fd(unsigned long nb, char towork, int fd);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif