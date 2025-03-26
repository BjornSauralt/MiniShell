/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:20:01 by cfleuret          #+#    #+#             */
/*   Updated: 2025/03/26 13:56:40 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_list_tok(t_shell *data, char **str)
{
	int	i;

	if (!str)
		return ;
	data->token = ft_new_token(str[0]);
	i = 1;
	while (str[i])
	{
		ft_add_token(&data->token, ft_new_token(str[i]));
		i++;
	}
}

static int	meta_char(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (strcmp(str, "<") != 0 && strcmp(str, ">") != 0
		&& ft_strncmp(str, ">>", len) != 0 && strcmp(str, "<<") != 0
		&& strcmp(str, "|") != 0)
		return (1);
	return (0);
}

static void	set_token_type(t_shell *data, int type)
{
	t_token	*t;

	t = data->token;
	while (t->type != -1)
		t = t->next;
	if (type == 2)
	{
		if (meta_char(t->str[0]) == 1)
			t->type = 0;
		if (ft_strncmp(t->str[0], "-", 1) == 0)
			t->type = 4;
		else
			t->type = 2;
	}
	else
		t->type = 1;
	if (strncmp(t->str[0], "$", 1) == 0)
		t->type = 3;
}

static void	full_cmd(t_shell *data, char **str)
{
	int		i;
	t_token	*t;

	t = data->token;
	i = 0;
	while (str[i])
	{
		if (t->type == 1)
			add_param(data, i, str);
		i++;
		t = t->next;
	}
}

int	init_tokens(t_shell *data, char *line)
{
	int		i;
	char	**str;
	char	*path;

	i = 0;
	str = ft_split(line, ' ');
	if (!str)
		return (1);
	init_list_tok(data, str);
	while (str[i])
	{
		path = find_path(str[i], data->env);
		if (is_builtin(str[i]) == true)
			set_token_type(data, 1);
		else if (!path)
			set_token_type(data, 2);
		else
			set_token_type(data, 1);
		i++;
	}
	full_cmd(data, str);
	free_str(str);
	return (0);
}
