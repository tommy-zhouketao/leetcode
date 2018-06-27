#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> exist;
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            if (exist.find(nums[i]) != exist.end()) {
                return true;
            }
            exist[nums[i]] = true;
        }
        return false;
    }
};