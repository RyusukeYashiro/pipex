/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:50:51 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/21 18:31:41 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/pipex.h"


int     ft_open(char *file , int  file_type)
{
    int     fd;
    if (file_type == 0)
        fd = open(file , O_RDONLY);
    else if(file_type == 1)
        fd = open(file , (O_WRONLY | O_CREAT | O_TRUNC));
    return (fd);
}