template <typename T>
inline T min(T a, T b) {
    return (a < b) ? a : b;
}

#define MIN(f(i), g(i))


#include <algorithm>
auto m = std::min(x++, y); // Still evaluates x++ only once 

//problem with this is 

#define min(a, b) (a > b ? b: a)
//problem with this code is, if you pass
// min(x++, y)
