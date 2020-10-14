

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
> - ##### CGI(공통 게이트웨이 인터페이스) 란?
>
>   nginx는 웹서버이기 때문에 정적 콘텐츠밖에 다루지 못한다. 동적 페이지를 구현하기 위해서는 웹 서버 대신 동적 콘텐츠를 읽은 뒤 html로 변환시켜 웹 서버에게 다시 전달해주는 **외부 프로그램(php 모듈)**이 필요하다. 이런 **연결 과정의 방법 혹은 규약을 정의한 것이 CGI**이다.
>
>   예를 들어 설명하면, 로그인과 게시글 등록을 하기 위해서는 동적인 페이지 구현이 필요하다. 또 동적인 페이지를 구현하기 위해서는 웹서버 이외의 외부 프로그램에서 처리하는 방법을 사용한다. 웹서버에서 요청을 받아 그 요청을 외부 프로그램에 넘겨주면, 외부 프로그램은 프로그램 파일을 읽어 html로 반환하는 단계를 거치게 된다. 이것을 **CGI** 라고 한다.
>
>  > 여기서 동적인 페이지라 함은 접속할때마다 변하는 페이지를 의미합니다.
>
>  
>
> - ##### php-fpm (PHP FastCGI Process Manager) 란?
>
>  일반 CGI 보다 빠른 처리가 가능한 FastCGI. 정리하자면,
>
>  `php-fpm` 을 통해 **nginx와 php를 연동시켜 우리의 웹 서버가 정적 콘텐츠 뿐만 아니라 동적 콘텐츠를 다룰 수 있도록** 만드는 것이다.
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
> - 웹 서버의 문서 루트 디렉토리를 설정하면 index.html index.htm 등과 같이 메인 페이지가 설정이 됩니다.
>
>   해당 디렉토리에 index.html, index.htm 파일이 있으면 해당파일을 자동으로 열어주게되죠.
>
>   요새 HTML5 + CSS3에 관련한 기술을 조사하다보면서 간단한 테스트를 하고있는데, 매번 주소표시줄에 http://www.xxxx.co.kr/rootdir/testfile.html 과 같이 일일이 입력하는게 귀찮아서 자동으로 루트 디렉토리의 파일들을 자동으로 리스팅해주는 기능이 필요해졌습니다.

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

- `etc/nginx/sites-available/default` 파일을 수정해줄건데, 좀 더 편한 접근을 위해 vim을 설치해준다.
  `apt-get -y install vim`
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

  > 이 작업이 왜 nginx에서 가능한지는 다음과 같은 이유가 있다.
  >
  > nginx는 사용자로부터 요청을 분배해주는 프록시 서버 역할을 한다.
  >
  > * 프록시 서버(proxy server)란, 클라이언트가 자신을 통해서 다른 네트워크 서비스에 간접적으로 접속할 수 있게 해 주는 컴퓨터 시스템이나 응용 프로그램을 가리킨다.

  

- 우리는 http로 들어왔을 때 ssl을 적용한 https로 redirection을 하길 원한다.

- 따라서 server 기본 포트인 80을 받으면 ssl을 적용한 https로 return 해주는 작업이 필요하다.

