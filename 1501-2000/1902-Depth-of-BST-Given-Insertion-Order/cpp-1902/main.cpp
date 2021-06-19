/// Source : https://leetcode.com/problems/depth-of-bst-given-insertion-order/
/// Author : liuyubobobo
/// Time   : 2021-06-18

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using TreeMap
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxDepthBST(vector<int>& order) {

        map<int, int> tree; // e -> depth
        int res = 1;
        tree[order[0]] = 1;

        for(int i = 1; i < order.size(); i ++){
            int d = 1;

            map<int, int>::iterator iter = tree.lower_bound(order[i]);
            if(iter != tree.end()) {
                d = max(d, iter->second + 1);
            }

            if(iter != tree.begin()){
                iter --;
                d = max(d, iter->second + 1);
            }

            tree[order[i]] = d;
            res = max(res, d);
        }
        return res;
    }
};


int main() {

    vector<int> order1 = {2, 1, 4, 3};
    cout << Solution().maxDepthBST(order1) << endl;
    // 3

    return 0;
}
