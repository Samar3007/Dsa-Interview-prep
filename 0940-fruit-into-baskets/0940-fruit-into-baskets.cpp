class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n=f.size();
        int i=0, st=0, maxi=-1;
        
        int first = -1, second = -1;
        int ind1 = -1, ind2 = -1;
        
        while(i<n){
            if(first==-1 || f[i]==first){
                first=f[i];
                ind1=i;
            }
            else if(second==-1 || f[i]==second){
                second=f[i];
                ind2=i;
            }
            else{
                if(ind1>ind2){
                    st=ind2+1;
                    second=f[i];
                    ind2=i;
                }
                else{
                    st=ind1+1;
                    first=f[i];
                    ind1=i;
                }

            }
            maxi=max(maxi,i-st+1);
            i++;
        }

        return maxi;
    }
};