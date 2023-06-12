class SnapshotArray {
public:
    map<int,map<int,int>>m;
    int s=0;
    vector<int>v;
    SnapshotArray(int length) {
        for(int i=0;i<length;i++)
            v.push_back(0);
    }
    
    void set(int index, int val) {
        v[index]=val;
        m[index][s]=val;
    }
    
    int snap() {
        s++;
        return s-1;
    }
    
    int get(int index, int snap_id) {
        if(m.find(index)==m.end())
            return 0;
        auto it=m[index].upper_bound(snap_id);
        if(it==m[index].begin())
            return 0;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */