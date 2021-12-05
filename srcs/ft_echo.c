/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:40:15 by jeujeon           #+#    #+#             */
/*   Updated: 2021/12/05 21:18:09 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_mini *mini, char *script)
{
	int	str_length;

	str_length = ft_strlen(script);
	write(1, script, str_length);
	return (0);
}