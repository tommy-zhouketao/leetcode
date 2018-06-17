#include <iostream>
#include <vector>
#include <map>

using namespace std;

// HashMap count approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        int len = nums.size();
        int half = len / 2;
        for (int i = 0; i < len; i++) {
            if (count.find(nums[i]) != count.end()) {
                if (++count[nums[i]] > half) {
                    return nums[i];
                    break;
                }
            } else {
                count[nums[i]] = 1;
            }
        }
        return nums[0];
    }
};

// Divide and Conquer
class Solution2 {
public:
    int count(vector<int>& nums, int left, int right, int number) {
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (nums[i] == number) {
                cnt ++;
            }
        }
        return cnt;
    } 

    int divideAndConquer(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int mid = (right - left) / 2 + left;
        int leftCandidate = divideAndConquer(nums, left, mid);
        int rightCandidate = divideAndConquer(nums, mid+1, right);
        if (leftCandidate == rightCandidate) {
            return leftCandidate;
        }

        int leftCandidateCount = count(nums, left, right, leftCandidate);
        int rightCandidateCount = count(nums, left, right, rightCandidate);
        if (leftCandidateCount > rightCandidateCount) {
            return leftCandidate;
        } 
        return rightCandidate;
    }

    int majorityElement(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size()-1);
    }
};

// Boyer-Moore Voting Algorithm
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        int length = nums.size();
        for (int i = 1; i < length; i ++) {
            if (!count) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count ++;
            } else {
                count --;
            }
        }
        return candidate;
    }
};

