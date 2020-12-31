/// Source : https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Vector to stroe all elements
/// HashMap to restore all maps between elements and index
/// Time Complexity: O(1)
/// Space Complexity: O(n)
class RandomizedCollection {

private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> indexes;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        nums.clear();
        indexes.clear();
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        indexes[val].insert(nums.size() - 1);

        return indexes[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(indexes.find(val) != indexes.end()){
            int i = *indexes[val].begin();
            indexes[val].erase(i);
            if(indexes[val].size() == 0)
                indexes.erase(val);

            int num = nums.back();
            nums.pop_back();
            if(!(num == val && nums.size() == i)){

                nums[i] = num;
                indexes[num].erase(nums.size());
                indexes[num].insert(i);
            }

            return true;
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int rndIndex = rand() % nums.size();
        return nums[rndIndex];
    }
};


int main() {

    return 0;
}