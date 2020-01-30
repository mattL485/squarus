#include "Board.h"


//this initializes the board.
Board::Board(int dimensions)
{
	this->size = dimensions;
	placements = new int *[size];
	for (int sizeIt = 0; sizeIt < size; sizeIt++)
	{
		placements[sizeIt] = new int[size];
		
		//sets the default placement to zero.
		std::memset(placements[sizeIt], 0, size * sizeof(int));
	}
	/*
	 
	  **
	 **
	 *
	 
	 is the shape in the vector below
	 */

	shapeVector.push_back(make_tuple(0, 0, 1)); //testing
	shapeVector.push_back(make_tuple(0, 1, 1)); //testing
	shapeVector.push_back(make_tuple(1, 1, 1)); //testing
	shapeVector.push_back(make_tuple(1, 2, 1)); //testing
	shapeVector.push_back(make_tuple(2, 2, 1)); //testing

	//for (int sizeIteratorX = 0; sizeIteratorX < size; sizeIteratorX++)
	//{
	//	for (int sizeIteratorY = 0; sizeIteratorY < size; sizeIteratorY++)
	//	{
	//		placements.first.push_back(//.push_back(0);
	//	}
	//}
}

void Board::rangeCheck(int x, int y)
{
	//x range checking:
	if (x < 0)
	{
		throw(std::range_error("negative x location not allowed"));
	}
	if (x > size)
	{
		throw(std::range_error("out of bounds x location"));
	}

	//y range checking:
	if (y < 0)
	{
		throw(std::range_error("negative y location not allowed"));
	}
	if (y > size)
	{
		throw(std::range_error("out of bounds y location"));
	}
}

vector<tuple<int, int>> Board::findCorners()
{
	vector <tuple<int, int>> cornerVector;
	//may create vector of all placed piece coordinates so that performance is increased with a small
	//storage cost
	
	for (int pieceIteratorX = 0; pieceIteratorX < size; pieceIteratorX++)
	{
		for (int pieceIteratorY = 0; pieceIteratorY < size; pieceIteratorY++)
		{
			//does the piece belong to the ai
			if (getSquare(pieceIteratorX, pieceIteratorY) == 1)
			{
				if (getSquare(pieceIteratorX - 1, pieceIteratorY - 1))
				{
					cornerVector.push_back(make_tuple(pieceIteratorX - 1, pieceIteratorY - 1));
					
				}
			}
		}
	}
}

//I will add a paramter that indicates which piece should be added and where.
bool Board::placePiece()
{
	//I am now thinking these considerations wil be made within this method:
		//Most likely A separate method will be used to evaluate whether the place should be placed
		//(considers bounds checking, points structure, rotations (and coordinate fixing): https://www.desmos.com/calculator/128qknz9fw

	//rotations could be handled by considering them in one of four posititions:
	//1,2,3, or 4 referring to the quadrants the shape would be in if they were rotated

	int size = shapeVector.size();
	for (int tupleIt = 0; tupleIt < size; tupleIt++)
	{
		//may call placement checking method here (overlap and corner check, range is checked elesewhere):
		//perhaps a lower range check could be avoided via the use of uint's, but rotation math could get ugly

		setSquare(get<0>(shapeVector.back()), get<1>(shapeVector.back()), std::get<2>(shapeVector.back()));
		//may consider using a queue or stack
		shapeVector.pop_back();
	}
	return false;
}

void Board::getBoard()
{
}

bool Board::setSquare(int x, int y, int value)
{
	//bounds checking of x, y, and value, throw range error.
	if (value != 1)
	{
		throw(std::logic_error("bad value"));
	}
	rangeCheck(x, y);

	placements[x][y] = value;
	return true;
}

int Board::getSquare(int x, int y)
{
	//bounds checking of both x and y, throw range error.
	rangeCheck(x, y);

	return placements[x][y];
}

Board::Board()
{
	Board(14);

}
