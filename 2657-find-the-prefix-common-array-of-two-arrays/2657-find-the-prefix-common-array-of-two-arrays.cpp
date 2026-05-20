class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0); // To track occurrences of each number
        vector<int> C(n);
        int commonCount = 0;

        for (int i = 0; i < n; i++) {
            // Process A[i]
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                commonCount++; // It appeared in both A and B so far
            }

            // Process B[i]
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                commonCount++; // It appeared in both A and B so far
            }

            C[i] = commonCount;
        }

        return C;
    }
};