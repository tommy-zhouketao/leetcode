#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        vector<int>::iterator it = nums.begin();
        vector<int>::iterator front = it++;
        while (it != nums.end()) {
            if (*it == *front) {
                it = nums.erase(it);
            } else {
                front = it++;
            }
        }
        return nums.size();
    }
};