/// Source : https://leetcode.com/problems/contains-duplicate/
/// Author : liuyubobobo
/// Time   : 2017-01-18

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/// Using HashTable
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> record;
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( record.find( nums[i] ) == record.end() )
                record.insert( nums[i] );
            else
                return true;

        return false;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<int> vec = {0, 0, 1};
    print_bool(Solution().containsDuplicate(vec));

    return 0;
}