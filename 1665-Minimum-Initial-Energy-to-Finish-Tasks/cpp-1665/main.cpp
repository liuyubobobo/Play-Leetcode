#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        map<int, map<int, int>> lowact, highmin;
        for(const vector<int>& v: tasks){
            lowact[v[0]][v[1]] ++;
            highmin[v[1]][v[0]] ++;
        }

        int l = 0, r = 2e9;
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(lowact, highmin, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(map<int, map<int, int>> lowact, map<int, map<int, int>> highmin, int k){

        while(!lowact.empty()){
            if(k == highmin.rbegin()->first){
                int mini = highmin.rbegin()->first, act = highmin.rbegin()->second.begin()->first;
                k -= act;

                highmin[mini][act] --;
                if(highmin[mini][act] == 0) highmin[mini].erase(act);
                if(highmin[mini].empty()) highmin.erase(mini);

                lowact[act][mini] --;
                if(lowact[act][mini] == 0) lowact[act].erase(mini);
                if(lowact[act].empty()) lowact.erase(act);
            }
            else if(k >= lowact.begin()->second.rbegin()->first){

                int act = lowact.begin()->first, mini = lowact.begin()->second.rbegin()->first;
                k -= act;

                highmin[mini][act] --;
                if(highmin[mini][act] == 0) highmin[mini].erase(act);
                if(highmin[mini].empty()) highmin.erase(mini);

                lowact[act][mini] --;
                if(lowact[act][mini] == 0) lowact[act].erase(mini);
                if(lowact[act].empty()) lowact.erase(act);
            }
            else return false;
        }
        return true;
    }
};

int main() {

    vector<vector<int>> tasks1 = {{1, 2}, {2, 4}, {4, 8}};
    cout << Solution().minimumEffort(tasks1) << endl;
    // 8

    vector<vector<int>> tasks2 = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
    cout << Solution().minimumEffort(tasks2) << endl;
    // 32

    vector<vector<int>> tasks3 = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};
    cout << Solution().minimumEffort(tasks3) << endl;
    // 27

    vector<vector<int>> tasks4 = {{1, 2}, {1, 7}, {2, 3}, {5, 9}, {2, 2}};
    cout << Solution().minimumEffort(tasks4) << endl;
    // 11

    return 0;
}
