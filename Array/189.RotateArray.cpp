#include <iostream>
#include <vector>
#include <map>

using namespace std;

// rotate in-place approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int i = 0, temp = 0, len = nums.size();
        int count = 0, start = 0;
        while (count < len) {
            int i = start;
            int pre = nums[start];
            do {
                int j = (i + k) % len;
                temp = nums[j];
                nums[j] = pre;
                pre = temp;
                i = j;
                count ++;
            } while (start != i);
            start++;
        }
    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};