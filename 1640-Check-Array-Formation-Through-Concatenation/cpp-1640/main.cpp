/// Source : https://leetcode.com/problems/check-array-formation-through-concatenation/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashpMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {

        unordered_map<int, vector<int>> pmap;
        for(const vector<int>& row: pieces)
            pmap[row[0]] = row;

        int i = 0;
        while(i < arr.size()){
            int a = arr[i];
            if(!pmap.count(a)) return false;

            for(int e: pmap[a]){
                if(arr[i] != e) return false;
                i ++;
            }
        }
        return i == arr.size();
    }
};


int main() {

    vector<int> arr1 = {85};
    vector<vector<int>> pieces1 = {{85}};
    cout << Solution().canFormArray(arr1, pieces1) << endl;
    // 1

    vector<int> arr2 = {15, 88};
    vector<vector<int>> pieces2 = {{88}, {15}};
    cout << Solution().canFormArray(arr2, pieces2) << endl;
    // 1

    vector<int> arr3 = {49,18,16};
    vector<vector<int>> pieces3 = {{16,18,49}};
    cout << Solution().canFormArray(arr3, pieces3) << endl;
    // 0

    vector<int> arr4 = {91,4,64,78};
    vector<vector<int>> pieces4 = {{78},{4,64},{91}};
    cout << Solution().canFormArray(arr4, pieces4) << endl;
    // 1

    vector<int> arr5 = {1,3,5,7};
    vector<vector<int>> pieces5 = {{2, 4, 6, 8}};
    cout << Solution().canFormArray(arr5, pieces5) << endl;
    // 0

    return 0;
}
