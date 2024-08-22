class RandomizedCollection {
public:
    map<int,int> mp;
    vector<int> values;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag=false;
        if(mp.find(val)==mp.end()) flag=true;
        mp[val]++;
        values.push_back(val);
        return flag;
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        if (it == mp.end()) return false; 
        
        mp[val]--;
        if (mp[val] == 0) {
            mp.erase(val);
        }
        for(auto x=values.begin();x<=values.end();x++){
            if(*x==val){
                values.erase(x);
                break;
            }
        }
        return true;
    }
    
    int getRandom() {
        int randIndex = rand() % values.size();
        return values[randIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */