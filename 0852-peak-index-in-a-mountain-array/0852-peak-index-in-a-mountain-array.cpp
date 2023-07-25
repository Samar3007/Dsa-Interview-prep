class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=-1, ans=0, ind=0;
        for(;ind<arr.size();ind++){
            if(arr[ind]>maxi){
                maxi=arr[ind];
                ans=ind;
            }
        }
        return ans;
    }
};