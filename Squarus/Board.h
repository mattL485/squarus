#pragma once
//#include "Pieces.h"
//#include <bits/stdc++.h> 
#include <vector>
#include <iostream>
#include <tuple>

using std::get;
using std::vector;
using std::tuple;
using std::cout;
using std::make_tuple;

class Board
{
	size_t size;
	int ** placements;
	vector <tuple<int, int, int>> shapeVector;
	//int getBoard;
	bool gameover;

	//Pieces
	//vector <Pieces>
public:
	void /*for now*/ getBoard();
	bool setSquare(int x, int y, int value);
	int getSquare(int x, int y);
	Board();
	Board(int dimensions);
	void rangeCheck(int x, int y);
	vector<tuple<int, int>> findCorners();
	//vector <tuple<int x, int y, int value>> tupleVector;
	bool placePiece(/*will add type later, considering enum or struct of pieces*/);
};