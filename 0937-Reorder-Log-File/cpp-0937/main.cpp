/// Source : https://leetcode.com/problems/reorder-log-files/
/// Author : liuyubobobo
/// Time   : 2018-11-11

#include <iostream>
#include <vector>

using namespace std;


/// Using Custom Class and overloading < operator to sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    class Log{

    private:
        string s;
        int index;
        string id;
        string after;
        bool is_letter;

    public:
        Log(const string& log, int index): s(log), index(index){

            int space = s.find(' ');
            id = s.substr(0, space);
            after = s.substr(space + 1);
            is_letter = isalpha(after[0]);
        }

        bool operator<(const Log& another){

            if(is_letter != another.is_letter)
                return is_letter;

            if(is_letter)
                return after == another.after ? id < another.id : after < another.after;
            return index < another.index;
        }

        string get_s() const{
            return s;
        }
    };

public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        vector<Log> arr;
        for(int i = 0; i < logs.size(); i ++)
            arr.push_back(Log(logs[i], i));

        sort(arr.begin(), arr.end());

        vector<string> res;
        for(const Log& e: arr)
            res.push_back(e.get_s());
        return res;
    }
};


int main() {

    return 0;
}