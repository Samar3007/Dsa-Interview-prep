class Solution {
public:
     int binary(vector<int> m)
    {
        int l = 0;
        int h = m.size()-1;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> cnt;
        for(int i=0;i<mat.size();i++){
            int ones=binary(mat[i]);
            cnt.push({ones,i});
        }
        vector<int> ans;
        
        while(k--){
            ans.push_back(cnt.top().second);
            cnt.pop();
        }
        
        return ans;
    }
};