; prototype : char *ft_strdup(const char *s1);

section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup: ; [rdi = s1]
	call _ft_strlen ; [rdi = s1] s1의 길이를 재서 rax에 반환
	inc rax ; rax++ ('\0' 문자를 위해 + 1)
	mov rbx, rdi ; [rbx = rdi = s1]
	mov rdi, rax ; [rdi = rax] 할당할 문자열의 크기를 rdi에 넘겨준다.
	call _malloc ; rax에 동적 할당된 메모리의 주소가 반환된다.
				 ; (할당에 실패하면 0(NULL)을 반환)
	cmp rax, 0 ; 할당 오류 체크
	je return ; 할당에 실패했다면 바로 return (rax : 0)
	mov rdi, rax ; 할당에 성공하면, rdi에는 malloc 반환값을
	mov rsi, rbx ; rsi에는 복사할 문자열을 넘겨준다.
	call _ft_strcpy ; ft_strcpy 호출, rax에 복사가 완료된 문자열 반환
	jmp return ;

return:
	ret ; 종료, rax 값 반환