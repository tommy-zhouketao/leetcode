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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *odd = head;
        ListNode *even = odd->next;
        ListNode *temp;
        while (even != NULL && even->next != NULL) {
            temp = even->next;
            even->next = even->next->next;

            temp->next = odd->next;
            odd->next = temp;

            odd = odd->next;
            even = even->next;
        }
        return head;
    }
};