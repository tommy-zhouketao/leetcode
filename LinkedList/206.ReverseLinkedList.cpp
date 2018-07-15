#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution { // recursive solution
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // Definition for head on sub list without the current one.
        ListNode *subHead = head->next;
        // Get result of sub list
        ListNode *res = reverseList(subHead);
        // The old Head is tail of new list. 
        head->next = NULL;
        subHead->next = head;
        return res;
    }
};

class Solution2 { // iterative solution
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *cur = NULL;
        while (temp != NULL) {
            cur = temp->next;
            temp->next = prev;
            prev = temp;
            temp = cur;
        }
        return prev;
    }
};