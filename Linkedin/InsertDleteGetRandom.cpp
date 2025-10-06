class RandomizedCollection {
public:
    vector <int> arr;
    unordered_map <int, unordered_set <int>> pos;
    //val-> set of indices
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        arr.push_back(val);
        int index = arr.size()-1;
        pos[val].insert(index);
        return pos[val].size() ==1;
    }
    
    bool remove(int val) {
        auto it =pos.find(val);
        if(it == pos.end() || it->second.empty())
        {
            return false;
        }
        int i = *it->second.begin();
        int lastIdx = (int)arr.size()-1;
        int lastVal = arr[lastIdx];

        if(i != lastIdx)
        {
            arr[i] = lastVal;
            pos[lastVal].erase(lastIdx);
            pos[lastVal].insert(i);
        }

        //tidy up
        it->second.erase(i);
        arr.pop_back();
        if (it->second.empty()) pos.erase(it);
        return true;
    }
    
    int getRandom() {
        int r = rand()%  (int)arr.size();
        return arr[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
