//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int ind, int price[], vector<vector<int>>& dp, int n){
        if(ind==0){
            return n*price[0];
        }
        if(dp[ind][n]!=-1) return dp[ind][n];
        int notTake =  0 + solve(ind-1,price,dp,n);
        int take = INT_MIN, rod_len=ind+1;
        
        if(rod_len<=n){
            take=price[ind] + solve(ind,price,dp,n-rod_len);
        }
        
        return dp[ind][n] = max(take,notTake);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,price,dp,n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends