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
    ListNode* oddEvenList(ListNode* head) {
        // dummy heads
        ListNode* smallDummy = new ListNode(0);
        ListNode* bigDummy   = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* big   = bigDummy;

        ListNode* temp = head;
        int count = 1;
        while (temp) {

            if (count % 2 != 0) {
                small->next = temp;
                small = small->next;
            } else {
                big->next = temp;
                big = big->next;
            }

            temp = temp->next;
            count++;
        }

        // end big list
        big->next = nullptr;

        // join both lists
        small->next = bigDummy->next;

        return smallDummy->next;
    }
};

int main (){

}