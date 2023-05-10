class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num=n*n;
        int st=1;
        vector<vector<int>> ans(n, vector<int> (n,0));
        if(n==0) return ans;
        int left=0, right=n-1, top=0,bottom=n-1;
        int x=1;
        while(num>0){
            if(x==1){
                for(int i=top;i<=right;i++){
                    ans[top][i]=st++;
                    num--;
                    x=2;
                }
                top++;
            }
            else if(x==2){
                for(int i=top;i<=bottom;i++){
                    ans[i][right]=st++;
                    num--;
                    x=3;
                }
                right--;
            }
            else if(x==3){
                for(int i=right;i>=left;i--){
                    ans[bottom][i]=st++;
                    num--;
                    x=4;
                }
                bottom--;
            }
            else if(x==4){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=st++;
                    num--;
                    x=1;
                }
                left++;
            }
        }
        return ans;
    }
};