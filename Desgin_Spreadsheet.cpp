#include<iostream>
#include<vector>
using namespace std;

class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid;

    pair<int, int> parseCell(const string &cell) {
        char col = cell[0];
        int c = col - 'A';
        int r = stoi(cell.substr(1)) - 1;
        return {r, c};
    }

    int getCellValue(const string &s) {
        if (isdigit(s[0])) return stoi(s);
        auto [r, c] = parseCell(s);
        return grid[r][c];
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }

    int getValue(string formula) {
        formula = formula.substr(1);
        int plusPos = formula.find('+');
        string a = formula.substr(0, plusPos);
        string b = formula.substr(plusPos + 1);
        return getCellValue(a) + getCellValue(b);
    }
};

int main (){

}