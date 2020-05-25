u$h
=============================


### Developers:
[Yuri Burienkov](https://github.com/ronald112)

### Installation:
>1. git clone https://github.com/ronald112/ush.git
>2. make
>3. ./ush
>4. enjoy!

### Description:
This is a simple representation of shell for UNIX system's. It can manage several commands and pipes, just use ';' to seprate commands and '|' to separate command in pipeline.

### Builtins-table:

| Builtin | Flags   |                       Description                      |
|:-------:|:-------:|:------------------------------------------------------:|
| exit    |         | exit from ush                                          |
| cd      | S,P     | change directory                                       |
| env     | i,P,u   | print environ variable                                 |
| pwd     | P,L     | print working directory                                |

-----------
