#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	FILE	*file;
	char	*image;
	int		read;

	int		b_width;
	int		b_height;
	char	b_char;
	int		x;
	int		y;

	char	type;
	float	center_x;
	float	center_y;
	float	r;
	char	c_char;

	float	distance;

	if (argc != 2)
		return (ft_putstr("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (ft_putstr("Error: Operation file corrupted"));
	if (fscanf(file, "%d %d %c\n", &b_width, &b_height, &b_char) != 3)
	{
		fclose(file);
		return (ft_putstr("Error: Operation file corrupted"));
	}
	if (!(b_width > 0 && b_width <= 300 && b_height > 0 && b_height <= 300))
	{
		fclose(file);
		return (ft_putstr("Error: Operation file corrupted"));
	}
	image = (char *)malloc(sizeof(char) * (b_width * b_height));
	memset(image, b_char, b_width * b_height);
	while ((read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c_char)) == 5)
	{
		y = 0;
		while (y < b_height)
		{
			x = 0;
			while (x < b_width)
			{
				if (!(r > 0) || !(type == 'c' || type == 'C'))
				{
					free(image);
					fclose(file);
					return (ft_putstr("Error: Operation file corrupted\n"));
				}
				distance = sqrtf(powf(x - center_x, 2) + powf(y - center_y, 2));
				if (distance <= r)
				{
					if (type == 'c')
					{
						if (r - distance <= 1.0000000)
							image[y * b_width + x] = c_char;
					}
					else if (type == 'C')
						image[y * b_width + x] = c_char;
				}
				x++;
			}
			y++;
		}
	}
	if (read != -1)
	{
		free(image);
		fclose(file);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	y = 0;
	while (y < b_height)
	{
		write(1, image + (y * b_width), b_width);
		write(1, "\n", 1);
		y++;
	}
	free(image);
	fclose(file);
	return (0);
}

