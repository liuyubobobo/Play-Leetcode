/// Source : https://leetcode.com/problems/fruit-into-baskets/description/
/// Author : liuyubobobo
/// Time   : 2018-09-15

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Segment the array into blocks
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int totalFruit(vector<int>& tree) {

        vector<pair<int, int>> blocks;
        int start = 0;
        for(int i = start + 1; i <= tree.size(); i ++)
            if(i == tree.size() || tree[i] != tree[start]){
                blocks.push_back(make_pair(tree[start], i - start));
                start = i;
                i = start;
            }
//        for(const pair<int, int>& p: blocks)
//            cout << "(" << p.first << "," << p.second << ") ";
//        cout << endl;

        int res = 0;
        unordered_set<int> fruits;
        int sum = 0;
        for(int i = 0; i <= blocks.size();)
            if(i == blocks.size() || (fruits.size() == 2 && fruits.count(blocks[i].first) == 0)){
                res = max(res, sum);

                if(i < blocks.size()){
                    sum = 0;
                    i --;
                    fruits.clear();
                }
                else
                    break;
            }
            else{
                fruits.insert(blocks[i].first);
                sum += blocks[i].second;
                i ++;
            }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 1};
    cout << Solution().totalFruit(nums1) << endl;

    vector<int> nums2 = {0, 1, 2, 2};
    cout << Solution().totalFruit(nums2) << endl;

    return 0;
}