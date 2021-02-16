; prototype : ssize_t ft_write(int fd, void *buff, size_t nbyte);

section .text
	global _ft_write
	extern ___error

_ft_write:
	mov rax, 0x2000004; write에 해당하는 시스템콜 넘버를 설정
	syscall ; 설정된 시스템콜 넘버에 해당하는 함수를 불러온다.
	jc set_err ; 만약 syscall 오류가 발생하면, rax = 에러 번호, carry flag = 1
	ret

set_err:
	push rax; 스택에 rax 값 (에러 번호) 저장
	call ___error; ___error 함수 호출, rax에 errno(외부 변수)의 주소를 리턴해준다.
	pop rdx; 스택에 저장해놓은 에러 번호를 rdx에 담는다.
	mov [rax], rdx; errno(외부 변수)의 주소에 에러 번호(rdx)를 넣어주어 errno를 세팅해준다.
	mov rax, -1; write 함수 오류 시에 리턴해야할 값 -1을 담아준다.
	ret