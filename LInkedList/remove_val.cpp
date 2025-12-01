#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            if(temp->val == val){
                if(!prev) head = temp->next;
                else prev->next = temp->next;
                temp=temp->next;
                continue;
            }
            prev = temp;
            temp=temp->next;
        }
        return head;
    }
};

int main (){

}