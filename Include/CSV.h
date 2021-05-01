//
// Created by ahmad-lap on 4/16/21.
//

#ifndef ASSIGNMENT2_CSV_H
#define ASSIGNMENT2_CSV_H

#define DATABASE "./Data.csv"

#include <stdio.h>
#include <string.h>
#include "Fprocess.h"
#include "Dtypes.h"
/*
 * Main Phone Book Data Structure
 */

typedef struct BookInstance{
    char Name[BUFFER_SIZE];
    char Email[BUFFER_SIZE];
    char Phone[BUFFER_SIZE];
}BookInstance;

// PROTOTYPES
void PrintFile(const char* FileName);
void GetInstance(const char* FileName, const char* instance);
void Tokenize(char * tokens[3], char_t str[BUFFER_SIZE], const char* del);
void PrintLine(const char* FileName, int32_t line);
void AddInstance(const char* FileName, const BookInstance Entry);
void DeleteInstance(const char* FileName, const char* instance);
void EditInstance(const char_t * FileName, const char_t * instance, uint16_t field, char_t * edit);

// MACROS
#define BUFFER_SIZE 1024

#endif //ASSIGNMENT2_CSV_H
