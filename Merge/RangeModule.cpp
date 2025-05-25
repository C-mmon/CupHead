class RangeModule {
public:
map <int,int> range;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        //check for the lower bound 
        auto it = range.lower_bound(left);
        if(it !=  range.begin() && prev(it)->second >= left)
        {
            --it;
        }
        while(it != range.end() && it->first <= right)
        {
            left = min(left, it->first);
            right = max(right, it->second);
            it= range.erase(it);
        }
        range[left]= right;
    }
    
    bool queryRange(int left, int right) {
        auto it = range.lower_bound(left);

if (it != range.end() && it->first == left) {
    // The interval starts exactly at 'left'
    return it->second >= right;
}

if (it == range.begin()) {
    // No interval before 'left'
    return false;
}

--it; // Go to the previous interval
return it->first <= left && it->second >= right;
              
    }
    
    void removeRange(int left, int right) {
                //check for the lower bound 
        auto it = range.lower_bound(left);
        //if the right of the previous range is greater than left
        //its better to choose this 
        //also before decremeneting we need to ensure that the iterator is 
        // not at the begin
        if(it !=  range.begin() && prev(it)->second > left)
        {
            --it;
        }
        //we need to keep eraseing and ensure we dont reach the end 

        // further we need to check if the iterator left value is less than righth
        ///if true it meeans it falls within that range
        while(it != range.end() && it->first < right)
        {
            int start= it->first;
            int end = it->second;
            it= range.erase(it);
            //we need to check if the start value is less than left 
            if(start <  left)
            {
                range[start] = left;
            }
            if(end > right)
            {
                range[right]= end;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
