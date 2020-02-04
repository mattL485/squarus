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
	//placements represents all the current pieces placed
	//on the board and who their respective player is
	int ** placements;
	//shapeVector contains all of the size and positional
	//data for each piece
	vector <tuple<int, int, int>> shapeVector;
	vector <tuple<int, int, int>> playersVector;
	//int getBoard;
	bool gameover;

	//a simplification of what the quadrant would be
	enum Orientation {one, two, three, four};


	// An Atom has positions, orientation, and value
	struct Atom 
	{
		Atom()
		{
			value = 0;
		}
		vector <tuple<int, int, int>> shapesVector;
		Orientation orientation;
		int value;

		Atom(int value);
		Atom(vector <tuple<int, int, int>> shapesVector);
		//positions (shapeVector?)
	};

	//this vector of structs contains all of the data for the pieces
	//used in the game
	vector<Atom> pieceVector;

	// A Piece is an Atom called the head
	// followed by a (possibly empty) list of pieces
	// called the tail.
	//Each piece that is added needs to be able 
	//to have it's total value calculated
	struct Piece 
	{
		Atom head;
		Piece()
		{
			head.value = 0;
		};
		std::vector<Piece> tail;
	};

	Piece piece;


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