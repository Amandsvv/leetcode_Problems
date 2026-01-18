#incklude<iostream>
using namespace std;

class Solution{
public:
  if(!head || !head->next || left == right) return head;
  ListNode dummy(0);
  ListNode* prev = &dummy;  
  for(int i = 1; i < left; i++){
    prev = prev->next;
  } 
  ListNode* curr = prev->next;
  ListNode* nxt = NULL;
  
  for(int i =  0;i < right -left; i++){
    nxt = curr->next;
    curr->next = nxt->next;
    nxt->next = prev->next;
    prev->next = nxt;
  }
  return dummy.next;
};
