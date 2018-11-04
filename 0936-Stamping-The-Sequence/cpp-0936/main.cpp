/// Source : https://leetcode.com/problems/stamping-the-sequence/
/// Author : liuyubobobo
/// Time   : 2018-11-03

#include <iostream>
#include <vector>

using namespace std;


/// Reverse Simulation
/// Time Complexity: O(len(target) * len(stamp))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {

        if(target.size() < stamp.size())
            return {};

        if(target.size() == stamp.size()){
            if(stamp == target)
                return {0};
            return {};
        }

        vector<int> res;
        while(!allQ(target, 0, target.size())){

            int pos = possibleStamp(target, stamp);
            if(pos == -1)
                return {};

            res.push_back(pos);
            for(int i = 0; i < stamp.size(); i ++)
                target[pos + i] = '?';
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    bool allQ(const string& s, int start, int end){
        for(int i = start; i < end; i ++)
            if(s[i] != '?')
                return false;
        return true;
    }

    int possibleStamp(const string& s, const string& stamp){

        for(int i = 0; i <= s.size() - stamp.size(); i ++)
            if(!allQ(s, i, i + stamp.size()) && ok(s, i, stamp))
                return i;
        return -1;
    }

    bool ok(const string& s, int start, const string& stamp){

        for(int i = 0; i < stamp.size(); i ++)
            if(s[start + i] != '?' && s[start + i] != stamp[i])
                return false;
        return true;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string stamp1 = "abc", target1 = "ababc";
    print_vec(Solution().movesToStamp(stamp1, target1));
    // [0, 2]

    string stamp2 = "abca", target2 = "aabcaca";
    print_vec(Solution().movesToStamp(stamp2, target2));
    // [3, 0, 1]

    return 0;
}