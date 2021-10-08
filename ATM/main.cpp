#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[] = { 0,0,0,5,5,0 }; //массив, где в [0] хранятся купюры по 100 рублей, [1] - по 200 рублей и т.д.
	int arrMoney[] = { 5000,2000,1000,500,200,100 }; //массив с номиналом купюр, начиная с 5000 и на убывание
	int arrCash[] = { 0,0,0,0,0,0 };
	int cash, cashF, summa = 0;
	for (int i = 0; i < 6; i++) {
		summa += arr[i] * arrMoney[i];
	}
	for (int i = 0; i < 6; i++) {//цикл на вывод количество купюр каждого номинала в банкомате
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
	for (int i = 0; i < 5; i++) { //цикл на промежуток от 5000 до 200 купюр
		if (cash >= arrMoney[i]) { //проверка на операцию больше или равную 5000
			if (cash / arrMoney[i] <= arr[i]) { //если операция укладывается в лимит элемента массива, то производит дальнейший расчет
				arrCash[i] = cash / arrMoney[i];
				arr[i] -= arrCash[i];
				cash -= arrCash[i] * arrMoney[i];
			}
			else { //если операция превышает лимит элемента массива, то пересчитываем запрашиваеммую цифру и присваиваем массиву 0
				cash -= arr[i] * arrMoney[i];
				arrCash[i] = arr[i];
				arr[i] = 0;
			}
		}
	}
	if (cash >= 100) { //условие для 100 рублевок
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
	cout << "Всего в банкомате осталось: " << summa - cashF << " рублей" << endl;
	return 0;
}