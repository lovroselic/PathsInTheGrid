// PathsInTheGrid.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.codeabbey.com/index/task_view/paths-in-the-grid

#include <iostream>
#include <vector>
#include <string>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION 0.01

using namespace std;

int main()
{
    cout << "PathsInTheGrid v" << VERSION << "!\n\n";
    string path = "Test.txt";
    vector<string> raw_data = loadData(path);
    printVector(raw_data);
}


