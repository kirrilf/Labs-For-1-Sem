#include <iostream>
#include <windows.h> 
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <random>
#include <time.h>

using namespace std;


int A[30][30];
int C[8][8];
int x = 1, y = 1, xC = 0, yC = 0;


//включин режим отладки 
void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
//////////////
void charecterCalculation(int x, int y, int sizeX, int sizeY) {
	if (x == 0 && y == 0) {
		//A[x][y] = 1;
		A[x][y] = 474;
	}
	else if (x == 0 && y == sizeY - 1) {
		//A[x][y] = 2;
		A[x][y] = 447;
	}
	else if (x == sizeX - 1 && y == 0) {
		//A[x][y] = 3;
		A[x][y] = 448;
	}
	else if (x == sizeX - 1 && y == sizeY - 1) {
		//A[x][y] = 4;
		A[x][y] = 217;
	}
	else if (x % 2 == 0 && y % 2 != 0) {
		//A[x][y] = 6;
		A[x][y] = 452;
	}
	else if (x % 2 != 0 && y % 2 == 0) {
		//A[x][y] = 5;
		A[x][y] = 435;
	}
	else if (x == 0 && y % 1 == 0) {
		//A[x][y] = 7;
		A[x][y] = 450;
	}
	else if (x % 2 == 0 && y == 0) {
		//A[x][y] = 9;
		A[x][y] = 451;
	}
	else if (x % 2 == 0 && y == sizeY - 1) {
		//A[x][y] = 10;
		A[x][y] = 436;
	}

	else if (x == sizeX - 1 && y % 2 == 0) {
		//A[x][y] = 8;
		A[x][y] = 449;
	}
	else if (x % 2 == 0 && y % 2 == 0 && x != 0 && y != 0 && x != sizeX - 1 && y != sizeY - 1) {
		//A[x][y] = 11;
		A[x][y] = 453;
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
//////////////////////////



void go_to(int sizeX, int sizeY) {
	gotoxy(x, y);
	while (true) {
		gotoxy(x, y);
		int i = _getch(), j = _getch();
		if (j == 72) {
			y -= 2;
			yC -= 1;
		}
		else if (j == 80) {
			y += 2;
			yC += 1;
			if (y < 1) {
				y = sizeX * 2 - 1;
				yC = sizeX - 1;
			}
		}
		else if (j == 75) {
			x -= 2;
			xC -= 1;
		}
		else if (j == 77) {
			x += 2;
			xC += 1;
		}
		if (i == 13) {
			if (A[y][x] == 0) {
				A[y][x] = 15;
				C[yC + 1][xC + 1] = 1;
				break;
			}
			else {
				//gotoxy(sizeX*3, sizeY*3);//////////////
				//cout << "Pip";////////////////
				continue;
			}
		}
		/*if (y < 1) {
			y = sizeX * 2-1;
			yC = sizeX-1;
		}*/
		if (x < 1) {
			x = sizeY * 2 - 1;
			xC = sizeY - 1;
		}
		if (x > sizeY * 2) {
			x = 1;
			xC = 0;
		}
		if (y > sizeX * 2) {
			y = 1;
			yC = 0;
		}
		gotoxy(10, 10);/////////////////
		cout << x << "   " << y << endl;///////////////////
		cout << xC << "  " << yC;//////
	}
}

void arrayDraw(int sizeX, int sizeY) {
	gotoxy(0, 0);
	for (int i = 0; i < sizeX * 2 + 1; i++) {
		for (int j = 0; j < sizeY * 2 + 1; j++) {
			if (A[i][j] == 15) {
				SetColor(10, 0);
				cout << "x";
			}
			else if (A[i][j] == 2) {
				SetColor(12, 0);
				cout << "o";
			}
			else {
				SetColor(14, 0);
				cout << (char)A[i][j];
			}
		}
		cout << endl;
	}
}

void randZero(int sizeX, int sizeY) {


	int X[30], Y[30], k = 0, a, b, ran, aX, aY;
	for (int i = 1; i < sizeX + 1; i++) {
		for (int j = 1; j < sizeY + 1; j++) {
			if (C[i][j] == 0) {
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
	C[a][b] = 2;
	//cout << a << b;
	a -= 1;
	b -= 1;
	aX = a * 2 + 1;
	aY = b * 2 + 1;

	A[aX][aY] = 2;


}

int gameOverCheck(int sizeX, int sizeY) {
	for (int i = 0; i < sizeX + 2; i++) {
		for (int j = 0; j < sizeY + 2; j++) {
			if (C[i][j] == C[i - 1][j - 1] && C[i][j] == C[i + 1][j + 1] && C[i][j] != 0) {
				if (C[i][j] == 1) {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (C[i][j] == C[i - 1][j + 1] && C[i][j] == C[i + 1][j - 1] && C[i][j] != 0) {
				if (C[i][j] == 1) {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (C[i][j] == C[i - 1][j] && C[i][j] == C[i + 1][j] && C[i][j] != 0) {
				if (C[i][j] == 1) {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (C[i][j] == C[i][j - 1] && C[i][j] == C[i][j + 1] && C[i][j] != 0) {
				if (C[i][j] == 1) {
					return 1;
				}
				else {
					return 0;
				}
			}
		}
	}
	int k = 0;
	for (int i = 1; i < sizeX + 1; i++) {
		for (int j = 1; j < sizeY + 1; j++) {
			if (C[i][j] == 0) {
				k++;
			}
		}
	}
	if (k == 0) {
		return 3;
	}


	return 8;
}

void fieldDrawing(int sizeX, int sizeY) {
	fillingField(sizeX * 2 + 1, sizeY * 2 + 1);

	while (true) {
		system("cls");

		/*///////////////////////////////////////*/
		gotoxy(0, 10);
		for (int i = 0; i < sizeX + 2; i++) {
			for (int j = 0; j < sizeY + 2; j++) {
				cout << C[i][j];
			}
			cout << endl;
		}
		/*////////////////////////////////////*/

		arrayDraw(sizeX, sizeY);
		go_to(sizeX, sizeY);
		int victory = gameOverCheck(sizeX, sizeY);
		if (victory == 1) {
			system("cls");
			SetColor(10, 0);
			cout << "GAME OVER" << endl;
			cout << "Won the CROSS" << endl;
			cout << "Press 'ENTER' key to view the playing field";
			break;
		}
		else if (victory == 0) {
			system("cls");
			SetColor(12, 0);
			cout << "GAME OVER" << endl;
			cout << "Won the ZERO" << endl;
			cout << "Press 'ENTER' key to view the playing field";
			break;
		}
		else if (victory == 3) {
			system("cls");
			SetColor(14, 0);
			cout << "GAME OVER" << endl;
			cout << "DRAW" << endl;
			cout << "Press 'ENTER' key to view the playing field";
			break;
		}
		randZero(sizeX, sizeY);
		victory = gameOverCheck(sizeX, sizeY);
		if (victory == 1) {
			system("cls");
			SetColor(10, 0);
			cout << "GAME OVER" << endl;
			cout << "Won the CROSS" << endl;
			cout << "Press 'ENTER' key to view the playing field";
			break;
		}
		else if (victory == 0) {
			system("cls");
			SetColor(12, 0);
			cout << "GAME OVER" << endl;
			cout << "Won the ZERO" << endl;
			cout << "Press 'ENTER' key to view the playing field";
			break;
		}
		else if (victory == 3) {
			system("cls");
			SetColor(14, 0);
			cout << "GAME OVER" << endl;
			cout << "DRAW" << endl;
			cout << "Press 'ENTER' key to view the playing field";
			break;
		}


	}
}




int main()
{
	while (true) {
		system("cls");
		int sizeX, sizeY;
		cout << "Enter field size: " << endl;
		cout << "WIDTH: ";
		cin >> sizeX;
		cout << "HEIGHT: ";
		cin >> sizeY;
		if (sizeX > 2 && sizeY > 2 && sizeX <= 5 && sizeY <= 5) {

			fieldDrawing(sizeX, sizeY);

			_getch();

			system("cls");
			arrayDraw(sizeX, sizeY);
			break;
		}
		cout << "ERROR" << endl;
		cout << "Allowed range is from 3 to 5 inclusive." << endl;
		cout << "Press 'ENTER' key to continue";
		_getch();
		_getch();

		x = 1;
		y = 1;
		xC = 0;
		yC = 0;


	}

	return 0;
}