- Nginx 설정파일(`./etc/nginx/sites-available/default`)의 server 블록 안에 다음과 같은 구문을 추가하면, 해당 가상 서버로 접속한 사용자를 지정한 주소로 자동 Redirection 시킬 수 있다.

  > ##### 작업할 내용
  >
  > : `./etc/nginx/sites-available/default` 파일에 `return 301 {Redirection 주소};` 추가하기.
  >
  > ```
  > server {
  > 	listen 80 default_server; // IPv4
  > 	listen [::]:80 default_server; // IPv6
  > 
  > 	return 301 https://$host$request_uri;
  > }
  > ```
  >
  > - [HTTP](https://ko.wikipedia.org/wiki/HTTP) 응답 [상태 코드](https://ko.wikipedia.org/wiki/HTTP_상태_코드) **301 Moved Permanently**는 영구적인 [URL 리다이렉션](https://ko.wikipedia.org/wiki/URL_리다이렉션)을 위해 사용된다.
  > - 301 리다이렉트는 사용자가 HTTP를 HTTPS로 업그레이드하게 만드는 최상의 방법으로 간주된다.
  >
  >
  > ##### 작업 내용 관련 간단한 설명
  >
  > > **Nginx Configuration**
  > >
  > > > - nginx에서 Configuration 옵션은 `디렉티브(directives)`라고 불린다. 디렉티브는 `블록(blocks)` 또는 `컨텍스트(contexts)`라고 알려진 그룹으로 구성된다. 이 `블록`과 `컨텍스트`는 nginx에서 동일한 의미로 사용된다.
  > > > - `#` 문자로 시작하는 줄은 주석으로서 nginx에 의해 해석되지 않는다.
  > > > - 디렉티브를 나타낼 때는 반드시 `세미콜론(;)`으로 끝나거나, 또는 `중괄호 블록({})`로 끝나야 한다.
  > >
  > > - **http 블록**
  > >   `http` 블록은 웹 트래픽을 처리하는 디렉티브들을 담고있다. 이 디렉티브들은 종종 *Universal*으로 불리는데, 왜냐하면 그것들은 nginx가 서브하는 모든 웹사이트 컨피겨레이션에 전달되기 때문이다. `http` 블록에서 사용되는 모든 디렉티브들의 목록은 [Nginx 문서](https://nginx.org/en/docs/http/ngx_http_core_module.html)에서 찾아볼 수 있다.
  > >
  > > - **server 블록**
  > >
  > >    만약 nginx를 Debian 또는 Ubuntu 리포지토리에서 설치했다면, `http` 블록 안에는 `include /etc/nginx/sites-enabled/*;` 디렉티브가 포함되어 있을 것이다. 그 `.../sites-enabled/` 디렉토리는 `/etc/nginx/sites-available/` 디렉토리 안의 컨피겨레이션 파일들을 가리키는 `심링크들(symlinks)`을 담고 있다.
  > >
  > >    당신의 nginx 설치 소스에 따라 샘플 컨피겨레이션 파일은 `/etc/nginx/conf.d/default.conf` 또는 `etc/nginx/sites-enabled/default`에 위치할 것이다.
  > >
  > > - **리스닝 포트 (Listening Ports)**
  > >
  > >   - `listen` 디렉티브는 nginx에게 HTTP 연결을 위해 필요한 `hostname/IP`와 `TCP 포트(port)`를 알려준다.
  > >   - `default_server` 인자가 의미하는 것은 이 가상의 호스트가 다른 가상의 호스트들의 `listen statement`와 매치되지 않는 모든 요청에 응답한다는 것이다.
  > >
  > > - **이름 기반의 가상 호스팅(Name-Based Virtual Hosting)**
  > >
  > >   `server_name` 디렉티브는 하나의 IP 주소에 대해 여러개의 도메인(domains)을 사용할 수 있게 한다. 서버는 전달받은 요청 헤더(request header)에 기반하여 어떤 도메인을 서브할지 결정한다.
  > >
  > > - **location 블록**
  > >
  > >   - `location` 디렉티브는 서버 안의 리소스에 대한 요청을 어떻게 응답해야 할지를 설정한다.
  > >   - `server_name` 디렉티브가 nginx에게 해당 도메인에 대한 요청을 어떻게 처리해야 하는지 설정하는 것처럼, `location` 디렉티브는 특정 파일과 특정 디렉토리에 대한 요청을 처리한다.
  > >
  > > - **Index 디렉티브**
  > >
  > >   - `index` 디렉티브는 NGINX에 지정된 파일이없는 경우 어떤 파일을 제공할지 알려줍니다. 
  > >   - `index` 디렉티브에 여러 파일이 지정된 경우 NGINX는 목록을 순서대로 처리하고 존재하는 첫 번째 파일로 요청을 수행합니다. `index.html`해당 디렉토리에없는 경우 `index.htm`사용됩니다. 둘 다 존재하지 않으면 404 메시지가 전송됩니다.
  >
  > **출처**
  >
  > - https://architectophile.tistory.com/12
  > - https://www.linode.com/docs/web-servers/nginx/how-to-configure-nginx/


#### 7-2. https로 들어왔을 때, SSL이 적용되도록 하기

> 위의 과정을 통해, http로 들어오면 https로 Redirection을 해주는 작업을 완료하였다.
> 그러나 https로 들어왔을 때, SSL이 작동하지 않으면 소용이 없는 작업이므로
> https로 접속 시, SSL이 적용되도록 하는 작업을 추가해준다.

- 본 작업 역시 `./etc/nginx/sites-available/default` 파일에 아래 내용을 추가함으로 가능하다.

- 또한 이후에 사용할 php를 위해 index.php도 추가한다.

- 새롭게 추가하는 부분

  ```
  server {
  	listen 443 ssl;
  	listen [::]:443 ssl;
  
  	# ssl 설정
  	ssl on;
  	ssl_certificate /etc/ssl/certs/localhost.dev.crt;
  	ssl_certificate_key /etc/ssl/private/localhost.dev.key;
  
  	# 서버의 root디렉토리 설정
  	root /var/www/html;
  
  	# 읽을 파일 목록
  	index index.html index.htm index.nginx-debian.html index.php;
  
  	server_name _;
  	location / {
  		try_files $uri $uri/ =404;
  	}
  }
  ```

- 443 포트를 위한 서버 블록에는 ssl on 과 인증서의 경로를 작성해준다. 나머지는 기존에 있던 설정 그대로.

- 변경 후, **`service nginx reload`** 를 해줌으로 변경된 설정을 적용한다.

![image-20201009154742862](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201009154742862.png)

- http로 접속했으나 https로 redirection 되었음.
- 경고 이유: 개발이나 사적인 목적을 위해서 SSL의 암호화 기능을 이용하려한다면 자신이 직접 CA의 역할을 할 수도 있다. 물론 이것은 공인된 인증서가 아니기 때문에 이러한 사설 CA의 인증서를 이용하는 경우 브라우저는 경고를 출력한다.

## 8. php-fpm 설치 및 Nginx 설정

> #### 간단한 설명
>
> - **php란?**
>   : 대표적인 **서버 사이드 스크립트 언어**.
>
> - **CGI(공통 게이트웨이 인터페이스) 란?**
>   : nginx는 웹서버이기 때문에 정적 콘텐츠밖에 다루지 못한다. 동적 페이지를 구현하기 위해서는 웹 서버 대신 동적 콘텐츠를 읽은 뒤 html로 변환시켜 웹 서버에게 다시 전달해주는 **외부 프로그램(php 모듈)**이 필요하다. 이런 **연결 과정의 방법 혹은 규약을 정의한 것이 CGI**이다.
>   
>   - 이 표준에 맞추어 만들어진 것이 CGI 스크립트 또는 CGI 프로그램으로, CGI 프로그램은 어떤 프로그래밍 언어로도 만들 수 있다.
>   - 두 개 이상의 컴퓨터간의 자료들을 주고받는 프로그램 또는 주고받는 것 자체를 의미한다고 할 수 있다.
>   - 웹페이지는 HTML언어에 의해서 기본적으로 만들어진다. 하지만 HTML만으로 모든 정보를 다 처리할 수는 없다.
>   - 왜냐하면 HTML언어는 서버로부터 HTML문서를 보여주는 역할만 할 뿐, 사용자의 동작을 바로 반영하여 업로드할 수는 없기 때문이다. 
>   - 따라서 홈페이지를 서버-클라이언트 모두 양방향으로 구성할 필요성이 있는 것이다. 
>   - 이를 해결한 여러 방법 중 하나가 외부 프로그램을 수행하여 그 결과를 HTML형태로 보여주는 방식인 CGI다.
>   - 넓은 의미로는 CGI를 수행하는 프로그램을 CGI라고 하기도 한다.
> - 그 대표적인 예가 방명록, 게시판, 메모장 등이다
>   
> - **php-fpm (PHP FastCGI Process Manager) 란?**
>   : 일반 GCI 보다 빠른 처리가 가능한 FastGCI. 정리하자면,
>
>   `php-fpm` 을 통해 **nginx와 php를 연동시켜 우리의 웹 서버가 정적 콘텐츠 뿐만 아니라 동적 콘텐츠를 다룰 수 있도록** 만드는 것이다.
>
>   - php-fpm은 FastCGI다.
>   - 요청할 때마다 새로운 프로세스 생성하는 CGI는 상대적으로 느리다.
>   - 그래서 요청할 때마다 새로운 프로세스를 생성하는 것이 아니라 이미 생성한 프로세스를 재활용하는 방법을 사용하는 것이 고안되었다.
>   - 즉, CGI보다 좀 더 빠른 버전이라고 할 수 있다.

### 8-1. php-fpm 설치하기

- 입력할 명령어 :  `apt-get install -y php-fpm`

### 8-2. nginx default 파일에 php 처리를 위한 설정을 추가

- 다음의 내용을 `server 블록` 에 추가한다. 

  ```
  	# PHP 추가
  	location ~ \.php$ {
  		include snippets/fastcgi-php.conf;
  		fastcgi_pass unix:/var/run/php/php7.3-fpm.sock;
  	}
  ```

  > **주의 사항**
  >
  > - fastcgi_pass 편집 시, 설치된 php-fpm의 버전과 맞게 기재해주어야 한다. 이번 케이스에선 설치된 php-fpm의 버전은 7.3이므로, `php7.3-fpm.sock`으로 설정하였다.
  > - 또한 현재 상황은 redirection된 경우이기 때문에 https 설정인 `listen 443`이 있는 블록에 설정해주어야 한다.
  > - 

- 위 내용을 추가한 default 파일 
  ![image-20201009163539197](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201009163539197.png)

  > 기존 default 파일에 주석처리가 되어있으므로 주석만 풀어주면된다.

### 8-3. 잘 적용이 되었는지 Check

- 입력할 명령어

  ```
  service php7.3-fpm start
  service php7.3-fpm status
  ```



## 9. MariaDB(MySQL) 설치

### 9-1. 사전 지식

- **MySQL** : 세계에서 가장 많이 쓰이는 오픈 소스의 관계형 데이터베이스 관리 시스템이다.

  > - 데이터베이스란 정보를 저장하는 애플리케이션이다.
  > - 정보를 파일에 저장하는 것도 좋은 방법이나, 데이터베이스는 파일에 저장하는 것 보다 훨씬 많은 기능을 제공한다. 
  > - 말하자면 정보를 저장하는데 특화된 시스템이라고 할 수 있다. 오늘날 거의 대부분의 데이터들이 데이터베이스에 저장되고 있다.

### 9-2. 설치

- **MariaDB(MySQL) 설치**
   MySQL을 설치한다. 단, 현재 우리가 사용하는 OS인 Debian에선 MySQL과 거의 동일한 프로그램인 mariaDB를 default로 사용하고 있다. 이에 두 프로그램 모두를 설치하였다.
  - 입력할 명령어 : `apt-get install -y mariadb-server php-mysql php-mbstring`
  - `php-mysql`은 php에서 mysql에 접근할 수 있게 해주는 모듈이다.
  - `php-mbstring`은 2바이트 확장 문자를 읽을 수 있도록 해주는 모듈이다.

## 10. Wordpress 설치

### 10-1. 설치 및 압축해제

```
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
```

### 10-2. 유저 그룹 권한설정

```
chown -R www-data:www-data /var/www/html/wordpress
```

- `chown`: chown은 파일을 소유하는 유저와 그룹을 변경하기 위해서 사용한다. 
- 브라우저에서 `wordpress` 를 사용하기 위해 폴더에 접근권한을 바꾸어준다.

### 10-3. wp-config.php 파일 수정

- 10-4. wordpress를 위한 DB 테이블 생성


- db 설정을 위해 mysql을 실행시킨다.

  ```
   service mysql start
  ```

- mysql 접속 및 DB 생성

  ```
  mysql # 실행시키면 mysql로 들어가짐
  
  # `;` 꼭 입력하기;
  CREATE DATABASE IF NOT EXISTS wordpress;
  Grant all privileges on *.* to ‘user’@‘%’ identified by ‘설정한비밀번호’ with grant option;
  flush privileges;
  show databases; // 변경되었는지 조회
  exit
  
  ```

- - - 

### 10-5. wordpress 로컬로 접속해보기

이제 wordpress DB 설정이 모두 끝났다.

- https://127.0.0.1/wordpress/ 로 접속했을때 아래와 같은 페이지가 나오면 성공이다.



# --- 여기서 오류 발생 --- 



## 9. MySQL과 phpmyadmin

> **Subject 요구사항 중..**
>
> The services will be a WordPress website, phpmyadmin and MySQL. You will need to make sure your SQL database works with the WordPress and phpmyadmin. (subject)

- subject 요구에 따라 wordpress 웹사이트를 만들 것이다.
- 이에 앞서 SQL database가 wordpress와 phpmyadmin과 잘 연동되도록 MySQL과 phpmyadmin을 설치, 설정할 것이다.

### 9-1. 사전 지식

- **phpmyadmin**

  > - phpmyadmin은 MySQL을 월드 와이드 웹 상에서 관리할 목적으로 PHP로 작성한 오픈 소스 도구이다
  >
  >   (즉, phpmyadmin은 웹페이지로 접속 가능한 DB관리 툴이다)
  >
  > - 보통은 CLI에서 SQL문으로 DB를 다루나 phpmyadmin은 웹으로 가능케 한다.

### 9-2. 설치하기

- **MariaDB(MySQL) 설치**
   MySQL을 설치한다. 단, 현재 우리가 사용하는 OS인 Debian에선 MySQL과 거의 동일한 프로그램인 mariaDB를 default로 사용하고 있다. 이에 두 프로그램 모두를 설치하였다.

  - 입력할 명령어 : `apt-get -y install mariadb-server php-mysql php-mbstring`
  - `php-mysql`은 php에서 mysql에 접근할 수 있게 해주는 모듈이다.
  - `php-mbstring`은 2바이트 확장 문자를 읽을 수 있도록 해주는 모듈이다.

- **phpmyadmin 설치**
   phpmyadmin은 debian 내에서 `apt-get` 등으로 설치할 수 없다. 이에 URL로부터 파일을 다운로드 받을 수 있는 `wget`이라는 프로그램을 이용하여 phpmyadmin을 설치한다.

  - **입력할 명령어**

    ```
    apt-get install -y wget
    wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
    ```

  - 다운 받은 파일 묶음 풀기

    - 다운 받은 파일은 일종의 압축 파일과 비슷한 `.tar` 파일로, 다음 명령어를 통해 파일을 추출한다.
    - 입력할 명령어
      - `tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz`

    > **tar 명령어**
    >
    > ```
    > - 기본 형식: tar [OPTION...] [FILE]...
    >       - 옵션
    >           -f     : 대상 tar 아카이브 지정. (기본 옵션)
    >           -c     : tar 아카이브 생성. 기존 아카이브 덮어 쓰기. (파일 묶을 때 사용)
    >           -x     : tar 아카이브에서 파일 추출. (파일 풀 때 사용)
    >           -v     : 처리되는 과정(파일 정보)을 자세하게 나열.
    >           -z     : gzip 압축 적용 옵션.
    >           -j     : bzip2 압축 적용 옵션.
    >           -t     : tar 아카이브에 포함된 내용 확인.
    >           -C     : 대상 디렉토리 경로 지정.
    >           -A     : 지정된 파일을 tar 아카이브에 추가.
    >           -d     : tar 아카이브와 파일 시스템 간 차이점 검색.
    >           -r     : tar 아카이브의 마지막에 파일들 추가.
    >           -u     : tar 아카이브의 마지막에 파일들 추가.
    >           -k     : tar 아카이브 추출 시, 기존 파일 유지.
    >           -U     : tar 아카이브 추출 전, 기존 파일 삭제.
    >           -w     : 모든 진행 과정에 대해 확인 요청. (interactive)
    >           -e     : 첫 번째 에러 발생 시 중지.
    > ```

  - **파일명 변경 및 이동**

    ```
    mv phpMyAdmin-5.0.2-all-languages phpmyadmin
    mv phpmyadmin /var/www/html/
    ```

    - phpmyadmin을 웹 페이지에 설정하기 위해 `/var/www/html/` 으로 이동시킨다.

  - **쿠키 권한을 위한 blowfish 암호 설정**

    - phpmyadmin 내엔 설정하는 파일 용도로 `config.sample.inc.php`가 있다.   
      config.sample.inc.php을 복사해 `config.inc.php` 파일을 만든다.

    - 해당 파일은 sample로 두고, 복사 후 `config.inc.php` 로 만들어 내게 맞는 내용으로 변경하는 것이 보통이다.

    - 복사를 위한 명령어
      `cp -rp /var/www/html/phpmyadmin/config.sample.inc.php /var/www/html/phpmyadmin/config.inc.php`

    - 암호 설정을 위한 편집

      - `vim /var/www/html/phpmyadmin/config.inc.php`
      - 파일 내부의 내용 중, blowfish_secret(암호화 문자열) 부분에 대한 설정이 필요하다.
      - [blowfish 암호 생성 사이트](https://phpsolved.com/phpmyadmin-blowfish-secret-generator/?g=[insert_php]echo $code;[/insert_php]) 에서 키를 생성/복사한 뒤 `config.inc.php`에 추가한다.
      - config.inc.php 파일 내 `$cfg['blowfish_secret'] = ''; /* YOU MUST FILL IN THIS FOR COOKIE AUTH! */` 부분을 편집할 것이며, `''`에 비밀번호를 넣으면 된다.

    - 편집 후, 지금까지의 설정을 적용시키기 위해 필요한 서비스를 reload, restart 해준다.

      ```
      service nginx reload
      service php7.3-fpm restart 
      ```

  - **phpmyadmin을 위한 DB 테이블 생성**

    - DB 설정을 위해 MySQL을 실행시켜준다.

      ```
      service mysql start
      ```

    - phpmyadmin/sql 폴더의 `create_table.sql` 파일을 mysql로 리디렉션 시켜준다. (MySQL로 데이터를 관리)

      ```
      mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
      ```

      > **명령어 설명**
      >
      > - `<` 로 외부 `.sql` 파일에서 데이터를 불러올 수가 있다.
      >   - table을 새로 만들어주는 sql문이 이미 들어있기에 이를 사용한다.
      > - `-u` 옵션으로 user는 root로 설정한다.
      > - --skip-password

    - MySQL 서버 관리하기

      - 입력할 명령어

        ```
        mysqladmin -u root -p password
        ```

        - `mysqladmin` - MySQL 서버를 관리하기 위한 클라이언트이다.
        - 주로 관리 연산을 수행하는 클라이언트로, 서버의 구성 및 현재의 상태를 체크하거나 데이터 베이스를 생성 및 제거하기 위해 사용한다.
        - `-u` 옵션: 서버 접속 시 사용하는 mysql 사용자 이름
        - `-p` 옵션: 서버 접속 시 사용하는 패스워드   
          (설치 직후엔 root 사용자에 password가 없어 위처럼 사용 가능하다.)

      - 기존 비밀번호는 없으니 enter로 넘어가고, new password와 confirm new password 창엔 원하는 비밀번호를 입력한다.

    - MySQL  접속하기

      - 입력할 명령어

        ```
        mysql // sql 접속, 만약 비밀번호를 먼저 설정한 경우라면 아래의 경우처럼 사용한다.
        #  mysql -pPASSWORD -p 플래그에 붙여서 설정한 비밀번호를 기입한다.
        
        show databases; // database 조회
        CREATE DATABASE IF NOT EXISTS wordpress; // 워드프레스를 위한 DB 만들기
        Grant all privileges on *.* to ‘user’@‘%’ identified by ‘설정한비밀번호’ with grant option;
        flush privileges;
show databases; // 변경되었는지 조회
        exit
        ```
        
        > `SHOW DATABASES;` 명령어를 통해 DB목록을 확인할 수 있다.
        >
        > 그 외 mysql 문법이 궁금하다면 [예제로 익히는 SQL 문법](https://yeosong1.github.io/sql문법) 확인!
        
        > `@'localhost'` 는 로컬 접속만 허용하겠다는 뜻이고 `@'%'`로 작성하면 외부 접속을 허용하겠다는 뜻이다.
        >
        > **GRANT**: 사용자를 생성, 권한 부여하는 명령어. (권한: 사용자에 따라 접근할 수 있는 db데이터가 다름)
        
        > `flush privileges;`
        >
        > - 보통은 INSERT, DELETE, UPDATE를 통해 사용자를 추가, 삭제, 권한 변경 등을 수행하였을 때 이 변경 사항을 반영하기 위하여 사용한다.
        > - 이 때 `FLUSH PRIVILEGES`는 grant 테이블을 reload함으로서 변경 사항을 즉시 반영하도록 한다.
      
    - phpmyadmin 작동확인 
    
      - 변경된 사항을 다시 적용한다.
    
      - **입력할 명령어**
    
        ```
              - service mysql start;
              - service nginx reload;
        ```
    
      - 브라우저로 확인한다.
    
        - `localhost/phpmyadmin` 접속
        - 아이디는 root, 비밀번호는 mysql에서 설정한 비밀번호

## 10. Wordpress 설치하기

- wordpress 역시 설정을 위해 sample 파일이 주어진다. 용도에 맞게 쓰기 위해 복사 후 편집한다.

- `wp-config-sample.php` 을 복사해 `wp-config.php` 를 만든다.

  ```
  cp -rp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php 
  ```

- `wp-config.php` 파일의 DB_NAME, DB_USER, DB_PASSWORD 3가지 항목을 수정해준다.

  ```
  vim var/www/html/wordpress/wp-config.php 
  ```

  ![image-20201009174816315](/Users/hyeokim/Library/Application Support/typora-user-images/image-20201009174816315.png)

- ####  **wordpress 작동 확인**

  - 이상의 변화를 서버에 적용시키고, 브라우저로 접속하여 제대로 잘 설정되었는지 확인한다.
  - 입력할 명령어
    - `service nginx reload`
  - localhost/wordpress 접속

## 11. Autoindex 적용하기

> You will also need to make sure your server is running with an autoindex that must be able to be disabled. (subject)

- autoindex란, 인덱스 페이지를 디렉토리 목록으로 나타내는 방법을 말한다.

- 이를 활성화시키는 것 역시, 앞서 여러 설정을 반영하기 위해 사용했던 `etc/nginx/sites-available/default` 를 편집함으로 가능하다.

- Location block 에 `autoindex on` 을 추가한다.

  ```
  server {
  	listen 443 ssl;
  	listen [::]:443 ssl;
  
  	# ssl setting
  	ssl on;
  	ssl_certificate /etc/ssl/certs/localhost.dev.crt;
  	ssl_certificate_key /etc/ssl/private/localhost.dev.key;
  
  	# Set root dir of server
  	root /var/www/html;
  
  	index index.html index.nginx-debian.html index.php;
  
  	location / {
  		autoindex on;
  		try_files $uri $uri/ =404;
  	}
  
  	# PHP
  	location ~ \.php$ {
  		include snippets/fastcgi-php.conf;
  		fastcgi_pass unix:/var/run/php/php7.3-fpm.sock;
  	}
  }
  ```

- autoindex가 적용되었음에도 브라우저로 보면 변화가 없을 경우

  - 위 이미지처럼 index에 `index.nginx-debian.html`이 있는지 확인한다.
    (index.nginx-debian.html 파일을 index 디렉티브 라인에서 제거하면 된다)  
    (index index.html index.php;)
  - 이 html 문서는 welcome 페이지로, 이를 삭제하면 autoindex 화면을 만날 수 있다.

- `service nginx reload`로 변경사항을 적용한다.

---

### 의문점 정리

> **Q.** URL Redirection 작업 시에, **왜 nginx.conf 파일에 server 블록을 직접 추가하지 않고**
> etc/nginx/sites-available/default 파일에 server 블록을 추가하여 sites-enabled 에 심볼릭 링크를 걸어주는 방식으로 작업을 진행하는가?
>
> **A.** Configuration 파일들의 그룹핑, 재활용성을 높이기 위해서이다.  
> 별도의 폴더(sites-available, sites-enabled)에 가상 호스트에 따라서 Configuration 파일들을 기록해두고  
> nginx.conf의 http 블록, Include 디렉티브를 이용하여 끌어오는 방식으로 작업을 진행한다. 
>
> [출처](https://opentutorials.org/module/384/4529)

> **Q.** 
>
> **A.** **chown**은 파일을 소유하는 유저와 그룹을 변경하기 위해서 사용한다.  
> 폴더 권한 때문에 웹페이지를 제대로 띄우지 못하는 경우가 있다. 권한을 제대로 설정해야한다.  
> 웹서비스의 홈디렉토리의 소유자를 **www-data:www-data** 로 변경하는 방법이 있다.  
> 위와 같은 방식은 www-data의 권한을 탈취당해도 www-data가 가진 권한이 매우 적기에 보안상 추천되고 있다. 하지만 이는 FTP 접속에 제한이 될 수 밖에 없는데 계정사용자가 홈디렉토리에 접속해도 소유권이 모두 www-data 이기에 업로드/수정이 불가능하게 된다.  

---

##### 출처

- [hidaehyunlee의 velog : [ft_server] 선행지식 : Docker? Debian Buster? Nginx?](https://velog.io/@hidaehyunlee/ftserver-%EC%84%A0%ED%96%89%EC%A7%80%EC%8B%9D-Docker-Debian-Buster-Nginx-)
- https://conory.com/blog/42956