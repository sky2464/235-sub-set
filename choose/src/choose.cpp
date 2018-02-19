//============================================================================
// Name        : choose.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//
//  main.cpp
//  problem1.cpp
//
//  Created by Muhammad Usman on 2/17/18.
//  Copyright © 2018 Muhammad Usman. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


void print(int subset[],int size)
{
    cout<<"{";
    for(int i =0; i <size; i++)
    {
        if(subset[i] == '\0')
            cout<<"";
        else
        cout<<subset[i]<<",";
        
    }
    cout<< "}"<<endl;}
    


void helper(int arr[],int subset[],int i,int size)
{
   if(i == size)
   {
       print(subset,size);
    
   }
    else
    {
        subset[i]= '\0';
        helper(arr,subset,i+1,size);
        subset[i] = arr[i];
        helper(arr,subset,i+1,size);
    
    }
}
void powerset(int arr[], int size)
{
    int subset[size];
    helper(arr,subset,0,size);
}
int main()
{
    int size;
    cout<<"enter the size of array."<<endl;
    cin >> size;
    int arr[size];
    
    int value;
    for(int i =0; i<size; i++)
    {
        cout<<"enter the " << i <<"th element of the array."<<endl;
        cin>> value;
        arr[i] = value;
        
    }
    powerset(arr,size);
    return 0;

}

