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
	//string path = "Test.txt";
	string path = "try.txt";
	vector<string> raw_data = loadData(path);
	vector<string> first = splitString(raw_data[0], " ");
	const int ROW = stoi(first.at(0));
	const int COL = stoi(first.at(1));
	vector<vector<string>> data(ROW, vector<string>(COL, "."));
	for (int r = 1; r < raw_data.size(); r++) {
		vector<string> row = splitString(raw_data[r], " ");
		data.at(r - 1) = row;
	}

	print2DVector(data);
	vector<vector<int>> map(ROW, vector<int>(COL, 0));
	map[0][0] = 1;
	for (int c = 1; c < COL; c++) {
		if (data[0][c] == "+") {
			map[0][c] = map[0][c - 1];
		}
		else {
			map[0][c] = 0;
		}
	}
	for (int r = 1; r < ROW; r++) {
		if (data[r][0] == "+") {
			map[r][0] = map[r - 1][0];
		}
		else {
			map[r][0] = 0;
		}
	}
	for (int r = 1; r < ROW; r++) {
		for (int c = 1; c < COL; c++) {
			if ((data[r][c] == "+") || (data[r][c] == "$")) {
				map[r][c] += map[r - 1][c];
				map[r][c] += map[r][c - 1];
			}
			else {
				map[r][c] = 0;
			}
		}
	}
	print2DVector(map);
	cout << "Result: " << map[ROW - 1][COL - 1] << endl;
}


