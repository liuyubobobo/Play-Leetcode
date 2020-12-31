/// Source : https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace  std;


/// Simulation
/// Time Complexity: O(|orders| + |tables| * |foods|)
/// Space Complexity: O(|tables| * |foods|)
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {

        map<int, map<string, int>> data;
        set<int> table_numbers;
        set<string> food_names;
        for(const vector<string>& order: orders){
            int num = atoi(order[1].c_str());
            data[num][order[2]] ++;

            table_numbers.insert(num);
            food_names.insert(order[2]);
        }

        vector<vector<string>> res;
        map<string, int> food_to_index;
        vector<string> header = {"Table"};

        int i = 1;
        for(const string& food_name: food_names){
            header.push_back(food_name);
            food_to_index[food_name] = i ++;
        }
        res.push_back(header);

        for(const pair<int, map<string, int>>& p: data){
            vector<string> row(food_names.size() + 1, "0");
            row[0] = to_string(p.first);
            for(const pair<string, int>& p2: p.second)
                row[food_to_index[p2.first]] = to_string(p2.second);
            res.push_back(row);
        }
        return res;
    }
};


int main() {

    return 0;
}
