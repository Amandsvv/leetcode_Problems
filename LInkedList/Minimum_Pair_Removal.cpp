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
    ListNode* convertVectorToList(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        ListNode* dummy = new ListNode(0); // Dummy node
        ListNode* current = dummy;

        for (int num : nums) {
            current->next = new ListNode(num);
            current = current->next;
        }

        ListNode* head = dummy->next;
        delete dummy; 
        return head;
    }
    int minimumPairRemoval(vector<int>& nums) {
        ListNode* els = convertVectorToList(nums);
        int count = 0;

        while(true){
            bool sorted = true;
            int sum = INT32_MAX;
            ListNode* temp = els;

            while(temp && temp->next){
                if(temp->val > temp->next->val) sorted = false;
                sum = min(sum, temp->val+ temp->next->val);
                temp = temp->next;
            }
            temp = els;
            ListNode* prev = NULL;
            if(sorted) return count;

            while(temp && temp->next){
                if(temp->val + temp->next->val == sum){
                    ListNode* newNode = new ListNode(sum);
                    if(!prev) els = newNode;
                    else prev->next = newNode;
                    newNode->next = temp->next->next;
                    break;
                }
                prev = temp;
                temp=temp->next;
            }
            count++;
        }
        return count;
    }
};
int main (){

}