/// Source : https://leetcode-cn.com/contest/cnunionpay-2022spring/problems/kDPV0f/
/// Author : liuyubobobo
/// Time   : 2022-03-13

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Simulation
/// Time Complexity: init: O(1)
///                  add: O(1)
///                  remove: O(1)
///                  consume: O(n)
/// Space Complexity: O(n)
class DiscountSystem {

private:
    vector<vector<int>> activity; // 0: priceLimit, 1: discount, 2: number, 3: userLimit
    vector<vector<int>> user_in_act; // {useid, actid} -> freq
    vector<int> act_number; // actid -> number
    int max_id = -1;

public:
    DiscountSystem() :
        activity(1001, {-1, -1, -1, -1}),
        user_in_act(1001, vector<int>(1001, 0)),
        act_number(1001, 0){}

    void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {
        activity[actId] = {priceLimit, discount, number, userLimit};
        max_id = max(max_id, actId);
    }

    void removeActivity(int actId) {
        activity[actId] = {-1, -1, -1, -1};
    }

    int consume(int userId, int cost) {

        int best_act_id = -1, best_discount = -1;
        for(int actid = 0; actid <= max_id; actid ++){
            if(activity[actid][0] == -1) continue;
            if(cost < activity[actid][0]) continue;
            if(user_in_act[userId][actid] >= activity[actid][3]) continue;
            if(act_number[actid] >= activity[actid][2]) continue;

            if(activity[actid][1] > best_discount)
                best_act_id = actid, best_discount = activity[actid][1];
        }

        if(best_act_id == -1) return cost;

        user_in_act[userId][best_act_id] ++;
        act_number[best_act_id] ++;
        return max(cost - best_discount, 0);
    }
};


int main() {

    DiscountSystem sys;
    sys.addActivity(1, 10, 6, 3, 2);
    sys.addActivity(2, 15, 8, 8, 2);
    cout << sys.consume(101, 13) << '\n'; // 7
    sys.removeActivity(2);

    return 0;
}
