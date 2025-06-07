class TimeMap {
public:
unordered_map <string, vector<pair<string, int>>>  store;
    TimeMap() {
        
    }
    //
    
    void set(string key, string value, int timestamp) {
        //we need store key, value and time stamp 
        store[key].push_back({value, timestamp});

    }
    
    string get(string key, int timestamp) {
        //since the timestamp will be increasung there is no need to sort the vector 
        // instead what you can do is 
      if (store.find(key) == store.end() || store[key].empty()) {
            return ""; // Key doesn't exist or no values stored
        }
        int high = store[key].size()-1;
        int low= 0;
        while(low < high)
        {
            //wer will have different value we need to return the upper bound 
            int mid = low + (high - low) / 2 + 1; // will return the mid and we want it to be right biased
            // the given time stamp at the index  is greater than timestamp 
            // which means we need to look towards the left hand side 
            if(store[key][mid].second > timestamp)
            {
                high = mid-1;
            }
            else
            {
                //possibility of the low becoming the answer
                low= mid;
            }
        }
         if (store[key][low].second > timestamp) {
            return "";
        }

        return store[key][low].first; //we need to return the value at the largest timestamp
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
