## Assembly Language



### 1. 어셈블리 언어란?

- 어셈블리 언어는 기계어와 1:1 대응을 하는 언어이다.
- 어셈블리 언어는 그 코드가 어떤 일을 할지를 직접적으로 보여준다.
- 논리상의 오류나, 수행 속도, 수행 과정에 대해 명확히 해준다는 점에서 매우 직관적인 언어이다.
- 메모리상의 데이터나 I/O 기기를 직접 액세스 하는 등의 고급언어에서는 할 수 없는 조작을 할 수 있다.
- 어셈블리 언어를 배우면 시스템을 이해하는데 도움이 된다.
- 컴퓨터 구조(CPU)마다 기계어가 다르기 때문에 이에 대응하는 어셈블리어도 각각 달라지게 된다.
- 위와 같은 단점을 개선하기 위해 만들어진 것이 C언어와 같은 고급 언어로, CPU에 종속적이지 않으면서도 저급 언어처럼 메모리에 직접 접근할 수 있다는 장점이 있다.

> **고급 언어의 컴파일 과정**
>
> ![image-20210205235748378](C:\Users\143011\AppData\Roaming\Typora\typora-user-images\image-20210205235748378.png)



### 2. 어셈블리를 위한 기본 지식

#### 1) CPU

- 메모리에 있는 내용을 읽고 쓰는 역할을 하며, 데이터를 메모리와 각 레지스터로 보낸다.
- 프로그램의 명령을 해석하고 실행한다.
- 프로세서는 12~14개의 레지스터를 가지고 있으며, CPU의 연산, 논리 장치는 숫자와 기호에 관한 연산자를 인식한다.

#### 2) RAM

- 반도체로 조립된 셀들의 집합.
- 프로세스가 프로그램을 실행시키고 작동하기 위해서 필요한 정보들을 저장하는데 쓰인다.
- 각 셀들은 숫자값을 포함하고 주소가 정해질 수 있는 형식이며 프로그램에서 흔히 메모리라고 하는 것들은 메인메모리 즉, 램이라고 할 수 있다.

#### 3) Register

- 어셈블리 언어에서의 레지스터는 CPU내의 작은 저장 장소를 말한다.
- 레지스터는 CPU가 요청을 처리하는데 필요한 데이터(명령어의 종류, 연산결과, 복귀주소 등)를 일시적으로 저장하는 기억장치이다.
- CPU에서 사용하는 변수라고 생각하면 좀 더 쉽게 이해할 수 있다.



### 3. 어셈블리 프로그래밍

#### 1) Section

> 어셈블리 프로그램은 아래 세 개의 Section으로 구성되어있다.

- **section.data**  
  - 초기값이 있는 전역 변수, 혹은 스태틱 변수를 선언하는 공간
  - 상수, 파일 이름, 버퍼 사이즈 등을 여기에 선언할 수 있다.
- **section.text**
  - 실행할 코드를 작성하는 공간
- **section.bbs**
  - 추가적으로 변수를 선언할 때 사용하는 공간

#### 2) 문법 (x64 Intel 기준)

> 어셈블리 언어는 정해진 표준이 없고, CPU에 따라 여러 종류의 문법이 존재한다.
>
> 다음의 설명은 X64 Intel 문법을 기준으로 한다.

```
# 기본 포맷은 다음과 같다.

opcode operand1(Destination) operand2(source) ; 주석
```

- 위 포맷에서 `opcode`는 명령어, `operand`는 인자값이다.
  - 명시된 바와 같이 `operand1`은 Destination 인자, `operand2`는 Source 인자이다.
  - 어셈블리 프로그램은 opearand로서 레지스터를 다룬다.
- 숫자는 1, 2, 3, ... 과 같이 숫자 그대로 표기한다.
- 특정 레지스터의 메모리 주소를 참조할 때는 대괄호`[]` 를 사용한다.
- **offset** : RAX 레지스터에서 +4 만큼 떨어진 메모리 주소를 표기할 때는 [RAX + 4] 와 같이 표현한다.
- 세미콜론으로 주석을 처리한다.



### 4. 레지스터의 종류 (X64 기준)

#### 1) 범용 레지스터

- **RAX** (Accumulator)
  - 더하기, 빼기 등 산술/논리 연산을 수행하며 함수의 Return 값이 저장된다.
  - 시스템콜 함수를 사용하려면 RAX에 함수의 syscall 번호를 넣어준다.
