class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff2=abs(z-y), diff1=abs(z-x);
        if(diff2==diff1) return 0;
        else if(diff2<diff1) return 2;
        return 1;
    }
};