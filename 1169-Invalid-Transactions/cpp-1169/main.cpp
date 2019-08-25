/// Source : https://leetcode.com/problems/invalid-transactions/
/// Author : liuyubobobo
/// Time   : 2019-08-24

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {

private:
    class Transaction{

    public:
        string name, city;
        int time, amount;

        Transaction(const string& name, int time, int amount, const string& city):
            name(name), time(time), amount(amount), city(city){}
    };

    vector<Transaction> vec;

public:
    vector<string> invalidTransactions(vector<string>& transactions) {


        for(const string& s: transactions)
            vec.push_back(getTransaction(s));

        vector<string> res;
        for(int i = 0; i < vec.size(); i ++)
            if(vec[i].amount > 1000 || suspicious(i))
                res.push_back(transactions[i]);

        return res;
    }

private:
    bool suspicious(int index){

        for(int i = 0; i < vec.size(); i ++)
            if(i != index &&
               vec[i].name == vec[index].name &&
               vec[i].city != vec[index].city &&
               abs(vec[i].time - vec[index].time) <= 60) return true;
        return false;
    }

    Transaction getTransaction(const string& s){

        int name_i = s.find(',');
        string name = s.substr(0, name_i);

        int time_i = s.find(',', name_i + 1);
        int time = atoi(s.substr(name_i + 1, time_i - (name_i + 1)).c_str());

        int amount_i = s.find(',', time_i + 1);
        int amount = atoi(s.substr(time_i + 1, amount_i - (time_i + 1)).c_str());

        string city = s.substr(amount_i + 1);

        return Transaction(name, time, amount, city);
    }
};


int main() {

    return 0;
}