- **RBX** (Base)
  - 메모리 주소를 저장하기 위한 용도로 사용된다.
- **RCX** (Count)
  - 반복문에서 카운터로 사용되는 레지스터이다.
  - 고급언어 for문의 `i` 와 같은 역할이지만, `RCX`는 미리 반복 값을 정해두고 명령어를 사용할 때마다 값이 하나씩 줄어든다는 점이 다르다.
- **RDX** (Data)
  - 다른 레지스터를 서포트하는 여분의 레지스터이다.
  - 큰 수의 곱셉이나 나눗셈 연산에서 **RAX** 와 함께 사용된다.

#### 2) 인덱스 레지스터

- **RSI** (Source Index)
  - 데이터를 복사할 때 source 데이터, 즉 복사할 데이터의 주소가 저장된다.
- **RDI** (Destination Index)
  - 데이터를 복사할 때 복사된 destination 데이터의 주소가 저장된다.

#### 3) 포인터 레지스터

- **RSP** (Stack Point)
  - 스택프레임에서 스택의 끝 지점 주소(현재 스택 주소)가 저장된다.
  - 즉, 데이터가 계속 쌓일 때 스택의 가장 높은 곳을 가리킨다.
  - Push, Pop 명령을 통해 RSP 값이 위아래로 8바이트씩 이동하면서 스택프레임의 크기를 변경하게 된다.
- **RBP** (Base Point)
  - 함수가 호출되면 스택프레임이 형성 되는데 이 스택프레임의 시작 지점 주소(스택 복귀 주소)가 저장된다.

#### 4) 플래그 레지스터 (RFLAGS register)

> - 시스템 제어 용도 혹은 어셈블리에서는 비교/조건문 처리 용도로 사용되는 상태 레지스터이다.
> - 연산 결과에 따라 64비트 레지스터의 각 비트에 0(clear, reset) 혹은 1(set)로 표시해 처리 결과를 저장한다.

- **CF** (Carry Flag)  
  - 부호 없는 수끼리 연산 결과에서 자리올림/자리내림이 발생할 때 1
  - Unsigned int 값을 벗어날 때 1
- **OF** (Overflow Flag)
  - 부호 있는 수끼리 연산 결과가 용량을 초과하였을 경우 1
- **SF** (Sign Flag)
  - 연산 결과 최상위 비트가 1인 경우 1
- **ZF** (Zero Flag)
  - 연산 결과가 0이면 1
- **AF** (Auximiliary-carry Flag)
  - 16비트 연산시 자리올림/자리내림이 발생할 때 1
- **PF** (Parity Flag)
  - 연산 결과가 짝수면 1, 홀수면 0

- **DF**, **IF**, **TF** 
- 이 외에도, 64비트에서는 **R8 ~ R15**까지 8개의 레지스터가 추가로 사용되며, 하나의 레지스터는 아래 그림처럼 크기에 따라 적절히 쪼개 사용할 수 있다.

![image-20210206012244844](C:\Users\143011\AppData\Roaming\Typora\typora-user-images\image-20210206012244844.png)



### 5. 어셈블리 명령어 

#### 1) 조작 명령어

- `call` : 함수 호출
- `ret` : call로 호출된 함수를 종료하고 그 다음 명령줄로 이동
- `nop` : 아무것도 하지 않음
- `jmp` : 분기(라벨) 실행
- **조건 점프 명령어** : `cmp` 연산 결과에 따라 `jmp`
  - **je** : `cmp A B`에서 `A = B` 일때 특정 라벨로 `jmp`
  - **jne** : `cmp A B`에서 `A != B` 일때 특정 라벨로 `jmp`
  - **ja** : `cmp A B`에서 `A > B` 일때 특정 라벨로 `jmp`
  - **jb** : `cmp A B`에서 `A < B` 일때 특정 라벨로 `jmp`
  - **jae** : `cmp A B`에서 `A >= B` 일때 특정 라벨로 `jmp`
  - **jbe** : `cmp A B`에서 `A <= B` 일때 특정 라벨로 `jmp`

#### 2) 데이터 전송 명령어

- `push` : 스택에 값을 넣음
- `pop` : 스택에서 값을 가져옴
- `mov oper1 oper2 ` : 인자2(oper2)의 값을 인자1(oper1)에 대입 (전달)
- `lea oper1 oper2 ` : 인자2(oper2)의 주소를 인자1(oper1)에 대입 (전달) 

#### 3) 산술 명령어

