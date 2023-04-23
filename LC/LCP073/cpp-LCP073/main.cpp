/// Source : https://leetcode.cn/problems/0Zeoeg/
/// Author : liuyubobobo
/// Time   : 2023-04-22

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Simulation
/// Time Complexity: O(|total_characters|)
/// Space Complexity: O(|total_characters|)
class Solution {
public:
    int adventureCamp(vector<string>& expeditions) {

        set<string> init_set = get_set(expeditions[0]);

        int best = 0, res = -1;
        for(int i = 1; i < expeditions.size(); i ++){
            set<string> cur_set = get_set(expeditions[i]);
            int cur = 0;
            for(const string& s: cur_set)
                cur += !init_set.count(s);

            if(cur > best) best = cur, res = i;

            for(const string& s: cur_set)
                init_set.insert(s);
        }
        return res;
    }

private:
    set<string> get_set(const string& s){

        set<string> res;
        int pos = 0;
        while(pos < s.size()){
            int arrow_pos = s.find("->", pos);
            if(arrow_pos == string::npos){
                res.insert(s.substr(pos));
                break;
            }
            res.insert(s.substr(pos, arrow_pos - pos));
            pos = arrow_pos + 2;
        }
        return res;
    }
};


int main() {

    // ["xO->xO->xO","xO->BKbWDH","xO->BKbWDH","BKbWDH->mWXW","LSAYWW->LSAYWW","oAibBvPdJ","LSAYWW->u","LSAYWW->LSAYWW"]
    // 1
    return 0;
}
