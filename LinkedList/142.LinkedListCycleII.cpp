#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       if (head == NULL || head->next == NULL) {
           return NULL;
       }
       ListNode *oneStep = head->next;
       ListNode *twoStep = head->next->next;
       while (oneStep != twoStep) {
           if (twoStep == NULL) {
               return NULL;
           }
           oneStep = oneStep->next;
           twoStep = twoStep->next->next;
       }
       ListNode *p = head;
       ListNode *q = oneStep;
       while (p != q) {
           p = p->next;
           q = q->next;
       }
       return p;
    }
};