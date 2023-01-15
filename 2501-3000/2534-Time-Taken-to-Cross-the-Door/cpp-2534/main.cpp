/// Source : https://leetcode.com/problems/time-taken-to-cross-the-door/description/
/// Author : liuyubobobo
/// Time   : 2023-01-14

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Event Simulation
/// Time Compelxity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {

        int n = arrival.size();

        vector<int> res(n, -1);
        queue<int> enter_list, leave_list;
        int arrival_index = 0, t = 0, pre_state = -1;
        while(arrival_index < n || !enter_list.empty() || !leave_list.empty()){
            while(arrival_index < n && arrival[arrival_index] <= t){
                if(state[arrival_index] == 0) enter_list.push(arrival_index);
                else leave_list.push(arrival_index);
                arrival_index ++;
            }

            if(pre_state == -1 || pre_state == 1){
                if(!leave_list.empty()){
                    int index = leave_list.front(); leave_list.pop();
                    res[index] = t;
                    pre_state = 1;
                }
                else if(!enter_list.empty()){
                    int index = enter_list.front(); enter_list.pop();
                    res[index] = t;
                    pre_state = 0;
                }
                else pre_state = -1;
            }
            else{
                if(!enter_list.empty()){
                    int index = enter_list.front(); enter_list.pop();
                    res[index] = t;
                    pre_state = 0;
                }
                else if(!leave_list.empty()){
                    int index = leave_list.front(); leave_list.pop();
                    res[index] = t;
                    pre_state = 1;
                }
                else pre_state = -1;
            }
            t ++;
        }

        return res;
    }
};


void print_vec(const vector<int>& res){
    for(int e: res) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> arrival1 = {0, 1, 1, 2, 4}, state1 = {0, 1, 0, 0, 1};
    print_vec(Solution().timeTaken(arrival1, state1));
    // 0 3 1 2 4

    vector<int> arrival2 = {0,0,6,9,10,10,11,11,11,12,14,14,15,15,15,15,15,16,18,18},
    state2 = {0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,0,1,0,0};
    print_vec(Solution().timeTaken(arrival2, state2));
    // 0 3 1 2 4

    return 0;
}
