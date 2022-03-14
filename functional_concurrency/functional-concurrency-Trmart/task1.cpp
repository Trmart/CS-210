// Taylor Martin
// CS-210
// Functional Concurrency 
// 12/12/21
// @file task1.cpp
#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
int main()
{
    vector <int> v; 
    //fill vector lambda function
    auto glambda = [](vector<int>&v){int val=1;for(int i=0;i<60;i++){v.push_back(val);val++;}};
    glambda(v); 
    cout << "Starting long running function." << endl;
    //lambda function for printing vector elements every 1 sec
    auto lambda = [](vector <int>v){for(int i = 0; i < 60; i++){cout << v[i] << endl;sleep(1);}}; 
    lambda(v);
    cout << "Finished long running function." << endl;

    return 0; 
}