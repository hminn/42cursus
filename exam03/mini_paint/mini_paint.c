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

	// 배경을 위한 변수
	int		b_width;
	int		b_height;
	char	b_char;
	int		x;
	int		y;

	// 도형을 위한 변수
	char	type;
	float	center_x;
	float	center_y;
	float	r;
	char	c_char;
	float	distance;

	// 실행명령파일경로 매개변수 체크
	if (argc != 2)
		return (ft_putstr("Error: argument\n"));
	// 실행명령파일 열기
	if (!(file = fopen(argv[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	// 배경 관련 변수들 파싱
	if (fscanf(file, "%d %d %c\n", &b_width, &b_height, &b_char) != 3)
	{
		fclose(file);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	// 배경 변수들 에러 처리
	if (!(b_width > 0 && b_width <= 300 && b_height > 0 && b_height <= 300))
	{
		fclose(file);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	// 배경의 가로 x 세로의 크기만큼 할당 하기
	image = (char *)malloc(sizeof(char) * (b_width * b_height));
	// 배경색 칠하기 (배경 문자로 초기화)
	memset(image, b_char, b_width * b_height);
	// 한 줄씩 읽어가며 데이터 파싱하기 [정상적인 형식만 Looping]
	while ((read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c_char)) == 5)
	{
		// 도형 타입과 반지름 에러 처리
		if (!(r > 0) || !(type == 'c' || type == 'C'))
		{
			free(image);
			fclose(file);
			return (ft_putstr("Error: Operation file corrupted\n"));
		}
		// 도형, 원 그리기
		y = 0;
		while (y < b_height)
		{
			x = 0;
			while (x < b_width)
			{
				distance = sqrtf(powf(x - center_x, 2.) + powf(y - center_y, 2.));
				if (distance <= r)
				{
					if (type == 'c')
					{
						// 해당 픽셀이 테두리인지 확인
						if (r - distance < 1.0000000)
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
	// EOF가 아닐 때
	if (read != -1)
	{
		free(image);
		fclose(file);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	// 표준출력으로 터미널에 그리기
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