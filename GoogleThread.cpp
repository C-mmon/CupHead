// The questions says that we have to build a delayed task scheduler
// Some clarification that you must ask, only one schedule hardware time 
// can be active at a time, parallel execution of callback is allowed, assuming 
// thread pool 
// multiple callback can be scheduled at the same time in future
// whne it fires, we need to figure out what callbacks are ready to run 


#include <map>
#include <vector>
#include <functional>
#include <chrono>
#include <mutex>
#include <thread>
/** 
 * 
 * void greet()
 * { std:: cout << "hello"<<endl;;}
 * 
 * void runAfterDelay(void (*cb)(), int delay)
 * { cb(); ///callback the function  }
**/
using namespace std;
//why we need function void because it can work with lambda, functor,
// or anything
using Callback = function<void()>;
//or 
using CallBack = void(*)();

map <long long, vector <CallBack>> timeToCallBack;

// Emulated system clock
long long currentTimeMillis() {
    return chrono::duration_cast<chrono::milliseconds>(
        chrono::steady_clock::now().time_since_epoch()
    ).count();
}

class DelayedScheduler {
private:


public:
    //means the callback should be run after timeout ms
    //this callback should run after currenTime + timeout
    void scheduleCallback(Callback cb, long timeoutInMillis) {
        //recieve one call back invocation
        //scheduleHardwareTimer
                lock_guard<mutex> lock(mtx);

        long long execTime = currentTimeMillis() + timeoutInMillis;
        callbackMap[execTime].push_back(cb);

        // Check if we need to schedule a new hardware timer
        if (!timerActive || execTime < callbackMap.begin()->first) {
            scheduleNextHardwareTimer();
        }

    }
    //Assume this is already provided to you
    // Emulates the system's hardware timer (low-level interface)
    void scheduleHardwareTimer(long timeoutInMillis) {
    }

    //this is a class method, you can now run pending callback under hanlde hardware
    void handleHardwareTimer() {
        vector<Callback> readyCallbacks;

        {
            lock_guard<mutex> lock(mtx);
            long long now = currentTimeMillis();

            auto it = callbackMap.begin();
            while (it != callbackMap.end() && it->first <= now) {
                readyCallbacks.insert(readyCallbacks.end(), it->second.begin(), it->second.end());
                it = callbackMap.erase(it);
            }

            // Schedule next if more callbacks exist
            if (!callbackMap.empty()) {
                long long delay = max(0LL, callbackMap.begin()->first - currentTimeMillis());
                scheduleHardwareTimer(delay);
            } else {
                timerActive = false;
            }
        }

        // Execute callbacks in parallel
        for (Callback& cb : readyCallbacks) {
            thread(cb).detach(); // Or use a thread pool
        }
    }

private:
    void scheduleNextHardwareTimer() {
        if (callbackMap.empty()) return;

        long long now = currentTimeMillis();
        long long nextExecTime = callbackMap.begin()->first;
        long long delay = max(0LL, nextExecTime - now);

        scheduleHardwareTimer(delay);
    }
};
