// Taylor Martin
// CS-210
// Functional Concurrency 
// 12/12/21
// @file task2.cpp
#include <iostream>
#include <vector>
#include <thread> 
#include <chrono>
using std::vector;
using std::cout;
using std::endl;
int main()
{
    vector <int> v; 
    //fill vector lambda function 
    auto glambda = [](vector<int>&v){int val=1;for(int i=0;i<60;i++){v.push_back(val);val++;}};
    glambda(v); 
    //lambda function for printing vector elements every 1 sec
    auto lambda =[](vector<int>v){cout<<"thread_id: "<<std::this_thread::get_id<<endl;for(int i = 0; i < 60; i++){cout << v[i] << endl;std::this_thread::sleep_for(std::chrono::seconds(1));};}; 
    cout << "Starting long running function thread." << endl;
    // Create and start the long running thread using the lambda function from Task 1. Call this thread t.
    std::thread t(lambda,v); 
    // After the thread is started.
    cout << "Long running function started in the background." << endl;
    // Wait for long running function to finish.
    //join threads
    t.join();
    cout << "Long running thread has completed." << endl;  

    return 0; 
}