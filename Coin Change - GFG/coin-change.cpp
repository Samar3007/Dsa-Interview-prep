//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,0));
        
        for(int T=0;T<=sum;T++){
            if(T%coins[0]==0){
                dp[0][T]=1;
            }
        }
        for(int ind=1;ind<N;ind++){
            for(int T=0;T<=sum;T++){
                long long int take=0, notTake=0;
                notTake=dp[ind-1][T];
                if(coins[ind]<=T) take=dp[ind][T-coins[ind]];
                dp[ind][T]=notTake+take;
            }
        }
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends