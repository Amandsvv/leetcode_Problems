class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;

        for(int & num : arr1){
            string s = to_string(num);
            string curr = "";
            for(char& c : s){
                curr += c;
                prefixes.insert(curr);
            }
        }

        int ans = 0;
        for(int & el : arr2){
            string s = to_string(el);
            string curr = "";
            for(char & c : s){
                curr += c;
                if(prefixes.count(curr)){
                    ans = max(ans, (int)curr.size());
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};