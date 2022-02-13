/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2022, Kalapan Kannathasan - 100759041, Zirak Mughal - 100749132, Yash Patel - 100746810, Sujeev Uthayakumar - 100744194
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_

//Placeholder length used for functions
#define BUFFER_LEN 1024

//Functions that will be used by the shell application
//function that will tokenize the input
extern int strTokenizer(char* str, char tokens[][BUFFER_LEN]);

//function to get directory of current position user is in
extern void getCurrentDirectory(char* pwd);

//function to change directories
extern void changeDirectory(char* pwd, char* path);

//function to clear the text on the screen
extern void clearScreen(void);

//function to display the current directory
extern void displayDirectory(char* path);

//function to diplay all environment strings
extern void displayEnviron(char env[][BUFFER_LEN]);

//function to repeat the entered line
extern void echoShell(char* pwd, int token_count, char tokens[][BUFFER_LEN]);

//function to show what can be done within the shell
extern void helpShell(void);

//function to pause the shell
extern void pauseShell(void);

//function to quit out of shell
extern void quitShell(void);

#endif /* UTILITY_H_ */