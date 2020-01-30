#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Squarus.h"
#include "Board.h"

class Squarus : public QMainWindow
{
	Q_OBJECT

public:
	Squarus(QWidget *parent = Q_NULLPTR);
	Board * TheBoard;

private:
	Ui::SquarusClass ui;
};
