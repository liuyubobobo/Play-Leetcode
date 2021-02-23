/// Source : https://leetcode.com/problems/find-the-celebrity/
/// Author : liuyubobobo
/// Time   : 2021-02-22

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {

        for(int i = 0; i < n; i ++){
            bool ok = true;
            for(int j = 0; j < n; j ++)
                if(j != i){
                    if(!knows(j, i)){ok = false; break;}
                    if(knows(i, j)){ok = false; break;}
                }
            if(ok) return i;
        }
        return -1;
    }
};


int main() {

    return 0;
}
