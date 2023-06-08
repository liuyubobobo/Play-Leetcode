/// Source : https://leetcode.com/problems/count-houses-in-a-circular-street/description/
/// Author : liuyubobobo
/// Time   : 2023-06-08

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(k)
/// Space Complexity: O(1)

/// Definition for a street.
class Street {
public:
    Street(vector<int> doors);
    void openDoor();
    void closeDoor();
    bool isDoorOpen();
    void moveRight();
    void moveLeft();
};

class Solution {
public:
    int houseCount(Street* street, int k) {

        for(int i = 0; i < k; i ++, street->moveRight())
            if(street->isDoorOpen())
                street->closeDoor();

        street->openDoor();
        street->moveRight();

        int res = 1;
        while(!street->isDoorOpen()){
            res ++;
            street->moveRight();
        }
        return res;
    }
};


int main() {

    return 0;
}
