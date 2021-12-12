/// Source : https://leetcode.com/problems/watering-plants-ii/
/// Author : liuyubobobo
/// Time   : 2021-12-11

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {

        int n = plants.size();
        int l = 0, r = n - 1, res = 0, A = capacityA, B = capacityB;
        while(l < r){
            water(plants[l], A, res, capacityA);
            water(plants[r], B, res, capacityB);
            l ++, r --;
        }

        if(l == r){
            if(A >= B) water(plants[l], A, res, capacityA);
            else water(plants[l], B, res, capacityB);
        }
        return res;
    }

private:
    void water(const int need, int& cur, int& res, const int cap){
        if(cur >= need) cur -= need;
        else{
            res ++;
            cur = cap - need;
        }
    }
};


int main() {

    vector<int> plants1 = {2, 2, 3, 3};
    cout << Solution().minimumRefill(plants1, 5, 5) << endl;
    // 1

    vector<int> plants2 = {2, 2, 3, 3};
    cout << Solution().minimumRefill(plants2, 3, 4) << endl;
    // 2

    vector<int> plants3 = {5};
    cout << Solution().minimumRefill(plants3, 10, 8) << endl;
    // 0

    vector<int> plants4 = {1, 2, 4, 5, 5};
    cout << Solution().minimumRefill(plants4, 6, 5) << endl;
    // 2

    vector<int> plants5 = {2, 2, 5, 2, 2};
    cout << Solution().minimumRefill(plants5, 5, 5) << endl;
    // 1

    return 0;
}
