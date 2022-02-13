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
#include "myshell.h"

//placeholder varibles for length and amount
#define BUFFER_LEN 1024
#define MAX_TOKENS 10

//defining main function
int main(int argc, char *argv[]){
    //initializing variables to hold information
    char environ[2][BUFFER_LEN] = {0};
    char pwd[BUFFER_LEN] = {0};
    char myshell[BUFFER_LEN] = {0};
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};
    char tokens[MAX_TOKENS][BUFFER_LEN] = {0};
    int tokenCount = 0;

    //initialize pointer to NULL as precaution
    FILE* fp = NULL;

    //if the file is unable to open
    if(argc > 1){
        fp = fopen(argv[1],"r");
		if (fp == NULL){
			printf("Error opening batch file...\n");
			return EXIT_FAILURE;
		}
    //else allow input to be taken
	} else{
		fp = stdin;
	}

    //display messages to inform user the shell is active
    system("clear");
    printf("\n-------------------------------------------------------\n");
	printf("\nWelcome to the shell!, type help to discover more commands\n\n");
	getCurrentDirectory(pwd);
	getCurrentDirectory(myshell);
	strcpy(environ[0], "PWD: ");
	strcpy(environ[1], "MYSHELL: ");
	strcat(environ[0], pwd);
	strcat(environ[1], myshell);

    //print the directory
    printf("%s> ", pwd);

    while (fgets(buffer, BUFFER_LEN, fp) != NULL){
	    int index = 0;
		while (buffer[index] != '\n'){
			index++;
		}
		buffer[index] = '\0';
		
		tokenCount = strTokenizer(buffer, tokens);
		strcpy(command, tokens[0]);

        //if command entered is cd
        if (strcmp(command, "cd") == 0){
            changeDirectory(pwd, tokens[1]);
            strcpy(environ[0], "PWD: ");
            strcat(environ[0], pwd);
        //if command entered is clear
        } else if (strcmp(command, "clr") == 0){
            clearScreen();
        //if command entered is help
        } else if (strcmp(command, "help") == 0){
            helpShell();
        //if command entered is pause
        } else if (strcmp(command, "pause") == 0){
            pauseShell ();
        //if command entered is dir
        } else if (strcmp(command, "dir") == 0){
            displayDirectory(tokens[1]);
            printf("\n");
        //if command entered is echo
        } else if (strcmp(command, "echo") == 0){
            echoShell(pwd, tokenCount, tokens);
        //if command entered is environ
        } else if (strcmp(command, "environ") == 0){
            displayEnviron(environ);
        //if command entered is quit
        } else if (strcmp(tokens[0], "quit") == 0 || strcmp(tokens[0], "exit") == 0){
            quitShell();
            return EXIT_SUCCESS;
        //if command entered is not supported
        } else{
            printf("%s> ", pwd);
            printf("Unsupported command, use help to display the manual\n");
        }

        //reset the varibales
        memset(buffer, 0, sizeof buffer);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAX_TOKENS; i++){
			memset(tokens[i], 0, sizeof tokens[i]);
		}
		printf("%s> ", pwd);
    }
    //exit out of shell
    return EXIT_SUCCESS;
}
