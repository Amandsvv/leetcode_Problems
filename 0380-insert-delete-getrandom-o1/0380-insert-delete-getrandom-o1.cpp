class RandomizedSet {
public:
    unordered_map<long long, int> mp;
    vector<long long> vec;
    RandomizedSet() {
        
    }
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }else{
            vec.push_back(val);
            int pos = vec.size()-1;
            mp[val] = pos;
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int pos = mp[val]; // current position of val
            int sz = vec.size() - 1; // last idx of vector
            mp[vec[sz]] = pos; // update position of last value
            swap(vec[pos], vec[sz]); // swap both 
            vec.pop_back(); // pop val
            mp.erase(val); // delete from map
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        int idx = rand() % vec.size();
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */