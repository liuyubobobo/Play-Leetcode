/// Source : https://leetcode.com/problems/best-poker-hand/
/// Author : liuyubobobo
/// Time   : 2022-07-23

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {

        if(is_flush(suits)) return "Flush";

        sort(ranks.begin(), ranks.end());
        int max_same = get_max_same(ranks);
        if(max_same >= 3) return "Three of a Kind";
        else if(max_same == 2) return "Pair";
        return "High Card";
    }

private:
    int get_max_same(const vector<int>& data){

        int n = data.size(), res = 0;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || data[i] != data[start]){
                res = max(res, i - start);
                start = i;
            }
        return res;
    }

    bool is_flush(const vector<char>& suits){
        for(int i = 1; i < suits.size(); i ++)
            if(suits[i] != suits[0]) return false;
        return true;
    }
};


int main() {

    return 0;
}
