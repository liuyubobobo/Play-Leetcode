/// Source : https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


/// Sorting and Sliding Window
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {

        vector<pair<int, string>> v;
        for(int i = 0; i < keyName.size(); i ++)
            v.push_back({time_to_int(keyTime[i]), keyName[i]});

        sort(v.begin(), v.end());

        unordered_map<string, int> f;
        set<string> res;
        int l = 0, r = -1;
        while(l < v.size()){
            if(r + 1 < v.size() && v[r + 1].first - v[l].first <= 60){
                r ++;
                f[v[r].second] ++;
                if(f[v[r].second] >= 3) res.insert(v[r].second);
            }
            else f[v[l ++].second] --;
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
