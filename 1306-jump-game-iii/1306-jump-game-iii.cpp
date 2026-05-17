class Solution {
public:
    bool helper(vector<int>& arr, int i, vector<bool>& visited){
        if(i < 0 || i >= arr.size() || visited[i]) return false;
        if(arr[i] == 0) return true;
        visited[i] = true;
        return helper(arr, i + arr[i], visited) || helper(arr, i - arr[i], visited);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return helper(arr, start, visited);
    }
};