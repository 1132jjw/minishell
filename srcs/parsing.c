/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:22:09 by jeujeon           #+#    #+#             */
/*   Updated: 2021/12/05 20:19:06 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_redirect(char *line)
{
	if (ft_strncmp(line, ">>", 2) == 0)
	{
		if (line[2] != 0)
			error_func("parse error near '>'");
		return (2);
	}
	else if (ft_strncmp(line, ">", 1) == 0)
	{
		if (line[1] != 0)
			error_func("parse error near '>'");
		return (1);
	}
	else if (ft_strncmp(line, "<<", 2) == 0)
	{
		if (line[2] != 0)
			error_func("parse error near '<'");
		return (4);
	}
	else if (ft_strncmp(line, "<", 1) == 0)
	{
		if (line[1] != 0)
			error_func("parse error near '<'");
		return (3);
	}
	else if (ft_strncmp(line, "|", 1) == 0)
	{
		if (line[1] != 0)
			error_func("parse error near '|'");
		return (5);
	}
	return (0);
}

int	get_token_size(char **splited)
{
	int		i;
	int		token_size;

	i = 0;
	token_size = 0;
	while(splited[i])
	{
		if (is_redirect(splited[i]))
			token_size++;
		i++;
	}
	return (token_size + 1);
}

void	create_cmd(t_token *token, char **splited)
{
	int	i;
	int	token_index;
	int	cmd_size;

	i = 0;
	token_index = 0;
	while(splited[i])
	{
		cmd_size = 0;
		while (splited[i] != NULL && !is_redirect(splited[i]))	//cmd 크기
		{
			cmd_size++;
			i++;
		}
		token[token_index].cmd = malloc(sizeof(char *) * (cmd_size + 1));
		if (token[token_index].cmd == NULL)
			error_func("malloc error");
		token[token_index].cmd[cmd_size] = NULL;
		if (splited[i] == NULL)
			break ;
		token_index++;
		i++;
	}
}

t_token	*create_token(t_mini *mini, char **splited)
{
	t_token	*token;

	mini->token_size = get_token_size(splited);
	token = (t_token *)malloc(sizeof(t_token) * (mini->token_size));
	if (token == NULL)
		return (NULL);
	create_cmd(token, splited);
	return (token);
}

void	save_cmd_red_data(t_mini *mini, char **splited)
{
	int	i;
	int	token_index;
	int	cmd_index;

	i = 0;
	token_index = 0;
	while(splited[i])
	{
		cmd_index = 0;
		while (splited[i] != NULL && !is_redirect(splited[i]))	//cmd 크기
		{
			mini->token[token_index].cmd[cmd_index] = splited[i];
			cmd_index++;
			i++;
		}
		mini->token[token_index].cmd[cmd_index] = NULL;
		if (splited[i] == NULL)
		{
			mini->token[token_index].redirect = 0;
			break ;
		}
		if (is_redirect(splited[i]))
			mini->token[token_index].redirect = is_redirect(splited[i]);
		token_index++;
		i++;
	}
}

void	print_cmd(t_mini *mini)
{
	int		i;
	int		j;

	i = 0;
	while (i < mini->token_size)
	{
		j = 0;
		printf("token[%d]\n", i);
		while (mini->token[i].cmd[j])
		{
			printf("%s\n", mini->token[i].cmd[j]);
			j++;
		}
		printf("redirect:%d\n\n", mini->token[i].redirect);
		i++;
	}
}

void	command_parsing(t_mini *mini)
{
	int		i;
	int		j;
	int		k;
	char	**tmp_split;

	tmp_split = ft_split(mini->line, ' ');
	mini->token = create_token(mini, tmp_split);
	save_cmd_red_data(mini, tmp_split);
	print_cmd(mini);
	free(tmp_split);
}
