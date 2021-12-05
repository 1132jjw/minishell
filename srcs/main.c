/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/12/05 15:58:32 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_func(char *error_m)
{
	printf("%s\n", error_m);
	exit(1);
}

void	excute_built_in_command(t_mini *mini)
{
	
}

int		is_built_in_command(t_mini *mini)
{
	return (1);
}

int		is_exist_command(t_mini *mini)
{
	return (1);
}

void	execute_command(t_mini *mini)
{

}

void	check_command(t_mini *mini)
{
	char	**cmd;
	int		i;

	i = 0;
	while (i < mini->token_size)
	{
		cmd = mini->token[i].cmd;
		if (ft_strncmp(cmd[0], "exit", 4) == 0)
			exit(0);
		else if (is_built_in_command(mini))
			excute_built_in_command(mini);
		else if (is_exist_command(mini))
			execute_command(mini);
		else
			printf("command not found\n");
		i++;
	}
}

// void	is_exit(t_mini *mini) // 종료 시그널 체크 함수
// {		
// 	if (mini->exit_flag == 0)
// 		return ;
// 	free_resource(mini);
// 	exit(0);
// }

void	new_prompt(t_mini *mini) // 프롬프트 생성 함수
{
	char	*str;

	str = readline("minishell >");
	add_history(str);
	mini->line = str;
}

void	loop_init(t_mini *mini) // 현재 위치 갱신 함수
{
	char	**split_str;
	int		i;

	getcwd(mini->pwd, 1024);
	printf("%s\n", mini->pwd);
	split_str = ft_split(mini->pwd, '/');
	if (split_str == NULL)
		error_func("malloc error");
	i = 0;
	while (split_str[i])
		i++;
	if (i == 2)
		mini->locate = ft_strdup("~");
	else
		mini->locate = ft_strdup(split_str[i - 1]);
	i = 0;
	while (split_str[i])
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
}

t_mini	*minishell_init(void)
{
	t_mini	*mini;

	mini = (t_mini *)malloc(sizeof(t_mini));
	if (mini == NULL)
		error_func("malloc error");
	mini->pwd = (char *)malloc(sizeof(char) * 1024);
	if (mini->pwd == NULL)
		error_func("malloc error");
	mini->exit_flag = 0;
	return (mini);
}

void	cmd_free(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	ft_free(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (i < mini->token_size)
	{
		cmd_free(mini->token[i].cmd);
		i++;
	}
	free(mini->token);
	free(mini->line);
}

int	main(int argc, const char **argv) // return (1)은 에러 시그널
{
	t_mini	*mini;

	mini = minishell_init();
	while (1)
	{
		// loop_init(mini);
		new_prompt(mini);
		command_parsing(mini);
		check_command(mini);
		ft_free(mini);
	}
	free(mini->pwd);
	free(mini);
	return (0);
}
