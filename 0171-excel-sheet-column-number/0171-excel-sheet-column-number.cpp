class Solution {
public:
    int titleToNumber(string columnTitle) {
        int num=0;
        for(char c:columnTitle){
            int val=c-'A'+1;
            num=num*26+val;
        }
        return num;
    }
};