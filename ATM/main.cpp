#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[] = { 1,1,0,9,10,2 }; //массив, где в [0] хранятся купюры по 100 рублей, [1] - по 200 рублей и т.д.
	int arrCash[] = { 0,0,0,0,0,0 };
	int cash, cashF, summa;
	summa = arr[0]*100+arr[1]*200+arr[2]*500+arr[3]*1000+arr[4]*2000+arr[5]*5000;
	cout << "В банкомате: " << arr[0]<< " ед. по 100 рублей" << endl;
	cout << "В банкомате: " << arr[1]<< " ед. по 200 рублей" << endl;
	cout << "В банкомате: " << arr[2]<< " ед. по 500 рублей" << endl;
	cout << "В банкомате: " << arr[3]<< " ед. по 1000 рублей" << endl;
	cout << "В банкомате: " << arr[4]<< " ед. по 2000 рублей" << endl;
	cout << "В банкомате: " << arr[5]<< " ед. по 5000 рублей" << endl;
	cout << endl;
	cout << "Всего в банкомате " << summa << " рублей" << endl;
	cout << endl;
	cout << "Введите снимаемую сумму: ";
	cin >> cash;
	cashF = cash; //переменная cashF для вычисления остатка денежных средств в банкомате в конце кода
	if (cash % 100 != 0 || cash>summa || cash<=99) { //проверка на корректный запрос и на превышение лимита
		cout << endl;
		cout << "Банкомат не может выдать данную сумму" << endl;
		exit(0);
	}
	if (cash >= 5000) { //проверка на операцию больше или равную 5000
		if (cash / 5000 <= arr[5]) { //если операция укладывается в лимит элемента массива, то производит дальнейший расчет
			arrCash[5] = cash / 5000;
			arr[5] -= arrCash[5];
			cash = cash - arrCash[5] * 5000;
		}
		else { //если операция превышает лимит элемента массива, то пересчитываем запрашиваеммую цифру и присваиваем массиву 0
			cash = cash - arr[5]*5000;
			arrCash[5] += arr[5];
			arr[5] = 0;
		}
	}
	if (cash >= 2000) {
		if (cash / 2000 <= arr[4]) {
			arrCash[4] = cash / 2000;
			arr[4] -= arrCash[4];
			cash = cash - arrCash[4] * 2000;
		}
		else {
			cash = cash - arr[4]*2000;
			arrCash[4] += arr[4];
			arr[4] = 0;
		}
	}
	if (cash >= 1000) {
		if (cash / 1000 <= arr[3]) {
			arrCash[3] = cash / 1000;
			arr[3] -= arrCash[3];
			cash = cash - arrCash[3] * 1000;
		}
		else {
			cash = cash - arr[3]*1000;
			arrCash[3] += arr[3];
			arr[3] = 0;
		}
	}
	if (cash >= 500) {
		if (cash / 500 <= arr[2]) {
			arrCash[2] = cash / 500;
			arr[2] -= arrCash[2];
			cash = cash - arrCash[2] * 500;
		}
		else {
			cash = cash - arr[2]*500;
			arrCash[2] += arr[2];
			arr[2] = 0;
		}
	}
	if (cash >= 200) {
		if (cash / 200 <= arr[1]) {
			arrCash[1] = cash / 200;
			arr[1] -= arrCash[1];
			cash = cash - arrCash[1] * 200;
		}
		else {
			cash = cash - arr[1]*200;
			arrCash[1] += arr[1];
			arr[1] = 0;
		}
	}
	if (cash >= 100) {
		arrCash[0] = cash / 100;
		arr[0] -= arrCash[0];
		cash = cash - arrCash[0] * 100;
	}
	if (cash == 0) {
		cout << endl;
		cout << "Операция выдачи наличных выполнена успешно!" << endl;
	}
	cout << "Выдано: " << arrCash[0] << " ед. по 100 рублей" << endl;
	cout << "Выдано: " << arrCash[1] << " ед. по 200 рублей" << endl;
	cout << "Выдано: " << arrCash[2] << " ед. по 500 рублей" << endl;
	cout << "Выдано: " << arrCash[3] << " ед. по 1000 рублей" << endl;
	cout << "Выдано: " << arrCash[4] << " ед. по 2000 рублей" << endl;
	cout << "Выдано: " << arrCash[5] << " ед. по 5000 рублей" << endl;
	cout << endl;
	cout << "Остаток в банкомате: " << arr[0] << " ед. по 100 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[1] << " ед. по 200 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[2] << " ед. по 500 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[3] << " ед. по 1000 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[4] << " ед. по 2000 рублей" << endl;
	cout << "Остаток в банкомате: " << arr[5] << " ед. по 5000 рублей" << endl;
	cout << endl;
	cout << "Всего в банкомате осталось: " << summa-cashF << " рублей" << endl;
	return 0;
}
