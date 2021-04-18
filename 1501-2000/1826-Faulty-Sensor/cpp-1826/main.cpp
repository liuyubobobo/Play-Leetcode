/// Source : https://leetcode.com/problems/faulty-sensor/
/// Author : liuyubobobo
/// Time   : 2021-04-18

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {

        int res = -1;
        for(int i = 0; i < sensor1.size(); i ++)
            if(ok(sensor1, i, sensor2)){
                res = 2;
            }

        for(int i = 0; i < sensor2.size(); i ++)
            if(ok(sensor2, i, sensor1)){
                if(res == 2) return -1;
                res = 1;
            }

        return res;
    }

private:
    bool ok(const vector<int>& a, int index, const vector<int>& b){

        vector<int> x = a;
        x.erase(x.begin() + index);

        vector<int> y = b;
        y.pop_back();

        return x == y;
    }
};


int main() {

    vector<int> sensor11 = {2, 3, 4, 5}, sensor12 = {2, 1, 3, 4};
    cout << Solution().badSensor(sensor11, sensor12) << endl;
    // 1

    return 0;
}
