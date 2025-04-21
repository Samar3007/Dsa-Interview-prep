class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        int arr[1000]={0};
        for(int it:answers){
            if(arr[it]++%(it+1) == 0) ans+=it+1;
        }
        return ans;
    }
};