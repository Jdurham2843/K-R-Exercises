#include <stdio.h>
#include <stdlib.h>

long getContents(FILE *fp, char** contents);
char* stripComments(char* contents, long size);

int main(int argc, char** argv) {
    FILE *fp;
    char* filename;
    long originalSize, finalSize;
    char* contents;
    char* strippedContents;

    if (argc > 1) {
        filename = argv[1]; 
    } else {
        printf("Example use: rc <inputFileName> \n");
        return EXIT_FAILURE;
    }

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("there was an issue opening the file\n");
        return EXIT_FAILURE;
    }

    originalSize = getContents(fp, &contents);
    fclose(fp);

    strippedContents = stripComments(contents, originalSize);

    fp = fopen(filename, "w");
    fputs(strippedContents, fp);
    
    fclose(fp);

    free(contents);
    free(strippedContents);
    return 0;
}

long getContents(FILE *fp, char** contents) {
    long fsize;
    char* readContents;

    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET); /* rewind */ 

    readContents = malloc(fsize + 1);
    fread(readContents, 1, fsize, fp);
    
    *contents = readContents;
    return fsize;
}

char* stripComments(char* contents, long size) {
    int i;
    char* strippedContents = malloc(size + 1);
    int inComment = 0;

    for (i = 0; i < size - 1 ; ++i) {
        if (!inComment && contents[i] == '/' && contents[i+1] == '*') {
            inComment = 1;
            strippedContents[i] = ' ';
            ++i;
            strippedContents[i] = ' ';
        } else if (inComment && contents[i] == '*' && contents[i+1] == '/') {
            inComment = 0;
            strippedContents[i] = ' ';
            ++i;
            strippedContents[i] = ' ';
        } else if (inComment) {
            strippedContents[i] = ' ';
        } else {
            strippedContents[i] = contents[i];
        }
    }

    if (!inComment) {
        strippedContents[i+1] = contents[i+1];
    }

    return strippedContents;
}