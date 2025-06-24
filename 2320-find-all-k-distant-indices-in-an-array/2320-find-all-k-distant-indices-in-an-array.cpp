class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<pair<int,int>> i_s;
        //int prev=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                // if(prev>=it-k){
                //     int st = i_s.back().first;
                //     i_s.pop_back();    
                //     i_s.push_back({max(0,st),min(it+k,n-1)});
                // }
                // else{
                //     i_s.push_back({max(0,it-k),min(it+k,n-1)});
                // }
                // prev = it+k;
                i_s.push_back({max(0,i-k),min(i+k,n-1)});
            }
        }
        
        vector<int> ans(n);
        

        for(int j=0;j<i_s.size();j++){
            //cout<<i_s[j].first<<' '<<i_s[j].second<<endl;
            int st=i_s[j].first;
            int end=i_s[j].second;
            for(int i=st;i<=end;i++){
                ans[i]=1;
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(ans[i]) res.push_back(i);
        }
        return res;

    }
};