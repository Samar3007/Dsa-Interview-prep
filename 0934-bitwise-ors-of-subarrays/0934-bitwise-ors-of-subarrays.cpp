class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, result, curr;
        int n=arr.size();
        prev.insert(arr[0]);
        result.insert(arr[0]);

        for(int i=1;i<n;i++){
            for(int it:prev){
                curr.insert(it|arr[i]);
                result.insert(it|arr[i]);
            }
            result.insert(arr[i]);
            curr.insert(arr[i]);
            prev=curr;
            curr.clear();
        }
        return result.size();
    }
};