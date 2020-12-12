#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    string predictPartyVictory(string senate) {

        int n = senate.size();
        vector<bool> ban(n, false);

        set<int> R, D;
        for(int i = 0; i < n; i ++)
            if(senate[i] == 'R') R.insert(i);
            else D.insert(i);

        int index = 0;
        while(!R.empty() && !D.empty()){

            if(!ban[index]){
                int banid;
                if(senate[index] == 'R'){
                    set<int>::iterator iter = D.lower_bound(index);
                    if(iter == D.end()) iter = D.begin();
                    banid = *iter;
                    D.erase(iter);
                }
                else{
                    set<int>::iterator iter = R.lower_bound(index);
                    if(iter == R.end()) iter = R.begin();
                    banid = *iter;
                    R.erase(iter);
                }

                ban[banid] = true;
            }

            index = (index + 1) % n;
        }
        return R.empty() ? "Dire" : "Radiant";
    }
};


int main() {

    cout << Solution().predictPartyVictory("DRRDRDRDRDDRDRDR") << endl;
    // R

    return 0;
}
