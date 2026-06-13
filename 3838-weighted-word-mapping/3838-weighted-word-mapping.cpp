class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = "";
        for(auto & w : words){
            int sum = 0;
            for(auto & c : w){
                sum+=weights[(int)(c - 'a')];
            }
            int mod = sum % 26;
            char ch = 'z' - mod;
            s+=ch;
        }
        return s;
    }
};