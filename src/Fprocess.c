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
 *      5- Search Lines for Certain Word or Character
 */

// Imports
#include "../Include/Fprocess.h"

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
    fprintf(fp, "%s\n", Line);
    fclose(fp);
}

/*
 * Edit a Certain Line in File, if new_line is
 * given it will replace the current line in file
 */
void FEditL(char *FileName, int line, char* new_line){
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

/*
 * Finds a line within a file that contains
 * a certain word or a character
 */
int FFindL(char* FileName, char* str){
    FILE *ptr;
    char line[BUFFER_SIZE], *lid;
    int count = 0;
    ptr = fopen(FileName, "r");

    while (fgets(line, BUFFER_SIZE, ptr) != NULL) {
        lid = strstr(line, str);
        count++;
        if(lid != NULL){
            fclose(ptr);
            return count ;
        }
    }
    printf("Not Found");
    fclose(ptr);
    return -1;
}

void FGetL(char * FileName, char* line, int idx){
    FILE *ptr = fopen(FileName, "r");
    char Buffer[BUFFER_SIZE];
    int count = 0;
    if (FCountL(FileName) > idx) line = NULL;
    while (fgets(Buffer, BUFFER_SIZE, ptr)){
        if(count == idx){
            strcpy(line, Buffer);
        }
        count++;
    }
    fclose(ptr);
}