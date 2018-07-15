#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *prev = new ListNode(0);
        prev->next = head;
        ListNode *front = prev;
        ListNode *latter = prev;
        for (int i = 0; i < n; i++) {
            front = front->next;
        }
        while (front->next) {
            latter = latter->next;
            front = front->next;
        }
        ListNode *d = latter->next;
        latter->next = latter->next->next;
        delete(d);
        return prev->next;
    }
};