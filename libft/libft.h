/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:45:01 by jcollon           #+#    #+#             */
/*   Updated: 2023/02/03 17:00:05 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Convert a string to an integer
 * 
 * @param str: string to convert
 * @return converted integer
 */
int		ft_atoi(const char *str);

/**
 * @brief Fill a memory area with zeros
 * 
 * @param ptr: memory address to fill
 * @param size: number of bytes to fill
 */
void	ft_bzero(void *ptr, size_t size);

/**
 * @brief Allocate memory and fill it with zeros
 * 
 * @param count: number of elements to allocate
 * @param size: size of each element
 * @return pointer to the allocated memory
 */
void	*ft_calloc(size_t count, size_t size);

/**
 * @brief Check if a character is alphanumeric (Aa0)
 * 
 * @param c: character to check
 * @return 1 if the character is alphanumeric, 0 otherwise
 */
int		ft_isalnum(int c);

/**
 * @brief Check if a character is alphabetic (Aa)
 * 
 * @param c: character to check
 * @return 1 if the character is alphabetic, 0 otherwise
 */
int		ft_isalpha(int c);

/**
 * @brief Convert an integer to a string
 * 
 * @param n: integer to convert
 * @return the MALLOCED string
 */
char	*ft_itoa(int n);

/**
 * @brief Get the length of a string
 * 
 * @param str: string to get the length of
 * @return the length of the string
 */
int		ft_strlen(const char *str);

/**
 * @brief Check if a character is ASCII (0-127)
 * 
 * @param c: character to check
 * @return 1 if the character is ASCII, 0 otherwise
 */
int		ft_isascii(int c);

/**
 * @brief Check if a character is a digit (0-9)
 * 
 * @param c: character to check
 * @return 1 if the character is a digit, 0 otherwise
 */
int		ft_isdigit(int c);

/**
 * @brief Check if a character is printable (no control characters)
 * 
 * @param c: character to check
 * @return 1 if the character is printable, 0 otherwise
 */
int		ft_isprint(int c);

/**
 * @brief Get the address of the first occurence of a character in a string
 * 
 * @param str: string to search in
 * @param c: character to search for
 * @param limit: number of bytes to search in
 * @return the address of the first occurence of the character, NULL if not
 * found
 */
void	*ft_memchr(const void *str, int c, size_t limit);

/**
 * @brief Compare two memory addresses
 * 
 * @param str1: first memory address
 * @param str2: second memory address
 * @param limit: number of bytes to compare
 * @return int 
 */
int		ft_memcmp(const void *str1, const void *str2, size_t limit);

/**
 * @brief Copy src to dest
 * 
 * @param dest: destination address
 * @param src: source address
 * @param limit: number of bytes to copy
 * @return dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t limit);

/**
 * @brief Copy src to dest, allowing overlapping memory addresses
 * 
 * @param dest: destination address
 * @param src: source address
 * @param n: number of bytes to copy
 * @return dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Put character c in the first n bytes of the memory address s
 * 
 * @param s: memory address
 * @param c: character to put
 * @param n: number of bytes to put the character in
 * @return s
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Put character c on the file descriptor fd
 * 
 * @param c: character to put
 * @param fd: file descriptor
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Put string str on the file descriptor fd
 * 
 * @param str: string to put
 * @param fd: file descriptor
 */
void	ft_putstr_fd(char *str, int fd);

/**
 * @brief Put number nb on the file descriptor fd
 * 
 * @param nb: number to put
 * @param fd: file descriptor
 */
void	ft_putnbr_fd(int nb, int fd);

/**
 * @brief Split a string into an array of strings, using the character c as a
 * delimiter
 * 
 * @param s: string to split
 * @param c: delimiter
 * @return the MALLOCED array of strings
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Returns the address of the first occurence of the character c in the
 * string str
 * 
 * @param str: string to search in
 * @param c: character to search for
 * @return the address of the first occurence of the character, NULL if not
 */
char	*ft_strchr(const char *str, int c);

/**
 * @brief Duplicate a string
 * 
 * @param src: string to duplicate
 * @return the MALLOCED duplicate of the string
 */
char	*ft_strdup(char *src);

