/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:38:30 by cfleuret          #+#    #+#             */
/*   Updated: 2025/04/18 10:59:47 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_shell *data, char *line)
{
	free(line);
	free_tokens(data->token);
}

void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_tokens(t_token *t)
{
	while (t)
	{
		if (t->infile != STDIN_FILENO)
			close(t->infile);
		if (t->outfile != STDOUT_FILENO)
			close(t->outfile);
		delfirst(&t);
	}
}


void	free_env(t_env *env)
{
	while (env)
	{
		delfirst_stack(&env);
	}
}

void	ft_close(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
