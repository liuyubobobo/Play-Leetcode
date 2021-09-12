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
        for(const vector<int>& rec: rectangles){
            int w = rec[0], h = rec[1];
            int g = gcd(w, h);
            w /= g, h /= g;
            table[{w, h}] ++;
        }

        long long res = 0ll;
        for(const pair<pair<int, int>, int>& p: table){
            long long n = p.second;
            res += n * (n - 1) / 2;
        }
        return res;
    }

private:
    int gcd(int a, int b){
        if(a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    return 0;
}
