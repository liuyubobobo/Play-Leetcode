/// Source : https://leetcode.com/problems/find-original-array-from-doubled-array/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Greedy + Using Set
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        sort(changed.begin(), changed.end());

        set<pair<int, int>> data; // value, index
        for(int i = 0; i < changed.size(); i ++)
            data.insert({changed[i], i});

        set<int> visited;
        vector<int> res;
        for(int i = 0; i < changed.size(); i ++){
            data.erase({changed[i], i});
            if(!visited.count(i)){
                set<pair<int, int>>::iterator iter = data.lower_bound(make_pair(changed[i] * 2, INT_MIN));
                if(iter == data.end() || iter->first != changed[i] * 2) return {};

                int ii = iter->second;
                visited.insert(i); visited.insert(ii);
                data.erase(iter);
                res.push_back(changed[i]);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
