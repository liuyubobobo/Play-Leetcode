/// Source : https://leetcode.com/problems/simplify-path/
/// Author : liuyubobobo
/// Time   : 2019-02-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        map<int, int> map;
        for(int e: arr) map[e] ++;

        for(const pair<int, int>& p: map)
            if(!p.first){
                if(p.second >= 2) return true;
            }
            else if(map.count(p.first * 2)) return true;
        return false;
    }
};


int main() {

    return 0;
}
