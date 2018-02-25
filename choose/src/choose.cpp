//============================================================================
// Name        : choose.cpp
// Author      : Navid Saboori, Muhammad Usman
// Version     :
// Copyright   : Sky2464, MUsman
// Description : m Choose K in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// function to print the array of subset.
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
    cout<< "}"<<endl;
}
    

// helper function to add elements in subset array.
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
    int subset[size];// makes another array equal to the size of original to add elements one by one.
    helper(arr,subset,0,size);
}
// main function to start the programme.
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

