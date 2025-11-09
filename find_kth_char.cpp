#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    char kthChar(string word, int k){
        if(word.size() >= k) return word[k-1];
        string generatedString = "";
        for(char ch : word){
            generatedString+= ch+1;
        }
        word+=generatedString;
        return kthChar(word,k);
    }
    char kthCharacter(int k) {
        string word = "a";
        return kthChar(word,k);
    }
};
int main (){
    int k = 5;
    auto obj = Solution();
    cout<<obj.kthCharacter(k)<<endl;
}