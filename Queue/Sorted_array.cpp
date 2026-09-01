#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 5

int arr[MAXSIZE];
int size = 0;

void deletemax(){
    if(size==0){
        cout<<"Priority queue is empty"<<endl;
    }
    else{
        cout<<"Deleted element"<<arr[size-1]<<endl;
        size--;
    }
}
void insert (int x){
    if(size==MAXSIZE)
    cout<<"Priority queue is full"<<endl;
    else{
        int i=size-1;
        while(i>=0 && arr[i]>x)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=x;
        size++;
    }
}
void peek(){
if(size==0)
{
    cout<<"Priority queue is empty"<<endl;
}
else{
cout<<"Peek element"<<arr[size-1]<<endl;
}
}
void display(){
    // base case
    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
    }
}
int main()
{
    insert(10);
    insert(30);
    insert(20);
    insert(50);
    insert(40);
    display();
    peek();
    deletemax();
    display();
    peek();
    return 0;
}