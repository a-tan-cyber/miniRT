/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/17 22:53:54 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

// ft_string.c
size_t	ft_strlen(const char *str);
void	ft_reverse_string(char *string, char *reverse_string, int length);
char	*ft_reverse_string_malloc(char *string);
char	*ft_str_replace(char *text, size_t start, size_t len, char *expanded);

// ft_string_cat.c
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

// ft_string_cmp.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *str, char *to_find);
// char			*ft_strnstr(const char *str, char *to_find, size_t len);
char	*ft_strchr(const char *str, int to_find);
// char			*ft_strrchr(const char *str, int to_find);
int		ft_strchr_idx(const char *str, int to_find);

// ft_string_cnt.c
int		ft_count_cins(const char *str, char c);
int		num_of_x_ignore_y_substr(const char *line, char x, char y);

// ft_string_btcmp.c
int		ft_str_is_subset(const char *pool, const char *legal);

// ft_string_con.c
char	*concat_char(char *string, char c);
char	*concat_char_insitu(char *string, char c);

// ft_string_cpy.c
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_str_append(char *s1, const char *s2);

// ft_string_m.c
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, size_t n);
void	*ft_bzero(void *dest, size_t size);
void	*ft_calloc(size_t len, size_t size);

// ft_string_mem.c
void	*ft_memset(void *dest, int n, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *src, int c, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// ft_string_mem2.c
char	*ft_memappend_front(const char *s1, size_t len1, char *s2, size_t len2);
void	*ft_memappend_back(void *s1, size_t len1, const void *s2, size_t len2);
void	*ft_memjoin2(void const *s1, size_t len1, void const *s2, size_t len2);
char	*ft_strjoin2(char const *s1, char const *s2);

// ft_string_p.c
void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_puterr(char *str);
void	ft_putnstr(char *str, int n);
void	ft_putnbr(int nb);

// ft_put_fd.c
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_write_all(int fd, const void *buf, size_t len);

// ft_string_s.c
// int		ft_strjoin_total_len(int size, char **strs, char *sep);
char	*ft_strjoin(int size, char **strs, char *sep);
// char	*ft_strjoin2(char const *s1, char const *s2);
// void	*ft_memjoin2(void const *s1, size_t len1, void const *s2, size_t len2);
// size_t  find_split_count(char *str, char *charset);
size_t	find_split_count(char *str, char *charset);
char	**ft_split(char *str, char *charset);

// ft_string_v.c
int		ft_str_is_alpha(char *str);
int		ft_str_is_lower(char *str);
int		ft_str_is_upper(char *str);
int		ft_str_is_printable(char *str);

// ft_string_vi.c
int		ft_str_is_int(char *str);
int		ft_str_is_num(char *str);

// ft_string_t.c
char	*ft_str_toupper(char *str);
char	*ft_str_tolower(char *str);
char	*ft_str_titlecase(char *str);

// ft_string_trim.c
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strtrim_ws(char const *s1);

// ft_string_substr.c
char	*ft_substr(char const *s, size_t start, size_t len);
void	ft_str_replace_chr(char *text, int original, int target);

#endif