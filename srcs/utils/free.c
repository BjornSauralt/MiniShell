/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:38:30 by cfleuret          #+#    #+#             */
/*   Updated: 2025/03/26 17:08:05 by cfleuret         ###   ########.fr       */
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
