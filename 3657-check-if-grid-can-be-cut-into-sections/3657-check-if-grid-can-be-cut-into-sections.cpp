class Solution {
public:
    bool checkValidCuts(int l, vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<pair<int,int>> x_axis, y_axis;
        for(int i=0;i<n;i++){
            x_axis.push_back({rectangles[i][0],rectangles[i][2]});
            y_axis.push_back({rectangles[i][1],rectangles[i][3]});
        }
        sort(x_axis.begin(),x_axis.end());
        sort(y_axis.begin(),y_axis.end());
        
        int cnt1 = 0, cnt2 = 0, prev_max = x_axis[0].second;
        for(int i=1;i<n;i++){
            if(x_axis[i].first>=prev_max){
                cnt1++;
            }
            prev_max = max(prev_max,x_axis[i].second);
        }
        cout<<cnt1<<cnt2;
        prev_max = y_axis[0].second;
        for(int i=1;i<n;i++){
            if(y_axis[i].first>=prev_max){
                cnt2++;
            }
            prev_max = max(prev_max,y_axis[i].second);
        }
        return cnt1>=2 || cnt2>=2;
    }
};