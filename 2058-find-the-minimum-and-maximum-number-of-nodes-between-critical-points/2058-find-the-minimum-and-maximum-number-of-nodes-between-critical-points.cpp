/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idxs;
        int prevNV = head->val;
        ListNode* temp = head->next;
        int idx = 1;
        while (temp->next) {
            int nextNV = temp->next->val;
            if (temp->val < prevNV && temp->val < nextNV) {
                idxs.push_back(idx);
            }
            if (temp->val > prevNV && temp->val > nextNV) {
                idxs.push_back(idx);
            }
            cout<<endl;
            prevNV = temp->val;
            temp = temp->next;
            idx++;
        }

        int sz = idxs.size();
        if (sz <= 1)
            return {-1, -1};
        
        int mn = INT_MAX, mx = idxs[sz-1] - idxs[0];
        for(int i = 1; i < sz; i++){   
            mn = min(mn, idxs[i] - idxs[i-1]);
        }
        return {mn, mx};
    }
};