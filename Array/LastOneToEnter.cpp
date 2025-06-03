If someone just used the door in the previous second (time - 1 == lastUsedTime):
• And the last direction was Exit and there’s still someone waiting to exit, choose Exit.
• Otherwise if no one’s waiting to Enter, you also choose Exit.
• Else choose Enter.

If the door was idle last second, again prefer Exit (but fall back to Enter if Exit is empty).

Whenever you pop from a queue, record prevState (1 for exit, 0 for enter), record lastUsedTime = time, and set result[person] = time.

vector<int> getDoorTimes(vector<int>& arrival, vector<int>& state) {
    int n = arrival.size();
    vector<int> result(n, -1);
    queue<int> enterQ, exitQ;

    int time = 0, idx = 0;
    int prevState = 1;    // 1=exit, 0=enter
    int lastUsedTime = -2;

    while (idx < n || !enterQ.empty() || !exitQ.empty()) {
        // enqueue everyone who has arrived by `time`
        while (idx < n && arrival[idx] <= time) {
            if (state[idx] == 0) enterQ.push(idx);
            else                exitQ.push(idx);
            idx++;
        }

        // decide who goes at `time`
        if (!enterQ.empty() || !exitQ.empty()) {
            bool useExit;
            if (time - 1 == lastUsedTime) {
                // door was used last second → follow prevState if possible
                useExit = (prevState == 1 && !exitQ.empty()) || enterQ.empty();
            } else {
                // door was idle → exit has priority
                useExit = !exitQ.empty();
            }

            int person;
            if (useExit) {
                person = exitQ.front();
                exitQ.pop();
                prevState = 1;
            } else {
                person = enterQ.front();
                enterQ.pop();
                prevState = 0;
            }

            result[person] = time;
            lastUsedTime     = time;
        }

        time++;
    }

    return result;
}
