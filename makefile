CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LFLAGS = 
LIBS = -lm
SOURCES = myshell.c utility.c
OBJECTS = $(subst .c,.o,$(SOURCES))
EXE = myshell.exe
.PHONY: clean help
 

%.o : %.c
	$(CC) $(CFLAGS) -c $< 

all : $(EXE)

myshell.exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	rm -f $(OBJECTS) $(EXE) *~

help:
	@echo "Valid targets:"
	@echo "  clean:  removes .o and binary files"