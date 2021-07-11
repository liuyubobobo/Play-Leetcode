/// Source : https://leetcode.com/problems/h-index-ii/
/// Author : liuyubobobo
/// Time   : 2021-07-11

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(maxv * logn)
/// Space Complexity: O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {

        for(int h = citations.back(); h >= 0; h --){
            int x = citations.end() - lower_bound(citations.begin(), citations.end(), h);
            if(x >= h) return h;
        }
        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}
