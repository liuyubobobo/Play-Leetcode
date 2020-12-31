/// Source : https://leetcode.com/problems/number-of-recent-calls/
/// Author : liuyubobobo
/// Time   : 2018-11-03

#include <iostream>
#include <queue>

using namespace std;


/// Using a Queue
/// Time Complexity: O(query)
/// Space Complexity: O(3000)
class RecentCounter {

private:
    queue<int> q;
public:
    RecentCounter() { }

    int ping(int t) {
        q.push(t);
        while(t - 3000 > q.front())
            q.pop();
        return q.size();
    }
};


int main() {

    return 0;
}