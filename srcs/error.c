/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:08:39 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/09 13:08:40 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_msg_error(char *msg)
{
	if (msg != NULL)
		ft_putendl(msg);
	else
		ft_putendl("Error");
	exit(1);
}
