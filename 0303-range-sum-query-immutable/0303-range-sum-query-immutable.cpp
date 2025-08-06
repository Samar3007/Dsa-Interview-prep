class NumArray {
public:
    vector<int> num, segTree;
    NumArray(vector<int>& nums) {
        num=nums;
        int n=nums.size();
        segTree.resize(4*n);
        buildTree(0,0,n-1,segTree,nums);
        for(auto it: segTree){
            cout<<it<<' ';
        }
    }

    void buildTree(int i, int l, int r, vector<int>& segTree, vector<int>& nums){
        if(l==r){
            segTree[i]=nums[r];
            return;
        }
        int mid=(l+r)/2;
        buildTree(2*i+1,l,mid,segTree,nums);
        buildTree(2*i+2,mid+1,r,segTree,nums);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }

    int query(int i, int l, int r, int st, int end, vector<int>& segTree){
        if(l>end || r<st) return 0;
        if(l>=st && r<=end) return segTree[i];
        int mid=(l+r)/2;
        int left = query(2*i+1, l, mid, st, end, segTree);
        int right = query(2*i+2, mid+1, r, st, end, segTree);
        return left+right;
    }

    int sumRange(int left, int right) {
        int n=num.size();
        return query(0, 0, n-1, left, right, segTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */