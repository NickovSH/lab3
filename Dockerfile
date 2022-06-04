FROM ubuntu

RUN apt-get update && apt-get install -y g++

COPY ./main_prog.cpp .
COPY ./proc.s .

RUN g++ ./main_prog.cpp -c -o main_prog.o
RUN as proc.s -o proc.o
RUN g++ main_prog.o proc.o

CMD ./a.out
