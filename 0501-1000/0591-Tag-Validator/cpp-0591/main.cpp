#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValid(string code) {

        while(true){
            int cdata_start = code.find("<![CDATA[");
            if(cdata_start == string::npos) break;
            if(cdata_start == 0) return false;

            int cdata_end = code.find("]]>", cdata_start);
            if(cdata_end == string::npos || cdata_end + 3 == code.size()) return false;

            code = code.substr(0, cdata_start) + code.substr(cdata_end + 3);
        }


        vector<string> tag_stack;
        int i = 0;
        while(i < code.size()){
            pair<int, int> tag_pos = get_tag_pos(code, i);
            int tag_start = tag_pos.first, tag_end = tag_pos.second;

            if(tag_start == -1) return false;
            if(i == 0 && tag_start != 0) return false;

            bool is_start_tag = true;
            string tag_name = "";
            if(code[tag_start + 1] == '/'){
                is_start_tag = false;
                tag_name = code.substr(tag_start + 2, tag_end - (tag_start + 2));
            }
            else{
                tag_name = code.substr(tag_start + 1, tag_end - (tag_start + 1));
            }

            if(!is_valid_tag(tag_name)) return false;

            if(is_start_tag){
                tag_stack.push_back(tag_name);
                i = tag_end + 1;
            }
            else{
                if(tag_stack.empty() || tag_stack.back() != tag_name) return false;
                tag_stack.pop_back();
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

    return 0;
}
