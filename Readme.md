**Clang command to build, cs50 library included.**

`clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow "fileNameToBuild" -lcrypt -lcs50 -lm -o "nameOfOutputFile"`
