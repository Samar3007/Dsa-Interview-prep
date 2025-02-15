class Solution {
public:

    bool solve(string s, int target)
    {
        if (s == "" && target == 0) return true;
        if (target < 0) return false;
        
        bool ans = false;
        for (int i = 0; i < s.size(); i++)
        {
            string left = s.substr(0, i + 1);
            string right = s.substr(i + 1);
            int leftNum = stoi(left);
            
            bool isPossible = solve(right, target - leftNum);
            if (isPossible) {
                ans = true;
                break;
            }
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int maxi = 0;
        int i = 1;
        for(i;i<=n;i++){
            int sqr = i*i;
            if(solve(to_string(sqr),i)) maxi += sqr;
        }
        return maxi;
    }
};