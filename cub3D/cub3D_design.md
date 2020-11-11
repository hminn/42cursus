# **Cub3D**



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

---



### 1. Project Flow

> #### 맵 파일(.cub) 파싱 작업
>
> : 프로그램 실행 시, 입력된 인자를 받아 맵의 경로가 유효한지, 맵 정보가 온전히 들어있는지, 맵의 형태가 온전한지 체크하고 입력 받은 플래그 정보를 저장한다.
>
> - 맵 파싱 정보를 담을 config 초기화 작업 진행
>
> - 유효한 형식의 맵 파일 혹은 경로가 잘 들어왔는지 Arguments check 
>
> -  gnl 함수를 이용하여 .cub 파일(맵 파일)을 한 줄 씩 읽어 내려가며 파싱 및 데이터 저장
>
>   > 1. 해상도 파싱 (**parse_resolution.c**)
>   >
>   >    - 해상도 형식이 맞는지 check (**check_resolution_format**)
>   >    - 해상도 정보를 config 구조체의 res 배열에 담아준다.
>   >    - 입력받은 해상도의 크기가 디스플레이의 해상도보다 클 경우에는 현재 디스플레이의 해상도에 맞게 해상도를 설정.
>   >
>   > 2. 벽 4면 &  스프라이트 텍스처 파싱
>   >
>   >    - xpm 확장자를 가진 파일 형식이 맞는지 check (**check_filename_ext**)
>   >    - 텍스처 이미지 파일의 파일명 혹은 경로를 config 구조체의 texture 배열에 담아준다.
>   >
>   > 3. 바닥과 천장의 RGB 값 (색깔) 파싱
>   >
>   >    - 각 요소의 RGB 값이 유효한지, 형식에 맞는지 check (**check_color_format**)
>   >    - 각각의 RGB 값을 10진법으로 변환하여 config 구조체의 color 배열에 담아준다.
>   >
>   > 4. 각각의 옵션이 잘 들어왔는지, 맵이 유효한지 체크
>   >
>   >    - 옵션 정보가 잘 들어왔는지 config 구조체의 id를 통해 체크한다.
>   >
>   >    - 맵을 buf 변수에 계속해서 쌓고, 몇 줄인지 계속 세어나간다.
>   >
>   >    - 맵을 다 읽으면 줄바꿈문자(\n)를 기준으로 split 하여 config 구조체의 2차원배열 map에 담아준다.
>   >
>   >    - 유효한 맵인지 확인하는 작업 진행
>   >
>   >      > 1. 맵의 첫번째 좌표부터 쭉 검사 진행
>   >      > 2. 플레이어의 위치 좌표를 만나면(NSEW), 그 위치 정보를 저장한다.  
>   >      >    : 플레이어의 현재 위치, 시야 방향, 그에 따른 방향벡터와 카메라 평면벡터 등의 정보를 저장
>   >      > 3. 맵 에러 검사
>   >      >    - 지정되지 않은 문자가 들어온 경우
>   >      >    - 맵 유효성을 만족하지 않는 경우
>   >      >      1. 맵의 끝 부분이 벽으로 둘러 싸여있지 않는 경우
>   >      >      2. 끊긴 길이 있는 경우
>   >      >      3. 플레이어의 위치가 지정되지 않은 경우
>   >      > 4. 맵을 사각형의 형태로 변환한다.  
>   >      >    : 각 행을 열의 길이만큼 늘려준다 (' '문자로 채워줌)



> #### 레이캐스팅 작업
>
> - 레이캐스팅에 필요한 구조체 및 변수들을 초기화 하는 작업 진행
>
> - 벽 및 xpm 파일 이미지를 데이터 형태로 변환
>
> - Key Event 관련 hooking과 그로 인해 변경된 데이터에 기반한 레이캐스팅 작업이 포함된 Main loop Hooking을 설정해준다.
>
> - Main Loop 함수
>
>   > 1. 작업에 필요한 정보를 담고있는 ray 구조체를 초기화한다.
>   > 2. DDA 알고리즘 시작 전, 필요한 계산을 진행한다.
>   > 3. DDA 알고리즘을 통해 광선이 부딪힌 면을 체크한다. (ray->side)
>   >    (W, E, S, N  순서로 0, 1, 2, 3)
>   > 4. 벽과 카메라 평면 사이의 수직거리를 구해 화면에 그려야 할 수직선의 높이를 얻어 저장한다. (ray->line_height)
>   > 5. 수직선의 높이를 이용하여 실제로 그릴 지점을 계산한다. (ray->draw_start, ray->draw_end)
>   > 6. 픽셀의 x 좌표를 기준으로 위의 과정을 반복한다.
>   > 7. 해당 좌표와 그 좌표에 해당하는 수직거리(perpWallDist)를 z_buffer 배열에 담아준다.
>   > 8. 각 벽의 텍스쳐를 결정해서 이미지로 그려주는 작업 진행 (Texturization)
>   > 9. 천장, 바닥의 색깔을 이미지로 그려주는 작업 진행 (ver_line_color_image)
>   > 10. 아이템(sprite)을 그려주는 작업을 진행
>   > 11. --save 플래그가 들어왔는지 check, 들어왔다면 스크린샷 작업 진행
>   > 12. 일련의 과정을 통해 그려낸 이미지를 창(window)에 뿌려준다.



