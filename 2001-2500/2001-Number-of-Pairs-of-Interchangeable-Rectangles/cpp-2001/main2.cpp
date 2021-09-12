/// Source : https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
/// Author : liuyubobobo
/// Time   : 2021-09-11

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {

        map<pair<int, int>, int> table;
        long long res = 0ll;
        for(const vector<int>& rec: rectangles){
            int w = rec[0], h = rec[1], g = gcd(min(w, h), max(w, h));
            w /= g, h /= g;
            if(table.count({w, h})){
                int v = table[{w, h}];
                res += v;
                table[{w, h}] = v + 1;
            }
            else table[{w, h}] = 1;
        }
        return res;
    }

private:
    int gcd(int a, int b){
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    return 0;
}
