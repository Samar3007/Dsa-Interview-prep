class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.length(), n=needle.length();
        int ans=-1;

        for (int i = 0; i <= h - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};
