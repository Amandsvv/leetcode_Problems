#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubledString = s +s;
        size_t foundPosition = doubledString.find(s, 1);
      
        return foundPosition < s.size();
    }
};
int main()
{
    string s = "a";
    auto obj = Solution();
    if(obj.repeatedSubstringPattern(s)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}