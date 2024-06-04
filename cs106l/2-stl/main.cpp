#include <iostream>
#include <vector>
#include <algorithm>

#define kNumInts 20

int main() {
    std::vector<int> vec(kNumInts);
    std::generate(vec.begin(), vec.end(), rand);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
