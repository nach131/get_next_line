/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:20:03 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/12 12:21:05 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

void	ft_tp_line(t_print *tp, char **line)
{
	char	*str;
	int		len_tp;

	str = ft_strchr(tp->content, '\n');
	if (str && !*line)
	{
		len_tp = str - tp->content + 1;
		*line = ft_put_line(tp->content, len_tp);
		ft_cut_tp(tp, len_tp);
	}
	else if (str && *line)
		ft_tp_str_line(tp, &(*line));
	else if (*tp->content && *line != NULL)
	{
		len_tp = ft_strlen(tp->content);
		str = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(str, tp->content);
		ft_cut_tp(tp, len_tp);
		free(str);	
	}
	else
	{
		len_tp = ft_strlen(tp->content);
		*line = ft_put_line(tp->content, len_tp);
		ft_cut_tp(tp, len_tp);
	}
}
