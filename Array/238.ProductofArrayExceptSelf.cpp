#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, n = nums.size(), zeroNum = 0;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroNum++;
                continue;
            }
            product *= nums[i];
        }
        if (zeroNum == 0) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    res[i] = product;
                } else {
                    res[i] = product / nums[i];
                }
            }
        } else if (zeroNum == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    res[i] = product;
                } else {
                    res[i] = 0;
                }
            }
        }
        
        return res;
    }
};