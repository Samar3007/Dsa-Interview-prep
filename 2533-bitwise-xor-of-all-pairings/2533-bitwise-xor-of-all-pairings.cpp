class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1%2==0 && n2%2==0){
            return 0;
        }
        if(n1%2==0){
            for(int i=0;i<n1;i++){
                ans = ans^nums1[i];
            }
        }
        else if(n2%2==0){
            for(int j=0;j<n2;j++){
                ans = ans^nums2[j];
            }
        }
        else{
            for(int i=0;i<n1;i++){
                ans = ans^nums1[i];
            }
            for(int j=0;j<n2;j++){
                ans = ans^nums2[j];
            }
        }

        return ans;
    }
};