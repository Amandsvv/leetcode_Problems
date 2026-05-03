class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string d = goal + goal;
        return d.find(s) != string::npos;
    }
};