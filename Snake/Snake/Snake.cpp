#include <iostream>
#include "windows.h"
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <random>
#include <time.h>
#include <dos.h>
#include <stdio.h>


using namespace std;

int mapa[100][100], x = 1, y = 1, score = 1, xLast[250], yLast[250];
bool gameOv = false, food = true, rais = true;
int direct;

//убрать gotoxy в игре!!!

void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}
/////////////////////////////////////////////////////////////////////////
void charecterCalculation(int x, int y, int sizeX, int sizeY) {
	if (x == 0 && y == 0) {
		//A[x][y] = 1;
		mapa[x][y] = 474;
	}
	else if (x == 0 && y == sizeY - 1) {
		//A[x][y] = 2;
		mapa[x][y] = 447;
	}
	else if (x == sizeX - 1 && y == 0) {
		//A[x][y] = 3;
		mapa[x][y] = 448;
	}
	else if (x == sizeX - 1 && y == sizeY - 1) {
		//A[x][y] = 4;
		mapa[x][y] = 217;
	}
	else if (x == 0 || x == sizeX - 1) {
		//A[x][y] = 6;
		mapa[x][y] = 452;
	}
	else if (y == 0 || y == sizeY - 1) {
		//A[x][y] = 11;
		mapa[x][y] = 435;
	}


}

void fillingField(int sizeX, int sizeY) {
	system("cls");
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			charecterCalculation(i, j, sizeX, sizeY);
		}
	}

}
///////////////////////
void arrayDraw(int sizeX, int sizeY) {
	gotoxy(0, 0);
	for (int i = 0; i < sizeX * 2 + 1; i++) {
		for (int j = 0; j < sizeY * 2 + 1; j++) {
			cout << (char)mapa[i][j];
		}
		cout << endl;
	}
}
///////////////////////
void go_to(int sizeX, int sizeY, int N) {
	gotoxy(x, y);
	while (true) {
		gotoxy(x, y);
		int i = _getch(), j = _getch();
		if (j == 72) {
			y--;
		}
		else if (j == 80) {
			y++;
		}
		else if (j == 75) {
			x--;
		}
		else if (j == 77) {
			x++;
		}
		if (i == 13) {
			if (y == 1 && x == 1) {
				continue;
			}
			else {

				if (mapa[y][x] == 0) {
					mapa[y][x] = 35;
					x = 1;
					y = 1;
					break;
				}
				else {
					continue;
				}
			}
		}



		if (x < 1) {
			x = sizeY - 2;
		}
		if (x > sizeY - 2) {
			x = 1;
		}
		if (y < 1) {
			y = sizeX - 2;
		}
		if (y > sizeX - 2) {
			y = 1;
		}



		/*
		gotoxy(sizeY+3, 0);/////////////////
		//cout << "X= " << x << "   " <<"Y= " << y << " " << "N= " << N << endl;///////////////////
		cout << "N = " << N;
		*/
	}
}

void editMap(int sizeX, int sizeY, int N) {
	fillingField(sizeX, sizeY);
	while (N != 0) {
		arrayDraw(sizeX, sizeY);
		go_to(sizeX, sizeY, N);
		arrayDraw(sizeX, sizeY);
		N--;
	}

}

////////////////////////////////////////////////////////////////////////


void gameOverFun(int sizeX, int sizeY, int x, int y) {

	if (x < 1) {
		system("cls");
		cout << "GAME OVER";
		system("pause");
		gameOv = true;

	}
	if (x > sizeY - 2) {
		system("cls");
		cout << "GAME OVER";
		system("pause");
		gameOv = true;

	}
	if (y < 1) {
		system("cls");
		cout << "GAME OVER";
		system("pause");
		gameOv = true;

	}
	if (y > sizeX - 2) {
		system("cls");
		cout << "GAME OVER";
		system("pause");
		gameOv = true;

	}
	if (mapa[y][x] == 35 || mapa[y][x] == 88) {
		system("cls");
		cout << "GAME OVER";
		system("pause");
		gameOv = true;
	}


}

