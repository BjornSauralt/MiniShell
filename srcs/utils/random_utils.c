/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:34:10 by cfleuret          #+#    #+#             */
/*   Updated: 2025/03/31 14:19:45 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	strdup_param(t_token *t, int i, char **str, int count)
{
	int	j;

	t->str = malloc(sizeof(char *) * (count + 1));
	j = 0;
	while (j < count && str[i] != NULL)
	{
		t->str[j] = ft_strdup(str[i]);
		i++;
		j++;
	}
	t->str[j] = NULL;
}

char	**change_str(t_shell *data, char **str)
{
	t_token	*t;
	int		i;

	t = data->token;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = ft_strdup(t->str[0]);
		i++;
		t = t->next;
	}
	return (str);
}
