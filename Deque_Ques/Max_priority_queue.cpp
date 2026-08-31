#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 5

int arr[MAXSIZE];
int SIZE = 0;

void enqueue(int value)
{
    if (SIZE == MAXSIZE)
    {
        cout << "Priority queue is full\n";
    }
    else
    {
        arr[SIZE] = value;
        SIZE++;
    }
}
void dequeue()
{
    if (SIZE == 0)
    {
        cout << "Priority queue is empty\n";
    }
    else
    {
        int MAXINDEX = 0;

        for (int i = 1; i < SIZE; i++)
        {
            if (arr[i] > arr[MAXINDEX])
                MAXINDEX = i;
        }

        cout << arr[MAXINDEX] << " Deleted\n";

        for (int i = MAXINDEX; i < SIZE - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        SIZE--;
    }
}
void display()
{
    if (SIZE == 0)
    {
        cout << "Priority queue is empty\n";
    }
    else
    {
        cout << "Priority Queue: ";

        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> value;
        enqueue(value);
    }

    cout << "\n";
    display();

    dequeue();

    cout << "After deletion:\n";
    display();

    return 0;
}