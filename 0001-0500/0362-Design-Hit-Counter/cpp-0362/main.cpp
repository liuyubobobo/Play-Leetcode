/// Source : https://leetcode.com/problems/design-hit-counter/
/// Author : liuyubobobo
/// Time   : 2022-09-07

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// Using deque
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class HitCounter {

private:
    deque<int> hits;

public:
    HitCounter() {}

    void hit(int timestamp) {
        hits.push_back(timestamp);
        while(timestamp - hits.front() + 1 > 300) hits.pop_front();
    }

    int getHits(int timestamp) {

        while(!hits.empty() && timestamp - hits.front() + 1 > 300) hits.pop_front();
        return hits.size();
    }
};


int main() {

    return 0;
}
