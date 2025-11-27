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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool hasCycle = false;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                hasCycle = true;
                break;
            }
        }

        if(hasCycle){
            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }

        return NULL;
    }
};

int main (){

}