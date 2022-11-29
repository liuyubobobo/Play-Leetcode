/// Source : https://leetcode.com/problems/split-message-based-on-limit/description/
/// Author : liuyubobobo
/// Time   : 2022-11-28

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> splitMessage(string message, int limit) {

        int n = message.size();
        for(int part_len = 1;part_len + part_len + 3 < limit; part_len ++){
            vector<string> res;
            if(ok(n, message, part_len, limit, res)) return res;
        }
        return {};
    }

private:
    bool ok(int n, const string& message, int part_len, int limit, vector<string>& res){

        string part_num(part_len, '#');
        for(int i = 1, j = 0; j < n; i ++){
            string i_str = to_string(i);
            if(i_str.size() > part_len) return false;

            string suf = "<" + i_str + "/" + part_num + ">";
            int content_len = limit - suf.size();
            string content = message.substr(j, content_len);
            j += content_len;

            res.push_back(content + suf);
        }

        string len = to_string(res.size());
        if(len.size() != part_len) return false;

        for(string& s: res) s.replace(s.find(part_num), part_len, len);
        return true;
    }
};


void print_vec(const vector<string>& v){
    for(const string& e: v) cout << e << '\n';
}

int main() {

    string message1 = "this is really a very awesome message";
    print_vec(Solution().splitMessage("this is really a very awesome message", 9));

    return 0;
}
