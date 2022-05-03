/// Source : https://leetcode.com/problems/tag-validator/
/// Author : liuyubobobo
/// Time   : 2022-05-03

#include <iostream>
#include <vector>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isValid(string code) {

        vector<string> tag_stack;
        int i = 0;
        while(i < code.size()){
            pair<int, int> tag_pos = get_tag_pos(code, i);
            int tag_start = tag_pos.first, tag_end = tag_pos.second;

            if(tag_start == -1) return false;
            if(i == 0 && tag_start != 0) return false;

            // end tag
            if(code[tag_start + 1] == '/'){
                string tag_name = code.substr(tag_start + 2, tag_end - (tag_start + 2));
                if(!is_valid_tag(tag_name)) return false;

                if(tag_stack.empty() || tag_stack.back() != tag_name) return false;
                tag_stack.pop_back();
                i = tag_end + 1;
            }
            else if(code.find("<![CDATA[", tag_start) == tag_start){ // cdata tag
                if(tag_start == 0) return false;

                int cdata_end = code.find("]]>", tag_start);
                if(cdata_end == string::npos || cdata_end + 3 == code.size()) return false;

                i = cdata_end + 3;
            }
            else{ // start tag
                string tag_name = code.substr(tag_start + 1, tag_end - (tag_start + 1));
                if(!is_valid_tag(tag_name)) return false;

                tag_stack.push_back(tag_name);
                i = tag_end + 1;
            }

            if(i < code.size() && tag_stack.empty()) return false;
        }

        return  i == code.size() && tag_stack.empty();
    }

private:
    bool is_valid_tag(const string& tag){
        if(tag.empty() || tag.size() > 9) return false;
        for(char c: tag)
            if(!isupper(c)) return false;
        return true;
    }

    pair<int, int> get_tag_pos(const string& s, int index){

        int start_pos = s.find('<', index);
        if(start_pos == string::npos) return {-1, -1};

        int end_pos = s.find('>', start_pos);
        if(end_pos == string::npos) return {-1, -1};

        return {start_pos, end_pos};
    }
};


int main() {

    cout << Solution().isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>") << '\n';
    // 1

    cout << Solution().isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>") << '\n';
    // 1

    cout << Solution().isValid("<A>  <B> </A>   </B>") << '\n';
    // 0

    cout << Solution().isValid("<TRUE><![CDATA[wahaha]]]><![CDATA[]> wahaha]]></TRUE>") << '\n';
    // 1

    cout << Solution().isValid("<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>") << '\n';
    // 0

    cout << Solution().isValid("<A></A><B></B>") << '\n';
    // 0

    cout << Solution().isValid("<TAG>sometext</TAG><![CDATA[ABC]]>") << '\n';
    // 0

    cout << Solution().isValid("<TAG>sometext</TA<![CDATA[ABC]]>G>") << '\n';
    // 0

    return 0;
}
