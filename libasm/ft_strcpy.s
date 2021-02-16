; prototype : char *ft_strcpy(char *dst, const char *src);

section .text
	global _ft_strcpy

_ft_strcpy:
	xor rcx, rcx ; rcx의 값을 0으로 초기화
	xor rbx, rbx ; rbx의 값을 0으로 초기화
	cmp rsi, 0 ; rsi(source)와 0(NULL)을 비교
	je return ; source가 NULL이면 return label로 이동

copy:
	mov bl, byte [rsi + rcx] ; bl을 src 문자열의 rcx번째 문자로 초기화
	mov byte [rdi + rcx], bl; dst 문자열의 rcx번째 문자를 bl로 초기화
	inc rcx ; rcx를 1만큼 증가 (rcx++)
	cmp bl, 0 ; bl과 0(NULL)을 비교 (src 문자열의 끝에 도달했는지 check)
	je return ; 같으면 exit으로 이동
	jmp copy ; 같지 않으면 다시 copy로 (Looping)

return:
	mov rax, rdi; rax에 rdi 값 전달
	ret ; 함수 종료, rax 값을 반환