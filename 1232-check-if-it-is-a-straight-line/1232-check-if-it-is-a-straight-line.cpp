
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int len=coordinates.size();
        len--;
        int i=0;
        if(len==1 || len==0){
            return true;
        }
        int x2=coordinates[i+1][0];
        int y1=coordinates[i][1];
        int x1=coordinates[i][0];
        int y2=coordinates[i+1][1];
        len--;i++;
        while(len){
            int x=coordinates[i+1][0];
            int y=coordinates[i+1][1];
            
            if((y-y2)*(x-x1)==(x-x2)*(y-y1)){
                i++;len--;continue;
            }
            else{
                return false;
            }
        }       
        return true; 
    }
};