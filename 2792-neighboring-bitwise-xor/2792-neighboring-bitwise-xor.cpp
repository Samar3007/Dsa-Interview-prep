class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans = derived[0]; 
        for(int i=1;i<n;i++){
           ans=ans^derived[i]; 
        }
        if(ans==0) return true;
        return false;
    }
};