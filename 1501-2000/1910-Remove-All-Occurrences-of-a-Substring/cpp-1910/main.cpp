/// Source : https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
/// Author : liuyubobobo
/// Time   : 2021-06-26

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(|s| * |part|)
/// Space Complexity: O(|part|)
class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(true){
            int pos = s.find(part);
            if(pos == string::npos) break;

            s = s.substr(0, pos) + s.substr(pos + part.size());
        }
        return s;
    }
};


int main() {

    return 0;
}
