#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> prefixIndex;
    int sum = 0, maxLen = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == k)
            maxLen = i + 1;

        if(prefixIndex.find(sum - k) != prefixIndex.end())
            maxLen = max(maxLen, i - prefixIndex[sum - k]);

        if(prefixIndex.find(sum) == prefixIndex.end())
            prefixIndex[sum] = i;
    }

    cout << maxLen;
    return 0;
}
