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
void PrintFile(char* FileName){
    FILE * ptr;
    char buffer[BUFFER_SIZE];
    char* fields;
    ptr = fopen(FileName, "r");

    while(fgets(buffer, BUFFER_SIZE, ptr)){
        fields = strtok(buffer, ",");
        while (fields != NULL){
            printf("|%-30s", fields);
            fields = strtok(NULL, ",");
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
void Tokenize(char * tokens[], char str[BUFFER_SIZE], char* del){
    char* fields;
    short count = 0;
    fields = strtok(str, del);
    while (fields != NULL){
        tokens[count] = fields;
        fields = strtok(NULL, del);
        count++;
    }
}

/*
 * Print a certain line in csv file
 */
void PrintLine(char* FileName, int line){
    FILE *ptr;
    char Buffer[BUFFER_SIZE];
    int count = 0;
    char* line_tok[3];

    ptr = fopen(FileName, "r");

    while (fgets(Buffer, BUFFER_SIZE, ptr)){
        if (count == line){
            Tokenize(line_tok, Buffer, ",");
            for(int i=0; i<=2; i++) printf("|%-10s", line_tok[i]);
            printf("\n");
        }
        count++;
    }
}

/*
 *
 * Find given string
 */
void GetInstance(char* FileName, char* instance){
    int line;
    line = FFindL(FileName, instance);
    if (line != -1){
        PrintLine(FileName, line-1);
    }
}


/*
 * Add to Database instance from user
 */
void AddInstance(char* FileName, BookInstance Entry){
    char line[BUFFER_SIZE];
    sprintf(line, "%s,%s,%s", Entry.Name, Entry.Email, Entry.Phone);
    FAddL(FileName, line);
}


/*
 * Delete a Certain Instance from Database file
 */
void DeleteInstance(char* FileName, char* instance){
    int line;
    line = FFindL(FileName, instance);
    FEditL(FileName, line, NULL); // Null is passed to identify that this is a deletion process
}


/*
 * Edit a Certain instance in Data base
 */
void EditInstance(char* FileName, char* instance, int field, char* edit){
    int idx;
    char line[BUFFER_SIZE];
    char* tokens[3];
    char new_line[BUFFER_SIZE];

    idx = FFindL(FileName, instance);
    FGetL(FileName, line, idx);
    Tokenize(tokens, line, ",");
    tokens[field] = edit;


    sprintf(new_line, "%s,%s,%s", tokens[0], tokens[1], tokens[2]);
    FEditL(FileName, idx, new_line);
}
