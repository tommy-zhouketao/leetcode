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
    int findDuplicate(vector<int>& nums) {
        int oneStepIndex = 0;
        int twoStepIndex = 0;
        do {
            oneStepIndex = nums[oneStepIndex];
            twoStepIndex = nums[nums[twoStepIndex]];
        } while (oneStepIndex != twoStepIndex);
        int p = 0;
        int q = oneStepIndex;
        while (p != q) {
            p = nums[p];
            q = nums[q];
        }
        return p;
    }
};