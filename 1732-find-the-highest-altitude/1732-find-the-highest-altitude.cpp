class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        vector<int> res(gain.size()+1,0);
        if(gain.size()==1) return max(gain[0],0);
        for(int i=0;i<gain.size();i++){
            res[i+1]=gain[i]+res[i];
        }
        maxi=*max_element(res.begin(),res.end());
        return maxi;
    }
};