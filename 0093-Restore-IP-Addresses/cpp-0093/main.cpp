/// Source : https://leetcode.com/problems/restore-ip-addresses/
/// Author : liuyubobobo
/// Time   : 2019-01-18

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> res;
        vector<int> ip;
        dfs(s, 0, ip, res);
        return res;
    }

private:
    void dfs(const string& s, int index, vector<int>& ip, vector<string>& res){

        if(index == s.size()){
            if(ip.size() == 4)
                res.push_back(get_string(ip));
            return;
        }

        if(index == 0){
            ip.push_back(s[0] - '0');
            dfs(s, index + 1, ip, res);
        }
        else{
            int next = ip.back() * 10 + (s[index] - '0');
            if(next <= 255 && ip.back() != 0){
                ip.back() = next;
                dfs(s, index + 1, ip, res);
                ip.back() /= 10;
            }
            if(ip.size() < 4){
                ip.push_back(s[index] - '0');
                dfs(s, index + 1, ip, res);
                ip.pop_back();
            }
        }
    }

    string get_string(const vector<int>& ip){
        string res = to_string(ip[0]);
        for(int i = 1; i < ip.size(); i ++)
            res += "." + to_string(ip[i]);
        return res;
    }
};


void print_vec(const vector<string>& vec){

    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string s1 = "25525511135";
    print_vec(Solution().restoreIpAddresses(s1));
    // 255.255.111.35 255.255.11.135

    string s2 = "1";
    print_vec(Solution().restoreIpAddresses(s2));
    // empty

    string s3 = "010010";
    print_vec(Solution().restoreIpAddresses(s3));
    // 0.10.0.10 0.100.1.0

    return 0;
}