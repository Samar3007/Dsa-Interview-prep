class Solution {
public:
   int longestSubarray(vector<int>& A) {

        int i=0,k=1,j=0;
        int res=0;
        for(;j<A.size();j++){
            if(A[j]==0) k--;

            while(k<0){
                if(A[i]==0) k++;
                i++;
            }

            res=max(res,j-i);
        }
        return res;
    }
};

