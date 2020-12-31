/// Source : https://leetcode.com/problems/design-parking-system/
/// Author : liuyubobobo
/// Time   : 2020-10-03

#include <iostream>
#include <vector>
using namespace std;


/// Simulation
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class ParkingSystem {

private:
    vector<int> cap, cur;

public:
    ParkingSystem(int big, int medium, int small): cap(4), cur(4, 0){
        cap[1] = big, cap[2] = medium, cap[3] = small;
    }

    bool addCar(int carType) {

        if(cur[carType] + 1 <= cap[carType]){
            cur[carType] ++;
            return true;
        }
        return false;
    }
};


int main() {

    return 0;
}
