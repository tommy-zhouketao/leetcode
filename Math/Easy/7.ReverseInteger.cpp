#include <iostream>
using namespace std;

// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:
// Input: 123
// Output:  321

// Example 2:
// Input: -123
// Output: -321

// Example 3:
// Input: 120
// Output: 21

// Note:
// Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

class Solution {
public:
    int reverse(int x) {
        int sign, num, res = 0;
        if (x > 0) {
            sign = 0;
            num = x;
        } else {
            sign = 1;
            num = -x;
        }

        while (num) {
            if (res * 10 / 10 != res) { // judge overflow for multiplication
                return 0;
            }
            res *= 10;
            int rem = num % 10;
            num /= 10;
            if (res > 0 && res + rem < 0) { // judge overflow for addition
                return 0;
            }
            if (res < 0 && res + rem > 0) { // judge overflow for addition
                return 0;
            }
            res += rem;
        }
        return sign ? -res : res;
    }
};