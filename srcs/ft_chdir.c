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
	
	if (chdir(path) == 0)	// �������� ��� �ƹ��� ó�� �����൵ �׳� �����
		return (0);
	else					// ������� ��� ������ ���丮 + ��� path ��θ� �ٿ��ְ� chdir�Լ� ����
	{
		getcwd(buf, 1024);
		ft_strjoin(buf, path);
		if (chdir(path) == 0)
			return (0);
		else
			return (1);
	}
}