- `inc` : 인자의 값을 1 증가
- `dec` : 인자의 값을 1 감소
- `add` : 인자2 값을 인자1에 더함
- `sub` : 인자2 값을 인자1에서 뺌
- `cmp` : 인자1과 2의 값을 비교. 주로 위의 조건점프 명령어와 세트로 사용.
- `test`
  - 인자 1과 2를 AND 연산한다. 
  - 이 연산의 결과는 `ZF`(Zero Flag)에만 영향을 미치고 Operand 자체에는 영향을 미치지 않는다.
  - 보통 `rax`의 값이 0인지 확인할 때, `test rax, 0 ` 이런 식으로 사용된다.
  - 만약 TEST의 연산 결과가 0이라면 `ZF`는 1로, 연산결과가 1이라면 `ZF`는 0으로 세트된다.



### 6. 함수 호출 규약 (Calling Convention)

- 함수가 생성되고, 반환하는 과정을 정의해둔 것을 **함수 호출 규약**이라고 한다
  - 함수 호출 규약은 함수의 반환값을 어떤 레지스터에 저장할지,
     함수의 인자는 어떤 레지스터에 저장하여 보낼지, 스택 프레임은 어떤 식으로 사용할 지 등에 대해 정의
  - 함수 호출 규약은 환경에 따라 다양하게 나타난다
  - 여기서는 유닉스 체제에서 사용하는 System V AMD64 ABI 규약을 기반으로 기록
- 리눅스에서 함수 호출 시,
   매개변수는 **rdi, rsi, rdx, rcx, r8, r9** 순으로 레지스터에 넘겨진다
- 6개 이상의 매개 변수를 넘겨주어야 할 때는, 스택 프레임에 Parameter 처럼 저장하도록 약속하고 있다
- rax 는 함수의 반환값을 저장하도록 약속
  - 함수 호출 전에, rax 와 같은 매개변수 레지스터들이 비어있지 않으면 오류가 발생할 수 있다



> #### **스택 프레임** 이란?
>
> - 스택 프레임은 주소가 큰 쪽부터 작은 쪽으로 쌓여가는 형태
>   - 쌓여가는 스택을 함수 단위로 구분할 수 있다
>   - 하나의 스택(함수)은 **인자, 반환 주소, 지역 변수 순으로 데이터**를 가지고 있다
> - 명령 중 PUSH를 사용하면 해당 값을 프레임에 쌓게 되고,
>    POP을 사용하여 프레임의 위에 올려진 값을 가져올 수도 있다
>   - 이를 위해 스택 프레임의 가장 윗 부분을 알아야하고,
>      가장 윗 부분을 가리키는 Stack Pointer 를 항상 레지스터의 RSP에 저장한다
>   - 어떤 경우에도 RSP는 항상 스택 프레임의 가장 윗 부분을 가리키도록 약속
>     - **함수 호출의 약속 (Calling Convention)**
>   - PUSH를 하면 RSP가 PUSH한 데이터의 크기만큼 감소하고 (스택 프레임은 작은 주소로 이동) 반대로 POP을 하면 RSP가 증가한다



