/// Source : https://leetcode.com/problems/check-distances-between-same-letters/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {

        vector<int> first(26, -1);
        for(int i = 0; i < s.size(); i ++){
            if(first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            else{
                int d = i - first[s[i] - 'a'] - 1;
                if(distance[s[i] - 'a'] != d) return false;
            }
        }
        return true;
    }
};


int main() {

    return 0;
}
