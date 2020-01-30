#include "Squarus.h"

//this is the default construtor that initializes the board.
Squarus::Squarus(QWidget *parent)
	: QMainWindow(parent)
{
	//14x14
	//each box 64 pixels wide
	//snapping blocks
	//4 pixel margin
	//display all the blocks at the bottom
	ui.setupUi(this);
	TheBoard = new Board(14);
	int value[20]; // tester

	//bool success = TheBoard->setSquare(0, 0, 1);
	TheBoard->placePiece(); //tester
	value[0] = TheBoard->getSquare(0, 0); //tester
	value[1] = TheBoard->getSquare(0, 1); //tester
	value[2] = TheBoard->getSquare(1, 1); //tester
	value[3] = TheBoard->getSquare(1, 2); //tester
	value[4] = TheBoard->getSquare(2, 2); //tester

	bool wait = 1;


	//testing:
	/*
	try
	{
		bool success1 = TheBoard->setSquare(1, 1, 5);
	}
	catch (std::logic_error)
	{
		wait = 1;
	}

	value[1] = TheBoard->getSquare(1, 1);

	bool success2 = TheBoard->setSquare(2, 2, 1);
	value[2] = TheBoard->getSquare(2, 2);

	bool success3 = TheBoard->setSquare(3, 3, 1);
	value[3] = TheBoard->getSquare(3, 3);
	value[4] = TheBoard->getSquare(4, 4);

	value[5] = TheBoard->getSquare(5, 5);
	try 
	{
		value[6] = TheBoard->getSquare(0, 15);
	}
	catch (std::range_error) 
	{
		wait = 1;
	}
	try
	{
		value[7] = TheBoard->getSquare(15, 0);
	}
	catch (std::range_error)
	{
		wait = 1;
	}

	for (int size = 0; size < 20; size++)
	{
		std::cout << "the value at " << size << " is: " << value[size] << std::endl;
	}
	*/
}
