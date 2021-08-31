# Makefile for the CarMap-Chikito project

# Tell make phony targets
.PHONY: all install clean dirclean

all: mapeador.exe

mapeador.exe: $(wildcard *.o)

%.o: %.c
	