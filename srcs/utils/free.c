/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:38:30 by cfleuret          #+#    #+#             */
/*   Updated: 2025/03/12 15:21:34 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_shell *data, char *line)
{
	free(line);
	free_stack(data->cmd);
	free_stack(data->rand);
	free_stack(data->meta);
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

void	free_stack(t_stack *t)
{
	while (t)
	{
		delfirst_stack(&t);
	}
}

