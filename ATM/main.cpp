#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[] = { 1000,2000,5000,10000,20000,50000 };
	int cash, cashF, summa, result100, result200, result500, result1000, result2000, result5000;
	summa = 0;
	for (int i = 0; i < 6; i++) {
		summa = summa + arr[i];
	}
	cout << "В банкомате: " << arr[0] / 100 << " ед. по 100 рублей" << endl;
	cout << "В банкомате: " << arr[1] / 200 << " ед. по 200 рублей" << endl;
	cout << "В банкомате: " << arr[2] / 500 << " ед. по 500 рублей" << endl;
	cout << "В банкомате: " << arr[3] / 1000 << " ед. по 1000 рублей" << endl;
	cout << "В банкомате: " << arr[4] / 2000 << " ед. по 2000 рублей" << endl;
	cout << "В банкомате: " << arr[5] / 5000 << " ед. по 5000 рублей" << endl;
	cout << "Всего в банкомате " << summa << " рублей" << endl;
	cout << "Введите снимаемую сумму: ";
	cin >> cash;
	cashF = cash;
	if (cash % 100 != 0 || cash>summa ) {
		cout << "Банкомат не может выдать данную сумму" << endl;
		exit(0);
	}
	if (cash >= 5000) {
		if (cash / 5000 <= arr[5] / 5000) {
			result5000 = cash / 5000;
			arr[5] = arr[5] - result5000 * 5000;
			cash = cash - result5000 * 5000;
		}
		else {
			cash = cash - arr[5];
			arr[5] = 0;
		}
	}
	if (cash >= 2000) {
		if (cash / 2000 <= arr[4] / 2000) {
			result2000 = cash / 2000;
			arr[4] = arr[4] - result2000 * 2000;
			cash = cash - result2000 * 2000;
		}
		else {
			cash = cash - arr[4];
			arr[4] = 0;
		}
	}
	if (cash >= 1000) {
		if (cash / 1000 <= arr[3] / 1000) {
			result1000 = cash / 1000;
			arr[3] = arr[3] - result1000 * 1000;
			cash = cash - result1000 * 1000;
		}
		else {
			cash = cash - arr[3];
			arr[3] = 0;
		}
	}
	if (cash >= 500) {
		if (cash / 500 <= arr[2] / 500) {
			result500 = cash / 500;
			arr[2] = arr[2] - result500 * 500;
			cash = cash - result500 * 500;
		}
		else {
			cash = cash - arr[2];
			arr[2] = 0;
		}
	}
	if (cash >= 200) {
		if (cash / 200 <= arr[1] / 200) {
			result200 = cash / 200;
			arr[1] = arr[1] - result200 * 200;
			cash = cash - result200 * 200;
		}
		else {
			cash = cash - arr[1];
			arr[1] = 0;
		}
	}
	if (cash >= 100) {
		result100 = cash / 100;
		arr[0] = arr[0] - result100 * 100;
		cash = cash - result100 * 200;
	}
	if (cash == 0) {
		cout << "Операция выдачи наличных выполнена успешно!" << endl;
	}
	cout << "Остаток в банкомате: " << arr[0] / 100 << " ед. по 100 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[1] / 200 << " ед. по 200 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[2] / 500 << " ед. по 500 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[3] / 1000 << " ед. по 1000 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[4] / 2000 << " ед. по 2000 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[5] / 5000 << " ед. по 5000 рублей" << endl;
	cout << "Всего в банкомате осталось: " << summa-cashF << " рублей" << endl;
	return 0;
}
