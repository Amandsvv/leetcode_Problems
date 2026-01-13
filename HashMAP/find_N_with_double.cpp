#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> num;
        for(int el: arr){
            if(num.count(2*el) || num.count(el/2) && el%2 == 0) return true;
            else num.insert(el);
        }
        return false;
    }
};
int main (){

}