/// Source : https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


/// Hashing Table
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {

        unordered_map<string, vector<int>> map;
        for(int i = 0; i < keyName.size(); i ++)
            map[keyName[i]].push_back(time_to_int(keyTime[i]));

        set<string> res;
        for(const pair<string, vector<int>>& p: map){
            vector<int> t = p.second;
            sort(t.begin(), t.end());
            for(int i = 0; i + 2 < p.second.size(); i ++)
                if(t[i + 2] - t[i] <= 60){
                    res.insert(p.first);
                    break;
                }
        }
        return vector<string>(res.begin(), res.end());
    }

private:
    int time_to_int(const string& t){
        return ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + (t[3] - '0') * 10 + (t[4] - '0');
    }
};


void print_vec(const vector<string>& res){
    for(const string& s: res) cout << s << " "; cout << endl;
}

int main() {

    vector<string> name1 = {"daniel","daniel","daniel","luis","luis","luis","luis"};
    vector<string> time1 = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    print_vec(Solution().alertNames(name1, time1));

    return 0;
}
