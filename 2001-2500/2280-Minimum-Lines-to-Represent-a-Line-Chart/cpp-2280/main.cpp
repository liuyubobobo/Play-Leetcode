/// Source : https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/
/// Author : liuyubobobo
/// Time   : 2022-05-21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Linear Scan
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {

        sort(stockPrices.begin(), stockPrices.end());

        int n = stockPrices.size();

        vector<pair<int, int>> k;
        for(int i = 1; i < n; i ++){
            int x0 = stockPrices[i - 1][0], y0 = stockPrices[i - 1][1];
            int x1 = stockPrices[i][0], y1 = stockPrices[i][1];
            int a = y1 - y0, b = x1 - x0;

            int g = gcd(min(abs(a), abs(b)), max(abs(a), abs(b)));
            a /= g, b /= g;

            pair<int, int> p = {a, b};
            if(k.empty() || k.back() != p) k.push_back(p);
        }
        return k.size();
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
