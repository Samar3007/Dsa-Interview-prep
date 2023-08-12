//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int T=0;T<=n;T++){
            dp[0][T]=T*price[0];
        }
        
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=n;T++){
                
                int notTake =  0 + dp[ind-1][T];
                int take = INT_MIN, rod_len=ind+1;
                if(rod_len<=T){
                   take=price[ind] + dp[ind][T-rod_len];
                }

                dp[ind][T] = max(take,notTake);
            }
        }
        return dp[n-1][n];
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