void randZero(int sizeX, int sizeY) {


	int X[500], Y[500], k = 0, a, b, ran;
	for (int i = 1; i < sizeX; i++) {
		for (int j = 1; j < sizeY; j++) {
			if (mapa[i][j] == 0) {
				X[k] = i;
				Y[k] = j;
				k++;

			}
		}
	}

	if (k == 0) {
		return;
	}


	srand(time(0));
	ran = rand() % k;
	a = X[ran];
	b = Y[ran];
	mapa[a][b] = 29;


}

void test(int sizeX, int sizeY) {
	int X, Y;
	X = xLast[0];
	Y = yLast[0];
	mapa[Y][X] = 88;
	for (int i = 1; i < score; i++) {
		X = xLast[i];
		Y = yLast[i];
		mapa[Y][X] = 88;
	}

	bool con = false;

	for (int i = 1; i < sizeX - 1; i++) {
		for (int j = 1; j < sizeY - 1; j++) {
			for (int m = 1; m < score; m++) {
				if (j == xLast[m] && i == yLast[m]) {
					con = true;
				}
			}
			if ((i == yLast[0] && j == xLast[0]) || mapa[i][j] == 29 || mapa[i][j] == 35) {
				con = true;
			}
			if (!con) {
				mapa[i][j] = 0;
			}
			else {
				con = false;
			}

		}
	}

}




void goToSnake(int sizeX, int sizeY) {



	int i = _getch(), j = _getch();
	int prevX = xLast[0];
	int prevY = yLast[0];
	int prev2X, prev2Y;


	if (j == 72) {
		y--;
	}
	else if (j == 80) {
		y++;
	}
	else if (j == 75) {
		x--;
	}
	else if (j == 77) {
		x++;
	}
	if (mapa[y][x] == 29) {
		score++;
		food = true;


	}
	xLast[0] = x;
	yLast[0] = y;
	for (int i = 1; i < score; i++) {
		prev2X = xLast[i];
		prev2Y = yLast[i];
		xLast[i] = prevX;
		yLast[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}


	gameOverFun(sizeX, sizeY, x, y);
	if (gameOv == true) {
		return;
	}







}



void goSnake(int sizeX, int sizeY) {

	while (true) {
		goToSnake(sizeX, sizeY);
		test(sizeX, sizeY);
		if (gameOv == true) {
			return;
		}
		if (rais) {
			for (int i = 0; i < 4; i++) {
				randZero(sizeX, sizeY);
			}
			rais = false;
		}

		if (food) {
			randZero(sizeX, sizeY);
			food = false;
		}
		//////////

		arrayDraw(sizeX, sizeY);

	}



}








int main() {

	/*int sizeX, sizeY, N;
	if(sizeX )
	cin >> sizeX >> sizeY >> N;

	editMap(sizeX+2, sizeY+2, N);
	goSnake(sizeX + 2, sizeY + 2);




	gotoxy(1, 1);
	arrayDraw(sizeX, sizeY);*/
	while (true) {
		system("cls");
		int sizeX, sizeY, N;
		cout << "Enter field size: " << endl;
		cout << "WIDTH: ";
		cin >> sizeX;
		cout << "HEIGHT: ";
		cin >> sizeY;
		cout << "Number of obstacles: ";
		cin >> N;
		if (sizeX > 3 && sizeY > 3 && sizeX <= 20 && sizeY <= 20 && N < sizeX * sizeY - 6) {


			editMap(sizeX + 2, sizeY + 2, N);
			arrayDraw(sizeX, sizeY);
			gotoxy(1, 1);
			cout << "X";
			gotoxy(0, sizeY + 10);
			goSnake(sizeX + 2, sizeY + 2);

			_getch();
			int k = 0;
			for (int i = 1; i < sizeX; i++) {
				for (int j = 1; j < sizeY; j++) {
					if (mapa[i][j] == 0) {
						k++;
					}
				}
			}

			if (k == 0) {
				cout << "POBEDA";
				system("pause");
				system("cls");
				arrayDraw(sizeX, sizeY);
				break;
			}

			system("cls");
			arrayDraw(sizeX, sizeY);
			break;
		}
		cout << "ERROR" << endl;
		cout << "Allowed range is from 3 to inclusive and max obstacles =  ." << sizeX * sizeY - 6 << endl;
		cout << "Press 'ENTER' key to continue";
		_getch();
		_getch();




	}

	return 0;




	return 0;

}