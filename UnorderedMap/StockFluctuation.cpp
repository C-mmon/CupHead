class StockPrice {
public:
unordered_map<int,int> timeToPrice;
int latestTimeStamp;
map <int, int> priceToCount;
    StockPrice() {
        latestTimeStamp =INT_MIN;
    }
    
    void update(int timestamp, int price) {
        if(timeToPrice.find(timestamp)!= timeToPrice.end())
        {
            int prevStockVal = timeToPrice[timestamp];
            priceToCount[prevStockVal]--;
            if(priceToCount[prevStockVal] == 0)
            {
                priceToCount.erase(prevStockVal);
            }
        }
        timeToPrice[timestamp] = price;
        priceToCount[price]++;
        latestTimeStamp= max(timestamp, latestTimeStamp);
    }
    
    int current() {
        return timeToPrice[latestTimeStamp];
    }
    
    int maximum() {
        auto it = --priceToCount.end();
        return it->first;
    }
    
    int minimum() {
        auto it= priceToCount.begin();
        return it->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
