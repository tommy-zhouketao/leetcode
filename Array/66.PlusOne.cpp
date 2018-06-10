#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = len-1; i >= 0; i --) {
            digits[i]++;
            if (digits[i] >= 10) {
                digits[i] = 0;
                continue;
            }
            break;
        }
        vector<int> v(digits);
        if (digits[0] == 0) {
            v.insert(v.begin(), 1);
        }
        return v;
    }
};