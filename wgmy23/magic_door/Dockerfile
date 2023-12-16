FROM ubuntu:22.04

ENV user magic_door
ENV chall_port 10001

RUN apt-get update
RUN apt-get -y install socat

RUN adduser $user

WORKDIR /home/$user

ADD $user /home/$user/$user
ADD flag.txt /home/$user/flag.txt

RUN chown -R root:$user /home/$user
RUN chown root:$user /home/$user/flag.txt
RUN chown root:$user /home/$user/$user

RUN chmod 755 /home/$user/$user
RUN chmod 440 /home/$user/flag.txt

USER $user
EXPOSE $chall_port
CMD socat -T 30 TCP-LISTEN:$chall_port,reuseaddr,fork EXEC:/home/$user/$user
