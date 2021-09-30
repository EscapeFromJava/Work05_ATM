#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[] = { 1000,2000,5000,10000,20000,50000 };
	int cash, summa, result100, result200, result500, result1000, result2000, result5000;
	summa = 0;
	for (int i = 0; i < 6; i++) {
		summa = summa + arr[i];
	}
	cout << "В банкомате " << summa << " рублей" << endl;
	cout << "Введите снимаемую сумму" << endl;
	cin >> cash;
	if (cash % 100 != 0 || cash>summa ) {
		cout << "Банкомат не может выдать данную сумму" << endl;
		exit(0);
	}
	if (cash >= 5000) {
		result5000 = cash / 5000;
		arr[5] = arr[5] - result5000 * 5000;
		cash = cash - result5000 * 5000;
	}
	if (cash >= 2000) {
		result2000 = cash / 2000;
		arr[4] = arr[4] - result2000 * 2000;
		cash = cash - result2000 * 2000;
	}
	if (cash >= 1000) {
		result1000 = cash / 1000;
		arr[3] = arr[3] - result1000 * 1000;
		cash = cash - result1000 * 1000;
	}
	if (cash >= 500) {
		result500 = cash / 500;
		arr[2] = arr[2] - result500 * 500;
		cash = cash - result500 * 500;
	}
	if (cash >= 200) {
		result200 = cash / 200;
		arr[1] = arr[1] - result200 * 200;
		cash = cash - result200 * 200;
	}
	if (cash >= 100) {
		result100 = cash / 100;
		arr[0] = arr[0] - result100 * 100;
		cash = cash - result100 * 200;
	}
	if (cash == 0) {
		cout << "Операция выдачи наличных выполнена успешно!" << endl;
	}
	for (int i = 0; i < 6; i++) {
		cout << "Остаток в банкомате: " << arr[i] << endl;
	}
	return 0;
}
