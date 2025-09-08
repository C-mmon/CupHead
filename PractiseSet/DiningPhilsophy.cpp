//We are not using atomic bool, because using the mutex we can gurranting


class DiningPhilosophers {
private:
    static constexpr int N = 5;
    array<bool, N> token;
    array<mutex, N> forks;
    mutex cv_m;
    condition_variable cv;
    int n;

public:
    DiningPhilosophers(int n_ = N) : n(n_) {
        token.fill(false);
        token[0] = true;         // two non-adjacent starters
        token[2 % n] = true;
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
        int i = philosopher;
        int left = i;
        int right = (i + 1) % n;

        // wait for token (sleeping wait)
        {
            unique_lock<mutex> lk(cv_m);
            cv.wait(lk, [&]{ return token[i]; });
            // token remains true until we pass it after eating
        }

        //Once, we come here, locks are automatically destroyed
        //the above above are scoped lock, and ensure the destruction happens automatically
        

        // Acquire forks (consistent ordering to avoid deadlock among token-holders)
        if (left < right) {
            scoped_lock lock(forks[left], forks[right]);
            pickLeftFork();
            pickRightFork();

            eat();

            putRightFork();
            putLeftFork();
        } else {
            scoped_lock lock(forks[right], forks[left]);
            pickRightFork();
            pickLeftFork();

            eat();

            putLeftFork();
            putRightFork();
        }

        // pass token forward then clear ours, notify waiting threads
        {
            unique_lock<mutex> lk(cv_m);
            token[(i + 1) % n] = true;
            token[i] = false;
        }
        cv.notify_all(); // notify next token-holder(s)
    }
};
