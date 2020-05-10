/// Source : https://leetcode.com/problems/design-underground-system/
/// Author : liuyubobobo
/// Time   : 2020-05-09

#include <iostream>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: init: O(1)
///                  checkIn: O(1)
///                  checkout: O(1)
///                  getAverageTime: O(1)
/// Space Complexity: O(n^2)
class UndergroundSystem {

private:
    unordered_map<int, unordered_map<string, int>> in;
    unordered_map<string, unordered_map<string, pair<double, int>>> trip;

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        in[id][stationName] = t;
    }

    void checkOut(int id, string stationName, int t) {
        assert(in.count(id));
        trip[in[id].begin()->first][stationName].first += t - in[id].begin()->second;
        trip[in[id].begin()->first][stationName].second ++;
    }

    double getAverageTime(string startStation, string endStation) {

        if(trip.count(startStation) && trip[startStation].count(endStation))
            return trip[startStation][endStation].first / trip[startStation][endStation].second;
        return 0.0;
    }
};


int main() {

    return 0;
}
