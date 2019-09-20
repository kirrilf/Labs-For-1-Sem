#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <conio.h>

using namespace std;

map <char, int> s = {
		{'0', 0},
		{'1', 1},
		{'2', 2},
		{'3', 3},
		{'4', 4},
		{'5', 5},
		{'6', 6},
		{'7', 7},
		{'8', 8},
		{'9', 9},
		{'A', 10},
		{'B', 11},
		{'C', 12},
		{'D', 13},
		{'E', 14},
		{'F', 15},
		{'G', 16},
		{'H', 17},
		{'I', 18},
		{'J', 19},
		{'K', 20},
		{'L', 21},
		{'M', 22},
		{'N', 23},
		{'O', 24},
		{'P', 25},
		{'Q', 26},
		{'R', 27},
		{'S', 28},
		{'T', 29},
		{'U', 30},
		{'V', 31},
		{'W', 32},
		{'X', 33},
		{'Y', 34},
		{'Z', 35},
};
map <int, char> s1 = {
		{0, '0'},
		{1, '1'},
		{2, '2'},
		{3, '3'},
		{4, '4'},
		{5, '5'},
		{6, '6'},
		{7, '7'},
		{8, '8'},
		{9, '9'},
		{10, 'A'},
		{11, 'B'},
		{12, 'C'},
		{13, 'D'},
		{14, 'E'},
		{15, 'F'},
		{16, 'G'},
		{17, 'H'},
		{18, 'I'},
		{19, 'J'},
		{20, 'K'},
		{21, 'L'},
		{22, 'M'},
		{23, 'N'},
		{24, 'O'},
		{25, 'P'},
		{26, 'Q'},
		{27, 'R'},
		{28, 'S'},
		{29, 'T'},
		{30, 'U'},
		{31, 'V'},
		{32, 'W'},
		{33, 'X'},
		{34, 'Y'},
		{35, 'Z'},
};




void zamReverse(char* n1, char* n2, int* n1Rev, int* n2Rev) {
	int j = 0;
	for (int i = strlen(n1) - 1; i >= 0; i--) {
		n1Rev[j] = s[n1[i]];
		j++;
	}
	j = 0;
	for (int i = strlen(n2) - 1; i >= 0; i--) {
		n2Rev[j] = s[n2[i]];
		j++;
	}
}


int decimalTranslatin(int Size, int* Rev, int sis) {
	long long int temp, n1Dec = 0;
	for (int i = 0; i < Size; i++) {
		temp = pow(sis, i) * Rev[i];
		n1Dec += temp;
	}
	return n1Dec;

}


int addition(int* n1Rev, int* n2Rev, int sis, int n1Size, int n2Size, int* a) {
	int ost = 0, k, l = 0;
	if (n1Size > n2Size) {
		k = n1Size;
		for (int i = n2Size; i < n1Size; i++) {
			n2Rev[i] = 0;
		}
	}
	else {
		k = n2Size;
		for (int i = n1Size; i < n2Size; i++) {
			n1Rev[i] = 0;
		}
	}

	for (int i = 0; i < k; i++) {
		int temp;
		temp = n1Rev[i] + n2Rev[i] + ost;
		if (temp >= sis) {
			//a.push_back(temp - sis);
			a[l] = temp - sis;
			//cout << a[l] << "h" << endl;
			l++;
			ost = 1;
		}
		else {
			//a.push_back(temp);
			a[l] = temp;
			//cout << a[l] << "t" << endl << n2Rev[i];
			l++;
			ost = 0;
		}
	}

	if (ost != 0) {
		//a.push_back(ost);
		a[l] = ost;
		//cout << a[l] << "o" << endl;
		l++;
	}

	return l;
}


