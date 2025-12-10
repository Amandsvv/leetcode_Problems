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
    int getDecimalValue(ListNode* head) {
        string bin = "";
        ListNode* temp = head;
        while (temp) {
            bin += temp->val;
            temp = temp->next;
        }

        int pow = 1;
        int dec = 0;

        for(int i = bin.size()-1; i >= 0; i--){
            int val = pow*(bin[i]- 0 );
            dec+=val;
            pow*=2;
        }

        return dec;
    }
};