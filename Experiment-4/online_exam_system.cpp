#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    priority_queue<int, vector<int>, greater<int>> heap;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.push(x);
        if(heap.size() > k) {
            heap.pop();
        }
        if(heap.size() < k) {
            cout << -1 << endl;
        } else {
            cout << heap.top() << endl;
        }
    }
    return 0;
}
