/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_in_quote_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:55:43 by cfleuret          #+#    #+#             */
/*   Updated: 2025/04/09 17:00:53 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*dollar_utils_2(char *str, t_env *env)
{
	t_env	*t;
	int		len;
	int		i;
	int		j;
	char	*nstr;

	len = 0;
	i = 0;
	j = 0;
	t = env;
	while (t != env->prev)
	{
		if (ft_strncmp(t->str, str, ft_strlen(str)) == 0)
		{
			nstr = malloc(sizeof(char) * ft_strlen(t->str) - ft_strlen(str));
			while (t->str[i] != '=')
				i++;
			i++;
			while (t->str[i])
			{
				nstr[j] = t->str[i];
				j++;
				i++;
			}
			return (nstr);
		}
		t = t->next;
	}
	if (strncmp(t->str, str, ft_strlen(str)) == 0)
	{
		nstr = malloc(sizeof(char) * ft_strlen(t->str) - ft_strlen(str));
		while (t->str[i] != '=')
			i++;
		i++;
		while (t->str[i])
		{
			nstr[j] = t->str[i];
			j++;
			i++;
		}
		return (nstr);
	}
	return (NULL);
}

static int	is_valid_var_char(char c)
{
	return ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9')
		|| (c == '_'));
}

char	*dollar_utils_1(t_shell *data, char *str, int j)
{
	char	*temp;
	int		start;
	int		len;
	char	*value;

	start = j;
	while (str[j] && is_valid_var_char(str[j]))
		j++;

	len = j - start;
	if (len == 0)
		return (NULL);

	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	ft_strncpy(temp, &str[start], len);
	temp[len] = '\0';

	value = dollar_utils_2(temp, data->env);
	free(temp);
	if (!value)
		return (NULL);
	return (value);
}
