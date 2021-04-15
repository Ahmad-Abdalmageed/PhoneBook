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


#include "../Include/Fprocess.h"
#include <stdio.h>

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
    fprintf(fp, "%s", Line);
    fclose(fp);
}

/*
 * Delete a Certain line in File
 */
void FdeleteL(char FileName, int line){

}