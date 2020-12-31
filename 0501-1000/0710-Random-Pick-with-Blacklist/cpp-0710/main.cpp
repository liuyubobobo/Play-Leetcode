/// Source : https://leetcode.com/problems/random-pick-with-blacklist/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Remap all blacklist number to a legal number
/// Time Complexity: init: O(BlogB), where B is len(blacklist)
///                  pick: O(1)
/// Space Complexity: O(B)
class Solution {

private:
    int limit;
    unordered_map<int, int> trans;

public:
    Solution(int N, vector<int> blacklist) {

        sort(blacklist.begin(), blacklist.end());
        unordered_set<int> bset(blacklist.begin(), blacklist.end());

        limit = N - 1;
        trans.clear();
        for(int i = 0 ; i < blacklist.size() ; ){

            if(blacklist[i] == limit){
                limit --;
                break;
            }

            if(blacklist[i] > limit)
                break;

            if(bset.find(limit) != bset.end()){
                limit --;
                continue;
            }

            trans[blacklist[i]] = limit;
            limit --;
            i ++;
        }

        srand(time(NULL));
    }

    int pick() {
        int res = rand() % (limit + 1);
        if(trans.find(res) != trans.end())
            return trans[res];
        return res;
    }
};


int main() {

    Solution solution1(2, {1});
    cout << solution1.pick() << endl;

    Solution solution2(3, {1, 2});
    cout << solution2.pick() << endl;

    return 0;
}