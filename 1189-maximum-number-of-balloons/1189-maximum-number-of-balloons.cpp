class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // unordered_map<char,int> freq;
        // for(char ch : text){
        //     freq[ch]++;
        // }
        // int a = freq['b'];
        // int b = freq['a'];
        // int c = freq['l']/2;
        // int d = freq['o']/2;
        // int e = freq['n'];

        // return min(e,(min(min(a,b), min(c,d))));

        // int freq[5] = {0};
        // for(char ch: text){
        //     if(ch == 'b') freq[0]++;
        //     if(ch == 'a') freq[1]++;
        //     if(ch == 'l') freq[2]++;
        //     if(ch == 'o') freq[3]++;
        //     if(ch == 'n') freq[4]++;
        // }
        // int ans = INT_MAX;
        // freq[2]/=2; freq[3]/=2;
        // for(int el : freq){
        //     if(el < ans) ans = el;
        // }
        // return ans;

        int freq[26] = {};

        for (char ch : text)
            freq[ch - 'a']++;

        return min({freq['b' - 'a'], freq['a' - 'a'], freq['l' - 'a'] / 2,
                    freq['o' - 'a'] / 2, freq['n' - 'a']});
    }
};