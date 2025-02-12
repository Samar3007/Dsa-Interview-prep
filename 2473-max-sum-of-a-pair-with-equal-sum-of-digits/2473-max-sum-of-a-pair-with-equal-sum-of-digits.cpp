class Solution {
public:
    int add(int num){
        int sum = 0;
        while(num){
            sum = sum+(num%10);
            num = num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,multiset<int, greater<int>>> mpp;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = add(nums[i]);
            mpp[sum].insert(nums[i]);
        }
        int maxi = -1;
        for(auto it:mpp){
            cout<<it.first<<" "<<it.second.size()<<endl;
            if(it.second.size()>1){
                maxi = max(maxi,*it.second.begin()+*next(it.second.begin(),1));
            }
        }
        return maxi;
    }
};