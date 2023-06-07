//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int vec[2361]={0};
        for(int i=0;i<n;i++){
            vec[arr[i]]++;
            vec[dep[i]+1]-=1;
        }
        
        for(int j=1;j<2361;j++){
            vec[j]+=vec[j-1];
            
        }
        int maxi=vec[0];
        for(int i=1;i<2361;i++){
            maxi=max(vec[i],maxi);
            
        }
    	
    	
    	
    	
    	return maxi;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends