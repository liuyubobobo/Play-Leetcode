/// Source : https://leetcode.com/problems/valid-word-square/description/
/// Author : liuyubobobo
/// Time   : 2023-03-01

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(R * C)
/// Space Complexity: O(1)
class Solution {
public:
    bool validWordSquare(vector<string>& words) {

        int R = words.size();
        for(int i = 0; i < R; i++)
            for(int j = 0; j < words[i].size(); j++){
                if(j >= R || i >= words[j].size()) return false;
                if(words[i][j] != words[j][i]) return false;
            }
        return true;
    }
};


int main() {

    return 0;
}
