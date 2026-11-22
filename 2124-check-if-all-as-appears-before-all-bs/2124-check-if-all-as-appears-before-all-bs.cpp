class Solution {
public:
    bool checkString(string s) {
        int idxa = -1, idxb = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a') idxa = i;

            if(s[i] == 'b' && idxb == -1) idxb = i;

            if(idxb != -1 && idxb < idxa) return false;
        }
        return idxb == -1 ? true : idxa < idxb;
    }
};