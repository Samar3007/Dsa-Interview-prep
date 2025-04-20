class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        unordered_map<int,int> mpp;
        for(int it:answers){
            if(it==0) ans++;
            else{
                if(mpp[it]==0) ans+=it+1;
                mpp[it]++;
                if(mpp[it]==it+1) mpp[it]=0;
            }
        }
        return ans;
    }
};