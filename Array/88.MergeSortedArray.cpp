#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while(j < n && i < m+j) {
            if (nums2[j] <= nums1[i]) {
                for (int k = m+j; k > i; k--) {
                    nums1[k] = nums1[k-1];
                }
                nums1[i++] = nums2[j++];
            } else {
                ++i;
            }
        }
        while(j < n) {
            nums1[i++] = nums2[j++];
        }
    }
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};