# Functional Concurrency
Concurrency is the ability for more than one process to run simultaneously.

Functional programming is loosely writing a function to do an independent task that has no side-effects with respect to the context from where it is called.

As such these concepts are complementary.

In this assignment a C++ thread will be created to allow a task (function) to run in the background while the main thread continues to run.

This can be used to do things such as execute long running tasks while allowing a graphical application to remain responsive to user input.

You will use a [C++ lambda expression](https://en.cppreference.com/w/cpp/language/lambda), [thread](https://en.cppreference.com/w/cpp/header/thread), [sleep_for](https://en.cppreference.com/w/cpp/thread/sleep_for), and [join](https://en.cppreference.com/w/cpp/thread/thread/join).

## Task 1:
Create a C++ lambda function that runs a loop 60 times that sleeps for 1 second in each loop. (It should take about 60 seconds to complete).
Create a program that runs the lambda function more or less as follows:

    {
      std::cout << "Starting long running function." << std::endl;
      // Put your lambda function here and call it.
      std::cout << "Finished long running function." << std::endl;
    }

## Task 2: 
Create a C++ program that does the same thing but puts the long running lambda function in a thread. It will do more or less the following:
    
    {
      std::cout << "Starting long running function thread." << std::endl;
      // Create and start the long running thread using the lambda function from Task 1. Call this thread t.
  
      // After the thread is started.
      std::cout << "Long running function started in the background." << std::endl;
  
      // Wait for long running function to finish.
      std::cout << "Long running thread has completed." << std::endl;  
    }

## Task 3:
cout is not thread safe (which is to say you can't call it in two threads at the same time and have sensible results). Using the code from Task 2 and a std::mutex write the current number of sleeps done so far. Note that the mutex will most easily be done by making it a global variable. (In production code this would probably be a class variable.) Use the RAII construct std::lock_guard to lock and unlock the mutex as needed. Make the main routine loop 6 times sleeping for 10 seconds each time and outputting the loop count after each sleep using the same mutex.

The result should provide output for the thread about once a second while the main routine will output about once every 10 seconds.
