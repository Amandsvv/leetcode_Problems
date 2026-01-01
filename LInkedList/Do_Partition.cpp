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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);

        // Step 1: Count length
        int N = 0;
        ListNode* temp = head;
        while (temp) {
            N++;
            temp = temp->next;
        }

        // Step 2: Calculate size
        int base = N / k;
        int extra = N % k;

        temp = head;
        for (int i = 0; i < k && temp; i++) {
            ans[i] = temp;
            int currSize = base + (extra-- > 0 ? 1 : 0);

            // Move to end of this part
            for (int j = 1; j < currSize; j++) {
                temp = temp->next;
            }

            // Cut the list
            ListNode* nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }

        return ans;
    }
};

int main (){

}