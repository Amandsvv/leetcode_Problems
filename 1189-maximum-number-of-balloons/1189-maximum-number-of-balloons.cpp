class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        for(char ch : text){
            freq[ch]++;
        }
        int a = freq['b'];
        int b = freq['a'];
        int c = freq['l']/2;
        int d = freq['o']/2;
        int e = freq['n'];

        return min(e,(min(min(a,b), min(c,d))));
    }
};