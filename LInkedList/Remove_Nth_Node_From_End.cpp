#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        int idx = 0;
        ListNode *prev = nullptr;
        temp = head;
        while (temp)
        {
            if (idx == count - n)
            {
                if (!prev)
                {
                    return head->next;
                }
                else
                {
                    prev->next = temp->next;
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
            idx++;
        }
        return head;
    }
};
int main()
{
}