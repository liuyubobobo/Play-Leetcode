/// Source : https://leetcode.cn/contest/autox2023/problems/l9HbCJ/
/// Author : liuyubobobo
/// Time   : 2022-08-28

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: O((num + |block|) * log(num))
/// Space Complexity: O(num)
class Solution {
public:
    int getLengthOfWaterfallFlow(int num, vector<int>& block) {

        set<pair<int, int>> cols; // height -> col
        for(int i = 0; i < num; i ++)
            cols.insert({0, i});

        for(int b: block){
            auto iter = cols.begin();
            int h = iter->first, c = iter->second;
            cols.erase(iter);
            cols.insert({h + b, c});
        }

        return cols.rbegin()->first;
    }
};


int main() {

    return 0;
}
