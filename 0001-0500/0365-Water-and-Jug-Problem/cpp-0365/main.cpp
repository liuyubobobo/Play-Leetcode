/// Source : https://leetcode.com/problems/water-and-jug-problem/
/// Author : liuyubobobo
/// Time   : 2021-01-27

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;


/// BFS
/// Time Complexity: O(x * y)
/// Space Complexity: O(x * y)
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {

        unordered_set<long long> set;
        queue<pair<int, int>> q;
        q.push({0, 0});
        set.insert(0);
        while(!q.empty()){
            int a = q.front().first, b = q.front().second;
            q.pop();

            if(a == z || b == z || a + b == z) return true;

            if(!set.count(x * 10000000ll + b))
                q.push({x, b}), set.insert(x * 10000000ll + b);

            if(!set.count(a * 10000000ll + y))
                q.push({a, y}), set.insert(a * 10000000ll + y);

            if(!set.count(b))
                q.push({0, b}), set.insert(b);

            if(!set.count(a * 10000000ll))
                q.push({a, 0}), set.insert(a * 10000000ll);

            if(!set.count((a - min(a, y - b)) * 10000000ll + b + min(a, y - b)))
                q.push({a - min(a, y - b), b + min(a, y - b)}),
                set.insert((a - min(a, y - b)) * 10000000ll + b + min(a, y - b));

            if(!set.count((a + min(x - a, b)) * 10000000ll + b - min(x - a, b)))
                q.push({a + min(x - a, b), b - min(x - a, b)}),
                set.insert((a + min(x - a, b)) * 10000000ll + b - min(x - a, b));
        }
        return false;
    }
};


int main() {

    return 0;
}
