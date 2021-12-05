/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/12/04 15:58:37 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <signal.h>
#include <dirent.h>
#include <term.h>
#include <curses.h>

typedef struct s_token		// 링크드 리스트 형태
{
	char	**cmd;
	int		redirect;
} t_token;

typedef struct s_mini
{
	t_token	*token;			// "[command] [option] [redirect]"를 담고있음, 크기는 (redirect갯수 + 1)로 malloc할 예정
	char	*line;			// 유저의 입력 라인
	char	*locate;		// 현재 셸의 위치
	char	*pwd;			// pwd
	int		num_redirect;	// redirect 갯수, 나중에 token free하기 위해 필요
	int		exit_flag;		// 셸의 종료 시그널
	int		token_size;
} t_mini;

// main_function
void	command_parsing(t_mini *mini);
void	error_func();

#endif