int subtraction(int* n1Rev, int* n2Rev, int sis, int n1Size, int n2Size, long long int n1Dec, long long int n2Dec, int* a) {
	if (n1Dec < n2Dec) {
		int tempMas[50];
		for (int i = 0; i < n1Size; i++) {
			tempMas[i] = n1Rev[i];
			//cout << n1Rev[i] << "  " <<1 <<  endl;
		}
		for (int i = 0; i < n1Size; i++) {
			n1Rev[i] = 0;
		}
		for (int i = 0; i < n2Size; i++) {
			n1Rev[i] = n2Rev[i];
			//cout << n2Rev[i] <<"  " << 2 <<endl;
		}
		for (int i = 0; i < n2Size; i++) {
			n2Rev[i] = 0;
		}
		for (int i = 0; i < n1Size; i++) {
			n2Rev[i] = tempMas[i];
			//cout << n2Rev[i] << "  " << 3 << endl;
		}
		int temp = n1Size;
		n1Size = n2Size;
		n2Size = temp;

	}

	int ost = 0, k, l = 0;
	if (n1Size > n2Size) {
		k = n1Size;
		for (int i = n2Size; i < n1Size; i++) {
			n2Rev[i] = 0;
		}
	}
	else {
		k = n2Size;
		for (int i = n1Size; i < n2Size; i++) {
			n1Rev[i] = 0;
		}
	}

	for (int i = 0; i < k; i++) {
		int temp;
		if (n1Rev[i] == n2Rev[i] && ost == 0) {
			a[l] = 0;
			l++;
		}
		else if (n1Rev[i] <= n2Rev[i]) {
			temp = n1Rev[i] + sis - ost - n2Rev[i];
			//cout << n1Rev[i] << "N1  " << ost << "  " << n2Rev[i] << "n2 " << temp << endl;
			ost = 1;
			//a.push_back(temp);
			a[l] = temp;
			l++;

		}
		else {
			temp = n1Rev[i] - ost - n2Rev[i];
			//cout << n1Rev[i] << "N1  " << ost << "  " << n2Rev[i] << "n2 " << temp  << endl;
			ost = 0;
			//a.push_back(temp);
			a[l] = temp;
			l++;
		}

	}
	if (ost != 0) {
		//a.push_back(ost);
		a[l] = ost;
		l++;
	}

	return l;

}


int multiplication(int* n1Rev, int* n2Rev, int sis, int n1Size, int n2Size, int n1Dec, int n2Dec, int* temp) {
	int size = n1Size;
	for (int i = 0; i < n1Size; i++) {
		temp[i] = n1Rev[i];
	}

	for (int i = 0; i < n2Dec - 1; i++) {
		size = addition(n1Rev, temp, sis, n1Size, size, temp);
	}


	return size;

}

int division(int* n1Rev, int* n2Rev, int sis, int n1Size, int n2Size, int n1Dec, int n2Dec, int* temp) {
	if (n1Dec < n2Dec) {
		int tempMas[50];
		for (int i = 0; i < n1Size; i++) {
			tempMas[i] = n1Rev[i];
			//cout << n1Rev[i] << "  " <<1 <<  endl;
		}
		for (int i = 0; i < n1Size; i++) {
			n1Rev[i] = 0;
		}
		for (int i = 0; i < n2Size; i++) {
			n1Rev[i] = n2Rev[i];
			//cout << n2Rev[i] <<"  " << 2 <<endl;
		}
		for (int i = 0; i < n2Size; i++) {
			n2Rev[i] = 0;
		}
		for (int i = 0; i < n1Size; i++) {
			n2Rev[i] = tempMas[i];
			//cout << n2Rev[i] << "  " << 3 << endl;
		}
		int tempa = n1Size;
		n1Size = n2Size;
		n2Size = tempa;
		tempa = n1Dec;
		n1Dec = n2Dec;
		n2Dec = tempa;
	}


	int size = n1Size, k = 0;
	for (int i = 0; i < n1Size; i++) {
		temp[i] = n1Rev[i];
	}

	while (n1Dec > 0) {
		size = subtraction(temp, n2Rev, sis, size, n2Size, n1Dec, n2Dec, temp);
		n1Dec = decimalTranslatin(size, temp, sis);
		k++;
	}

	return k;


}

