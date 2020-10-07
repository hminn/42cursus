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



