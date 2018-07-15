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

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        // Finding the rear node of front half on list
        ListNode* iterator = head;
        int count = 0;
        while (iterator != NULL) {
            count++;
            iterator = iterator->next;
        }
        int half = count/2;
        int i = 1;
        iterator = head;
        while (i < half) {
            iterator = iterator->next;
            i++;
        }
        // Dividing list into two parts
        ListNode *latterHead = iterator->next;
        if (count % 2) {
            ListNode *d = latterHead;
            latterHead = latterHead->next;
            delete(d);
        }
        iterator->next = NULL;
        // Reversing the front half
        ListNode *frontRear = reverseList(head);
        // Comparing two list whether if is equivalence
        while (frontRear != NULL && latterHead != NULL && frontRear->val == latterHead->val) {
            frontRear = frontRear->next;
            latterHead = latterHead->next;
        }
        while (frontRear != NULL || latterHead != NULL) {
            return false;
        }
        return true;
    }
};