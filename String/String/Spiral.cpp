#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <conio.h>
#include <locale.h>

using namespace std;


int A[100][100];

void po(int size, int size_h) {
	int i = 0, j = -1, ima = size - 1, jma = size_h - 1, imi = 1, jmi = 0, c = 1;


	while (c <= size * size_h) {
		while (j < jma) {
			j++;
			A[i][j] = c;
			c++;
		}
		jma--;
		if (c > size * size_h) {
			break;
		}
		while (i < ima) {
			i++;
			A[i][j] = c;
			c++;
		}
		ima--;
		if (c > size * size_h) {
			break;
		}
		while (j > jmi) {
			j--;
			A[i][j] = c;
			c++;
		}
		jmi++;
		if (c > size * size_h) {
			break;
		}
		while (i > imi) {
			i--;
			A[i][j] = c;
			c++;
		}
		imi++;
	}
}


void po_reverse(int size, int size_h) {
	int i = 0, j = -1, ima = size - 1, jma = size_h - 1, imi = 1, jmi = 0, c = size * size_h;


	while (c > 0) {
		while (j < jma) {
			j++;
			A[i][j] = c;
			c--;
		}
		jma--;
		if (c <= 0) {
			break;
		}
		while (i < ima) {
			i++;
			A[i][j] = c;
			c--;
		}
		ima--;
		if (c <= 0) {
			break;
		}
		while (j > jmi) {
			j--;
			A[i][j] = c;
			c--;
		}
		jmi++;
		if (c <= 0) {
			break;
		}
		while (i > imi) {
			i--;
			A[i][j] = c;
			c--;
		}
		imi++;
	}
}


void protiv(int size, int size_h) {
	int i = -1, j = 0, ima = size - 1, jma = size_h - 1, imi = 0, jmi = 1, c = 1;



	while (c <= size * size_h) {
		while (i < ima) {
			i++;
			A[i][j] = c;
			c++;
		}
		ima--;
		if (c > size * size_h) {
			break;
		}
		while (j < jma) {
			j++;
			A[i][j] = c;
			c++;
		}
		jma--;
		if (c > size * size_h) {
			break;
		}
		while (i > imi) {
			i--;
			A[i][j] = c;
			c++;
		}
		imi++;
		if (c > size * size_h) {
			break;
		}
		while (j > jmi) {
			j--;
			A[i][j] = c;
			c++;
		}
		jmi++;
	}
}


void protiv_reverse(int size, int size_h) {
	int i = -1, j = 0, ima = size - 1, jma = size_h - 1, imi = 0, jmi = 1, c = size * size_h;



	while (c > 0) {
		while (i < ima) {
			i++;
			A[i][j] = c;
			c--;
		}
		ima--;
		if (c <= 0) {
			break;
		}
		while (j < jma) {
			j++;
			A[i][j] = c;
			c--;
		}
		jma--;
		if (c <= 0) {
			break;
		}
		while (i > imi) {
			i--;
			A[i][j] = c;
			c--;
		}
		imi++;
		if (c <= 0) {
			break;
		}
		while (j > jmi) {
			j--;
			A[i][j] = c;
			c--;
		}
		jmi++;
	}
}


int menu() {
	int k = 1, num = 1;

	string A = "1 По часовой, прямой порядок      ", B = "2 По часовой, обратный порядок    ", C = "3 Против часовой, прямой порядок  ", D = "4 Против часовой, обратный порядок";

	cout << A << "<---\n";
	cout << B << "\n";
	cout << C << "\n";
	cout << D << "\n";


	while (true) {

		int l = _getch(), c = _getch();
		system("cls");

		if (c == 80) {
			k++;
		}

		else if (c == 72) {
			k--;
		}


		if (k == 5) {
			k = 1;
		}

		else if (k == 0) {
			k = 4;
		}

		if (l == 13) {
			return k;
		}


		if (l == 49) {
			return 1;
		}
		else if (l == 50) {
			return 2;
		}
		else if (l == 51) {
			return 3;
		}
		else if (l == 52) {
			return 4;
		}



		if (k == 1) {
			cout << A << "<---\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
		}
		else if (k == 2) {
			cout << A << "\n";
			cout << B << "<---\n";
			cout << C << "\n";
			cout << D << "\n";
		}
		else if (k == 3) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "<---\n";
			cout << D << "\n";
		}
		else if (k == 4) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "<---\n";
		}



	}

}


int main()
{
	setlocale(LC_CTYPE, "");

	while (true) {
		int k = menu(), n, m;
		cout << "Введите размер матрицы: ";
		cin >> n >> m;
		if (n > 0 && n < 10 && m > 0 && m < 10) {

			if (k == 1) {
				po(n, m);
			}
			else if (k == 2) {
				po_reverse(n, m);
			}
			else if (k == 3) {
				protiv(n, m);
			}
			else if (k == 4) {
				protiv_reverse(n, m);
			}


			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					printf("%3d", A[i][j]);
				}
				cout << endl;
			}
			break;
		}

	}

	return 0;
}
