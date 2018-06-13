#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        for (int i = 1; i <= numRows; i++) {
            triangle[i-1].resize(i);
            triangle[i-1][0] = 1;
            triangle[i-1][i-1] = 1;
            for (int j = 1; j <= i - 2; j++) {
                triangle[i-1][j] = triangle[i-2][j-1] + triangle[i-2][j];
            }
        }
        return triangle;
    }
};