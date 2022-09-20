/// Source : https://leetcode.com/problems/design-sql/
/// Author : liuyubobobo
/// Time   : 2022-09-20

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Simulation
/// Time Complexity: init: O(n)
///                  query: O(logn)
/// Space Complexity: O(all rows)
class SQL {

private:
    map<string, int> table_name_2_table_id;
    const vector<int> columns;
    vector<int> next_row_id;
    vector<vector<vector<string>>> tables;

public:
    SQL(vector<string>& names, vector<int>& columns) :
        columns(columns), next_row_id(names.size(), 1), tables(names.size()) {

        for(int i = 0; i < names.size(); i ++)
            table_name_2_table_id[names[i]] = i;
    }

    void insertRow(string name, vector<string> row) {

        int table_id = table_name_2_table_id[name];

        tables[table_id].push_back(row);
        next_row_id[table_id] ++;
    }

    void deleteRow(string name, int rowId) {

    }

    string selectCell(string name, int rowId, int columnId) {
        int table_id = table_name_2_table_id[name];
        return tables[table_id][rowId - 1][columnId - 1];
    }
};

int main() {

    return 0;
}
