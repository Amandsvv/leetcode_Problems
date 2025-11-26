#include<iostream>
#include<vector>
using namespace std;


//  * Definition for singly-linked list.
 struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* head2 = nullptr;
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* newNode = new ListNode(temp->val);
            if(head2 == nullptr){
                head2 = newNode;
            }else{
                newNode -> next = head2;
                head2 = newNode;
            }
            temp = temp->next;
        }
        return head2;
    }
};

int main (){

}