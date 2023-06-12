class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int count=0;      
        
        for(int s:gain){
            count+=s;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};