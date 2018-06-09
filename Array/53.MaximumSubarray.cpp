#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DivideAndConquer {
public:
    int sum;
    int maxWithBegin;
    int maxWithEnd;
    int maximumSubArray;

    DivideAndConquer(int sum, int maxWithBegin, int maxWithEnd, int maximumSubArray):
        sum(sum), 
        maxWithBegin(maxWithBegin), 
        maxWithEnd(maxWithEnd), 
        maximumSubArray(maximumSubArray)
        {} 
};

class Solution2 {
public:
    DivideAndConquer divideAndConquer(vector<int>& nums) {
        if (nums.size() == 1) {
            return DivideAndConquer(nums[0], nums[0], nums[0], nums[0]);
        }
        vector<int> L(nums.begin(), nums.begin() + nums.size()/2);
        vector<int> R(nums.begin() + nums.size()/2, nums.end());
        DivideAndConquer l = divideAndConquer(L);
        DivideAndConquer r = divideAndConquer(R);

        return DivideAndConquer(
            l.sum + r.sum,
            max(l.maxWithBegin, l.sum + r.maxWithBegin),
            max(r.maxWithEnd, r.sum + l.maxWithEnd),
            max(max(l.maximumSubArray, r.maximumSubArray), l.maxWithEnd + r.maxWithBegin)
            );
    }

    int maxSubArray(vector<int>& nums) {
        DivideAndConquer dc = divideAndConquer(nums);
        return dc.maximumSubArray;
    }
};

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