#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> asteroidCollision(vector<int> ast){
        vector<int> ans;
        for(int a : ast){

            bool destroyed = false;
            while(!ans.empty() && a < 0 && ans.back() > 0){
                if(ans.back() < -a){
                    ans.pop_back();
                }else if(ans.back() == -a){
                    ans.pop_back();
                    destroyed = true;
                    break;
                }else{
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) ans.push_back(a);
        }
        return ans;
    }
};
int main (){
    vector<int> asteroids = {5,10,-5};
    Solution obj;

    vector<int> ans = obj.asteroidCollision(asteroids);
    for(int el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}