> #### 그래픽 렌더링 및 key events 작업 (Using mlx library)





### 2. Variable

> **s_image**
>
> - 텍스쳐를 올릴 때, 텍스쳐 이미지 정보를 담아주는 구조체
>
> - *img : xpm 파일의 이미지 주소를 가리키고 있는 포인터
>
> - *data : 이미지를 데이터 형태로 변환한 값을 가리키고 있는 포인터
>
> - **각 픽셀의 색상이 저장된 주소를 계산하기 위해 필요한 변수들**
>
>   > - size_l : 이미지 한 줄을 저장하는데 쓰이는 바이트 수. 다음 줄로 이동할 때 필요
>   > - bpp : 픽셀 하나를 표현하는데 필요한 비트 수 (RGB : 24 / ARGV : 32)
>   > - endian : 숫자를 1바이트씩 쪼개서 저장할 때의 저장순서를 나타낸다.
>   >   (big endian : 큰 자릿수가 앞에 저장됨 / little endian : 작은 자릿수가 앞에 저장됨)  
>   >   (보통 우리가 사용하는 x86 계열 cpu는 리틀엔디언 방식으로 데이터를 저장한다.)

> **s_line**
>
> - 
>
> - 

> **s_ray**
>
> - 
> - 

> **s_sprite**
>
> - 스프라이트의 정보를 담는 구조체
> - x, y 좌표 및 텍스쳐 번호
>
> **s_sprites**
>
> - 스프라이트 구조체의 연결 리스트
>
> s_draw_sprite
>
> - 
>
> - 



> **s_key**
>
> - 키 이벤트에 대한 정보를 담고 있는 구조체
>
> - 

> **s_player**
>
> - 플레이어의 위치, 방향, 카메라 평면 및 높낮이 등의 정보를 담고 있는 구조체
>
> - id : 
> - count : 
> - cam_height : 
> - pos : 플레이어의 현재 위치 좌표
> - dir : 플레이어의 현재 방향 벡터
> - plane : 플레이어 시점의 카메라 평면 벡터

> **s_config**
>
> - 맵 파일(.cub)의 파싱된 정보들을 저장할 구조체
>
> - id : 맵 파싱의 항목들(해상도, 각각의 텍스처, 바닥과 천장의 색깔, 맵)을 체크하기 위한 변수
> - res : 해상도를 담을 변수
> - color : 천장과 바닥의 색깔을 담을 변수
> - row, col : 맵의 row와 col
> - flag : --save 플래그를 담아줄 변수
> - texture : 텍스쳐 파일 경로를 담을 변수
> - map_name : m
> - map : 파싱된 맵 정보를 저장할 이차원 배열
> - player : 플레이어 정보를 담고있는 구조체

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

### Inf0. 추가 사항

> - **Exit_Program** 의 Free 추가 **(refer_cub3D : exit_program 함수 참고)**
>   : 에러 발생 시, 이전에 동적 할당한 모든 값들 Free 해주는 작업

> - 변수명 & 함수명 & 파일명 
>
>   > - main.c
>   > - s_info
>   >
>   > - raycasting_a.c, raycasting_b.c

> - 수정해야 할 부분들
>
>   > 1. ~~parse_resolution.c 의 63번째줄  
>   >    : 동적할당이 이루어지지 않았는데도 free를 해주고 있음~~
>   >    : ft_strtrim -> ft_substr 에서 동적 할당하는 부분이 있음.



### Inf1. 의문 사항

- 해상도 최대와 최소 설정? 어떤 기준으로?
- static 변수를 사용하는 이유는 무엇인가?
- check_filename_ext의 27-28번째 줄? 필요한 부분인가?
- ray->side 값? 이게 맞는 건지? check 해볼 것!



### Inf1.  진행 결과

- main.c 진행중

- **parse_hub.c**

  > - resolution  완료
  > - texture 완료
  > - map 완료

- **parse_resolution.c** 완료 ✅

- **parse_utils.c** 완료 ✅

- **parse_texture_color** 완료 ✅

- **parse_map.c** 완료 ✅

- parse_map_player.c 완료 ✅

- **init_xpm.c** 완료 ✅

- **raycasting_a.c, raycasting_b.c** 완료 ✅

- **sprite.c** 완료 ✅

- **texture.c **완료 ✅

- **image.c** 완료 ✅

- **draw_sprite.c** 완료 ✅

- **screenshot.c** 완료 ✅

- **config_key.c** 완료 ✅

- **control_camera.c** 완료 ✅

- **control_player.c** 완료 ✅

