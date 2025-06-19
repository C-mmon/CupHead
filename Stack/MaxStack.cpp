class MaxStack {
    stack<int> s;
    stack<int> maxs;

public:
    void push(int x) {
        s.push(x);
        if (maxs.empty() || x >= maxs.top())
            maxs.push(x);
        else
            maxs.push(maxs.top());
    }

    int pop() {
        int top = s.top();
        s.pop();
        maxs.pop();
        return top;
    }

    int top() {
        return s.top();
    }

    int peekMax() {
        return maxs.top();
    }

    int popMax() {
        int maxVal = maxs.top();
        stack<int> buffer;

        // Pop until we find the max
        while (s.top() != maxVal) {
            buffer.push(s.top());
            s.pop();
            maxs.pop();
        }

        // Remove the max
        s.pop();
        maxs.pop();

        // Push back remaining elements
        while (!buffer.empty()) {
            push(buffer.top());
            buffer.pop();
        }

        return maxVal;
    }
};
