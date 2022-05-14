/// Source : https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/
/// Author : liuyubobobo
/// Time   : 2022-05-14

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {

        int n = tiles.size();

        vector<pair<int, int>> data(n);
        for(int i = 0; i < n; i ++) data[i] = {tiles[i][0] - 1, tiles[i][1] - 1};
        sort(data.begin(), data.end());
        int res1 = get_res(n, data, carpetLen);

        int max_len = data.back().second + 1;

        for(pair<int, int>& p: data)
            p = {max_len - p.second, max_len - p.first};
        sort(data.begin(), data.end());
        int res2 = get_res(n, data, carpetLen);

        return max(res1, res2);
    }

private:
    int get_res(int n, const vector<pair<int, int>>& data, int len){

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + (data[i].second - data[i].first + 1);

        int res = 0;
        for(int i = 0; i < n; i ++){
            auto iter = lower_bound(data.begin() + i, data.end(), make_pair(data[i].first + len, -1));
            iter --;
            int j = iter - data.begin();

            assert(i <= j);

            int tres = 0;
            if(i <= j - 1) tres += presum[j] - presum[i];

            int pre = data[j].first - data[i].first;
            tres += min(len - pre, data[j].second - data[j].first + 1);

            res = max(res, tres);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> tiles1 = {{1,5},{10,11},{12,18},{20,25},{30,32}};
    cout << Solution().maximumWhiteTiles(tiles1, 10) << '\n';
    // 9

    vector<vector<int>> tiles2 = {{10,11},{1, 1}};
    cout << Solution().maximumWhiteTiles(tiles2, 2) << '\n';
    // 2

    return 0;
}
