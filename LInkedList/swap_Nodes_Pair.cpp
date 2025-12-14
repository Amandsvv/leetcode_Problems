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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev = NULL;

        while (fast && slow) {
            ListNode* nextPair = fast->next;

            if (slow == head) {
                head = fast;
            } else {
                prev->next = fast;
            }

            slow->next = fast->next;
            fast->next = slow;

            prev = slow;
            slow = nextPair;

            if(slow){
                fast = slow->next;
            }else{
                fast = NULL;
            }
        }
        return head;
    }
};