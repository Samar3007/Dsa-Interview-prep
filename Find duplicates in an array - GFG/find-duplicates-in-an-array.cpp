//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> vec(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            vec[arr[i]]=vec[arr[i]]+1;
            if(vec[arr[i]]>1 && vec[arr[i]]<3){
                ans.push_back(arr[i]);
            }
        }
        if(ans.empty()) return {-1};
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends