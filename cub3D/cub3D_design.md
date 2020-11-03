# **Cub3D**

---

### 0. Fuction Description

> **mlx_xpm_file_to_image**
>
> - `void *mlx_xpm_file_to_image(void *xvar,char *file,int *width,int *height)`
> - xpm 파일을 mlx image 객체로 변환해주는 함수
> - 이 함수는 알아서 image의 width와 height을 세팅해주기 때문에, 해당 값을 받을 변수의 주소 값을 넘겨주면 된다.

> **mlx_get_data_addr**
>
> - `char  *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);`
>
> - ![image-20201028155417393](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201028155417393.png)
>
>   : 위와 같은 형태의 (4px X 2px) xpm 파일은 mlx에서 다음과 같이 저장이 된다.
>
>   ![image-20201028155621646](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201028155621646.png)
>
>   : 이러한 변환을 해주는 함수가 바로 mlx_get_data_addr
>
> - 하나의 픽셀의 색상을 표현할 때는 RGB를 16진법으로 변환해서 사용한다.
>
>   > **RGB**
>   >
>   >  
>   >
>   > Red, Green, Blue (빨강, 초록, 파랑) 세 종류의 기본 색을 이용하여 색을 표현한다.
>   >
>   > 각각의 요소는 0 ~ 255 의 값을 가질 수 있다. 이 값은 해당 색이 얼마나 섞였는지를 나타낸다.
>   >
>   >  
>   >
>   > ex) 완전 빨강: R = 255, G = 0, B = 0
>   >
>   >    완전 초록: R = 0, G = 255, B = 0
>   >
>   >    완전 파랑: R = 0, G = 0, B = 255
>   >
>   >    완전 검정: R = 0, G = 0, B = 0
>   >
>   >    완전 하양: R = 255, G = 255, B = 255
>   >
>   >  
>   >
>   > 이런 방식으로 256 * 256 *256, 총 16,777,216 개의 색을 표현할 수 있다.
>
>   > **ARGB**
>   >
>   > RGB에 투명도(Alpha)값을 추가해 ARGB 형식(0xAARRGGBB)으로 나타내기도 한다.
>   >
>   > A 또한 0(완전 불투명) ~ FF(완전 투명)의 값을 갖는다.
>   >
>   >  
>   >
>   > 예를 들어 0xFF0000은 0x**00**FF0000와 동일하기 때문에 완전 불투명한 빨강
>   >
>   > 0x**CC**FF0000: 50% 투명한 빨강
>   >
>   > 0x**FF**FF0000: 완전 투명한 빨강
>   >
>   >  
>   >
>   > ARGB가 가질 수 있는 값은 0x00000000 ~ 0xFFFFFFFF 로 (unsigned int) 범위와 동일하다.
>
>   
>
> - 결론적으로, xpm 파일 이미지를 데이터 형태로 변환해주는 함수이다.

> 

---



### 0. Project Flow

> 0. 맵 파싱 작업
> 1. 레이캐스팅 작업
> 2. Mlx 라이브러리를 이용한 그래픽 렌더링 작업

### 1. Analyze BaseLine Code 

> **s_img**
>
> - 텍스쳐를 올릴 때, 텍스쳐 이미지 정보를 담아주는 구조체
> - *img : xpm 파일의 이미지 주소를 가리키고 있는 포인터
> - *data : 이미지를 데이터 형태로 변환한 값을 가리키고 있는 포인터

> **Sprite**
>
> - 스프라이트의 정보를 담는 구조체
> - x, y 좌표 및 텍스쳐 번호

> **s_info**
>
> - 대부분의 정보를 담고 있는 구조체
> - PosX, PosY : 플레이어의 초기 위치벡터
> - DirX, DirY : 플레이어의 초기 방향벡터
> - PlaneX, PlaneY : 플레이어의 카메라평면벡터
>   (카메라평면의 길이 : 방향벡터의 길이 의 비율로 시야각(FOV)이 결정된다.)
> - *Mlx : 그래픽 작업을 진행할 mlx instance
> - *Win : 그래픽 작업 내용을 렌더링 할 창(window)을 가리키는 포인터
> - Key : key 입력 정보를 저장할 변수들
> - Buf : 

> 

### 10. 추가 사항

> - **Exit_Program** 의 Free 추가 **(refer_cub3D : exit_program 함수 참고)**
>   : 에러 발생 시, 이전에 동적 할당한 모든 값들 Free 해주는 작업

> - 