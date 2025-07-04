# Libft2
![Static Badge](https://img.shields.io/badge/Grade-125-green) ![Static Badge](https://img.shields.io/badge/Bonus-Yes-green?style=flat)
 ![Static Badge](https://img.shields.io/badge/Language-C-blue?style=flat)

Libft is the first project of the 42 Common Core.
The aim of this project is to recode some functions from libc library + some custom functions.

This project pass all francinette --strict tests.

I have added, and will add, other functions during my cursus.
### Here you can find my code for the following functions :
#### Functions on characters
- `int	ft_toupper(int c)`
- `int	ft_tolower(int c)`
- `t_bool	ft_isalpha(int c)`
- `t_bool	ft_isdigit(int c)`
- `t_bool	ft_isalnum(int c)`
- `t_bool	ft_isascii(int c)`
- `t_bool	ft_isblank(int c)`
- `t_bool	ft_iscntrl(int c)`
- `t_bool	ft_isgraph(int c)`
- `t_bool	ft_isprint(int c)`
- `t_bool	ft_ispunct(int c)`
- `t_bool	ft_isspace(int c)`
- `t_bool	ft_isxdigit(int c)`
#### Functions on strings
- `size_t	ft_strlen(const char *s)`
- `size_t	ft_strlcpy(char *dst, const char *src, size_t size)`
- `size_t	ft_strlcat(char *dst, const char *src, size_t size)`
- `int	ft_strncmp(const char *s1, const char *s2, size_t n)`
- `void	ft_striteri(char *s, void (*f)(unsigned int, char *))`
- `char	*ft_strchr(const char *s, int c)`
- `char	*ft_strrchr(const char *s, int c)`
- `char	*ft_strdup(const char *s)`
- `char	*ft_strnstr(const char *big, const char *little, size_t len)`
- `char	**ft_split(const char *s, char c)`
- `char	*ft_strjoin(const char *s1, const char *s2)`
- `char	*ft_strtrim(const char *s1, const char *set)`
- `char	*ft_substr(const char *s, unsigned int start, size_t len)`
- `char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))`
#### Conversions functions
- `char	*ft_atob(unsigned char c)`
- `int	ft_atoi(const char *str)`
- `long	ft_atol(const char *str)`
- `long long	ft_atoll(const char *str)`
- `char	*ft_atox(unsigned char c, t_bool upper)`
- `char	*ft_itoa(int n)`
#### Memory manipulation functions
- `void	ft_bzero(void *s, size_t n)`
- `void	*ft_calloc(size_t nmemb, size_t size)`
- `void	*ft_memchr(const void *s, int c, size_t n)`
- `int	ft_memcmp(const void *s1, const void *s2, size_t n)`
- `void	*ft_memcpy(void *dest, const void *src, size_t n)`
- `void	*ft_memmove(void *dest, const void *src, size_t n)`
- `void	*ft_memset(void *s, int c, size_t n)`
#### Writing functions
- `void	ft_putchar_fd(char c, int fd)`
- `void	ft_putstr_fd(char *s, int fd)`
- `void	ft_putendl_fd(char *s, int fd)`
- `void	ft_putnbr_fd(int n, int fd)`
#### Chained lists functions
- `t_list	*ft_lstnew(void *content)`
- `void	ft_lstadd_front(t_list **lst, t_list *new)`
- `int	ft_lstsize(t_list *lst)`
- `t_list	*ft_lstlast(t_list *lst)`
- `void	ft_lstadd_back(t_list **lst, t_list *new)`
- `void	ft_lstdelone(t_list *lst, void (*del)(void*))`
- `void	ft_lstclear(t_list **lst, void (*del)(void*))`
- `void	ft_lstiter(t_list *lst, void (*f)(void *))`
- `t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`
#### Math functions
- `int	ft_min(int a, int b)`
- `int	ft_max(int a, int b)`
- `int	ft_pow(int x, int exp)`
- `int	ft_abs(int x)`
- `long	ft_labs(long x)`
- `long long	ft_llabs(long long x)`
- `unsigned int	ft_sqrt(unsigned int x)`
#### Other functions from 42 projects
- `int	ft_printf(const char *format, ...)`
- `char	*get_next_line(int fd)`