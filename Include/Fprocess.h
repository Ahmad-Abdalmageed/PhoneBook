//
// Created by ahmad-lap on 4/15/21.
//

#ifndef ASSIGNMENT2_FPROCESS_H
#define ASSIGNMENT2_FPROCESS_H

// Includes
#include <stdio.h>
#include <string.h>

// Macros
#define BUFFER_SIZE 1024

int FCountL(char FileName[]);
void FAddL(char FileName[], char Line[]);
void FEditL(char *FileName, int line, char* new_line);
int FFindL(char* FileName, char* str);
void FGetL(char * FileName, char* line, int idx);

#endif //ASSIGNMENT2_FPROCESS_H
