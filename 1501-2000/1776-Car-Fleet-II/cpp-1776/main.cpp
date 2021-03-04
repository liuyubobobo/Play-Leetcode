/// Source : https://leetcode.com/problems/car-fleet-ii/
/// Author : liuyubobobo
/// Time   : 2021-03-03

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cassert>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        int n = cars.size();

        set<int> carset;
        for(int i = 0; i < n; i ++)
            carset.insert(i);

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        for(int i = 0; i + 1 < n; i ++)
            if(cars[i][1] > cars[i + 1][1])
                pq.push({(double)(cars[i + 1][0] - cars[i][0]) / (cars[i][1] - cars[i + 1][1]), i});

        vector<double> res(n, -1.0);
        while(!pq.empty()){
            double t = pq.top().first, index = pq.top().second;
            pq.pop();
            if(res[index] >= 0.0) continue;

            res[index] = t;

            int next = get_next(carset, index);
            if(next == -1) continue;

            int prev = get_prev(carset, index);
            if(prev == -1) continue;

            carset.erase(index);

            if(cars[prev][1] > cars[next][1])
                pq.push({(double)(cars[next][0] - cars[prev][0]) / (cars[prev][1] - cars[next][1]), prev});
        }
        return res;
    }

private:
    int get_prev(set<int>& s, int index){

        set<int>::iterator iter = s.lower_bound(index);
        assert(iter != s.end());

        if(iter == s.begin()) return -1;
        iter --;
        return *iter;
    }

    int get_next(set<int>& s, int index){

        set<int>::iterator iter = s.lower_bound(index);
        assert(iter != s.end());
        iter ++;
        return iter == s.end() ? -1 : *iter;
    }
};


void print_vec(const vector<double>& v){
    for(double e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> cars1 = {{1,2},{2,1},{4,3},{7,2}};
    print_vec(Solution().getCollisionTimes(cars1));
    // 1.00000,-1.00000,3.00000,-1.00000

    vector<vector<int>> cars2 = {{3,4},{5,4},{6,3},{9,1}};
    print_vec(Solution().getCollisionTimes(cars2));
    // 2.00000,1.00000,1.50000,-1.00000

    return 0;
}
