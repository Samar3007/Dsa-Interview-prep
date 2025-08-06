class Solution {
public:
    void buildTree(int i, int l, int r, vector<int> &segTree, vector<int> &num){
        if(l==r){
            segTree[i]=num[r];
            return;
        }
        
        int mid = (l+r)/2;
        
        buildTree(2*i+1,l,mid,segTree,num);
        buildTree(2*i+2,mid+1,r,segTree,num);
        
        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
    }

    
    bool query(int i, int l, int r, int val, vector<int> &segTree){
        if(val>segTree[i]) return false;

        if(l==r){
                segTree[i]=-1;
                return true;
        }
        
        int mid=(l+r)/2;
        
        bool left=false, right= false;
        
        
        if(segTree[2*i+1]>=val) left = query(2*i+1, l, mid, val, segTree);
        else right = query(2*i+2, mid+1, r, val, segTree);
        
        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
        return left || right;
    }

    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n=b.size();
        vector<int> segTree(4*n);
        buildTree(0,0,n-1,segTree,b);
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            bool val = query(0,0,n-1,f[i],segTree);
            if(!val) ans++;
        }
        return ans;
    }
};