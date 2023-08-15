//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int arr[n], cnt=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==1){
                cnt++;
                arr[i]=-1;
            }
            else arr[i]=1;
        }
        
        int curr_sum=0;
        int maxi=0;
        
        for(int i =0;i<n;i++){
            curr_sum+=arr[i];
            if(curr_sum<0) curr_sum=0;
            else maxi=max(maxi,curr_sum);
           
        }
        return cnt+maxi;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends