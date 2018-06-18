/// https://leetcode.com/problems/car-fleet/description/
/// Author : liuyubobobo
/// Time   : 2018-06-17

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Sort and Scan
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Car{
public:
    int position;
    double time;

    Car(int position, double time){
        this->position = position;
        this->time = time;
    }

    friend bool operator<(const Car& carA, const Car& carB){
        return carA.position > carB.position;
    }

    friend ostream& operator<<(ostream& os, const Car& car){
        os << "position: " << car.position << " time: " << car.time;
        return os;
    }
};


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        assert(position.size() == speed.size());

        if(position.size() == 0)
            return 0;

        if(position.size() == 1)
            return 1;

        vector<Car> cars;
        for(int i = 0 ; i < position.size() ; i ++)
            cars.push_back(Car(position[i], (double)(target - position[i]) / speed[i]));
        sort(cars.begin(), cars.end());
//        for(const Car& car: cars)
//            cout << car << endl;

        int res = 1;
        for(int i = 1 ; i < cars.size() ; i ++)
            if(cars[i].time <= cars[i-1].time)
                cars[i].time = cars[i-1].time;
            else
                res ++;

        return res;
    }
};


int main() {

    int target1 = 12;
    vector<int> position1 = {10, 8, 0, 5, 3};
    vector<int> speed1 = {2, 4, 1, 1, 3};
    cout << Solution().carFleet(target1, position1, speed1) << endl;

    return 0;
}