/**
 * @brief Join two strings
 * 
 * @param s1: first string
 * @param s2: second string
 * @return the MALLOCED joined string
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Concatenate two strings (dst needs to be big enough to hold the result
 * )
 * 
 * @param dst: the string to concatenate to
 * @param src: the string to concatenate at the end of dst
 * @param dstsize: the maximum size of dst
 * @return the length of the concatenated string (if dstsize != 0 or the length
 * of dst is greater than dstsize it returns dstsize + the length of src)
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Copy a string (dst needs to be big enough to hold the result)
 * 
 * @param dst: the string to copy to
 * @param src: the string to copy from
 * @param dstsize: the maximum size of dst
 * @return the size of the string src (IDK why it's not the size of dst)
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Compare two strings and return the difference between the first
 * different characters
 * 
 * @param s1: first string
 * @param s2: second string
 * @param limit: maximum number of bytes to compare
 * @return 0 if the strings are equal, otherwise the difference between the
 * first different characters 
 */
int		ft_strncmp(const char *s1, const char *s2, size_t limit);

/**
 * @brief Find the first occurence of the string little in the string big
 * 
 * @param big: string to search in
 * @param little: string to search for
 * @param limit: maximum number of bytes to search in
 * @return the address of the first occurence of the string, NULL if not found
 */
char	*ft_strnstr(const char	*big, const char *little, size_t limit);

/**
 * @brief Returns the address of the last occurence of the character c in the
 * string str
 * 
 * @param str: string to search in
 * @param c: character to search for
 * @return the address of the last occurence of the character, NULL if not
 */
char	*ft_strrchr(const char *str, int c);

/**
 * @brief Remove the characters in the string set from the beginning and end of
 * the string str
 * 
 * @param str: string to trim
 * @param set: string containing the characters to remove
 * @return the MALLOCED trimmed string 
 */
char	*ft_strtrim(char const *str, char const *set);

/**
 * @brief Copy the string str to a new string, starting at the index start and
 * copying at most limit characters
 * 
 * @param str: string to copy from
 * @param start: index to start copying from
 * @param limit: maximum number of characters to copy
 * @return the MALLOCED substring
 */
char	*ft_substr(char const *str, unsigned int start, size_t limit);

/**
 * @brief Convert a character to a lowercase character
 * 
 * @param c: character to convert
 * @return the lowercase character
 */
int		ft_tolower(int c);

/**
 * @brief Convert a character to an uppercase character
 * 
 * @param c: character to convert
 * @return the uppercase character
 */
int		ft_toupper(int c);

/**
 * @brief Apply the function f to each character of the string str
 * 
 * @param str: string to apply the function to
 * @param f: function to apply
 */
void	ft_striteri(char *str, void (*f)(unsigned int, char*));

/**
 * @brief Apply the function f to each character of the string str and return a
 * new string with the result
 * 
 * @param str: string to apply the function to
 * @param f: function to apply
 * @return the MALLOCED string with the result
 */
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));

/**
 * @brief Put a string on the file descriptor fd, followed by a newline
 * 
 * @param str: string to put
 * @param fd: file descriptor
 */
void	ft_putendl_fd(char *str, int fd);

/**
 * @brief Create a new t_list
 * 
 * @param content The content to create the node with
 * @return t_list* The new node
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the node 'new_lst' at the beginning of the list.
 * 
 * @param lst: the address of a pointer to the first link of a list.
 * @param new_lst: the address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new_lst);

/**
 * @brief Counts the number of nodes in a list.
 * 
 * @param lst: the beginning of the list.
 * @return the length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Last node of the list.
 * 
 * @param lst: the beginning of the list.
 * @return returns the last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node ’new’ at the end of the list.
 * 
 * @param lst: the address of a pointer to the first link of a list.
 * @param new_lst: the address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new_lst);

/**
 * @brief Takes as a parameter a node and frees the memory of the node’s content
 * using the function ’del’ given as a parameter and free the node.
 * @param lst: the node to free.
 * @param del: the address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Iterates the list 'lst' and applies the function 'f'
 * on the content of each node.
 * 
 * @param lst: the address of a pointer to a node.
 * @param f: the address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content
 * of each node. Creates a new list resulting of the successive applications of
 * the function 'f'. The 'del' function is used to delete
 * the content of a node if needed.
 * 
 * @param lst: the address of a pointer to a node.
 * @param f: the address of the function used to iterate on the list.
 * @param del: the address of the function used to delete the content of
 * a node if needed.
 * @return the new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free. Finally, the pointer to the list
 * is set to NULL.
 * 
 * @param lst: the address of a pointer to a node.
 * @param del: the address of the function used to delete the content of the
 * node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

#endif