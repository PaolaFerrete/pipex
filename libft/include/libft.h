/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:29:09 by pferrete          #+#    #+#             */
/*   Updated: 2024/06/05 10:59:13 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//return 0 if is not a character alphabetic, and 1 if it is
int		ft_isalpha(int c);
//return  0 if is not a digit, and 1 if is
int		ft_isdigit(int c);
//return 0 if is not a character alphanumeric, and 1 if it is
int		ft_isalnum(int c);
//return 0 if is not a character ascii, and 1 if it is
int		ft_isascii(int c);
//return 0 if is not printable, and 1 if it is
int		ft_isprint(int c);
//return the number of elements in string
size_t	ft_strlen(const char *str);
//return a copy of the modified string
void	*ft_memset(void *str, int value, size_t num);
/* retorn none. erases the data in the n
bytes of the memory starting at the location pointed */
void	ft_bzero(void *str, size_t n);
/*returns a pointer to dest. Copies n bytes from
memory area src to memory area dest*/
void	*ft_memcpy(void *dest, const void *src, size_t count);
//returns a pointer to dest
void	*ft_memmove(void *dest, const void *src, size_t n);
//returns the length of src
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
// returns the inicial length of dest plus the length of src
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
//returns the convert letter or c if the convertion was not possible
int		ft_toupper(int c);
//returns the convert letter or c if the convertion was not possible
int		ft_tolower(int c);
/*return a pointer to the matched character
or null if the character is not found*/
char	*ft_strchr(const char *s, int c);
/*return a pointer to the matched character
or null if the character is not found*/
char	*ft_strrchr(const char *s, int c);
//returns an int less than, equal to, or greater than zero
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*returns a pointer to the matching byte
or null if the caracter doesn't find*/
void	*ft_memchr(const void *ptr, int ch, size_t count);
//returns a pointer to the matching byte or null if the caracter doesn't find
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*if little is empty returns big; if little doesn't
find returns null; returns a pointer to the first character*/
char	*ft_strnstr(const char *big, const char *little, size_t len);
/* convert int */
int		ft_atoi(const char *nptr);
/* return a pointer with dinamic memory*/
void	*ft_calloc(size_t nmemb, size_t size);
/*return a copy of string and use a malloc for memory allocated*/
char	*ft_strdup(const char *s);
/*return a pointer to substring*/
char	*ft_substr(const char *s, unsigned int start, size_t len);
/*return a pointer with two concateneted strings */
char	*ft_strjoin(const char *s1, const char *s2);
/*return a pointer which has a trim string*/
char	*ft_strtrim(char const *s1, char const *set);
/*retorn a ponteir to ponter with strigs split*/
char	**ft_split(char const *s, char c);
/*return a char pointer with number to char*/
char	*ft_itoa(int n);
/*return a char pointer change for function f*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*it's a function void*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/*it's a function void. Print a character*/
void	ft_putchar_fd(char c, int fd);
/*it's a function void. Print a string*/
void	ft_putstr_fd(char *s, int fd);
/*it's a function void. Print a string and \n*/
void	ft_putendl_fd(char *s, int fd);
/*it's a function void. Print an int*/
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_strcmp(char *s1, char *s2);


#endif
