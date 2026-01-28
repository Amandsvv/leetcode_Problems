#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secretFreq, guessFreq;

        int bull = 0, cow = 0;

        // Step 1: Count Bulls and store unmatched digits
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                secretFreq[secret[i]]++;
                guessFreq[guess[i]]++;
            }
        }

        // Step 2: Count Cows
        for (pair<char, int> pr : guessFreq) {
            if (secretFreq.count(pr.first)) {
                cow += min(pr.second, secretFreq[pr.first]);
            }
        }

        // Step 3: Build answer
        string ans = to_string(bull) + "A" + to_string(cow) + "B";

        return ans;
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        vector<int> count(10,0);

        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]) bull++;
            else{
                int s = secret[i] - '0';
                int g = guess[i] - '0';

                if(count[s] < 0) cow++;
                if(count[g] > 0) cow++;

                count[s]++;
                count[g]--;
            }
        } 

        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};

int main (){

}