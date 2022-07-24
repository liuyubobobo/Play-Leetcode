/// Source : https://leetcode.com/problems/design-a-food-rating-system/
/// Author : liuyubobobo
/// Time   : 2022-07-23

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Using Map
/// Time Complexity: O(logn) for every operation
/// Space Complexity: O(n)
class FoodRatings {

private:
    map<string, map<int, set<string>>> tree;
    map<string, pair<string, int>> food;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        int n = foods.size();
        for(int i = 0; i < n; i ++){
            food[foods[i]] = {cuisines[i], ratings[i]};
            tree[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    void changeRating(string food_name, int newRating) {

        pair<string, int> p = food[food_name];
        string cuision = p.first;
        int oldRating = p.second;

        tree[cuision][oldRating].erase(food_name);
        if(tree[cuision][oldRating].empty()) tree[cuision].erase(oldRating);
        tree[cuision][newRating].insert(food_name);

        food[food_name].second = newRating;
    }

    string highestRated(string cuisine) {
        return *(tree[cuisine].rbegin()->second.begin());
    }
};


int main() {

    return 0;
}
