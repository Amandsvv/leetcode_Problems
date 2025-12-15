#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jew;
        for(char ch : jewels){
            jew.insert(ch);
        }
        int count = 0;
        for(char ch : stones){
            if(jew.find(ch) != jew.end()) count++;
        }
        return count;
    }
};
int main (){

}