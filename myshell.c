#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

#define BUFFER_LEN 1024
#define MAX_TOKENS 10

int main(int argc, char *argv[]){
    char environ[2][BUFFER_LEN] = {0};
    char pwd[BUFFER_LEN] = {0};
    char myshell[BUFFER_LEN] = {0};
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};
    char tokens[MAX_TOKENS][BUFFER_LEN] = {0};
    int tokenCount = 0;

    FILE* fp = NULL;

    if(argc > 1){
        fp = fopen(argv[1],"r");
		if (fp == NULL){
			printf("Error opening batch file...\n");
			return EXIT_FAILURE;
		}
	} else{
		fp = stdin;
	}

    printf("\n-------------------------------------------------------\n");
	printf("\nWelcome to the shell!, type help to discover more commands\n\n");
	getCurrentDirectory(pwd);
	getCurrentDirectory(myshell);
	strcpy(environ[0], "PWD: ");
	strcpy(environ[1], "MYSHELL: ");
	strcat(environ[0], pwd);
	strcat(environ[1], myshell);

    printf("%s> ", pwd);
    while (fgets(buffer, BUFFER_LEN, fp) != NULL){
	    int index = 0;
		while (buffer[index] != '\n'){
			index++;
		}
		buffer[index] = '\0';
		
		tokenCount = strTokenizer(buffer, tokens);
		strcpy(command, tokens[0]);

        if (strcmp(command, "cd") == 0){
            changeDirectory(pwd, tokens[1]);
            strcpy(environ[0], "PWD: ");
            strcat(environ[0], pwd);
        } else if (strcmp(command, "clear") == 0){
            clearScreen();
        } else if (strcmp(command, "help") == 0){
            helpShell();
        } else if (strcmp(command, "pause") == 0){
            pauseShell ();
        } else if (strcmp(command, "dir") == 0){
            displayDirectory(tokens[1]);
            printf("\n");
        } else if (strcmp(command, "echo") == 0){
            echoShell(pwd, tokenCount, tokens);
        } else if (strcmp(command, "environ") == 0){
            displayEnviron(environ);
        } else if (strcmp(tokens[0], "quit") == 0 || strcmp(tokens[0], "exit") == 0){
            quitShell();
            return EXIT_SUCCESS;
        } else{
            printf("%s> ", pwd);
            printf("Unsupported command, use help to display the manual\n");
        }
        memset(buffer, 0, sizeof buffer);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAX_TOKENS; i++){
			memset(tokens[i], 0, sizeof tokens[i]);
		}
		printf("%s> ", pwd);
    }
    return EXIT_SUCCESS;
}
