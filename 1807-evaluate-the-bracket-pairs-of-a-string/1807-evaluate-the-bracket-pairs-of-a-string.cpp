class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto& vec: knowledge){
            mp[vec[0]] = vec[1];
        }

        string ans = "";
        int i = 0;
        while(i < s.size()){
            char ch = s[i];
            if(ch == '('){
                string key = "";
                i++; //skip (
                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }

                if(mp.find(key) != mp.end()){
                    ans += mp[key];
                }else{
                    ans+='?';
                }
            }else ans+=ch;
            
            i++;
        }
        return ans;
    }
};