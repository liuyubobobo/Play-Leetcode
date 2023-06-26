/// Source : https://leetcode.com/problems/robot-collisions/description/
/// Author : liuyubobobo
/// Time   : 2023-06-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Stack
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        int n = positions.size();

        vector<tuple<int, int, char, int>> robots; // pos, health, dir, index
        for(int i = 0; i < n; i ++) robots.push_back({positions[i], healths[i], directions[i], i});

        sort(robots.begin(), robots.end());

        vector<pair<int, int>> res; // health, index
        vector<tuple<int, int, char, int>> stack;
        for(int i = 0; i < n;) {
            if(!stack.empty() && get<2>(stack.back()) == 'L'){
                res.push_back({get<1>(stack.back()), get<3>(stack.back())});
                stack.pop_back();
            }
            else if(stack.empty() || get<2>(robots[i]) == get<2>(stack.back())){
                stack.push_back(robots[i]); i ++;
            }
            else{
                int& stack_health = get<1>(stack.back());
                int& cur_health = get<1>(robots[i]);
                if(stack_health == cur_health){
                    stack.pop_back(); i ++;
                }
                else if(stack_health < cur_health){
                    stack.pop_back();
                    cur_health --;
                }
                else{
                    stack_health --;
                    i ++;
                }
            }
        }

        while(!stack.empty()){
            res.push_back({get<1>(stack.back()), get<3>(stack.back())});
            stack.pop_back();
        }

        sort(res.begin(), res.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second < b.second;
        });

        vector<int> ret;
        for(const auto& p: res) ret.push_back(p.first);
        return ret;
    }
};


void print_vec(const vector<int>& v){

    if(v.empty()){
        cout << "empty\n";
        return;
    }

    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> pos1 = {5, 4, 3, 2, 1};
    vector<int> health1 = {2, 17, 9, 15, 10};
    string dir1 = "RRRRR";
    print_vec(Solution().survivedRobotsHealths(pos1, health1, dir1));
    // 2 17 9 15 10

    vector<int> pos2 = {3, 5, 2, 6};
    vector<int> health2 = {10, 10, 15, 12};
    string dir2 = "RLRL";
    print_vec(Solution().survivedRobotsHealths(pos2, health2, dir2));
    // 14

    vector<int> pos3 = {1, 2, 5, 6};
    vector<int> health3 = {10, 10, 11, 11};
    string dir3 = "RLRL";
    print_vec(Solution().survivedRobotsHealths(pos3, health3, dir3));
    // empty

    vector<int> pos4 = {3, 40};
    vector<int> health4 = {49, 11};
    string dir4 = "LL";
    print_vec(Solution().survivedRobotsHealths(pos4, health4, dir4));
    // 49 11

    return 0;
}
