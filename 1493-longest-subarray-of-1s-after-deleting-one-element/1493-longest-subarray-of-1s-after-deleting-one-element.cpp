class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int i = 0, j,K=1;
        for (j = 0; j < A.size(); ++j) {
            if (A[j] == 0) K--;
            if (K < 0 && A[i++] == 0) K++;
        }
        return j - i-1;
    }
};