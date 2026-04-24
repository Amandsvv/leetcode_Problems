class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        vector<int> vec(3,0);
        for(char ch : moves){
            if(ch == 'L')vec[0]++;
            if(ch == 'R')vec[1]++;
            if(ch == '_')vec[2]++;
        }
        if(vec[0] < vec[1]) vec[1]+=vec[2];
        else vec[0]+=vec[2];
        
        return abs(vec[0] - vec[1]);
    }
};