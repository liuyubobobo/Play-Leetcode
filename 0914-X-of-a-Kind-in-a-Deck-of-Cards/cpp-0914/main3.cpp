/// Source : https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
/// Author : liuyubobobo
/// Time   : 2018-09-30

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/// Calculate the gcd of all frequency
/// Time Complexity: O(n*logn)
/// Space Complexity: O(n)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for(int x: deck)
            freq[x] ++;

        int g = -1;
        for(const pair<int, int>& p: freq)
            if(g == -1)
                g = p.second;
            else
                g = gcd(g, p.second);

        return g > 1;
    }

private:
    int gcd(int a, int b){
        if(a < b)
            swap(a, b);

        if(a % b == 0)
            return b;

        return gcd(b, a%b);
    }
};


int main() {

    vector<int> vec = {1,1,1,1,2,2,2,2,2,2};
    cout << Solution().hasGroupsSizeX(vec) << endl;
    // true

    return 0;
}