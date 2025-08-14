class Solution {
public:
    string largestGoodInteger(string num) {
        int i=2;
        int maxi=-1;
        while(i<num.size()){
            if(num[i]==num[i-1] && num[i-1]==num[i-2]){
                maxi=max(num[i]-'0',maxi);    
            }
            i++;
        }
        if(maxi==-1) return "";
        return string(3,maxi+'0');
    }
};