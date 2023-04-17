class Solution {
public:
    
    void finalCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& res, vector<int>& comb){
        if(target==0){
            res.push_back(comb);
            return;
        }
        
        for(int i=ind; i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            comb.push_back(arr[i]);
            finalCombination(i+1,target-arr[i],arr,res,comb);
            comb.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(candidates.begin(),candidates.end());
        finalCombination(0, target, candidates, res, comb);
        return res;
    }
};