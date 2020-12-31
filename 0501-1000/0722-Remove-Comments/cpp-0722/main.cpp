/// Source : https://leetcode.com/problems/remove-comments/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// Parsing
/// Time Complexity: O(s) where s is the total length of source
/// Space Complexity: O(mw) where mw is the max length of one line
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {

        vector<string> res;

        bool left = false;
        string leftString = "";
        for(int i = 0 ; i < source.size() ; ){
            string code = source[i];

            if(left){
                size_t pos = code.find("*/");
                if(pos != string::npos){
                    code = leftString + code.substr(pos+2);
                    left = false;
                }
                else{
                    i ++;
                    continue;
                }
            }

            size_t pos1 = code.find("//");
            size_t pos2 = code.find("/*");
            if(pos1 == string::npos && pos2 == string::npos){
                if(code != "")
                    res.push_back(code);
                i ++;
            }
            else if(pos1 != string::npos && (pos2 == string::npos || pos1 < pos2)){
                if(pos1 != 0)
                    res.push_back(code.substr(0, pos1));
                i ++;
            }
            else if(pos2 != string::npos && (pos1 == string::npos || pos2 < pos1)){
                size_t pos_right = code.find("*/", pos2+2);
                if(pos_right != string::npos)
                    source[i] = code.substr(0, pos2) + code.substr(pos_right+2);
                else{
                    left = true;
                    leftString = code.substr(0, pos2);
                    i ++;
                }
            }
        }

        return res;
    }
};


void printCode(const vector<string>& code){
    for(string line: code)
        cout << line << endl;
}
int main() {

    vector<string> source1;
    source1.push_back("/*Test program */");
    source1.push_back("int main()");
    source1.push_back("{ ");
    source1.push_back("  // variable declaration ");
    source1.push_back("int a, b, c;");
    source1.push_back("/* This is a test");
    source1.push_back("   multiline  ");
    source1.push_back("   comment for ");
    source1.push_back("   testing */");
    source1.push_back("a = b + c;");
    source1.push_back("}");
    printCode(Solution().removeComments(source1));

    /*
    int main()
    {

    int a, b, c;
    a = b + c;
    }
    */

    cout << endl;

    // ---

    vector<string> source2;
    source2.push_back("a/*comment");
    source2.push_back("line");
    source2.push_back("more_comment*/b");

    printCode(Solution().removeComments(source2));

    // "ab"

    return 0;
}