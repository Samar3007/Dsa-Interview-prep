class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        double diag=0.0, maxiDiag=0, prevDiag=0;
        int maxiArea=0;

        for(auto it:d){
            diag=pow(it[0],2)+pow(it[1],2);
            diag=sqrt(diag);
            if(diag>maxiDiag){
                maxiDiag=diag;
                int area=it[0]*it[1];
                maxiArea=area;
            }
            else if(diag==maxiDiag){
                int area=it[0]*it[1];
                maxiArea=max(maxiArea,area);
            }
        }
        return maxiArea;
    }
};