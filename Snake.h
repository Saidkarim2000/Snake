/*
ID: U1910033, U1910007
Full Names: Yuldashev Saidkarim, Zafarov Saidakbar
*/



#include<iostream>
#include<cfguard.h> // cfguard.h is used in order to tackle the type redefinition error in the class Snake
#include<conio.h> // This library allows to keep track of what user enters

using namespace std;


class Snake
{
private:
	int a, b, fruitX, fruitY, score;
	int Number_Of_Tails;

public:

	int getA()
	{
		return a;
	}
	void setA(int x) { a = x; }
	int getB() { return b; }
	void setB(int y)
	{
		b = y;
	}
	int getFruitX()
	{
		return fruitX;
	}
	void setFruitX(int f_x)
	{
		fruitX = f_x;
	}
	int getFruitY()
	{
		return fruitY;
	}
	void setFruitY(int f_y)
	{
		fruitY = f_y;
	}
	int getScore()
	{
		return score;
	}
	void setScore(int s)
	{
		score = s;
	}
	int getNumber_Of_Tails()
	{
		return Number_Of_Tails;
	}
	void setNumber_Of_Tails(int nTail)
	{
		Number_Of_Tails = nTail;
	}
};

class Game : public Snake
{
public:
	bool G_O;
	int x, y, f_x, f_y, s;
	long int nTail = 0;
	const int width = 40; // This is just the width of the map
	const int height = 15; // The height of the map
	long int tailX[100], tailY[100];
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; // enum eDirection is declaring an enumeration called eDirection, which essentially becomes a new type
	eDirection direction;   // eDirection dir; is saying "a variable of type eDirection", which can either be STOP, LEFT, RIGHT, UP, or DOWN.

	void Setup()
	{
		G_O = false;
		direction = STOP; // Snake will be stayed on its place and not move
		x = width / 2 - 1;
		y = height / 2 - 1;
		f_x = rand() % width; // The rand() function is necessary for the random appearance of fruits on the map.
		f_y = rand() % height;
		s = 0;
	}
	void Map() {
		system("cls"); // It is needed to see only one map, not infinity amount of it

		//This commands draw the upper side of the map
		for (int i = 0; i < width + 1; i++)
			cout << "o";
		cout << endl;
		// This commands are responsible for left and right sides of the map
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0 || j == width - 1)
					cout << "o";

				if (i == y && j == x)
					cout << "x";
				else if (i == f_y && j == f_x)
					cout << "F";
				else {
					bool print = false;
					for (int k = 0; k < nTail; k++) {
						if (tailX[k] == j && tailY[k] == i) {
							print = true;
							cout << "#";
						}
					}
					if (!print)
						cout << " ";
				}
			}
			cout << endl;
		}

		//This for loop draws the lower side of the map
		for (int i = 0; i <= width; i++)
			cout << "o";
		cout << endl;
		cout << endl;
		cout << "           Your Score: " << s << endl;

	}
	void Input() {
		if (_kbhit()) {   // The kbhit() function returns true if any key on the keyboard is pressed. Otherwise, 0 is returned
			switch (_getch()) {  // The function waits for any key to be pressed, and its code is returned to use the function. Conio.h library is required 
			case'a':
				direction = LEFT;
				break;
			case'd':
				direction = RIGHT;
				break;
			case'w':
				direction = UP;
				break;
			case's':
				direction = DOWN;
				break;
			case'p':
				G_O = true;
				break;
			}

		}
	}
	void Logic() {
		// This whole part before switch statement is responsible for the Tail of the Snake

		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;
		tailX[0] = x;
		tailY[0] = y;
		for (int i = 1; i < nTail; i++) {
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
		//Direction of the Snake
		switch (direction) {
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		}
		if (x >= width - 1)
			x = 0;
		else if (x < 0)
			x = width - 2;

		if (y >= height)
			y = 0;
		else if (y < 0)
			y = height - 1;
		// Command for gameover operation
		if (x > width || x < 0 || y>height || y < 0)
			G_O = true;
		for (int i = 0; i < nTail; i++)
		{
			if (tailX[i] == x && tailY[i] == y)
				G_O = true;
		}
		if (x == f_x && y == f_y) {
			s += 10;
			f_x = rand() % width; // The rand() function is necessary for the random appearance of fruits on the map.
			f_y = rand() % height;
			nTail++; // The tail will grow longer as it eats fruit
		}

	}
};