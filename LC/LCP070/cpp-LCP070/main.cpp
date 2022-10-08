/// Source : https://leetcode.cn/problems/XxZZjK/
/// Author : liuyubobobo
/// Time   : 2022-10-07

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(size^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> sandyLandManagement(int size) {

        if(size == 1)
            return {{1, 1}};

        vector<vector<int>> res = {{1, 1}};
        if(size % 2 == 1){
            for(int i = 2; i <= size; i += 2){
                if(i % 4 == 2){
                    res.push_back({i, 1});
                    for(int j = 3; j <= 2 * i + 1; j += 2)
                        res.push_back({i + 1, j});
                }
                else{
                    res.push_back({i, 2});
                    for(int j = 1; j <= 2 * i + 1; j += 2)
                        res.push_back({i + 1, j});
                }
            }
            if((size - 1) % 4 == 2) res.push_back({size, 1});
        }
        else if(size % 4 == 2){
            for(int i = 2; i < size; i += 2){
                if(i % 4 == 2){
                    for(int j = 1; j <= 2 * i - 1; j += 2) res.push_back({i, j});
                    res.push_back({i + 1, 1});
                }
                else{
                    for(int j = 3; j <= 2 * i - 1; j += 2) res.push_back({i, j});
                    res.push_back({i + 1, 2});
                }
            }
            for(int j = 1; j <= 2 * size - 1; j += 2) res.push_back({size, j});
        }
        else{
            res.push_back({2, 3});
            for(int i = 3; i <= size; i += 2){
                if(i % 4 == 3){
                    res.push_back({i, 2});
                    for(int j = 1; j <= 2 * (i + 1) - 1; j += 2) res.push_back({i + 1, j});
                }
                else{
                    res.push_back({i, 1});
                    for(int j = 3; j <= 2 * (i + 1) - 1; j += 2) res.push_back({i + 1, j});
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
