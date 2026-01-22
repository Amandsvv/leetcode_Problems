#include<iostream>
#include<vector>

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
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head || !head->next || k == 0) return head;
       vector<int> nums = {};
        ListNode* temp = head;

       while(temp){
           nums.push_back(temp->val);
           temp = temp->next; 
       } 

       int n = nums.size();
       k = k % n;
       int idx = n-k;
        if(k == 0) return head;

       ListNode* rotatedList = new ListNode(0);
       temp = rotatedList;

       for(int i = idx; i < n; i++){
            ListNode* newNode = new ListNode(nums[i]);
            temp->next = newNode;
            temp = temp->next;
       }

       for(int i = 0; i < idx; i++){
            ListNode* newNode = new ListNode(nums[i]);
            temp->next = newNode;
            temp = temp->next;
       }
       return rotatedList->next;
    }
};

int main(){
 return 0;
}
