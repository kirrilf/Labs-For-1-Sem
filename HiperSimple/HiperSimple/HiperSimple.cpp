#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector <int> a;



bool proverka_na_prost(long long int n) {
	for (long long int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}




void giper_prost(long long int n, int one) {
	for (int i = one; i < 10; i++) {

		long long int k = n * 10 + i;


		if (k < pow(2, 32) && proverka_na_prost(k)) {

			a.push_back(k);
			giper_prost(k, one);


		}
	}
}


string dvach(long long int n) {
	string dva = "";

	while (n >= 2) {
		int ost = n % 2;
		if (ost == 0) {
			dva
				= "0" + dva;
			n /= 2;
		}
		else {
			dva = "1" + dva;
			n /= 2;
		}

	}
	if (n == 0) {
		dva = "0" + dva;
	}

	else {
		dva = "1" + dva;
	}

	return dva;
}




int main() {
	string numb;
	int one;
	cout << "One is a prime number ? (Yes/No)\n";
	cin >> numb;
	if (numb == "Yes" || numb == "yes") {
		one = 1;
	}
	else {
		one = 2;
	}


	giper_prost(0, one);

	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++) {

		cout << a[i] << " \n";

	}


	cout << "Total=" << a.size() << endl;

	return 0;
}