# Lab 2: Developing a Shell

## Lab Members:
- Kalapan Kannathasan - 100759041 (Created clearScreen, pauseShell, helpShell, and quitShell functions)
- Zirak Mughal - 100749132 (Documented code, Created ulility.h, makefile)
- Yash Patel - 100746810 (Created strTokenizer, getCurrentDirectory, changeDirectory, and displayDirectory functions)
- Sujeev Uthayakumar - 100744194 (Created myshell.h, myshell.c, and readme.md)

## Description
This application a simple cli that is written in the c language which consists of .c and .h files which is compiled by a makefile. The .h files are to initialize funtions that will be used by .c files, and the .c files will be defining how these functions will act. The makefile compiles the files to object files and then to single executable file.

## Commands
- `cd` - change working directory
- `clr` - clear the text within terminal
- `dir` - list the contents of directory
- `environ` - list all the environment strings
- `echo` - display what user entered
- `help` - list the commands the shell has
- `pause` - pause functionality of shell
- `quit` - exit out of shell

## Make File Commands
- `make` or `make all` - to create all object files, as well as the executable file
- `make clean` - to remove all object files and the executable file
- `make help` -  to see what files can be removed

## Running Powershell Stand Alone
To run the powershell alone and take command line, all that is required is to use the `./myshell`

## Running Powershell with Redirection
For redirection the program must be executed as such: `./myshell inputFile > outputFile`