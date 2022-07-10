/// Source : https://leetcode.com/problems/move-pieces-to-obtain-a-string/
/// Author : liuyubobobo
/// Time   : 2022-07-10

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool canChange(string start, string target) {

        vector<pair<char, int>> pos1, pos2;
        for(int i = 0; i < start.size(); i ++)
            if(start[i] != '_') pos1.push_back({start[i], i});
        for(int i = 0; i < target.size(); i ++)
            if(target[i] != '_') pos2.push_back({target[i], i});

        if(pos1.size() != pos2.size()) return false;

        for(int i = 0; i < pos1.size(); i ++){
            if(pos1[i].first != pos2[i].first) return false;
            if(pos1[i].first == 'L' && pos1[i].second < pos2[i].second) return false;
            if(pos1[i].first == 'R' && pos1[i].second > pos2[i].second) return false;
        }
        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
