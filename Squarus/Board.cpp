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

	piece.head.value = 5;
	piece.head.orientation = one;

	shapeVector.push_back(make_tuple(0, 0, 1)); //testing
	shapeVector.push_back(make_tuple(0, 1, 1)); //testing
	shapeVector.push_back(make_tuple(1, 1, 1)); //testing
	shapeVector.push_back(make_tuple(1, 2, 1)); //testing
	shapeVector.push_back(make_tuple(2, 2, 1)); //testing
	
	piece.head.shapesVector = shapeVector;


	//prelimnary placement of first piece:
	for (int tupleIt = 0; tupleIt < shapeVector.size(); tupleIt++)
	{
		setSquare(get<0>(shapeVector.back()), get<1>(shapeVector.back()), std::get<2>(shapeVector.back()));
		//may consider using a queue or stack
		shapeVector.pop_back();
		tupleIt--;
	}

	//should be done in construction to add all pieces to piece list
	Atom newPiece(5);
	newPiece.shapesVector.push_back(make_tuple(0, 0, 1));
	newPiece.shapesVector.push_back(make_tuple(1, 0, 1));
	newPiece.shapesVector.push_back(make_tuple(2, 0, 1));
	newPiece.shapesVector.push_back(make_tuple(3, 0, 1));
	newPiece.shapesVector.push_back(make_tuple(4, 0, 1));
	newPiece.orientation = one;
	pieceVector.push_back(newPiece);

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
	//this vector is declared locally within this method
	//so that the cornerVector is always new
	vector <tuple<int, int>> cornerVector;
	//may create vector of all placed piece coordinates so that performance is increased with a small
	//storage cost

	if (playersVector.empty())//or if the first player just went
	{
		cornerVector.push_back(make_tuple(0, 0));
		return cornerVector;
	}

	for (int pieceIteratorX = 0; pieceIteratorX < size; pieceIteratorX++)
	{
		for (int pieceIteratorY = 0; pieceIteratorY < size; pieceIteratorY++)
		{
			//does the piece belong to the ai
			if (getSquare(pieceIteratorX, pieceIteratorY) == 1)
			{
				if (getSquare(pieceIteratorX - 1, pieceIteratorY - 1) == 0)
				{
					cornerVector.push_back(make_tuple(pieceIteratorX - 1, pieceIteratorY - 1));
				}
				if (getSquare(pieceIteratorX - 1, pieceIteratorY + 1) == 0)
				{
					cornerVector.push_back(make_tuple(pieceIteratorX - 1, pieceIteratorY + 1));
				}
				if (getSquare(pieceIteratorX + 1, pieceIteratorY - 1) == 0)
				{
					cornerVector.push_back(make_tuple(pieceIteratorX + 1, pieceIteratorY - 1));
				}
				if (getSquare(pieceIteratorX + 1, pieceIteratorY + 1) == 0)
				{
					cornerVector.push_back(make_tuple(pieceIteratorX + 1, pieceIteratorY + 1));
				}
			}
		}
	}

	for (int cornerIterator = 0; cornerIterator < cornerVector.size(); cornerIterator++)
	{
		int tempX = get<0>(cornerVector[cornerIterator]);
		int tempY = get<1>(cornerVector[cornerIterator]);
		if (tempY != 0 && getSquare(tempX, tempY - 1) != 0)
		{
			//this is where a stack would be very convenient to pop
			cornerVector.erase(cornerVector.begin() + cornerIterator);
			cornerIterator--;
		}
		else if (getSquare(tempX, tempY + 1) != 0)
		{
			cornerVector.erase(cornerVector.begin() + cornerIterator);
			cornerIterator--;
		}
		else if (tempX != 0 && getSquare(tempX - 1, tempY) != 0)
		{
			cornerVector.erase(cornerVector.begin() + cornerIterator);
			cornerIterator--;
		}
		else if (getSquare(tempX + 1, tempY) != 0)
		{
			cornerVector.erase(cornerVector.begin() + cornerIterator);
			cornerIterator--;
		}
		else if (tempX < 0)
		{
			cornerVector.erase(cornerVector.begin() + cornerIterator);
			cornerIterator--;
		}		
		else if (tempY < 0)
		{
			cornerVector.erase(cornerVector.begin() + cornerIterator);
			cornerIterator--;
		}		
		else if (tempX > size)
		{
			cornerVector.erase(cornerVector.begin() + cornerIterator);
			cornerIterator--;
		}		
		else if (tempY > size)
		{
			cornerVector.erase(cornerVector.begin() + cornerIterator);
			cornerIterator--;
		}
	}

	return cornerVector;
}

//I will add a paramter that indicates which piece should be added and where.
bool Board::placePiece()
{
	//I am now thinking these considerations wil be made within this method:
		//Most likely A separate method will be used to evaluate whether the place should be placed
		//(considers bounds checking, points structure, rotations (and coordinate fixing): https://www.desmos.com/calculator/128qknz9fw

	//rotations could be handled by considering them in one of four posititions:
	//1,2,3, or 4 referring to the quadrants the shape would be in if they were rotated

	//may call placement checking method here (overlap and corner check, range is checked elesewhere):
	//perhaps a lower range check could be avoided via the use of uint's, but rotation math could get ugly

	//finds the available corners to consider placement


	//finds available corner to place the piece
	vector <tuple<int, int>> potentialCornerVector = findCorners();

	//iterate through piecevector and create a child for each possibility
	for (int potentialPieceIterator = 0; potentialPieceIterator < pieceVector.size(); potentialPieceIterator++)
	{
		/*
		 1. check if the piece can be placed at the available corner spaces
		 2. if it can, add the piece to the tail of the currentHead.
		*/
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

	playersVector.push_back(make_tuple(x, y, value));
	placements[x][y] = value;
	return true;
}

int Board::getSquare(int x, int y)
{
	//bounds checking of both x and y, throw range error.
	try
	{
		rangeCheck(x, y);
	}
	catch (std::range_error)
	{
		return -1;
	}

	return placements[x][y];
}

Board::Board()
{
	Board(14);

}

Board::Atom::Atom(int value)
{
	value = value;
}

Board::Atom::Atom(vector<tuple<int, int, int>> shapesVector)
{
	//insert copy constructor
	shapesVector = shapesVector;
}
