/*
 *  Created by ahmad-lap on 4/15/21.
 *
 *  FProcess is a Source File for all File Manipulation
 *  Processes Needed in this project.
 *
 *  Contains Implementations for:
 *      1- Adding New Lines in File
 *      2- Deleting Lines
 *      3- Edit Lines
 *      4- Count Lines
 */

// Imports
#include "../Include/Fprocess.h"
#include <stdio.h>

// Macros
#define BUFFER_SIZE 1024

/*
 * Count the Number of lines
 * included in a text file
 */
int FCountL(char FileName[]){
    int count = 0, chr;
    FILE* fp;

    // Open File Selected and get the
    // First Character
    fp = fopen(FileName, "r");
    chr = getc(fp);

    // Loop the whole file for
    // New lines and count
    while (chr  != EOF){
        if (chr == '\n') count++;
        chr = getc(fp);
    }
    fclose(fp);
    return count;
}

/*
 * Append new Lines to Existing File
 */
void FAddL(char FileName[], char Line[]){
    FILE* fp;
    fp = fopen(FileName, "a");
    fprintf(fp, "\n%s", Line);
    fclose(fp);
}

/*
 * Delete a Certain line in File
 */
void FeditL(char *FileName, int line, char* new_line){
    int count = 0;
    char buffer[BUFFER_SIZE];
    FILE *src, *temp;

    src = fopen(FileName, "r");
    temp = fopen("./temp.tmp", "w");

    while (fgets(buffer, BUFFER_SIZE, src) != NULL){
        if(line != count) fputs(buffer, temp);
        else{
            if(new_line) fputs(new_line, temp);
        }
        count++;
    }

    fclose(src);
    fclose(temp);

    remove(FileName);
    rename("./temp.tmp", FileName);
}