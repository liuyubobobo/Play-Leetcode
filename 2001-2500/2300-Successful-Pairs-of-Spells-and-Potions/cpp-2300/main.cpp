/// Source : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
/// Author : liuyubobobo
/// Time   : 2022-06-11

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogm)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        vector<long long> spells_ll(spells.size());
        for(int i = 0; i < spells.size(); i ++)
            spells_ll[i] = spells[i];

        vector<long long> potions_ll(potions.size());
        for(int i = 0; i < potions.size(); i ++)
            potions_ll[i] = potions[i];
        sort(potions_ll.begin(), potions_ll.end());

        vector<int> res(spells.size());
        for(int i = 0; i < spells.size(); i ++){
            long long energy = spells_ll[i];
            long long least_potion = success / energy;
            if(least_potion * energy < success) least_potion ++;

            res[i] = potions_ll.end() - lower_bound(potions_ll.begin(), potions_ll.end(), least_potion);
        }
        return res;
    }
};


int main() {

    return 0;
}
