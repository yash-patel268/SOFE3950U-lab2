/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2022, Kalapan Kannathasan - 100759041, Zirak Mughal - 100749132, Yash Patel - 100746810, Sujeev Uthayakumar - 100744194
 * All rights reserved.
 * 
 */
//import the required libraries 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h" 

//defining the strTokenizer function
int strTokenizer(char* str, char tokens[][BUFFER_LEN]){
	//variables that will be used
	char delimiter[2] = " ";
	int tokens_count = 0;

	//chop the string
	char* token = strtok(str, delimiter);

	//while the string isnt done cycle through
	while (token != NULL){
		strcpy(tokens[tokens_count], token);
		tokens_count++;
		token = strtok(NULL, delimiter);
	}
	//return the final counted amount
	return tokens_count;
}

//defining the getCurrentDirectory function
void getCurrentDirectory(char* pwd){
	//return the directory
    getcwd(pwd, BUFFER_LEN);
}

//defining the changeDirectory function
void changeDirectory(char* pwd, char* path){
	//assign the new directory to var
    int change = chdir(path);

	//if path was entered
	if (strcmp(path,"") != 0){
		//if path exists
		if (change == 0){
			getCurrentDirectory(pwd);
		//if path doesnt exist
		} else{
			printf("%s> No such path exists!\n", pwd);
		}
	}
}

//defining the clearScreen function
void clearScreen(void){
	//system clears the text
    system("cls||clear");
}

//defining the displayDirectory function
void displayDirectory(char* path){
	//struct initialized
	struct dirent *de; 
	DIR *dr = NULL;

	//if argument entered is blank return current directory
    if (strcmp(path, "") == 0){
        dr = opendir(".");
	//if argument entered isnt blank return the path
	} else{	
		dr = opendir(path); 
	}

	//if the path doesnt exist
	if (dr == NULL) { 
		printf("Could not find the directory specified!\n" );  
	} 

	//if directory doesnt equal Null print directory
	while ((de = readdir(dr)) != NULL){ 
		printf("%s\n", de->d_name); 
	}
    closedir(dr);
}

//defining displayEnviron function
void displayEnviron(char env[][BUFFER_LEN]){
	//print all environment variables
    printf("%s\n%s\n", env[0], env[1]);
}

//defining echoShell function
void echoShell(char* pwd, int token_count, char tokens[][BUFFER_LEN]){
	//find all entered arguments and print them
    printf("%s> ", pwd);
	for(int i = 1; i < token_count; i++){
		printf("%s ", tokens[i]);
	}
	printf("\n");
}

//defining helpShell function
void helpShell(void){
	//print formatted list with all commands
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

//defining pauseShell function
void pauseShell(void){
	//pause shell by requesting input and only when input is enter will the shell continue
	printf("\n\nShell is now paused. Please press ENTER key to continue....\n\n");
	char code = (char)getchar();
	while (code != '\n'){
		code = (char)getchar();
	}
}

//defining quitShell function
void quitShell(void){
	printf("Closing....\n");
}