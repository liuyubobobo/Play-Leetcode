/// Source : https://leetcode.com/problems/detect-capital/
/// Author : liuyubobobo
/// Time   : 2021-11-12

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(|s|)
/// Space Complexity: O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {

        return all_upper(word) || all_lower(word) || (isupper(word[0]) && all_lower(word.substr(1)));
    }

private:
    bool all_upper(const string& s){
        for(char c: s) if(islower(c)) return false;
        return true;
    }

    bool all_lower(const string& s){
        for(char c: s) if(isupper(c)) return false;
        return true;
    }
};


int main() {

    return 0;
}
