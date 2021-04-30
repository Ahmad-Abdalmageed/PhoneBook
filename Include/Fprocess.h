//
// Created by ahmad-lap on 4/15/21.
//

#ifndef ASSIGNMENT2_FPROCESS_H
#define ASSIGNMENT2_FPROCESS_H

// Includes
#include <stdio.h>
#include <string.h>
#include "Dtypes.h"

// Macros
#define BUFFER_SIZE 1024

int32_t FCountL(const char_t FileName[]);
void FAddL(const char_t FileName[], const char_t Line[]);
void FEditL(const char_t *FileName, int32_t line, const char_t* new_line);
int32_t FFindL(const char_t* FileName, const char_t* str);
void FGetL(const char_t * FileName, char_t* line, int32_t idx);

#endif //ASSIGNMENT2_FPROCESS_H
