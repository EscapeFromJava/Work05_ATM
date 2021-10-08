#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[] = { 1,1,0,9,10,2 }; //массив, где в [0] хранятся купюры по 100 рублей, [1] - по 200 рублей и т.д.
	int arrMoney[] = { 5000,2000,1000,500,200,100 }; //массив с номиналом купюр, начиная с 5000 и на убывание
	int arrCash[] = { 0,0,0,0,0,0 };
	int cash, cashF, summa;
	summa = arr[0] * 5000 + arr[1] * 2000 + arr[2] * 1000 + arr[3] * 500 + arr[4] * 200 + arr[5] * 100;
	for (int i = 0; i < 6; i++) {
		cout << "В банкомате: " << arr[i] << " ед. по " << arrMoney[i] << " рублей" << endl;
	}
	cout << "Всего в банкомате " << summa << " рублей" << endl;
	cout << "Введите снимаемую сумму: ";
	cin >> cash;
	cashF = cash; //переменная cashF для вычисления остатка денежных средств в банкомате в конце кода
	if (cash % 100 != 0 || cash > summa || cash <= 99) { //проверка на корректный запрос и на превышение лимита
		cout << endl;
		cout << "Банкомат не может выдать данную сумму" << endl;
		return 0;
	}
	if (cash >= 5000) { //проверка на операцию больше или равную 5000
		if (cash / 5000 <= arr[0]) { //если операция укладывается в лимит элемента массива, то производит дальнейший расчет
			arrCash[] = cash / 5000;
			arr[0] -= arrCash[0];
			cash = cash - arrCash[0] * 5000;
		}
		else { //если операция превышает лимит элемента массива, то пересчитываем запрашиваеммую цифру и присваиваем массиву 0
			cash = cash - arr[0] * 5000;
			arrCash[0] += arr[0];
			arr[0] = 0;
		}
	}
	if (cash >= 2000) {
		if (cash / 2000 <= arr[1]) {
			arrCash[1] = cash / 2000;
			arr[1] -= arrCash[1];
			cash = cash - arrCash[1] * 2000;
		}
		else {
			cash = cash - arr[1] * 2000;
			arrCash[1] += arr[1];
			arr[1] = 0;
		}
	}
	if (cash >= 1000) {
		if (cash / 1000 <= arr[2]) {
			arrCash[2] = cash / 1000;
			arr[2] -= arrCash[2];
			cash = cash - arrCash[2] * 1000;
		}
		else {
			cash = cash - arr[2] * 1000;
			arrCash[2] += arr[2];
			arr[2] = 0;
		}
	}
	if (cash >= 500) {
		if (cash / 500 <= arr[3]) {
			arrCash[3] = cash / 500;
			arr[3] -= arrCash[3];
			cash = cash - arrCash[3] * 500;
		}
		else {
			cash = cash - arr[3] * 500;
			arrCash[3] += arr[3];
			arr[3] = 0;
		}
	}
	if (cash >= 200) {
		if (cash / 200 <= arr[4]) {
			arrCash[4] = cash / 200;
			arr[4] -= arrCash[4];
			cash = cash - arrCash[4] * 200;
		}
		else {
			cash = cash - arr[4] * 200;
			arrCash[4] += arr[4];
			arr[4] = 0;
		}
	}
	if (cash >= 100) {
		if (cash / 100 <= arr[5]) {
			arrCash[5] = cash / 100;
			arr[5] -= arrCash[5];
			cash = cash - arrCash[5] * 100;
		}
		else {
			cout << "Банкомат не может выдать данную сумму" << endl;
			return 0;
		}
	}
	if (cash == 0) {
		cout << "Операция выдачи наличных выполнена успешно!" << endl;
	}
	for (int i = 0; i < 6; i++) {
		cout << "Выдано: " << arrCash[i] << " ед. по " << arrMoney[i] << " рублей" << endl;
	}
	for (int i = 0; i < 6; i++) {
		cout << "Остаток в банкомате: " << arr[i] << " ед. по " << arrMoney[i] << " рублей" << endl;
	}
	cout << "Всего в банкомате осталось: " << summa-cashF << " рублей" << endl;
	return 0;
}
