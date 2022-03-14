# RAII

In C++ a core concept is Resource Allocation is Initialization (RAII). 

In this assignment you will create a class using std::fopen and std::fclose https://en.cppreference.com/w/cpp/io/c/fopen. Normal C++ streams provide a similar capability.

This class will open the file on construction and close it on destruction.

It will implement a read method and write method that wrap the fread and fwrite functions taking the same arguments and returning the same values.

If and error occurs during any operation it will throw a logic_error exception with text explaining the problem. For example

    throw std::logic_error("Couldn't open the file: " + "inputfile");

* Create program demonstrating the use of your class that implements a copy file function.
* Catch any exceptions thrown in your main program and have them print the exception thrown.
* Constructor will take the same arguments as fopen choose a default for mode that makes sense.
* Prevent copy and move semantics
* Prevent implicit construction https://en.cppreference.com/w/cpp/language/explicit
