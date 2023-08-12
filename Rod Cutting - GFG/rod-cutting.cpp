//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int cutRod(int price[], int n) {
        vector<int> prev(n+1,0);
        
        for(int T=0;T<=n;T++){
            prev[T]=T*price[0];
        }
        
        for(int ind=1;ind<n;ind++){
            
            vector<int> curr(n+1,0);
            
            for(int T=0;T<=n;T++){
                
                int notTake =  0 + prev[T];
                int take = INT_MIN, rod_len=ind+1;
                if(rod_len<=T){
                   take=price[ind] + curr[T-rod_len];
                }

                curr[T] = max(take,notTake);
            }
            prev=curr;
        }
        return prev[n];
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