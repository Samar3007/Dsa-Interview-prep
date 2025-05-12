class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=k && j!=k && i!=j){
                        int num=digits[i]*100+digits[j]*10+digits[k];
                        if(num>=100 && num%2==0) st.insert(num);
                    }
                }
            }
        }
        
        vector<int> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};