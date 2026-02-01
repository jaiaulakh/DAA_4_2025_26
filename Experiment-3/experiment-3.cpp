#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;
    mp[0] = -1;   // prefix sum 0 at index -1

    int sum = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] == 'P')
            sum += 1;
        else
            sum -= 1;

        if (mp.find(sum) != mp.end()) {
            ans = max(ans, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    cout << ans << endl;
    return 0;
}
// Test Case:
    // Input:
    // 5
    // P A P A P
    // Output:
    // 4
