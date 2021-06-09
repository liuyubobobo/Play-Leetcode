/// Source : https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
/// Author : liuyubobobo
/// Time   : 2021-06-09

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int twoEggDrop(int n) {

        for(int i = 1; i <= n; i ++){

            int sum = 0;
            for(int j = i; j >= 1; j --)
                sum += j;
            if(sum >= n) return i;
        }
        return -1;
    }
};


int main() {

    return 0;
}
