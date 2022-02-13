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
	get_currentDir(pwd);
	get_currentDir(myshell);
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
		
		tokenCount = string_tokenizer(buffer, tokens);
		strcpy(command, tokens[0]);

        if (strcmp(command, "cd") == 0){
            change_dir(pwd, tokens[1]);
            strcpy(environ[0], "PWD: ");
            strcat(environ[0], pwd);
        } else if (strcmp(command, "clear") == 0){
            clear_screen();
        } else if (strcmp(command, "help") == 0){
            display_help();
        } else if (strcmp(command, "pause") == 0){
            pause_shell();
        } else if (strcmp(command, "dir") == 0){
            display_dir(tokens[1]);
            printf("\n");
        } else if (strcmp(command, "echo") == 0){
            echoShell(pwd, tokenCount, tokens);
        } else if (strcmp(command, "environ") == 0){
            display_environs(environ);
        } else if (strcmp(tokens[0], "quit") == 0 || strcmp(tokens[0], "exit") == 0){
            quitShell();
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
