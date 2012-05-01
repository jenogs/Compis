#!/bin/bash
flex SimpleFlow.l
bison -d SimpleFlow.y
g++ -g SimpleFlow.tab.c lex.yy.c -lfl -o SimpleFlow
