/// Source : https://leetcode.com/problems/most-beautiful-item-for-each-query/
/// Author : liuyubobobo
/// Time   : 2021-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn + qlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        vector<pair<int, int>> data(items.size());
        for(int i = 0; i < items.size(); i ++) data[i] = {items[i][0], items[i][1]};
        sort(data.begin(), data.end());

        for(int i = 1; i < data.size(); i ++)
            data[i].second = max(data[i].second, data[i - 1].second);

        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int t = queries[i];
            vector<pair<int, int>>::iterator iter = upper_bound(data.begin(), data.end(), make_pair(t, INT_MAX));
            int index = iter - data.begin() - 1;
           res[i] = (index == -1 ? 0 : data[index].second);
        }
        return res;
    }
};


int main() {

    return 0;
}
