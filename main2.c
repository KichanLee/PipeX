#include "pipex.h"

char	*plus_slash(char *str)

{
	char	*str_slash;
	int		i;

	str_slash = (char *)malloc(ft_strlen_a(str) + 2);
	i = 1;
	if(!str_slash)
		return (NULL);
	str_slash[0] = '/';
	while (*str)
	{
		str_slash[i] = *str;
		++i;
		++str;
	}
	str_slash[i] = '\0';
	return (str_slash);
}

char	*ft_check_path(char **envp)
{
	int	i;
	char *path_check;
	char *re;

	i = 0;
	while (envp[i])
	{
		path_check = ft_strnstr(envp[i], "PATH", ft_strlen_a(envp[i]));
		if(path_check)
			return(path_check);
		i++;
	}
	return (NULL);
}

int		ft_check_access(char **av, char **envp)
{
	int	i;
	char *check_file;
	int	flag_av1;
	int	flag_av2;

	i = 0;
	flag_av1 = 0;
	flag_av2 = 0;
	check_file = NULL;

	while (envp[i])
	{
		check_file = ft_strjoin(envp[i], plus_slash(av[1]));
		printf("check_file : %s\n", check_file);
		if(!check_file)
			return (0);
		if(access(check_file, F_OK | X_OK) == 0)
			flag_av1 = 1;
		++i;
	}
	i = 0;
	while (envp[i])
	{
		check_file = ft_strjoin(envp[i], plus_slash(av[2]));
		printf("check_file : %s\n", check_file);
		if(access(check_file, F_OK | X_OK) == 0)
			flag_av2 = 1;
		++i;
	}
	if(flag_av1 && flag_av2)
		return (1);
	return (0);
}

int main(int ac, char **av, char **envp)
{ 
	char		*str;
	t_struct	t;
	int			acc_check;

	str = ft_check_path(envp);

	t.s_envp = ft_split(str, ':');
	acc_check = ft_check_access(av, t.s_envp);

}
