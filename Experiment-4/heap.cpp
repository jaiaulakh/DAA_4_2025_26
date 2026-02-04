/*
    Why is deleteVal() O(n) and not O(n log n)?

    Because:
    - Searching the value in heap takes O(n)
    - Replacing last element takes O(1)
    - Heapify takes O(log n)

    Overall complexity = O(n)
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int arr[MAX];
int sizee = 0;

void downHeap(int i)
{
    int minIdx = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < sizee && arr[l] < arr[minIdx])
        minIdx = l;
    if(r < sizee && arr[r] < arr[minIdx])
        minIdx = r;

    if(minIdx != i)
    {
        swap(arr[i], arr[minIdx]);
        downHeap(minIdx);
    }
}

void upHeap(int i)
{
    while(i > 0 && arr[(i-1)/2] > arr[i])
    {
        swap(arr[i], arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insertVal(int x)
{
    if(sizee == MAX)
    {
        cout << "heap full\n";
        return;
    }

    arr[sizee] = x;
    sizee++;

    upHeap(sizee-1);
}
void deleteMin()
{
    if(sizee == 0)
    {
        cout << "heap empty\n";
        return;
    }
    arr[0] = arr[sizee-1];
    sizee--;
    downHeap(0);
}

void deleteVal(int x)
{
    if(sizee == 0)
    {
        cout << "heap empty\n";
        return;
    }
    int pos = -1;
    for(int i = 0; i < sizee; i++)
    {
        if(arr[i] == x)
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
    {
        cout << "value not found\n";
        return;
    }
    arr[pos] = arr[sizee-1];
    sizee--;

    if(pos >= sizee) return;

    int parent = (pos-1)/2;

    if(pos > 0 && arr[pos] < arr[parent])
        upHeap(pos);
    else
        downHeap(pos);
}

void display()
{
    for(int i = 0; i < sizee; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    insertVal(2);
    insertVal(4);
    insertVal(6);
    insertVal(1);

    display();

    deleteMin();
    display();

    deleteVal(4);
    display();
}
