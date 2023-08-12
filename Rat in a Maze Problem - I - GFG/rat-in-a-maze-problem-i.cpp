//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> &m, int n, vector<vector<int>> &vis, int row, int col, string s, vector<string>& ans){
        if(row==n-1 && col==n-1){
            ans.push_back(s);
            return;
        }
        if((row+1)<n && vis[row+1][col]!=1 && m[row+1][col]==1){
            vis[row][col]=1;
            solve(m,n,vis,row+1,col,s+'D',ans);
            vis[row][col]=0;
        }
        if((col-1)>=0 && vis[row][col-1]!=1 && m[row][col-1]==1){
            vis[row][col]=1;
            solve(m,n,vis,row,col-1,s+'L',ans);
            vis[row][col]=0;
        }
        if((col+1)<n && vis[row][col+1]!=1 && m[row][col+1]==1){
            vis[row][col]=1;
            solve(m,n,vis,row,col+1,s+'R',ans);
            vis[row][col]=0;
        }
        if((row-1)>=0 && vis[row-1][col]!=1 && m[row-1][col]==1){
            vis[row][col]=1;
            solve(m,n,vis,row-1,col,s+'U',ans);
            vis[row][col]=0;
        }
    
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<string> ans;
        if(m[0][0]) solve(m,n,vis,0,0,"",ans);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends