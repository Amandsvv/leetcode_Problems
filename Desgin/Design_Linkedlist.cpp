#include<iostream>
#include<vector>
using namespace std;
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        ListNode* temp = head;
        int i = 0;

        while (temp) {
            if (i == index)
                return temp->val;

            temp = temp->next;
            i++;
        }

        return -1;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);

        if (!head) {
            head = node;
            return;
        }

        ListNode* temp = head;

        while (temp->next) {
            temp = temp->next;
        }

        temp->next = node;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* temp = head;
        int i = 0;

        while (temp && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (!temp) return; // index out of bounds

        ListNode* node = new ListNode(val);

        node->next = temp->next;
        temp->next = node;
    }

    void deleteAtIndex(int index) {
        if (!head) return;

        if (index == 0) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return;
        }

        ListNode* temp = head;
        int i = 0;

        while (temp->next && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (!temp->next) return; // index out of bounds

        ListNode* del = temp->next;
        temp->next = del->next;

        delete del;
    }
};
int main (){

}