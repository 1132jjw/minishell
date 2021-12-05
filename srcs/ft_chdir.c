/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:23:08 by jeujeon           #+#    #+#             */
/*   Updated: 2021/10/28 14:39:38 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_chdir(t_mini *mini, char *path)
{
	char	buf[1024];
	
	if (chdir(path) == 0)	// 절대경로인 경우 아무런 처리 안해줘도 그냥 실행됨
		return (0);
	else					// 상대경로인 경우 현재의 디렉토리 + 상대 path 경로를 붙여주고 chdir함수 실행
	{
		getcwd(buf, 1024);
		ft_strjoin(buf, path);
		if (chdir(path) == 0)
			return (0);
		else
			return (1);
	}
}