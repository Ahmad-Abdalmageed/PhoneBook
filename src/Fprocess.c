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
int32_t FCountL(const char_t FileName[]){
    int32_t count = 0, chr;
    FILE* fp;

    // Open File Selected and get the
    // First Character
    fp = fopen(FileName, "r");
    chr = getc(fp);

    // Loop the whole file for
    // New lines and count
    while (chr  != EOF){
        if (chr == (int32_t)'\n'){
            count++;
        }else{
            // Nothing To Do
        }
        chr = getc(fp);
    }
    fclose(fp);
    return count;
}

/*
 * Append new Lines to Existing File
 */
void FAddL(const char_t FileName[], const char_t Line[]){
    FILE* fp;
    fp = fopen(FileName, "a");
    fprintf(fp, "%s\n", Line);
    fclose(fp);
}

/*
 * Edit a Certain Line in File, if new_line is
 * given it will replace the current line in file
 */
void FEditL(const char_t *FileName, int32_t line, const char_t* new_line){
    int32_t count = 0;
    char_t buffer[BUFFER_SIZE] = {};
    FILE *src, *temp;

    src = fopen(FileName, "r");
    temp = fopen("temp.tmp", "w");

    while (fgets(buffer, BUFFER_SIZE, src) != NULL){
        if(line != count){
            fputs(buffer, temp);
        }
        else{
            if(new_line){
                fputs(new_line, temp);
            }else{
                // Do Nothing
            }
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
int32_t FFindL(const char_t* FileName, const char_t* str){
    FILE *ptr;
    char_t line[BUFFER_SIZE] = {}, *LINE_FOUND;
    int32_t count = 0;
    ptr = fopen(FileName, "r");

    while (fgets(line, BUFFER_SIZE, ptr) != NULL) {
        LINE_FOUND = strstr(line, str);
        count++;
        if(LINE_FOUND != NULL){
            break;
        }
    }
    if(LINE_FOUND == NULL){
        count = -1;
    } else{
        // Return Count
    }
    fclose(ptr);
    return count;
}

void FGetL(const char_t * FileName, char_t* line, int32_t idx){
    FILE *ptr;
    char_t Buffer[BUFFER_SIZE] = {};
    int32_t count = 0;

    if(FCountL(FileName) > idx){
        ptr = fopen(FileName, "r");
        while (fgets(Buffer, BUFFER_SIZE, ptr)){
            if(count == idx){
                strcpy(line, Buffer);
                break;
            }
            count++;
        }
        fclose(ptr);
    } else { // Index Needed is Out of Range
        line = "\0";
    }
}