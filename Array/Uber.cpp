There is a stream of numbers incoming. They can come in any order. We have to implement two methods.

incoming(num : int) -> This will ingest the number
getMissingMinSoFar() : -> This will return minimum missing number from the stream
Example
stream.getMissingMinSoFar() -> 0
stream.incoming(0)
stream.incoming(1)
stream.getMissingMinSoFar() -> 2

stream.incoming(5)
stream.getMissingMinSoFar() -> 2
stream.incoming(2)
stream.getMissingMinSoFar() -> 3

#include <unordered_set>

class Stream {
private:
    std::unordered_set<int> store;
    int minSoFar = 0;

public:
    void incoming(int n) {
        store.insert(n);
        while (store.find(minSoFar) != store.end()) {
            minSoFar++;
        }
    }

    int getMissingMinSoFar() {
        return minSoFar;
    }
};
