#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countDigitOne(int n) {
        if(n == 1) return 1;
        if(n <= 0) return 0;
        cout<<"N : "<<n<<endl;
        int count = 0, x = n;
        while(x){
            if(x%10 == 1) count++;
            x/=10;
        }

        return count + countDigitOne(n/2-1) + countDigitOne(n/2 + 1);
    }
};
int main (){
    int n = 13;
    auto obj = Solution();
    cout<<obj.countDigitOne(n);
    return 0;
}