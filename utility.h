#ifndef UTILITY_H_
#define UTILITY_H_

#define BUFFER_LEN 1024

extern int strTokenizer(char* str, char tokens[][BUFFER_LEN]);

extern void getCurrentDirectory(char* pwd);

extern void changeDirectory(char* pwd, char* path);

extern void clearScreen(void);

extern void pauseShell(void);

extern void displayDirectory(char* path);

extern void displayEnviron(char env[][BUFFER_LEN]);

#endif /* UTILITY_H_ */