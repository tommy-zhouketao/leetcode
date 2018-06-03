#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // O(n) solution
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> maxSubSum(nums); // To record largest sum of contiguous subarray which is begin with the index 
        int maxSum = nums[len-1];
        
        for (int i=nums.size()-2; i>=0; i--) {
            if (maxSubSum[i+1] > 0) {
                maxSubSum[i] += maxSubSum[i+1];
            }
            if (maxSubSum[i] > maxSum) {
                maxSum = maxSubSum[i];
            }
        }

        return maxSum;
    }
};