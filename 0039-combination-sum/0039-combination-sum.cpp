class Solution {
public:
    void find(int ind, vector<int>& arr, vector<vector<int>>& res, vector<int>& combination, int target){
        if(ind==arr.size()){
            if(target==0){
                res.push_back(combination);
            }
            return;
        }
        
        //picking
        if(arr[ind]<=target){
            combination.push_back(arr[ind]);
            find(ind, arr, res, combination, target-arr[ind]);
            combination.pop_back();
        }
        
        
        //not picking
        find(ind+1, arr, res, combination, target);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        find(0, candidates, res, combination, target);
        
        return res;
    }
};