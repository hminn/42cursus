/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:43:51 by hyeokim           #+#    #+#             */
/*   Updated: 2020/01/29 11:08:12 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_upper(char a)
{
	if (a >= 65 && a <= 90)
		return (1);
	else
		return (0);
}

int		ft_is_lower(char a)
{
	if (a >= 97 && a <= 122)
		return (1);
	else
		return (0);
}

int		ft_is_special(char a)
{
	if (a >= 48 && a <= 57)
		return (0);
	else if (!(ft_is_lower(a) || ft_is_upper(a)))
		return (1);
	else
		return (0);
}

char	*ft_changer(char *str)
{
	int		i;

	i = 0;
	while (!ft_is_special(*str))
	{
		if ((i == 0) && ft_is_lower(*str))
			*str = *str - 32;
		else if (ft_is_upper(*str))
			*str = *str + 32;
		str++;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	char	*chg;

	chg = str;
	while (*chg != 0)
	{
		if ((chg == str) || (ft_is_special(*chg)))
		{
			if (ft_is_lower(*chg))
				chg = ft_changer(chg);
			else
			{
				chg++;
				if (!(ft_is_special(*str)))
					chg = ft_changer(chg);
			}
		}
		else
			chg++;
	}
	return (str);
}
