/// Source : https://leetcode.com/problems/fruit-into-baskets/description/
/// Author : liuyubobobo
/// Time   : 2018-09-15

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int totalFruit(vector<int>& tree) {

        unordered_map<int, int> freq;
        int l = 0, r = -1, res = 0;
        while(l < tree.size()){
            if(freq.size() <= 2 && r + 1 < tree.size()){
                r ++;
                freq[tree[r]] ++;
            }
            else{
                freq[tree[l]] --;
                if(freq[tree[l]] == 0)
                    freq.erase(tree[l]);
                l ++;
            }

            if(freq.size() <= 2)
                res = max(res, getFruits(freq));
        }
        return res;
    }

private:
    int getFruits(const unordered_map<int, int>& freq){
        int res = 0;
        for(const pair<int, int>& p: freq)
            res += p.second;
        return res;
    }
};


int main() {

    return 0;
}