/// Source : https://leetcode.cn/contest/cnunionpay2022/problems/NyZD2B/
/// Author : liuyubobobo
/// Time   : 2022-09-23

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;


/// Using Map and Set to simulate
/// Time Complexity: O(logn)
/// Space Complexity: O(n)
class VendingMachine {

private:
    map<string, int> discounts;
    map<string, map<pair<int, int>, int>> items; // name -> price, expire_time -> number

public:
    VendingMachine() {

    }

    void addItem(int time, int number, string item, int price, int duration) {
        items[item][{price, time + duration}] += number;
    }

    long long sell(int time, string customer, string item, int number) {

        if(!items.count(item)) return -1;

        map<pair<int, int>, int>& s = items[item];
        vector<pair<int, int>> v, dels;
        int total = 0;
        for(const pair<pair<int, int>, int>& p: s){
            int expiration = p.first.second, cnt = p.second;
            if(expiration < time){
                dels.push_back(p.first);
                continue;
            }

            v.push_back(p.first);
            total += cnt;
            if(total >= number) break;
        }

        for(const pair<int, int>& del_key: dels) s.erase(del_key);

        if(total < number) return -1;

        int discount = 100;
        if(discounts.count(customer)){
            discount = discounts[customer];
            discounts[customer] = discount - 1;
        }
        else discounts[customer] = 99;

        long long total_price = 0;
        for(const pair<int, int>& buy_key: v){
            int cnt = s[buy_key];
            int buy_cnt = min(number, cnt);
            number -= buy_cnt;
            cnt -= buy_cnt;
            total_price += 1ll * buy_key.first * buy_cnt;

            if(cnt == 0) s.erase(buy_key);
            else s[buy_key] = cnt;
        }

        return total_price * discount / 100ll + !!(total_price * discount % 100ll);
    }
};

int main() {

    return 0;
}
