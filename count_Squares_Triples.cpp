#include<iostream>
#include<vector>
#include<cmath>
#include<typeinfo>

using namespace std;
class Solution {
public:
    int countTriples(int n) {
        int triples = 0;
        auto c = 0.0;
        for(int a = 1; a < n; a++){
            for(int b = a; b < n; b++){
                c = sqrt((a*a) + (b*b));
                if(c <= n && floor(c) == c) triples+=2;
                cout<<a<<"-"<<b<<"-"<<c<<"triples : "<<triples<<endl;
            }
        }
        return triples;
    }
};
int main (){
    Solution obj;
    cout<<obj.countTriples(10)<<endl;
    return 0;
}