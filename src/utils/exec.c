/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:38:19 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/05 20:18:49 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile

void   ft_exec(const char *cmd , const char **env)
{
    
}