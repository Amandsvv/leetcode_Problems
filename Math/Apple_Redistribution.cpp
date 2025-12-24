#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(), greater<int>());
        int TotalApple = 0;

        for(int apples : apple){
            TotalApple+=apples;
        }
        int count = 0, requiredSpace = 0;
        if(TotalApple == 0) return count;

        for(int i = 0; i < capacity.size(); i++){
            requiredSpace+=capacity[i];
            count++;
            if(requiredSpace >= TotalApple){
                return count;
            }
        }
        return count;
    }
};
int main (){

}