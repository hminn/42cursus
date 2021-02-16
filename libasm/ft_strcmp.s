; prototype : int ft_strcmp(const char *s1, const char *s2);

section .text
	global _ft_strcmp

_ft_strcmp:
	xor rax, rax; rax 값을 0으로 초기화
	xor rbx, rbx; rbx 값을 0으로 초기화
	xor rcx, rcx; rcx 값을 0으로 초기화
	jmp cmp; compare label로 이동

cmp:
	mov al, byte [rdi + rcx]; al을 *s1의 rcx번째 문자로 초기화
	mov bl, byte [rsi + rcx]; bl을 *s2의 rcx번째 문자로 초기화
	cmp al, bl; 두 문자를 비교
	jne diff; 두 문자가 다르면, diff 레이블로 이동
	je equal; 두 문자가 같다면, equal 레이블로 이동

diff:
	sub rax, rbx; rax 값에서 rbx를 뺀다
	ret ; 종료 후 rax 값 반환

equal:
	cmp al, 0; 두 문자가 같은데, 그 문자가 0(NULL) 문자인지 비교
	je return; 0(NULL) 문자가 맞다면 return 레이블로 이동
	inc rcx; 0(NULL) 문자가 아니라면 rcx++;
	jmp cmp; cmp 레이블로 이동 (Looping)

return:
	mov rax, 0; rax 값을 0으로 초기화
	ret ; 종료 후 rax 값 반환
