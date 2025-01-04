/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:20:00 by ryyashir          #+#    #+#             */
/*   Updated: 2024/12/31 15:40:50 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/pipex.h"


void   ft_ac_check(int ac)
{
    if(ac < 5)
    {
        ft_putstr_fd("this is ac error" , 2); 
        exit(0);
    }
}