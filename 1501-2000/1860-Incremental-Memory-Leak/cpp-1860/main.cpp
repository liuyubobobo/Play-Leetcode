/// Source : https://leetcode.com/problems/incremental-memory-leak/
/// Author : liuyubobobo
/// Time   : 2021-05-15

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(sqrt(memory1 + memory2))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {

        for(int i = 1;;i ++){
            if(i > memory1 && i > memory2)
                return {i, memory1, memory2};
            else if(memory1 >= memory2)
                memory1 -= i;
            else memory2 -= i;
        }
        return {};
    }
};


int main() {

    return 0;
}
