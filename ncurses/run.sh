#!/bin/sh

gcc $1.c -lncurses -o $1 && ./$1

