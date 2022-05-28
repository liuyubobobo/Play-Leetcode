/// Source : https://leetcode.com/problems/validate-ip-address/
/// Author : liuyubobobo
/// Time   : 2021-05-28

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string validIPAddress(string queryIP) {

        vector<string> v;
        if(queryIP.find('.') != string:: npos)
            v = split_ip(queryIP, '.');

        if(queryIP.find(':') != string:: npos)
            v = split_ip(queryIP, ':');

        if(v.size() == 4 && isIPv4(v)) return "IPv4";
        if(v.size() == 8 && isIPv6(v)) return "IPv6";
        return "Neither";
    }

private:
    vector<string> split_ip(const string& ip, char split_char){

        if(ip[0] == split_char || ip.back() == split_char) return {};

        vector<string> v;
        for(int start = 0, i = 1; i <= ip.size(); i ++)
            if(i == ip.size() || ip[i] == split_char){
                v.push_back(ip.substr(start, i - start));
                start = i + 1;
                i = start;
            }
        return v;
    }

    bool isIPv4(const vector<string>& v){
        for(const string& s: v)
            if(!ipv4_seg(s)) return false;
        return true;
    }

    bool ipv4_seg(const string& s){

        if(s == "0") return true;
        if(s[0] == '0') return false;
        if(s.size() > 3) return false;

        for(char c: s) if(!isdigit(c)) return false;

        int x = atoi(s.c_str());
        return 0 <= x && x <= 255;
    }

    bool isIPv6(const vector<string>& v){
        for(const string& s: v)
            if(!ipv6_seg(s)) return false;
        return true;
    }

    bool ipv6_seg(const string& s){

        if(s == "0") return true;
        if(s.size() > 4) return false;

        for(char c: s)
            if(!(isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F')))
                return false;
        return true;
    }
};


int main() {

    return 0;
}
