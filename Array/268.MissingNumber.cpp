#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int newLen = len + 1;
        int prev, temp;
        nums.push_back(-1);
        for (int start=0; start < newLen; start++) {
            if (nums[start] == start) {
                continue;
            }
            prev = nums[start];
            if (prev == -1) {
                continue;
            }
            do {
                temp = nums[prev];
                nums[prev] = prev;
                prev = temp;
            } while (temp != -1 && temp != nums[temp]);
        }
        
        for (int i = 0; i < newLen; i ++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return 0;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int expect = (1 + n) * n / 2;
        return expect - sum;
    }
};

