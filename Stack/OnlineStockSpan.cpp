    stack<pair<int, int>> st;
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        {
            st.push({price, span});
            return span;
        }
    }
    };

class StockSpanner {
public:
    vector<int> prices;
    vector<int> spans;

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;
        int i = prices.size() - 1;

        while (i >= 0 && prices[i] <= price) {
            span += spans[i];   // Jump over previous spans
            i -= spans[i];      // Skip previous dominated prices
        }

        prices.push_back(price);
        spans.push_back(span);
        return span;
    }
};
