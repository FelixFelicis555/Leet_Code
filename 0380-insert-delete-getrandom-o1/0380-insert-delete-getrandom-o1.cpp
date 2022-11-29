class RandomizedSet {
public:
    vector<int>data;
    unordered_map<int,int>mp;
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(mp.count(val))
         return false;
        data.push_back(val);
        mp[val]=data.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)==0)
            return false;
        mp[data.back()]=mp[val];
        data[mp[val]]=data.back();
        data.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return data[rand() % (data.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */