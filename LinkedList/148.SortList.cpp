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
        q->next = p->next;
        p->next = q;
    }

    ListNode* insertSort(ListNode* head, ListNode *other) {
        if (other == NULL) {
            return head;
        }
        if (head == NULL) {
            return other;;
        }
        if (other->val < head->val) {
            swap(head, other);
        }
        ListNode *p = head;
        ListNode *q = other;
        ListNode *t = nullptr;
        while (q) {
            if (p->next == NULL || p->next->val > q->val) {
                t = q;
                q = q->next;
                insert(p, t);
            }
            p = p->next;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *left = head;
        ListNode *right = head->next;

        while (right->next != NULL && right->next->next != NULL) {
            left = left->next;
            right = right->next->next;
        }
        
        ListNode *latter = left->next;
        left->next = nullptr;
        
        return insertSort(sortList(head), sortList(latter));
    }
};