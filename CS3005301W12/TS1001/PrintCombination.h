/***********************************************************************
 * File: PrintCombination.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/05/13
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/13
 * Description: Print Combination
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

std::vector<int> combination;
int start = 0;
int row = 0;


// Intent: To print all combinations of m elements taken n at a time from an integer array
// Pre: An integer array with size m, a positive integer n
// Post: The function prints all combinations of m elements taken n at a time to the console
void PrintCombination(int arr[], int m, int n) {
    if (n == 0) {
        if (row != 0)
        {
            cout << endl;
        }
        for (int i = 0; i < combination.size(); i++) {
            if (i != 0)
            {
                cout << " ";
            }
            cout << combination[i];
        }
        row += 1;
        return;
    }

    for (int i = start; i <= m - n; i++) {
        combination.push_back(arr[i]);
        start = i + 1;
        PrintCombination(arr, m, n - 1);
        combination.pop_back();
    }
}