int menu() {
	int k = 1, num = 1;

	string A = "+", B = "-", C = "*", D = "/";

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

bool checkSis(char* n1, char* n2, int sis, int n1Size, int n2Size) {

	string n = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (sis < 2 || sis > 36) {
		cout << "Valid number system 2:36";
		return false;
	}



	for (int i = 0; i < n1Size; i++) {
		if (s[n1[i]] > sis) {
			cout << "Vaild characters for this number system(" << sis << "): ";
			for (int i = 0; i < sis - 1; i++) {
				cout << n[i];
			}
			return false;
		}
	}

	for (int i = 0; i < n2Size; i++) {
		if (s[n2[i]] > sis) {
			cout << "Vaild characters for this number system(" << sis << "): ";
			for (int i = 0; i < sis - 1; i++) {
				cout << n[i];
			}
			return false;
		}
	}

	return true;
}

int main() {
	while (true) {
		char n1[50] = "", n2[50] = "";
		int n1Size, n2Size, sis, n1Rev[50], n2Rev[50], a[50], aSize;
		long long int n1Dec, n2Dec;

		cout << "Enter the first number: ";
		cin >> n1;
		cout << endl << "Enter the second number: ";
		cin >> n2;
		cout << endl << "Enter the number system: ";
		cin >> sis;
		system("cls");

		n1Size = strlen(n1);
		n2Size = strlen(n2);

		if (checkSis(n1, n2, sis, n1Size, n2Size) == true) {


			zamReverse(n1, n2, n1Rev, n2Rev);

			n1Dec = decimalTranslatin(n1Size, n1Rev, sis);
			n2Dec = decimalTranslatin(n2Size, n2Rev, sis);

			int j = menu();
			if (j == 1) {

				aSize = addition(n1Rev, n2Rev, sis, n1Size, n2Size, a);

				int aOtv = decimalTranslatin(aSize, a, sis);
				cout << "Answer: ";
				for (int i = aSize - 1; i >= 0; i--) {
					cout << s1[a[i]];
				}
				cout << endl;
				cout << "First number in decimal: " << n1Dec << endl;
				cout << "Second number in decimal: " << n2Dec << endl;
				cout << "Answer in decimal: " << aOtv << endl;
			}
			else if (j == 2) {

				aSize = subtraction(n1Rev, n2Rev, sis, n1Size, n2Size, n1Dec, n2Dec, a);

				int aOtv = decimalTranslatin(aSize, a, sis);
				cout << "Answer: ";
				for (int i = aSize - 1; i >= 0; i--) {
					cout << s1[a[i]];
				}

				cout << endl;
				cout << "First number in decimal: " << n1Dec << endl;
				cout << "Second number in decimal: " << n2Dec << endl;
				cout << "Answer in decimal: " << aOtv << endl;


			}
			else if (j == 3) {
				aSize = multiplication(n1Rev, n2Rev, sis, n1Size, n2Size, n1Dec, n2Dec, a);

				int aOtv = decimalTranslatin(aSize, a, sis);
				cout << "Answer: ";
				for (int i = aSize - 1; i >= 0; i--) {
					cout << s1[a[i]];
				}

				cout << endl;
				cout << "First number in decimal: " << n1Dec << endl;
				cout << "Second number in decimal: " << n2Dec << endl;
				cout << "Answer in decimal: " << aOtv << endl;

			}
			else if (j == 4) {
				aSize = division(n1Rev, n2Rev, sis, n1Size, n2Size, n1Dec, n2Dec, a);

				cout << endl;
				cout << "First number in decimal: " << n1Dec << endl;
				cout << "Second number in decimal: " << n2Dec << endl;
				cout << "Answer in decimal: " << aSize << endl;
			}
			cout << "If you want to continue, click ENTER.";
			int de = _getch();
			if (de == 13) {
				system("cls");
				_getch();
				continue;

			}
			else {
				break;
			}
		}
		cout << endl;
		cout << "If you want to continue, click ENTER.";
		int de = _getch();
		if (de == 13) {
			system("cls");
			_getch();
			continue;

		}
		else {
			break;
		}

	}











}