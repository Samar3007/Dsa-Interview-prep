class SnapshotArray {
public:
    vector<map<int,int>> Arr;
    int s_id=0;
    SnapshotArray(int length) {
        Arr.resize(length);
        for(int i=0;i<length;i++){
            Arr[i][0]=0;
        }
        return;
    }
    
    void set(int index, int val) {
        Arr[index][s_id]=val;
        return;
    }
    
    int snap() {
        s_id++; 
        return s_id-1;
    }
    
    int get(int index, int snap_id) {
        if(Arr[index].find(snap_id)==Arr[index].end()){
            auto it = --Arr[index].lower_bound(snap_id);
            return it->second;
        }
        return Arr[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */