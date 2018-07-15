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
    void insert(ListNode *p, ListNode *q) {
        if (p != NULL) {
            q->next = p->next;
            p->next = q;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val > l2->val) {
            swap(l1, l2);
        }
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *temp;
        while (q != NULL) {
            if (p->next == NULL || p->next->val > q->val) {
                temp = q;
                q = q->next;
                insert(p, temp);
            }
            p = p->next;
        }
        return l1;
    }
};