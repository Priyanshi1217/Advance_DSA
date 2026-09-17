#include <iostream>
using namespace std;

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; j++)
    {
        if(a[j] <= x)
        {
            i = i + 1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
void quick_sort(int a[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}
int main()
{
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    quick_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}