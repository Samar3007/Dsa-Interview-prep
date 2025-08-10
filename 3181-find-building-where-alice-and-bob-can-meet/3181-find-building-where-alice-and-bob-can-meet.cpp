class Solution {
public:
    void buildTree(int i, int l, int r, vector<int>& heights, vector<int>& segTree){
        if(l==r){
            segTree[i]=l;
            return;
        }
        int mid=(l+r)/2;
        buildTree(2*i+1,l,mid,heights,segTree);
        buildTree(2*i+2,mid+1,r,heights,segTree);
        
        int left=segTree[2*i+1];
        int right=segTree[2*i+2];

        if(heights[left]>=heights[right]){
            segTree[i]=left;
        }
        else segTree[i]=right;
    }

    int query(int i, int l, int r, int st, int end, vector<int>& heights, vector<int>& segTree){
        if(l>end || r<st) return -1;
        if(st<=l && r<=end) return segTree[i];
        
        int mid=(l+r)/2;
        int left=query(2*i+1,l,mid,st,end,heights,segTree);
        int right=query(2*i+2,mid+1,r,st,end,heights,segTree);
        
        if(left==-1){
            return right;
        }
        if(right==-1){
            return left;
        }
        int res=0;
        if(heights[left]>=heights[right]){
            res=left;
        }
        else res=right;
        return res;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        vector<int> segTree(4*n);
        buildTree(0,0,n-1,heights,segTree);
        
        vector<int> ans;
        
        for(auto it:queries){
            int maxInd=max(it[0],it[1]);
            int minInd=min(it[0],it[1]);
            
            if(minInd==maxInd){
                ans.push_back(minInd);
            }

            else if(heights[maxInd]>heights[minInd]){
                ans.push_back(maxInd);
            }

            else{
                int l=maxInd+1, r=n-1;
                int resInd=INT_MAX;
               
                while(l<=r){
                    int mid=(l+r)/2;
                    int ind=query(0,0,n-1,l,mid,heights,segTree);
                    
                    if(heights[ind] > max(heights[minInd],heights[maxInd])){
                        r=mid-1;
                        resInd=min(resInd,ind);
                    }
                    else{
                        l=mid+1;
                    }
                } 

                if(resInd!=INT_MAX) ans.push_back(resInd);
                else ans.push_back(-1);
            }

        }

        return ans;
    }
};