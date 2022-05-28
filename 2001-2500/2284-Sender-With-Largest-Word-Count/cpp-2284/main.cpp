/// Source : https://leetcode.com/problems/sender-with-largest-word-count/
/// Author : liuyubobobo
/// Time   : 2022-05-28

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(nlogn * |message|)
/// Space Complexity: O(n)
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        int n = messages.size();

        map<string, int, greater<string>> cnt;
        for(int i = 0; i < n; i ++){
            string name = senders[i];
            cnt[name] += get_cnt(messages[i]);
        }

        int largest = -1;
        string res = "";
        for(const pair<string, int>& p: cnt)
            if(p.second > largest) res = p.first, largest = p.second;
        return res;
    }

private:
    int get_cnt(const string& s){

        int res = 0;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                res ++;
                start = i + 1;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}
