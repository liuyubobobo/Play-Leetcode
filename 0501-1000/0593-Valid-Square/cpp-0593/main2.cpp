/// Source : https://leetcode.com/problems/valid-square/
/// Author : liuyubobobo
/// Time   : 2022-07-28

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Only check points' distance
/// Time Complexity: O(6)
/// Space Complexity: O(1)
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        vector<vector<int>> p ={p1, p2, p3, p4};
        map<int, int> table;
        for(int i = 0; i < 4; i ++)
            for(int j = i + 1; j < 4; j ++){
                if(p[i] == p[j]) return false;
                table[get_L2(p[i], p[j])] ++;
            }

        if(table.size() != 2) return false;
        if(table.begin()->second == 4 && table.rbegin()->second == 2 && table.begin()->first * 2 == table.rbegin()->first)
            return true;
        return false;
    }

private:
    int get_L2(const vector<int>& p1, const vector<int>& p2){
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};


int main() {

    return 0;
}
