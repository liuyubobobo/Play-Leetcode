/// Source : https://leetcode.com/problems/watering-plants/
/// Author : liuyubobobo
/// Time   : 2021-11-20

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {

        int res = 0, cur = -1, left = capacity;
        for(int i = 0; i < plants.size();)
            if(left >= plants[i]){
                res ++;
                left -= plants[i];
                cur ++;
                i ++;
            }
            else{
                res += (cur + 1) * 2;
                left = capacity;
            }
        return res;
    }
};


int main() {

    vector<int> plants1 = {2, 2, 3, 3};
    cout << Solution().wateringPlants(plants1, 5) << endl;
    // 14

    vector<int> plants2 = {1, 1, 1, 4, 2, 3};
    cout << Solution().wateringPlants(plants2, 4) << endl;
    // 30

    vector<int> plants3 = {7,7,7,7,7,7,7};
    cout << Solution().wateringPlants(plants3, 8) << endl;
    // 49

    return 0;
}
