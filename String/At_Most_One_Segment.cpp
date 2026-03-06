#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size() == 1) return true;
        if(s.find("01") != string::npos) return false;
        return true;
    }
};
int main (){

}