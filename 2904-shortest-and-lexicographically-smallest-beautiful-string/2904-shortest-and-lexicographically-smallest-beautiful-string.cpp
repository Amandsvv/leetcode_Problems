class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int sz = s.length();
        for(int len = k; len <= sz; len++){
            vector<string> vec;
            int count1 = 0;

            for(int i = 0; i < len; i++){
                if(s[i] == '1') count1++;
            }

            if(count1 == k){
                vec.push_back(s.substr(0, len));
            }

            for(int i = len; i < sz; i++){
                if(s[i] == '1') count1++;
                if(s[i-len] == '1') count1--;
                if(count1 == k){
                    vec.push_back(s.substr(i-len+1, len));
                }
            }

            if(vec.size() == 0){
                continue;
            }else if(vec.size() == 1){
                return vec[0];
            }else{
                sort(vec.begin(), vec.end());
                return vec[0];
            }
        }
        return "";
    }
};