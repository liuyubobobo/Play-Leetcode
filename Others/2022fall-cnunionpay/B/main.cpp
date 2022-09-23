/// Source : https://leetcode.cn/contest/cnunionpay2022/problems/6olJmJ/
/// Author : liuyubobobo
/// Time   : 2022-09-23

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


/// Binary Search
/// Time Complexity: O(|pos| * log(|station|))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> explorationSupply(vector<int>& station, vector<int>& pos) {

        int q = pos.size();
        vector<int> res(q, -1);
        for(int i = 0; i < q; i ++){
            int p = pos[i];
            int best_d = INT_MAX;

            auto iter = lower_bound(station.begin(), station.end(), p);
            if(iter != station.end()){
                if(*iter - p < best_d)
                    res[i] = iter - station.begin(), best_d = *iter - p;
            }
            if(iter != station.begin()){
                iter --;
                if(p - *iter <= best_d)
                    res[i] = iter - station.begin(), best_d = p - *iter;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
