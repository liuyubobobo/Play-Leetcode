/// Source : https://leetcode.com/problems/h-index/
/// Author : liuyubobobo
/// Time   : 2021-07-10

#include <iostream>
#include <vector>

using namespace std;


/// Sorintg and Binary Search
/// Time Complexity: O(max_v * logn)
/// Sapce Complexity: O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(), citations.end());

        for(int h = citations.back(); h >= 0; h --){
            int x = citations.end() - lower_bound(citations.begin(), citations.end(), h);
            if(x >= h) return h;
        }
        assert(false);
        return -1;
    }
};

int main() {

    vector<int> citations1 = {100};
    cout << Solution().hIndex(citations1) << endl;
    // 1

    return 0;
}
