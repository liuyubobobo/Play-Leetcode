/// Source : https://leetcode.com/problems/longest-uploaded-prefix/
/// Author : liuyubobobo
/// Time   : 2022-10-02

#include <iostream>
#include <set>

using namespace std;


/// Using TreeSet
/// Time Complexity: init: O(nlogn)
///                  upload and longest: O(logn)
/// Space Complexity: O(n)
class LUPrefix {

private:
    set<int> available;

public:
    LUPrefix(int n) {
        for(int i = 1; i <= n + 1; i ++) available.insert(i);
    }

    void upload(int video) {
        available.erase(video);
    }

    int longest() {
        auto iter = available.lower_bound(1);
        return *iter - 1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
