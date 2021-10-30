/// Source : https://leetcode.com/problems/kth-distinct-string-in-an-array/
/// Author : liuyubobobo
/// Time   : 2021-10-30

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        map<string, int> f;
        for(string& s: arr) f[s] ++;

        for(string& s: arr){
            if(f[s] == 1) k--;
            if(!k) return s;
        }
        return "";
    }
};


int main() {

    return 0;
}