> #### 함수의 호출과 반환
>
> - 사용 레지스터
>
>   - RBP : Base Pointer 로, **스택의 시작점** 이다
>   - RSP : Stack Pointer 로, **스택의 꼭대기(Top)** 이다
>   - RIP : 다음 실행할 명령어의 주소를 보관하는 값이다
>
> - 함수를 호출하고 반환 시에, 각 함수의 앞의 줄과 마지막 줄에는 공통으로 작성되는 부분이 존재하며,
>    이러한 공통된 사항들을 묶어 **'프롤로그'** 와 **'에필로그'** 라고 부른다
>
>   - '프롤로그'와 '에필로그' 소스코드
>
>     ```assembly
>     _function:
>       push rbp         ; prologue. 이전 함수의 스택 프레임 상의 위치(RBP)를 스택 프레임에 저장한다.
>       mov  rbp, rsp    ; prologue. 현재 함수의 스택 프레임 상의 위치(RBP)를 스택 프레임의 꼭대기(RSP)로 바꾼다.
>     
>       ... some code ...; 함수가 호출되지 않는 이상 RBP는 고정. 호출되더라도 반환 시에는 동일한 RBP를 가지고 있음.
>     
>       mov  rsp, rbp    ; epilog.   스택 프레임의 꼭대기(RSP)를 현재 함수의 스택 프레임 상의 위치(RBP)로 변경.
>       pop  rbp         ; epilog.   스택 프레임에서 현재 함수를 제거
>       ret              ; epilog.
>     
>     ; ret는 이전 함수로 돌아가는 명령어로 실제 명령어의 구성은 아래와 같다
>     ; pop rip
>     ; jmp rip
>     ; 현재 rsp에 있는 값을 rip에 넣은 뒤 해당 위치로 점프한다는 의미  
>     ; pop rbp를 통해 rsp가 +8이 되면서 rsp는 이전에 저장해둔 '이전 함수의 다음 명령어의 주소'를 갖고 있기에, 
>     ; rsp에 저장되어 있는 위치로 이동(점프)하는 것
>     ```
>
> - 예시 코드를 통한 설명
>
>   ```c
>   int sum(int a, int b)
>   {
>   	return (a + b);
>   }
>   
>   int main(void)
>   {
>   	int c = sum(1, 2);
>   
>   	return c;
>   }
>   ```
>
>   - 위의 예시 코드의 스택프레임의 변환은 다음과 같다
>     - 함수가 호출되면 함수의 스택 프레임(stack frame)이 생성되고,
>        스택 프레임이 스택에 추가 된다 (Push)
>     - 함수의 실행이 끝나 함수가 반환 될 때 스택 프레임이 스택에서 제거된다 (Pop)
>   - 아래 내용은,
>      위 예제 코드가 실행되면서 스택프레임이 어떻게 생성되고 제거되는지에 대한 구체적 설명
>
>   1. **main 함수가 호출되면 아래와 같은 스택프레임이 생성되고 스택에 추가된다**
>
>   ![https://blog.kakaocdn.net/dn/E5UKS/btqPQtdBKjL/Sd8HkH4qmBr1XLsivKHo61/img.png](https://blog.kakaocdn.net/dn/E5UKS/btqPQtdBKjL/Sd8HkH4qmBr1XLsivKHo61/img.png)
>
>   - main() 함수의 스택프레임
>     - RBP : Base Pointer
>       - 스택의 가장 낮은 위치를 가리킨다 (메모리에선 제일 높은 주소)
>       - 여기부터 스택이 쌓이기 시작할거라고 알려준다
>   - RSP : "스택 포인터" 레지스터 는 스택에 새로운 값이 들어올 때마다(push),
>      스택의 top을 추적한다
>
>   1. **sum( ) 함수가 호출되면 sum() 함수의 스택프레임이 스택에 push 된다**
>
>   - 함수가 끝나면 해당 스택프레임은 스택에서 제거되고,
>      RET 정보에 따라 돌아가야할 위치로 돌아간다
>
>   ![https://blog.kakaocdn.net/dn/bs94bf/btqPJMyPES7/yBkyU5x9ycy0W3LLEf8NS1/img.png](https://blog.kakaocdn.net/dn/bs94bf/btqPJMyPES7/yBkyU5x9ycy0W3LLEf8NS1/img.png)
>
>   



### 7. 시스템 콜 (System call)

- syscall 명령어를 통해, 시스템 상에 미리 선언되어 있는 함수를 어셈블리 프로그램에서도 사용할 수 있다

- 시스템 콜 함수는 고유의 번호(0x2000004)를 갖고 있으며, OS마다 조금씩 다르다
   Linux는 [여기](https://filippo.io/linux-syscall-table/) 참고, MacOS는 [여기](https://github.com/opensource-apple/xnu/blob/master/bsd/kern/syscalls.master) 참고

- **`write()`함수를 syscall하는 예제**

- 이 때 syscall 할 함수의 번호를 `rax`에 미리 넣어줘야한다

- syscall 함수의 반환값 또한 `rax`에 저장된다.

  > ##### 자주 사용하는 syscall numbers (mac)
  >
  > - **0x2000001** - exit()
  > - **0x2000002** -
  > - **0x2000003** - read()
  > - **0x2000004** - write()
  > - **0x2000005** - open()
  > - **0x2000006** - close()

- cf) 3이 아닌 0x200003인 이유는 macos에선 syscall에 클래스를 두기 때문이다

- macosx나 bsd는 system call 번호를 여러 ‘class'로 나눠뒀다

- read나 write는 syscall_class_unix에 속하기 때문에 upper bits 를 2로 설정한다

- 즉 **unix system call 의 system call 은 (0x2000000 + unix syscall #)**가 된다



### 8. __error 함수를 이용한 에러 처리

- 만약 syscall 후 에러가 발생했다면 이는 `___error` 함수를 이용해 처리해야한다

- syscall 함수는 **오류가 있을 경우 `rax`에 작은 음수(-1 ~ -4095)를 반환**하며
   unsigned int 값을 벗어나는 연산 결과이므로, 동시에 carry flag가 참이 된다

- 따라서 `jc`(carry flag가 1일 때 점프)를 활용하면 에러 처리 구문(err)으로 넘어갈 수 있다

- rax 에 담긴 음수의 정체를 이해하는 것이 중요하다

- 이 리턴값은,
   C언어에서 에러에 대한 정보를 나타내는 정보인 errno(쉽게 말해 미리 정의된 에러 번호)의 음수 값이다

- 즉, syscall 후 에러 발생 시 `rax`에는 -errno(-4095 ~ -1)가 반환된다

- `man 2 errno` 로 자세한 내용을 확인할 수 있다

- 어셈블리로 작성한 _err 구문이 올바르게 errno를 출력할 수 있도록 하기 위해서는,
   `rax`에 음수 리턴값, `[rax]`에 errno에 해당하는 숫자가 들어갈 수 있도록 작성해야한다

- **소스 코드**

  ```assembly
  extern ___error
      
  	jc _err
  	ret
  	
  _err:
  	push rax ;rax에 담겨있는 error value를 push해 스택에 백업
  	call ___error ;___error 함수를 호출하면 에러 주소값이 rax에 담긴다
  	pop rdx ;rdx에 스택에 저장시켜 놨던 error value를 pop
  	mov [rax], rdx ;rdx에 담긴 error value를 에러 주소를 변경하지 않고 값만 변경
  	mov rax, -1 ;return value는 -1이 되어야 하므로 rax에 -1을 넣고 반환
  	ret
  ```



### Inf. 출처

- [Daelee : 어셈블리 프로그램 구조와 x64 레지스터 이해하기](https://velog.io/@hidaehyunlee/libasm-%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8-%EA%B5%AC%EC%A1%B0%EC%99%80-x64-%EB%A0%88%EC%A7%80%EC%8A%A4%ED%84%B0-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0)
- [Daelee : 어셈블리 명령어(opcode) 정리](https://velog.io/@hidaehyunlee/libasm-%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC-%EB%AA%85%EB%A0%B9%EC%96%B4-opcode-%EC%A0%95%EB%A6%AC)
- [Daelee : strlen 함수를 어셈블리어로 짠다면?](https://velog.io/@hidaehyunlee/libasm-strlen-%ED%95%A8%EC%88%98%EB%A5%BC-%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC%EC%96%B4%EB%A1%9C-%EC%A7%A0%EB%8B%A4%EB%A9%B4)
- [Sjeon : Libasm Notion](https://www.notion.so/Libasm-8a36781c028144a4b23e1751c8d1ac81#f686eed615914f59b125c473952179cc) 



## Libasm



### 1. ft_strlen.s

#### (1) c 코드

```c
// prototype : size_t ft_strlen(const char *s)

size_t ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}
```

#### (2) Check Point (in Assembly)

- **매개변수로 받은 s의 주소는 `rdi` 레지스터에 들어온다.**
- **`rdi` 레지스터의 값은 `BYTE [rdi]`로 참조한다.**
- **`rax`를 통해 리턴 값을 반환한다.**

#### (3) 어셈블리 코드

```assembly
;prototype : size_t ft_strlen(const char *s);

section .text
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
```

- [데이터 타입과 다양한 명령어 예제들](https://blog.hexabrain.net/187)



### 2. ft_strcpy

#### (1) C 코드

```c
// prototype : char *ft_strcpy(char *dst, const char *src)

char *ft_strcpy(char *dst, const char *src)
{
    size_t i;
    
    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return (dst);
}
```

#### (2) Check Point (in Assembly)

- **함수 호출 규약에 따라서 함수의 매개변수 dst와 src는 각각 rdi와 rsi에 저장된다.**
- **범용 레지스터의 구조와 크기 : 필요한 크기에 따라 참조하는 레지스터가 달라진다.** [(참고)](https://karfn84.tistory.com/entry/%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC-%EB%A0%88%EC%A7%80%EC%8A%A4%ED%84%B0%EC%9D%98-%EA%B8%B0%EB%8A%A5)
- **레지스터를 0으로 초기화 할 때, `XOR rax rax ` 의 형태를 많이 사용한다.** [(참고)](http://jackpark88.blogspot.com/2018/04/xor-eax-eax.html)
- **rax를 통해 리턴할 주소값을 반환하면 된다.**

#### (3) 어셈블리 코드

```assembly
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
```



### 3. ft_strcmp

#### (1) C 코드

```c
int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;
    
    i = 0;
    while (*(s1 + i) == *(s2 + i))
    {
        if (*(s1 + i) == 0)
            return (0);
        i++;
    }
    return (*(s1 + i) - *(s2 + i));
}
```

#### (2) Check Point (in Assembly)

- diff 레이블에서 rax, rbx 가 아닌 al, bl을 사용해도 되는가?

#### (3) 어셈블리 코드

```assembly
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
	
```



### 4. ft_write

#### (1) Check Point (in Assembly)

> **시스템 콜(Syscall)**

- Syscall 명령어를 통해, 시스템 상에 미리 선언되어 있는 함수를 어셈블리 프로그램에서도 사용할 수 있다.
- 시스템 콜 함수는 고유의 번호를 갖고 있으며, OS 마다 조금씩 다르다. ([In MacOS](https://github.com/opensource-apple/xnu/blob/master/bsd/kern/syscalls.master))
- macosx나 bsd는 system call 번호를 여러 ‘class'로 나눠뒀다.
- read나 write는 syscall_class_unix에 속하기 때문에 upper bits 를 2로 설정한다.
- 즉, unix system call 의 system call 은 (0x2000000 + unix syscall #)가 된다.

> **___Error 함수를 이용한 에러 처리**

- **만약 syscall 후 에러가 발생했다면 이는 ___error 함수를 이용하여 errno 값을 세팅해줘야한다.**
- `___error` 함수란, errno의 주소를 리턴하는 함수
- errno에 에러번호를 세팅하려면 errno의 주소가 필요하다 (___error의 리턴값)
- Mac OS X 를 사용하는 컴퓨터에서는 시스템 콜 에러시, 직접 시스템 콜의 리턴값을 -1로 세팅하고 변수 errno에 에러넘버를 세팅해주어야한다.

> **에러 처리 Flow**

- write 함수에서 에러가 발생하면 carry flag 가 1로 바뀌고 rax에 에러 넘버가 저장된다.
- carry flag가 1이 되면 set_error 함수로 jump 한다.
- rax는 사용할 것이기때문에 rdx에 에러 넘버를 백업해둔다.
- 외부함수인 **___error를 호출**하면 rax의 에러 넘버를 보고 해당 errno의 주소를 리턴해준다
  - 여기서 errno는 외부변수
- errno의 주소에 에러 넘버(rdx에 담긴넘버)를 넣어주어 **errno를 세팅**해준다.
- 마지막으로 rax에 **-1을 담아 리턴**해준다.

- [참고](https://velog.io/@jehjong/Assembly-Language-%EC%8B%9C%EC%8A%A4%ED%85%9C%EC%BD%9C-%EC%97%90%EB%9F%AC%EC%B2%98%EB%A6%AC)

#### (2) 어셈블리 코드

```assembly
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
```



### 5. ft_read (ft_write와 시스템콜 넘버 차이밖에 없음)

```assembly
; prototype : ssize_t ft_read(int fd, void *buff, size_t nbyte);

section .text
	global _ft_read
	extern ___error

_ft_read:
	mov rax, 0x2000003; read에 해당하는 시스템콜 넘버를 설정
	syscall ; 설정된 시스템콜 넘버에 해당하는 함수를 불러온다.
	jc set_err ; 만약 syscall 오류가 발생하면, rax = 에러 번호, carry flag = 1
	ret

set_err:
	push rax; 스택에 rax 값 (에러 번호) 저장
	call ___error; ___error 함수 호출, rax에 errno(외부 변수)의 주소를 리턴해준다. 
	pop rdx; 스택에 저장해놓은 에러 번호를 rdx에 담는다.
	mov [rax], rdx; errno(외부 변수)의 주소에 에러 번호(rdx)를 넣어주어 errno를 세팅해준다.
	mov rax, -1; read 함수 오류 시에 리턴해야할 값 -1을 담아준다.
	ret
```



### 6. ft_strdup

#### (1) Check Point (in Assembly)

- 매개변수로 받은 문자열을 새로운 메모리에 복제하는 함수
- **Prototype** : `char *strdup(const char *s1);`

- 이 함수를 구현하기 위해선 _malloc이 필요함.

#### (2) 어셈블리 코드

```assembly
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
```



