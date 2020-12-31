/// Source : https://leetcode.com/problems/can-place-flowers/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        for(int i = 0; i < flowerbed.size() && n; i ++)
            if(flowerbed[i] == 0){
                flowerbed[i] = 1;
                if(i - 1 >= 0 && flowerbed[i - 1] == 1)
                    flowerbed[i] = 0;
                else if(i + 1 < flowerbed.size() && flowerbed[i + 1] == 1)
                    flowerbed[i] = 0;
                else n --;
            }
        return n == 0;
    }
};


int main() {

    return 0;
}
