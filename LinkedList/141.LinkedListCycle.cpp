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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *oneStep = head->next;
        ListNode *twoStep = head->next->next;
        while (oneStep != twoStep) {
            if (twoStep == NULL || twoStep->next == NULL) {
                return false;
            }
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }
        return true;
    }
};