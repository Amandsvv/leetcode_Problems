#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> els(nums.begin(),nums.end());

        ListNode* temp = head;
        vector<int> component = {};
        int ans = 0;

        while(temp){
            if(els.find(temp->val) != els.end()){
                component.push_back(temp->val);
            }else{
                if(component.size() != 0) {
                    ans++;
                    component.clear();
                }
            }
            temp= temp->next;
        }
        if(component.size() != 0) ans++;
        return ans;
    }
};
int main (){

}