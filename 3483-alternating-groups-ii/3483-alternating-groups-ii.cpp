class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, cnt = 1;
        for(int right=1;right<n+k-1;right++){
            if(colors[right%n]!=colors[(right-1)%n]) cnt++;
            else cnt=1;
            if(cnt >= k) ans++;
        }
        return ans;
    }
};