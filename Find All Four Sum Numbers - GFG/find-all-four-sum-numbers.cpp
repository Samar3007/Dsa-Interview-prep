//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1, r=n-1;
                long long int sum=0;
                sum+=nums[i];
                sum+=nums[j];
                long long int rem=target-sum;
                
                while(l<r){
                    long long int curr=nums[l]+nums[r];
                    if(curr==rem){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int tempIndex1 = l, tempIndex2 = r;
                        while(l < r && nums[l] == nums[tempIndex1]) l++;
                        while(l < r && nums[r] == nums[tempIndex2]) r--;
                    }
                    else if(curr>rem) r--;
                    else l++;
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends