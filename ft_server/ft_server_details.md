# ft_server

> #### ft_server?
>
> - Docker, Nginx, Debian Buster
>
> - **ft_server** 는 시스템 관리 개념을 소개하기 위한 과제이다. **스크립트를 이용해 업무를 자동화**하는 것의 중요성을 깨닫게 될 것이다. 이를 위해 `Docker` 기술을 학습하고 완전한 웹 서버를 설치해본다.

> #### 일반 지시사항
>
> - **srcs** 라는 폴더 안에 서버 환경설정을 위한 모든 파일을 위치시켜라.
> - **Dockerfile** 은 깃 저장소의 루트에 있어야 한다. 이건 당신의 container를 build할 것이다.
>   docer-compose는 사용할 수 없다. (docker-compose : container실행을 간편히 해주는 것 )
> - WordPress 웹 사이트에 필요한 모든 파일은 srcs안에 있어야 한다.

> #### 필수 사항
>
> - 오직 하나의 Docker container 안에 `Ngnix` 웹 서버를 설치해야 한다.
>   이 container의 OS는 `Debian Buster`여야 한다.
> - 당신의 웹 서버는 여러 서비스가 연동되어야한다. 여기서 말하는 서비스는 다음을 의미한다 .
>   - `Wordpress` 웹사이트
>   - `phpMyAdmin`
>   - `MySQL` : SQL 데이터베이스는 phpMyAdmin과 워드프레스에서 연동하여 사용이 가능해야 한다.
> - 당신의 서버는 `SSL 프로토콜`을 사용해야 한다.
> - `URL redirection`을 처리해야 한다.
> - 언제든 해제할 수 있는 `autoindex`가 적용되어야 한다.

![img](https://blog.kakaocdn.net/dn/cjYbCv/btqC4t6LHE2/Wqu39thIjmjhnvnqzh6Ck0/img.jpg)

> ### 과제에 필요한 배경 지식
>
> ##### 1. Devian
>
> `데비안`은 우분투 같은 리눅스 OS 종류 중에 하나다. 우분투처럼 APT를 패키지 및 소프트웨어 관리자로 사용하고 있다. 사실 우분투는 데비안에서 나온 운영체제이며, 우분투에서 볼 수 있는 대부분의 핵심 유틸리티는 데비안에서 나왔다.
>
> 데비안은 **안정성을 매우 중시하는 리눅스 배포판**이다. 때문에 안정성을 가장 큰 가치로 두어야 할 서버 쪽에서 상당한 인기를 끌고 있다.
>
> 2019년 7월 6일 배포된 최신 안정 버전은 **10.0(Buster)** 이다.
>
> ---
>
> ##### 2. nginx
>
> `엔진엑스`는 무료로 제공되는 오픈소스 웹 서버 프로그램이다. 간단하게 **웹 서버는 클라이언트로 부터 요청이 발생했을 때 요청에 맞는 정적콘텐츠을 보내주는 역할**을 한다. `Nginx`는 규모가 작은 서비스이면서 정적 데이터 처리가 많은 서비스에 적합하다고 한다.
>
> ---
>
> ##### 3. phpMyAdmin 및 php-fpm
>
> - **phpMyAdmin?**
>
>   : phpMyAdmin은 MySQL을 월드 와이드 웹 상에서 관리할 목적으로 php로 작성한 오픈 소스 도구이다.
>   : php를 기반으로 생성된 **mySQL의 GUI**로서 웹에서 실행할 수 있는 프로그램이다.
>
> - ##### php란?
>
>   대표적인 **서버 사이드 스크립트 언어**.
>   
>
> - ##### CGI(공통 게이트웨이 인터페이스) 란?
>
>    nginx는 웹서버이기 때문에 정적 콘텐츠밖에 다루지 못한다. 동적 페이지를 구현하기 위해서는 웹 서버 대신 동적 콘텐츠를 읽은 뒤 html로 변환시켜 웹 서버에게 다시 전달해주는 **외부 프로그램(php 모듈)**이 필요하다. 이런 **연결 과정의 방법 혹은 규약을 정의한 것이 CGI**이다.
>
>    예를 들어 설명하면, 로그인과 게시글 등록을 하기 위해서는 동적인 페이지 구현이 필요하다. 또 동적인 페이지를 구현하기 위해서는 웹서버 이외의 외부 프로그램에서 처리하는 방법을 사용한다. 웹서버에서 요청을 받아 그 요청을 외부 프로그램에 넘겨주면, 외부 프로그램은 프로그램 파일을 읽어 html로 반환하는 단계를 거치게 된다. 이것을 **CGI** 라고 한다.
>
>   > 여기서 동적인 페이지라 함은 접속할때마다 변하는 페이지를 의미합니다.
>
>   
>
> - ##### php-fpm (PHP FastCGI Process Manager) 란?
>
>   일반 CGI 보다 빠른 처리가 가능한 FastCGI. 정리하자면,
>
>   `php-fpm` 을 통해 **nginx와 php를 연동시켜 우리의 웹 서버가 정적 콘텐츠 뿐만 아니라 동적 콘텐츠를 다룰 수 있도록** 만드는 것이다.
>   
>   > CGI는 요청할때마다 새로운 프로세스 생성하여 구동하게 되는 데, 이렇게 되면 부하가 심할뿐만 느려지게 되어있습니다. 하지만 FastCGI은 요청할때마다 새로운 프로세스 생성하는 것이 아니라 이미 생성한 프로세스를 재활용하는 방법을 사용합니다. 때문에 처리가 빠르다는 장점이 있습니다.
>
> ---
>
> ##### 4. HTTPS 및 SSL
>
> - HTTPS(Hypertext Transfer Protocol over Secure Socket Layer)는 `SSL`위에서 돌아가는 HTTP의 평문 전송 대신에 **암호화된 통신을 하는 프로토콜**이다.
> - 이런 HTTPS를 통신을 서버에서 구현하기 위해서는 *신뢰할 수 있는 상위 기업*이 발급한 인증서가 필요로 한데 이런 발급 기관을 **CA(Certificate authority)**라고 한다. CA의 인증서를 발급받는것은 당연 무료가 아니다.
> - self-signed SSL 인증서는 **자체적으로 발급받은 인증서이며, 로그인 및 기타 개인 계정 인증 정보를 암호화**한다. 당연히 브라우저는 신뢰할 수 없다고 판단해 접속시 보안 경고가 발생한다.
> - self-signed SSL 인증서를 만드는 방법은 몇 가지가 있는데, 무료 오픈소스인 `openssl` 을 이용해 쉽게 만들수 있다.
>   - HTTPS를 위해 필요한 `개인키(.key)`, `서면요청파일(.csr)`, `인증서파일(.crt)`을 openssl이 발급해준다.
>
> ---
>
> ##### 5. Autoindx
>
> 

---



## 1. 도커 설치 및 주요 명령어 확인

- [Docker Desktop for Mac](https://hub.docker.com/editions/community/docker-ce-desktop-mac/)에서 `Stable` 버전 설치

- 설치가 완료되면 상단바에 고래 아이콘 등장한다. 도커가 실행중이라는 의미, 즉 터미널에서 도커 접근 가능.

- [도커 명령어 모음](https://yeosong1.github.io/도커-명령어-모음)

  - 컨테이너 조회 (실행 중, 중지된 것까지 포함)

    ```bash
    docker ps -a
    ```

  - 컨테이너 중지

    ```bash
    docker stop <컨테이너 이름 혹은 아이디>
    ```

  - 컨테이너 시작 (중지 된 컨테이너 시작) 및 재시작 (실행 중인 컨테이너 재부팅)

    ```bash
    docker start <컨테이너 이름 혹은 아이디>
    docker restart <컨테이너 이름 혹은 아이디>
    ```

  - 컨테이너 접속 (실행중인 컨테이너에 접속)

    ```bash
    docker attach <컨테이너 이름 혹은 아이디>
    ```



## 2. 도커로 데비안 버스터 이미지 생성

```sh
docker pull debian:buster 
```

확인하려면 `docker images`

![image-20201007145225726](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201007145225726.png)



## 3. 도커로 데비안 버스터 환경 실행 및 접속

```bash
docker run -it --name con_debian -p 80:80 -p 443:443 debian:buster
```

- ```
  -i : i 옵션은 interactive(입출력),
  ```

  ```
  -t : t 옵션은 tty(터미널) 활성화
  ```

  : 일반적으로 터미널 사용하는 것처럼 컨테이너 환경을 만들어주는 옵션

- `--name [컨테이너 이름]` 옵션을 통해 컨테이너 이름을 지정할 수 있다. 안하면 랜덤으로 생성?

- ```
  -p 호스트포트번호:컨테이너포트번호
  ```

  : p 옵션은 컨테이너의 포트를 개방한 뒤 호스트 포트와 연결한다.

  > 컨테이너 포트와 호스트 포트에 대한 개념이 궁금하다면 [여기](https://blog.naver.com/alice_k106/220278762795) 참고.

- `buster`를 명시하지 않아도 자동으로 최신 버전을 불러온다.

![image-20201007145613724](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201007145613724.png)

터미널 창이 위처럼 바뀌면 데비안 bash에 **접속**한 것이다.

종료하고 싶다면 `exit`. 종료한다고 컨테이너가 중지되는 것은 아니다. 컨테이너는 실행 중인 상태에서 접속만 끊은 것이라고 생각하면 된다. 다시 접속하고 싶다면 attach 명령어 사용.



## 4. 데비안 버스터에 Nginx, cURL 설치

```bash
apt-get -y install nginx curl
```

- 데비안에서는 패키지 매니저로 `apt-get `을 사용한다.

  - 뭔가 설치가 잘 안되면 `apt-get update`, `apt-get upgrade` 순서대로 진행하고 다시 설치.

- `cURL`은 서버와 통신할 수 있는 커맨드 명령어 툴이다. **url을 가지고 할 수 있는 것들은 다할 수 있다.**

  예를 들면, http 프로토콜을 이용해 웹 페이지의 소스를 가져온다거나 파일을 다운받을 수 있다. ftp 프로토콜을 이용해서는 파일을 받을 수 있을 뿐 아니라 올릴 수도 있다.

  > 자세한 curl 사용법과 옵션은 [여기](https://shutcoding.tistory.com/23) 참고.



## 5. Nginx 서버 구동 및 확인

- nginx 서버 실행

  ```bash
  service nginx start
  ```

- nginx 상태 확인

  ```bash
  service nginx status
  ```

  `[ ok ] nginx is running.` 가 뜨면 서버가 잘 돌아가고 있다는 뜻이다.

  localhost:80 에 접속해보면 서버와의 성공적인 첫 소통을 확인할 수 있다.

  ![image-20201007161759249](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201007161759249.png)



## 6. self-signed SSL 인증서 생성

- HTTPS(Hypertext Transfer Protocol over Secure Socket Layer)는 `SSL`위에서 돌아가는 HTTP의 평문 전송 대신에 **암호화된 통신을 하는 프로토콜**이다.
- 이런 HTTPS를 통신을 서버에서 구현하기 위해서는 *신뢰할 수 있는 상위 기업*이 발급한 인증서가 필요로 한데 이런 발급 기관을 **CA(Certificate authority)**라고 한다. CA의 인증서를 발급받는것은 당연 무료가 아니다.
- self-signed SSL 인증서는 **자체적으로 발급받은 인증서이며, 로그인 및 기타 개인 계정 인증 정보를 암호화**한다. 당연히 브라우저는 신뢰할 수 없다고 판단해 접속시 보안 경고가 발생한다.
- self-signed SSL 인증서를 만드는 방법은 몇 가지가 있는데, 무료 오픈소스인 `openssl` 을 이용해 쉽게 만들수 있다.
  - HTTPS를 위해 필요한 `개인키(.key)`, `서면요청파일(.csr)`, `인증서파일(.crt)`을 openssl이 발급해준다.

### 6.1. openssl 설치

```bash
apt-get -y install openssl
```

### 6.2. 개인키 및 인증서 생성

```bash
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Hyeokim/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
```

![image-20201008162026230](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201008162026230.png)

localhost.dev.key 와 localhost.dev.crt가 생성된다. 옵션들을 하나하나 확인해보면,

- req : 인증서 요청 및 인증서 생성 유틸.

- -newkey : 개인키를 생성하기 위한 옵션.

- rsa : 원하는 비트수 (보통 암호화 2048, 4096)

- nodes: no DES(대칭키 암호 알고리즘 Data Encryption Standard), 암호 사용하여 개인키를 보호하지 않음.

- x509: 공개키 인증서와 인증 알고리즘을 사용하기 위한 PKI 표준

- subj: 암호 입력시 들어갈 정보

  (subj를 옵션으로 기재하지 않으면, 커맨드 실행 시 위 정보를 입력하는 창이 나타난다)

- -keyout <키 파일 이름> : 키 파일 이름을 지정해 키 파일 생성.

- -out <인증서 이름> : 인증서 이름을 지정해 인증서 생성.

- -days 365 : 인증서의 유효기간을 작성하는 옵션.

### 6.3. 권한제한

- 먼저 컨벤션에 맞게 만든 키를 옮겨준다. (.key, .crt 파일 위치 관련 링크)

- 또한 위 두 파일의 권한은 777로 모든 사용자에게 열려 있으나, 보안을 위해 권한 설정을 해준다.

  > **리눅스 Permission 복습**
  > 보통 파일의 퍼미션은 9개의 문자로 구성된다.
  > 예를 들어, rwxr-xr-- 이라는 퍼미션이 있다면 이를 해석하는 방법은 다음과 같다.
  >
  > - r :  읽기 권한, w : 쓰기 권한, x : 실행 권한
  > - 앞에서부터 3개씩, 소유자 권한 / 소유그룹 권한 / 일반 사용자 권한이다.
  > - 위 예시에 따르면 rwx / r-x/ r-- 가 각각의 권한이 된다.
  > - chmod 를 통해 퍼미션을 변경할 때에는, 8진법의 숫자로 파일모드를 표기한다.
  > - 8진법 퍼미션 값 600 은 rw-/---/--- 가 된다.

```bash
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
```

## 7. Nginx에 SSL 설정 / URL Redirection 추가

- SSL protocol을 적용시키기 위해 nginx 설정에 반영해주어야 한다.
- 현재 `http://localhost` , `http://localhost:80`엔 정상적으로 접속 가능하나, `https://localhost:80`, `https://localhost`엔 접속할 수 없다.
- 따라서 nginx의 설정을 변경해주어야 한다. nginx는 크게 용도를 두 가지로 나누어 각 폴더 별로 설정을 저장한다.

> #### Nginx의 설정 관련 폴더
>
> - sites-available
>   - 설정을 저장하는 곳이다. 이곳에 저장한 설정은 실제로 nginx에 반영되지는 않는다.
>   - 따라서 여기에 만든 설정을 sites-enabled에 복사 또는 심볼릭링크를 걸어서 반영한다.
> - sites-enabled
>   - sites-available에 저장한 설정을 적용하기 위한 폴더.

#### 7-1. URL Redirection 작업 추가

> Your server should be able to use the SSL protocol. You will have to make sure that, depending on the url, your server redirects to the correct website. (subject)
>
> : subject에서 요구하듯, SSL protocol이 적용되어 URL에 따라 올바른 웹사이트로 들어가도록 해야 한다.

- 작업 요약 : **http로 들어왔을 때 redirection을 https 해준다.**

- 이와 관련된 작업은 `sites-enabled` 파일에서 location 명령으로 받은 요청을 분배해줌으로 가능하다.

  - 이 작업이 왜 nginx에서 가능한지는 다음과 같은 이유가 있다.

  - nginx는 사용자로부터 요청을 분배해주는 프록시 서버 역할을 한다.

    > 프록시 서버(proxy server)란, 클라이언트가 자신을 통해서 다른 네트워크 서비스에 간접적으로 접속할 수 있게 해 주는 컴퓨터 시스템이나 응용 프로그램을 가리킨다.

    

- 우리는 http로 들어왔을 때 ssl을 적용한 https로 redirection을 하길 원한다.

- 따라서 server기본 포트인 80을 받으면 ssl을 적용한 https로 return 해주는 작업이 필요하다.

- Nginx 설정파일(`./etc/nginx/sites-available/default`)의 server블록 안에 다음과 같은 구문을 추가하면, 해당 가상 서버로 접속한 사용자를 지정한 주소로 자동 Redirection 시킬 수 있다.

  > ##### 작업할 내용
  >
  > : `./etc/nginx/sites-available/default` 파일에 `return 301 {Redirection 주소};` 추가하기.
  >
  > ```
  > server {
  > 	listen 80; // IPv4
  > 	listen [::]:80; // IPv6
  > 
  > 	return 301 https://$host$request_uri;
  > }
  > ```
  >
  > 

  



---

##### 출처

- [hidaehyunlee의 velog : [ft_server] 선행지식 : Docker? Debian Buster? Nginx?](https://velog.io/@hidaehyunlee/ftserver-%EC%84%A0%ED%96%89%EC%A7%80%EC%8B%9D-Docker-Debian-Buster-Nginx-)
- https://conory.com/blog/42956