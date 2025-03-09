class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int left = 0, right = 0, cnt = 0;
        for(right;right<n+k-1;right++){
            if(right>0 && colors[right%n]==colors[(right-1)%n]){
                left = right;
            }
            if(right-left >= k-1) cnt++;
        }
        return cnt;
    }
};