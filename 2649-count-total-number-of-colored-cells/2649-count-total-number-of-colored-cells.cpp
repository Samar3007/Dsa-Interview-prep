class Solution {
public:
    long long coloredCells(int n) {
        return 1+(n-1)*4LL*n/2;
    }
};