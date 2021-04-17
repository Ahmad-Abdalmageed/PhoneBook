//
// Created by ahmad-lap on 4/16/21.
//

#ifndef ASSIGNMENT2_CSV_H
#define ASSIGNMENT2_CSV_H

#define DATABASE "./Data.csv"

#include <stdio.h>
#include <string.h>
#include "Fprocess.h"

/*
 * Main Phone Book Data Structure
 */

typedef struct BookInstance{
    char Name[BUFFER_SIZE];
    char Email[BUFFER_SIZE];
    char Phone[BUFFER_SIZE];
}BookInstance;

// PROTOTYPES
void PrintFile(char* FileName);
void GetInstance(char* FileName, char* instance);
void Tokenize(char * tokens[3], char* str, char* del);
void PrintLine(char* FileName, int line);
void AddInstance(char* FileName, BookInstance Entry);
void DeleteInstance(char* FileName, char* instance);
void EditInstance(char* FileName, char* instance, int field, char* edit);

// MACROS
#define BUFFER_SIZE 1024

#endif //ASSIGNMENT2_CSV_H
