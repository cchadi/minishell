#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>



typedef struct s_var  // for pipex functions
{
	char	**cmd_1;
	char	**cmd_2;
	char	*cmd_path_1;
	char	*cmd_path_2;
}			t_var;

typedef struct s_env // for socker the env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;

typedef struct s_shell // comming from parsing          // 1= infile
{                                                       // 2= cmd
    char *arg;                                          // 3= arg
    int type;                                           // 4= outfile
    struct s_shell *next;                               // 5= pipe
} t_shell;

typedef struct s_minishell // struct for execution
{
    char *infile;
    char *cmd;
    char *arg;
    char *outfile;
    int  pid;
    struct s_minishell *next;
} t_minishell;

/*********************    Linked_list    *********************/

t_minishell			*ft_lstnew(void);
t_minishell			*ft_lstlast(t_minishell *lst);
void				ft_lstadd_back(t_minishell **lst, t_minishell *new);
void				ft_lstadd_front(t_minishell **lst, t_minishell *new);

/**********************     LIBFT    **********************/

char	*ft_itoa(int n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isdigit( int c );
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memmove( void *dst, const void *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/******************* printf  ********************/

int			ft_putnbr(int c, int len);
int			ft_putchar(char c, int len);
int			ft_putstr(char *s, int len);
int			ft_printf(const char *str, ...);
int			ft_check(char s, va_list args, int len);
int			ft_put_positive(unsigned int c, int len);
int			ft_put_adress(unsigned long decimal, int len);
int			ft_decimal_to_hex(unsigned long decimal, int len);
int			ft_decimal_to_hexa(unsigned int decimal, int len);

/**************** pipex  *******************/

void		ft_free(char **ptr);
char		**command_tableau(char *str);
char		*if_accessible(char *cmd, char **env);
int			check_cmd(char **av, char **env, t_var *t);
void		ft_pipe(char **av, char **env, t_var *var);

/**************** get_next_line  *******************/

char		*get_next_line(int fd);
char		*returnline(char *buffer);
char		*ft_readfile(int fd, char *buffer);

/**************** builtins  *******************/

void build_pwd(void);
void build_env(t_env *v);
void build_exit(int status);
void build_cd(char *direction);
void build_unset(char *str, t_env **v);
void build_export(char *str, t_env **v);
void build_echo(char *str, int nl, int fd);

/************** env_linked_list  ****************/

t_env *env_lstnew(void);
t_env *split_env(char *str);
t_env *env_lstlast(t_env *lst);
void get_envp(char **envp, t_env **head);
void env_lstadd_back(t_env **lst, t_env *new);
void env_lstadd_front(t_env **lst, t_env *new);

/******************* execution ********************/

void execute_cmd(t_minishell *e);
void forming_list(t_minishell **my_struct, t_shell *shell);

#endif
