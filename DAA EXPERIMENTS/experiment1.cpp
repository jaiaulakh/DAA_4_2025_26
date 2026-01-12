
// Experiment 1


// 1. Recurrence Relation:

//    The function makes 3 recursive calls on input size n/2.
//    The non-recursive work consists of:
//    - A while loop running log(n) times, each doing O(n) work
//    - Additional linear operations

//    Recurrence Relation:
//        T(n) = 3T(n/2) + O(n log n)



// 2. Master Theorem Analysis:

//    Given:
//        a = 3
//        b = 2
//        f(n) = n log n
//    Time complexity = O(n^2)



#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long operationCount;
int maxRecursionDepth;


void complexRec(int n, int currentDepth)
{
    if (currentDepth > maxRecursionDepth)
        maxRecursionDepth = currentDepth;

    if (n <= 2)
    {
        operationCount++;
        return;
    }

    int p = n;
    while (p > 0)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = i ^ p;
            operationCount++;
        }
        p = p / 2;
        operationCount++;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * i;
        operationCount++;
    }

    reverse(arr.begin(), arr.end());
    operationCount += n;

    complexRec(n / 2, currentDepth + 1);
    complexRec(n / 2, currentDepth + 1);
    complexRec(n / 2, currentDepth + 1);
}



int main()
{
    int inputSizes[] = {8, 16, 32, 64};

    for (int i = 0; i < 4; i++)
    {
        int n = inputSizes[i];
        operationCount = 0;
        maxRecursionDepth = 0;

        auto start = high_resolution_clock::now();
        complexRec(n, 1);
        auto end = high_resolution_clock::now();

        auto timeTaken = duration_cast<milliseconds>(end - start);

        cout << "Input Size (n): " << n << endl;
        cout << "Total Operations: " << operationCount << endl;
        cout << "Maximum Recursion Depth: " << maxRecursionDepth << endl;
    }

    return 0;
}
