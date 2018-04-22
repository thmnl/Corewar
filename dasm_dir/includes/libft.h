/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:57:08 by brocher           #+#    #+#             */
/*   Updated: 2018/04/13 18:31:31 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <inttypes.h>
# include "ft_printf.h"

# define LIBFT_BUFF_SIZE	4096

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				**ft_splittrim(char *s, char c);
char				*ft_swap_char(char *s, char c, char k);
void				ft_free_tab(char **tab);
void				ft_puttab(char **tab);
char				*ft_strjoin_free(char *s1, char *s2, size_t n);
void				*ft_memset(void *str, int c, size_t n);
int					ft_abs(int value);
int					ft_atoi(char *str);
intmax_t			ft_atoi_max(char *str);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *str);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *str1, const void *str2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_ref(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstcount(t_list *head);
t_list				*ft_lstget(t_list *head, size_t pos);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putnstr(char *str, size_t n);
char				*ft_strdjoin(char *dest, char deli, char *src);
char				**ft_lexisort(char **tab, int start, int end);
char				*ft_strchrend(char *str, char c);
void				ft_putl(void);
char				*ft_itoalong(long int n);
void				ft_putnbrlong(long int nb);
void				ft_strquicksort(
char **sort, int start, int end, int fp(const char*, const char*));
void				ft_strvalueqsort(
char **sort, long *vsort, int start, int end);
void				ft_putstrpad(char const *s, int nb, char c);
void				ft_putstrpad_fd(char const *s, int nb, char c, int fd);
int					get_next_line(const int fd, char **line);
void				ft_putnbrl(int nb);
int					ft_ishexa(char c);
int					ft_atoihexa(char *str);
int					ft_isinstr(char const *haystack, char const *needle);
char				*ft_next_word(char *s);
int					ft_putfile(char *filename);
int					ft_iswspace(char c);
int					ft_putfd(int fd);
void				*ft_meminit(size_t size, char c);
size_t				ft_wstrlen(wchar_t *wstr);
int					ft_putwchar(wchar_t wc);
int					ft_putwchar_fd(wchar_t wc, int fd);
size_t				ft_putwstr(wchar_t *wstr);
size_t				ft_putwnstr(wchar_t *wstr, size_t n);
size_t				ft_putwnstr_fd(wchar_t *wstr, size_t n, int fd);
char				*ft_strprepad(char *str, size_t n, char c);
char				*ft_strpostpad(char *str, size_t n, char c);
char				*ft_itoaabs(int n);
size_t				ft_wcharlen(wchar_t wc);
char				*ft_itoabase_max(intmax_t value, int base);
char				*ft_itoabase_max_abs(intmax_t value, int base);
char				*ft_itoa_max_abs(intmax_t value);
char				*ft_itoa_umax_abs(uintmax_t value);
char				*ft_itoabase_umax_abs(uintmax_t value, int base);
void				ft_strtolower(char *str);
void				ft_putnstr_fd(char *str, size_t n, int fd);
int					ft_max(int v1, int v2);
int					ft_min(int v1, int v2);
int					ft_atoi_safe(char *str, int *err);
int					ft_round(float nb);
int					ft_charcount(char *str, char c);
int					ft_strexclu(const char *str, const char *ref);
int					ft_isupper(char c);
void				ft_putescape_fd(char c, int fd);
void				ft_putescape(char c);
int					ft_isoctal(char c);
char				ft_octal_to_char(char *str, int max_len);
void				ft_revpstr(char **tab, int start, int end);
int					ft_countpstr(char **arr);
char				**ft_duppstr(char **arr);
void				ft_putnpstr(char **tab, int start, int end);
void				ft_putpstr(char	**arr);
void				ft_delpstr(char **arr);
char				**ft_joinpstr(char **arr1, char **arr2);
char				**ft_addpstr(char *str, char **arr);
char				ft_escape_char(char c);
char				**ft_strsplit_func(char *str, int (*fp)(char*, int));
int					ft_isescape(char *str, int pos);
char				*ft_fdtostr(int fd);
char				**ft_filter_pstr_range(char **pstr, int start, int end);
int					ft_isinquotes(char *str, int pos);
char				**ft_remove_pstr_range(char **src, int start, int end);
char				**ft_dupnpstr(char **src, int len);
char				**ft_remove_pstr_func(char **src, int (*filter)(char*));
int					ft_strhas(char *str, char *characters);
void				ft_memrev(void	*memory, size_t len);
void				*safe_malloc(size_t n);

#endif
