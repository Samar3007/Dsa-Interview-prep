class Solution {
public:
    vector<int> partitionLabels(string s) {
        int maxi = INT_MIN, n = s.length();
        vector<int> ans;
        vector<pair<int,int>> ind(26,{-1,-1});
        for(int i=0;i<n;i++){  
            int curr = s[i]-'a';
            if(ind[curr].first == -1){
                ind[curr].first = i;
                ind[curr].second = i;
            }
            else{
                ind[curr].second = i;
            }
        }
        
        int prev = -1;
        for(int i=0;i<n;i++){
            maxi = max(maxi,ind[s[i]-'a'].second);
            if(i==maxi){
                int len = i-prev;
                ans.push_back(len);
                prev=i;
            }
        }
        return ans;
    }
};