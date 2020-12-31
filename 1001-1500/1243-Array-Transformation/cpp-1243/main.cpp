/// Source : https://leetcode.com/problems/array-transformation/
/// Author : liuyubobobo
/// Time   : 2019-11-08

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(max(arr) * |arr|)
/// Space Complexity: O(|arr|)
class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {

        vector<int> t = arr;
        bool change = false;
        do{
            change = false;
            arr = t;
            for(int i = 1; i < arr.size() - 1; i ++)
                if(t[i - 1] > t[i] && t[i + 1] > t[i]){arr[i] ++; change = true;}
                else if(t[i - 1] < t[i] && t[i + 1] < t[i]){arr[i] --; change = true;}
            t = arr;
        }while(change);
        return arr;
    }
};


int main() {

    return 0;
}