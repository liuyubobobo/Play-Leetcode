/// Source : https://leetcode.com/problems/first-unique-number/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using HashSet
/// Time Complexity: init: O(n)
///                  showFirstUnique: O(1)
///                  add: O(n), amortized: O(1)
/// Space Complexity: O(n)
class FirstUnique {

private:
    unordered_set<int> unique;
    unordered_set<int> duplicates;
    vector<int> data;
    int res;

public:
    FirstUnique(vector<int>& nums) : data(nums) {

        for(int num: nums)
            if(!duplicates.count(num)){
                if(unique.count(num)) unique.erase(num), duplicates.insert(num);
                else unique.insert(num);
            }

        for(res = 0; res < nums.size(); res ++)
            if(unique.count(nums[res])) break;
    }

    int showFirstUnique() {
        if(res < data.size()) return data[res];
        return -1;
    }

    void add(int num) {

        data.push_back(num);
        if(!duplicates.count(num)){
            if(unique.count(num)) unique.erase(num), duplicates.insert(num);
            else unique.insert(num);
        }

        while(res < data.size() && !unique.count(data[res])) res ++;
    }
};


int main() {

    return 0;
}
