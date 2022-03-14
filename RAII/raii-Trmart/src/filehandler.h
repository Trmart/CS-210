// Taylor Martin
// CS-210 
// RAII 
// "filehandler.h"
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <stdio.h> 

class FileHandler
{
    FILE* fp; //file pointer for stdio fopen and fclose

    public:
    FileHandler(const char* file_name, const char* file_mode); //constructor 
    ~FileHandler(); //destructor

    //prevent copy and move 
    FileHandler(const FileHandler&) = delete; 
    FileHandler &operator=(const FileHandler &other) = delete;

    void read_file(); //read
    void write_file(const char* data); //write
    
    bool is_EOF(); //checks if is the end of file 

    protected:
    void log_and_throw(const char* error_message); 
}; 

#endif