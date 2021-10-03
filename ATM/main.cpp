#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[] = { 1,10,3,9,10,2 }; //массив, где в [0] хранятся купюры по 100 рублей, [1] - по 200 рублей и т.д.
	int cash, cashF, summa, result100, result200, result500, result1000, result2000, result5000;
	summa = arr[0]*100+arr[1]*200+arr[2]*500+arr[3]*1000+arr[4]*2000+arr[5]*5000;
	cout << "В банкомате: " << arr[0]<< " ед. по 100 рублей" << endl;
	cout << "В банкомате: " << arr[1]<< " ед. по 200 рублей" << endl;
	cout << "В банкомате: " << arr[2]<< " ед. по 500 рублей" << endl;
	cout << "В банкомате: " << arr[3]<< " ед. по 1000 рублей" << endl;
	cout << "В банкомате: " << arr[4]<< " ед. по 2000 рублей" << endl;
	cout << "В банкомате: " << arr[5]<< " ед. по 5000 рублей" << endl;
	cout << "Всего в банкомате " << summa << " рублей" << endl;
	cout << "Введите снимаемую сумму: ";
	cin >> cash;
	cashF = cash; //переменная cashF для вычисления остатка денежных средств в банкомате в конце кода
	if (cash % 100 != 0 || cash>summa ) { //проверка на корректный запрос и на превышение лимита
		cout << "Банкомат не может выдать данную сумму" << endl;
		exit(0);
	}
	if (cash >= 5000) { //проверка на операцию больше или равную 5000
		if (cash / 5000 <= arr[5]) { //если операция укладывается в лимит элемента массива, то производит дальнейший расчет
			result5000 = cash / 5000;
			arr[5] -= result5000;
			cash = cash - result5000 * 5000;
		}
		else { //если операция превышает лимит элемента массива, то пересчитываем запрашиваеммую цифру и присваиваем массиву 0
			cash = cash - arr[5]*5000;
			arr[5] = 0;
		}
	}
	if (cash >= 2000) {
		if (cash / 2000 <= arr[4]) {
			result2000 = cash / 2000;
			arr[4] -= result2000;
			cash = cash - result2000 * 2000;
		}
		else {
			cash = cash - arr[4]*2000;
			arr[4] = 0;
		}
	}
	if (cash >= 1000) {
		if (cash / 1000 <= arr[3]) {
			result1000 = cash / 1000;
			arr[3] -= result1000;
			cash = cash - result1000 * 1000;
		}
		else {
			cash = cash - arr[3]*1000;
			arr[3] = 0;
		}
	}
	if (cash >= 500) {
		if (cash / 500 <= arr[2]) {
			result500 = cash / 500;
			arr[2] -= result500;
			cash = cash - result500 * 500;
		}
		else {
			cash = cash - arr[2]*500;
			arr[2] = 0;
		}
	}
	if (cash >= 200) {
		if (cash / 200 <= arr[1]) {
			result200 = cash / 200;
			arr[1] -= result200;
			cash = cash - result200 * 200;
		}
		else {
			cash = cash - arr[1]*200;
			arr[1] = 0;
		}
	}
	if (cash >= 100) {
		result100 = cash / 100;
		arr[0] -= result100;
		cash = cash - result100 * 100;
	}
	if (cash == 0) {
		cout << "Операция выдачи наличных выполнена успешно!" << endl;
	}
	cout << "Остаток в банкомате: " << arr[0] << " ед. по 100 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[1] << " ед. по 200 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[2] << " ед. по 500 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[3] << " ед. по 1000 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[4] << " ед. по 2000 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[5] << " ед. по 5000 рублей" << endl;
	cout << "Всего в банкомате осталось: " << summa-cashF << " рублей" << endl;
	return 0;
}
