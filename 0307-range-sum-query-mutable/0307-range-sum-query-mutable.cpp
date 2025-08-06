class NumArray {
public:
    vector<int> num, segTree;
    void buildTree(int i, int l, int r, vector<int> &segTree, vector<int> &num){
        if(l==r){
            segTree[i]=num[r];
            return;
        }
        
        int mid = (l+r)/2;
        
        buildTree(2*i+1,l,mid,segTree,num);
        buildTree(2*i+2,mid+1,r,segTree,num);
        
        segTree[i] = segTree[2*i+1]+segTree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        num=nums;
        int n=nums.size();
        segTree.resize(4*n);
        buildTree(0,0,nums.size()-1,segTree,num);
    }
    
    void updateTree(int ind, int val, int i, int l, int r, vector<int> &segTree, vector<int> &num){
        if(l==r){
            segTree[i]=val;
            return;
        }
        
        int mid = (l+r)/2;
        
        if(ind<=mid) updateTree(ind,val,2*i+1,l,mid,segTree,num);
        else updateTree(ind,val,2*i+2,mid+1,r,segTree,num);
        
        segTree[i] = segTree[2*i+1]+segTree[2*i+2];
    }

    void update(int index, int val) {
        num[index]=val;
        updateTree(index, val, 0, 0, num.size()-1, segTree, num);
    }
    
    int query(int i, int l, int r, int st, int end, vector<int> &segTree){
        if(l>end || r<st) return 0;
        if(l>=st && r<=end) return segTree[i];
        int mid=(l+r)/2;
        int left = query(2*i+1, l, mid, st, end, segTree);
        int right = query(2*i+2, mid+1, r, st, end, segTree);
        return left+right;
    }

    int sumRange(int left, int right) {
        return query(0,0,num.size()-1,left,right,segTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */