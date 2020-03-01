/// Source : https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
/// Author : liuyubobobo
/// Time   : 2020-02-29

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {

        vector<pair<int, int>> res;
        for(const vector<int>& r: restaurants)
            if((!veganFriendly || r[2]) && maxPrice >= r[3] && maxDistance >= r[4])
                res.push_back(make_pair(r[1], r[0]));

        sort(res.begin(), res.end(), greater<pair<int, int>>());

        vector<int> ret;
        for(const pair<int, int>& p: res) ret.push_back(p.second);
        return ret;
    }
};


void print_vec(const vector<int> vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> restaurants = {
            {1,4,1,40,10},
            {2,8,0,50,5},
            {3,8,1,30,4},
            {4,10,0,10,3},
            {5,1,1,15,1}
    };
    print_vec(Solution().filterRestaurants(restaurants, 0, 50, 10));
    // 4 3 2 1 5

    return 0;
}
