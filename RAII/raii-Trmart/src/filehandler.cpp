// Taylor Martin
// CS-210 
// RAII 
// "filehandler.cpp"
#include "filehandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept> 
#include <vector>
#include <string.h>
FileHandler::FileHandler(const char* file_name, const char* file_mode)
{
    fp = fopen(file_name, file_mode);
    if(fp == NULL)
    {
        log_and_throw("FAILED TO OPEN FILE\n"); 
    }

}
FileHandler::~FileHandler()
{
    fclose(fp); 
    printf("FILE RESOURCE RELEASED\n"); 
}

void FileHandler::read_file()
{
    //obtain file size
    fseek(fp,0,SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp); 

    //allocate memory to contain the whole file
    char*buffer = (char*) malloc(sizeof(char*)*fileSize);
    
    //copy result into the buffer 
    size_t result = fread(buffer, 1, fileSize, fp);

    if(result != fileSize)
    {
        log_and_throw("READ ERROR\n"); 
    }
    printf("%s\n",buffer);

    //the whole file is now loaded into the buffer
    free(buffer);
}



void FileHandler::write_file(const char* data)
{
    if(fp ==NULL)
    {
        log_and_throw("WRITING TO FILE FAILED\n"); 
    }
    //fwrite(data,strlen(data) + 1,sizeof(data),fp);
    fwrite (data , sizeof(char), sizeof(data), fp);
}

bool FileHandler::is_EOF()
{
    return feof(fp); // returns true if end of file
}

void FileHandler::log_and_throw(const char* error_message)
{
    perror(0);
    throw std::runtime_error(error_message); //throws runtime_error with supplied message
    exit(EXIT_FAILURE); 
}