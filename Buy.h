#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
class data
{
public:
	int day;
	int month;
	int year;
	void print_data();//печать даты в привычном формате
};
class Buy :public data
{
private:
	char buyer[20];
	string tovar;
	int cost;
public:
	void print_data() {
		data::print_data();
		cout << buyer << endl << tovar << endl << cost << endl;
	}
	int read_data(Buy* b);//чтение данных о совершенных покупках
	void buy(char* log,string tovar,int cost);//совершение покупки
	void zapis(Buy* b,int kol);//запись данных о совершенных покупках
	void otchet(Buy* b, int kol, char* login);//отчет о проданных товарах
	void sort(Buy* b, int kol);//сортировка продаж по дате
	int vivod(Buy* b, int kol,char* log);//вывод покупок отдельного покупателя
	int index(Buy* b, int& kol, int index, char* log);//поиск индекса для удаления
	void del_buy(Buy* b, int &kol, int index);//удаление покупки
	void del_buy(Buy* b, int &kol, string tov, char* log);//удаление покупки
	friend std::ostream& operator<< (std::ostream& out, const Buy& b);//перегрузка оператора вывода
	friend std::istream& operator>> (std::istream& in, Buy& b);//перегрузка оператора ввода
};