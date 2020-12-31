/// Source : https://leetcode.com/problems/intersection-of-three-sorted-arrays/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: O(|arr1| + |arr2| + |arr3|)
/// Space Complexity: O(|arr1| + |arr2| + |arr3|)
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {

        set<int> set1(arr1.begin(), arr1.end());
        set<int> set2;
        for(int e: arr2) if(set1.count(e)) set2.insert(e);

        vector<int> res;
        for(int e: arr3) if(set2.count(e)) res.push_back(e);
        return res;
    }
};


int main() {

    return 0;
}