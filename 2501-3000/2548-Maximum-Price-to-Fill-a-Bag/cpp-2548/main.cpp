/// Source : https://leetcode.com/problems/maximum-price-to-fill-a-bag/description/
/// Author : liuyubobobo
/// Time   : 2023-01-28

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {

        int total_weight = 0;
        for(const vector<int>& item: items) total_weight += item[1];
        if(total_weight < capacity) return -1;

        sort(items.begin(), items.end(),
             [](const vector<int>& item1, const vector<int>& item2){
            double p1 = item1[0], w1 = item1[1];
            double p2 = item2[0], w2 = item2[1];
            return p1 / w1 > p2 / w2;
        });

        double price = 0;
        for(const vector<int>& item: items){
            double p = item[0]; int w = item[1];
            if(w <= capacity) price += p, capacity -= w;
            else{
                price += capacity / (double)w * p;
                break;
            }
        }
        return price;
    }
};


int main() {

    return 0;
}
