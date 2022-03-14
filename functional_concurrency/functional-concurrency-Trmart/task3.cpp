// Taylor Martin
// CS-210
// Functional Concurrency 
// 12/12/21
// @file task3.cpp
#include <iostream>
#include <vector>
#include <thread> 
#include <chrono>
#include<mutex>
using std::vector;
using std::cout;
using std::endl;
int sleep_count = 0; //global variable to hold thread sleep count 
std::mutex sleep_count_mutex; //protects sleep_count
int main()
{
    vector <int> v; 
    //fill vector lambda function 
    auto glambda = [](vector<int>&v){int val=1;for(int i=0;i<60;i++){v.push_back(val);val++;}};
    glambda(v); 
    //lambda function for printing vector elements every 1 sec
    auto lambda =[](vector<int>v){const std::lock_guard<std::mutex>lock(sleep_count_mutex);for(int i = 0; i < 60; i++){cout << v[i] << endl;std::this_thread::sleep_for(std::chrono::seconds(1));sleep_count++;cout<<"sleep_count: "<<sleep_count<<endl;};}; 
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