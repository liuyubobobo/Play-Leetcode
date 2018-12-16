/// Source : https://leetcode.com/problems/prison-cells-after-n-days/
/// Author : liuyubobobo
/// Time   : 2018-12-15

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using Hash Map and State Compression
/// Time Complexity: O(2^8)
/// Space Complexity: O(2^8 * 8)
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {

        unordered_map<int, int> visited;

        vector<vector<int>> arr;
        vector<int> cur = cells;
        int i = 0;
        while(true){

            vector<int> next(8, 0);
            for(int i = 1; i < 7; i ++)
                if(cur[i - 1] == cur[i + 1])
                    next[i] = 1;

            int state = get_state(next);
            if(visited.count(state)){
                int start = visited[state];
                int len = i - start;
                return arr[start + (N - 1 - start) % len];
            }

            arr.push_back(next);
            visited[state] = i;

            if(i == N - 1)
                return next;

            i ++;
            cur = next;
        }
        assert(false);
        return {};
    }

private:
    int get_state(const vector<int>& cells){
        int state = 0;
        for(int i = 0; i < 8; i ++)
            if(cells[i])
                state += (1 << i);
        return state;
    }
};


void print_cells(const vector<int>& cells){
    for(int cell: cells)
        cout << cell << " ";
    cout << endl;
}

int main() {

    vector<int> cells1 = {0,1,0,1,1,0,0,1};
    print_cells(Solution().prisonAfterNDays(cells1, 7));
    // 0 0 1 1 0 0 0 0

    vector<int> cells2 = {1,0,0,1,0,0,1,0};
    print_cells(Solution().prisonAfterNDays(cells2, 1000000000));
    // 0 0 1 1 1 1 1 0

    vector<int> cells3 = {0,1,0,1,0,1,0,0};
    print_cells(Solution().prisonAfterNDays(cells3, 27));

    vector<int> cells4 = {1,1,0,0,0,0,1,1};
    print_cells(Solution().prisonAfterNDays(cells4, 7));

    vector<int> cells5 = {0,1,0,1,1,0,0,1};
    print_cells(Solution().prisonAfterNDays(cells5, 7));
    // 0 0 1 1 0 0 0 0


    return 0;
}