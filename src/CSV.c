/*
 *
 * Created by ahmad-lap on 4/16/21.
 * CSV Related Function Implementations
 *
 */

#include "../Include/CSV.h"


/*
 * Print the Whole CSV File
 * in a tabular format
 */
void PrintFile(const char_t* FileName){
    FILE * ptr;
    char_t buffer[BUFFER_SIZE] = {};
    char_t* fields;
    ptr = fopen(FileName, "r");

    while(fgets(buffer, BUFFER_SIZE, ptr)){
        fields = strtok(buffer, ",");
        while (fields != NULL){
            printf("|%-30s", fields);
            fields = strtok(NULL_CHAR, ",");
        }
        printf("\n");
    }
    fclose(ptr);
}

/*
 *
 * Extract Tokens from String given using
 * a delimiter present in string.
 */
void Tokenize(char_t * tokens[], char_t str[BUFFER_SIZE], const char_t* del){
    char_t* fields;
    int16_t count = 0;
    fields = strtok(str, del);
    while (fields != NULL){
        tokens[count] = fields;
        fields = strtok(NULL_CHAR, del);
        count++;
    }
}

/*
 * Print a certain line in csv file
 */
void PrintLine(const char_t* FileName, int32_t line){
    FILE *ptr;
    char_t Buffer[BUFFER_SIZE] = {};
    int32_t count = 0;
    char_t* line_tok[3];
    int16_t i;
    ptr = fopen(FileName, "r");

    while (fgets(Buffer, BUFFER_SIZE, ptr)){
        if (count == line){
            Tokenize(line_tok, Buffer, ",");
            for(i=0; i<=2; i++){
                printf("|%-20s", line_tok[i]);
            }
            printf("\n");
        }
        count++;
    }
}

/*
 *
 * Find given string
 */
void GetInstance(const char_t* FileName, const char_t* instance){
    int32_t line;
    line = (int32_t)FFindL(FileName, instance);
    if (line != -1){
        PrintLine(FileName, line-1);
    }else{
        printf("NOT Found!!\n");
    }
}


/*
 * Add to Database instance from user
 */
void AddInstance(const char_t * FileName, const BookInstance Entry){
    char_t line[BUFFER_SIZE] = {};
    sprintf(line, "%s,%s,%s", Entry.Name, Entry.Email, Entry.Phone);
    FAddL(FileName, line);
}


/*
 * Delete a Certain Instance from Database file
 */
void DeleteInstance(const char_t * FileName, const char_t * instance){
    int32_t line;
    line = FFindL(FileName, instance);
    FEditL(FileName, line-1, NULL_CHAR); // Null is passed to identify that this is a deletion process
}


/*
 * Edit a Certain instance in Data base
 */
void EditInstance(const char_t * FileName, const char_t * instance, uint16_t field, char_t * edit){
    int32_t idx;
    char_t line[BUFFER_SIZE] = "";
    char_t* tokens[3] = {};
    char_t new_line[BUFFER_SIZE] = "";

    idx = FFindL(FileName, instance) -1;
    if(idx == -1){
        printf("Instance NOT Found !");
    } else{
        FGetL(FileName, line, idx);
        Tokenize(tokens, line, ",");
        tokens[field] = edit;


        sprintf(new_line, "%s,%s,%s", tokens[0], tokens[1], tokens[2]);
        FEditL(FileName, idx, new_line);
    }
}
