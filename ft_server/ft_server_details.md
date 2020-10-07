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

