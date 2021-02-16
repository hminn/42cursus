;prototype : size_t ft_strlen(const char *s);

section .test
	global _ft_strlen

_ft_strlen :
	mov rax, 0; 리턴할 rax 값을 0으로 초기화 시킨다.
	jmp count; count label로 이동

count :
	cmp BYTE [rdi + rax], 0; 1바이트씩 읽고, 0(NULL)과 비교
	je return; [rdi + rax]에 있는 문자가 0이라면 return으로 이동
	inc rax; [rdi + rax]에 있는 문자가 0이 아니라면 rax를 1만큼 증가시킨다.
	jmp count; count label로 이동 (Looping)

return :
	ret ; 함수를 종료하고 rax 레지스터를 반환한다.