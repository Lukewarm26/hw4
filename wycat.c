/*
wycat.c
Author: Lucas Eifert
Date: 2/22/22

COSC 3750, Homework 4

This is a simple version of the cat utility. It will display the contents of a
file as standard output. 
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

void printFile(const char *);
void printStdout();

int main(int argc, char **argv) {

    //no arguments; read from stdin and write to stdout
    if( argc == 1 ) {
        printStdout();
    }
    //exists arguments; print contents to stdout
    else if( argc > 1 ) {
        for(int i = 1; i < argc; i++) {
            if(strcmp(argv[i], "-") == 0) printStdout();
            else printFile(argv[i]);
        }
    }  
}

//print the contents of a file to standard output
void printFile(const char *string) {

    char str[4096];
    FILE *infile;
    infile = fopen(string ,"r");
    if(infile == NULL) {
        perror(string);
        return;
    }
    int count = fread(str, sizeof(char), 4096, infile);
    fclose(infile);
    fwrite(str, sizeof(char), count, stdout);
    return;
}

//Copies stdin to stdout
void printStdout() {

    char str[4096];
    while(1) {
        int count = read(STDIN_FILENO, str, 4096);
        if(count == 0) break; //EOF
        else if(count < 0) {
            perror("error");
            break;
        }
        fwrite(str, sizeof(char), count, stdout);
    }
    return;
}
