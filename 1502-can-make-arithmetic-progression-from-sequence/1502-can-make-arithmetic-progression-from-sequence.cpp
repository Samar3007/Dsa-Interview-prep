class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size()-1;
        int i=0;
        int diff=arr[i+1]-arr[i];
        i++;n--;
        while(n){
            if(arr[i+1]-arr[i]==diff){
                n--;i++;
                continue;
            }
            else 
                return false;
        }
        return true;
    }
};