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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *it1 = headA;
        ListNode *it2 = headB;
        while (it1 != NULL) {
            lenA++;
            it1 = it1->next;
        }
        while (it2 != NULL) {
            lenB++;
            it2 = it2->next;
        }
        int diff = lenB - lenA;
        it1 = headA;
        it2 = headB;
        if (diff > 0) {
            swap(it1, it2);
        }
        diff = abs(diff);
        for (int i = 0; i < diff; i++) {
            it1 = it1->next;
        }
        while(it1 != it2) {
            it1 = it1->next;
            it2 = it2->next;
        }
        return it1;
    }
};