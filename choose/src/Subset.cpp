#include<iostream>

using namespace std;

// A function to print all combination of a given length from the given array.

void Subset(int a[], int reqLen, int start, int currLen, bool check[], int len)

{

// Return if the currLen is more than the required length.

if(currLen > reqLen)

return;

// If currLen is equal to required length then print the sequence.

else if (currLen == reqLen)

{

cout<<"\t";

cout<<"{ ";

for (int i = 0; i < len; i++)

{

if (check[i] == true)

{

cout<<a[i]<<" ";

}

}

cout<<"}\n";

return;

}

// If start equals to len then return since no further element left.

if (start == len)

{

return;

}

// For every index we have two options.

// First is, we select it, means put true in check[] and increment currLen and start.

check[start] = true;

Subset(a, reqLen, start + 1, currLen + 1, check, len);

// Second is, we don't select it, means put false in check[] and only start incremented.

check[start] = false;

Subset(a, reqLen, start + 1, currLen, check, len);

}

int main()

{

int i, n;

bool check[100];

cout<<"Enter the number of element array have: ";

cin>>n;

int arr[n];

cout<<"\n";

// Take the input of the array.

for(i = 0; i < n; i++)

{

cout<<"Enter "<<i+1<<" element: ";

cin>>arr[i];

check[i] = false;

}

// Sort the array.

int temp,j;

for(i = 0; i < n; i++)

{

for(j = i+1; j < n; j++)

{

if(arr[i] > arr[j])

{

temp = arr[i];

arr[i] = arr[j];

arr[j] = temp;

}

}

}

//Remove duplicates

int b[100],k=0;

b[k]=arr[0];

for(i = 1; i < n; i++)

{

if(b[k]!=arr[i]){

k++;

b[k]=arr[i];

}

}

for(i = 0; i < k+1; i++)

{

cout<<b[i];

}

cout<<"\nThe subset in the lexicographic order: \n";

cout<<"\t{ }\n";

for(i = 1; i <= k; i++)

{

Subset(b, i, 0, 0, check, k+1);

}

//Print the subset containing all element

cout<<"\t{ ";

for(i = 0; i < k+1; i++)

{

cout<<b[i]<<" ";

}

cout<<"}";

return 0;

}
