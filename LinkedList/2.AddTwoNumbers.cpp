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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *it1 = l1;
        ListNode *it2 = l2;
        int carry = 0;

        do {
            it1->val += it2->val + carry;
            if (it1->val >= 10) {
                it1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            if (carry) {
                if (it2->next == NULL) {
                    while (carry) {
                        if (it1->next == NULL) {
                            it1->next = new ListNode(1);
                            carry = 0;
                        } else {
                            it1->next->val += 1;
                            if (it1->next->val >= 10) {
                                it1->next->val %= 10;
                                carry = 1;
                                it1 = it1->next;
                            } else {
                                carry = 0;
                            }
                        }
                    }
                    break;
                }
                if (it1->next == NULL) {
                    it1->next = new ListNode(1);
                    carry = 0;
                }
            } else {
                if (it1->next == NULL) {
                    it1->next = it2->next;
                    break;
                }
            }
            it1 = it1->next;
            it2 = it2->next;
        } while (it2 && it1);

        
        return l1;
    }
};