#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h" 

int strTokenizer(char* str, char tokens[][BUFFER_LEN]){
	char delimiter[2] = " ";
	int tokens_count = 0;
	char* token = strtok(str, delimiter);

	while (token != NULL){
		strcpy(tokens[tokens_count], token);
		tokens_count++;
		token = strtok(NULL, delimiter);
	}

	return tokens_count;
}

void getCurrentDirectory(char* pwd){
    getcwd(pwd, BUFFER_LEN);
}

void changeDirectory(char* pwd, char* path){
    int change = chdir(path);

	if (strcmp(path,"") != 0){
		if (change == 0){
			getCurrentDirectory(pwd);
		} else{
			printf("%s> No such path exists!\n", pwd);
		}
	}
}

void clearScreen(void){
    system("cls||clear");
}

void displayDirectory(char* path){
	DIR *dirptr;
	struct dirent *item;

	dirptr = opendir(".");

	if (dirptr == NULL){
		return 1;
	}

	while(( item = readdir(dirptr) )){
		printf("%s\n", item->d_name);
	}
	printf("\n");
	closedir(dirptr);
}

void displayEnviron(char env[][BUFFER_LEN]){
    printf("%s\n%s\n", env[0], env[1]);
}

void echoShell(char* pwd, int token_count, char tokens[][BUFFER_LEN]){
    printf("%s> ", pwd);
	for(int i = 1; i < token_count; i++){
		printf("%s ", tokens[i]);
	}
}

void helpShell(void){
	printf("\nList of available commands:\n\n");
	printf("help\t\t\t Lists the help menu.\n");
	printf("dir <directory>\t\t Lists the contents of the directory\n");
	printf("environ\t\t\t Lists all the environment strings..\n");
	printf("echo <comment>\t\t Displays comment on the command line followed by a newline.\n");
	printf("cd <path>\t\t Changes the working directory to the specified path.\n");
	printf("clr\t\t\t Clears the screen.\n");
	printf("pause\t\t\t Pauses operation of the shell until the ENTER key is hit.\n");
	printf("quit\t\t\t Quits the shell.\n\n\n");
}

void pauseShell(void){
	printf("\n\nShell is now paused. Please press ENTER key to continue....\n\n");
	char code = (char)getchar();
	while (code != '\n'){
		code = (char)getchar();
	}
}

void quitShell(void){
	printf("Closing....\n");
	return EXIT_SUCCESS;
}