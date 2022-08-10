#include "Buy.h"
#include "User.h"
#include<time.h>
#include<ctime>
void Buy::buy(char* log, string tovar, int cost)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	strcpy(this->buyer, log);
	this->tovar = tovar;
	this->cost = cost;
	this->day = ltm->tm_mday;
	this->month = 1 + ltm->tm_mon;
	this->year = 1900 + ltm->tm_year;
}
int Buy::read_data(Buy*b)
{
	ifstream read("Покупки.txt");
	int i=0;
	if (!read.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		while (!read.eof())
		{
			read >> b[i].buyer;
			read >> b[i].day;
			read >> b[i].month;
			read >> b[i].year;
			read >> b[i].tovar;
			read >> b[i].cost;
			i++;
		}
	}
	read.close();
	return i;
}
void Buy::zapis(Buy* b, int kol)
{
	ofstream file("Покупки.txt");
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		for (int i = 0; i < kol; i++)
		{
			file << b[i].buyer << endl;
			file << b[i].day << endl;
			file << b[i].month << endl;
			file << b[i].year << endl;
			file << b[i].tovar << endl;
			if (i == kol - 1)
				file << b[i].cost;
			else
				file << b[i].cost << endl;
		}
	}
	file.close();
}
void Buy::otchet(Buy* b, int kol,char* login)
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Текущее время и дата: %s", asctime(timeinfo));	
	system("cls");
	int summa=0,kolt=0;
	cout << endl<<"     Отчет о проданных товарах магазина компьютерной техники: \t" << endl;
	cout << " ______________________________________________________________________________________" << endl;
	cout << "| № |   Дата продажи    |  Логин покупателя  |  Название товара  |  Стоимость покупки  |"<<endl;
	cout << "|___|___________________|____________________|___________________|_____________________|" << endl;
	for (int i = 0; i < kol; i++)
	{
		summa += b[i].cost;
		kolt++;
		cout << "|" << setw(3) << i + 1 << "|" << setw(8) << b[i].day << "." << b[i].month << "." << b[i].year << "\t|" << setw(20) << b[i].buyer << "|" << setw(19) << b[i].tovar << "|" << setw(21) << b[i].cost<<"|"<<endl;
		cout << "|___|___________________|____________________|___________________|_____________________|" << endl;
	}
	cout << "Общее число проданных товаров состовляет: " << kolt << "."<<endl;
	cout << "Выручка магазина составляет: " << summa << " белорусских рублей." << endl;
	cout << "Отчет составлен менеджером: " << login << "." << endl;
	cout << asctime(timeinfo) << endl;
	ofstream out("Отчет.txt");
	if (!out.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		out << "           Отчет о проданных товарах магазина компьютерной техники: \t" << endl;
		out << " ______________________________________________________________________________________" << endl;
		out << "| № |   Дата продажи    |  Логин покупателя  |  Название товара  |  Стоимость покупки  |" << endl;
		out << "|___|___________________|____________________|___________________|_____________________|" << endl;
		for (int i = 0; i < kol; i++)
		{
			out << "|" << setw(3) << i + 1 << "|" << setw(8) << b[i].day << "." << b[i].month << "." << b[i].year << "\t|" << setw(20) << b[i].buyer << "|" << setw(19) << b[i].tovar << "|" << setw(21) << b[i].cost << "|" << endl;
			out << "|___|___________________|____________________|___________________|_____________________|" << endl;
		}
		out << "Общее число проданных товаров состовляет: " << kolt << "."<<endl;
		out << "Выручка магазина составляет: " << summa << " белорусских рублей." << endl;
		out << "Отчет составлен менеджером: " << login << "." << endl;
		out << asctime(timeinfo) << endl;
	}
	out.close();
}

void Buy::sort(Buy* b, int kol)
{
	for (int j = 0; j < kol; j++)
	{
		for (int i=0;i<kol-1;i++)
		{
			if (b[i].year>b[i+1].year)
			{
				Buy tmp;
				tmp.day = b[i].day;
				tmp.month = b[i].month;
				tmp.year = b[i].year;
				b[i].day = b[i+1].day;
				b[i].month = b[i+1].month;
				b[i].year = b[i+1].year;
				b[i + 1].day = tmp.day;
				b[i + 1].month = tmp.month;
				b[i + 1].year = tmp.year;
			}
			else if(b[i].year == b[i+1].year)
			{
				if (b[i].month>b[i+1].month)
				{
					Buy tmp;
					tmp.day = b[i].day;
					tmp.month = b[i].month;
					tmp.year = b[i].year;
					b[i].day = b[i + 1].day;
					b[i].month = b[i + 1].month;
					b[i].year = b[i + 1].year;
					b[i + 1].day = tmp.day;
					b[i + 1].month = tmp.month;
					b[i + 1].year = tmp.year;
				}
				else if (b[i].month == b[i + 1].month)
				{
					if (b[i].day>b[i+1].day)
					{
						Buy tmp;
						tmp.day = b[i].day;
						tmp.month = b[i].month;
						tmp.year = b[i].year;
						b[i].day = b[i + 1].day;
						b[i].month = b[i + 1].month;
						b[i].year = b[i + 1].year;
						b[i + 1].day = tmp.day;
						b[i + 1].month = tmp.month;
						b[i + 1].year = tmp.year;
					}
				}
			}
		}
	}
}

int Buy::vivod(Buy* b, int kol, char* log)
{
	int kolt = 0, sum = 0;
	cout << " _________________________________________________________________" << endl;
	cout << "| № |   Дата продажи    |  Название товара  |  Стоимость покупки  |" << endl;
	cout << "|___|___________________|___________________|_____________________|" << endl;
	for (int i = 0; i < kol; i++)
	{
		if (strcmp(b[i].buyer,log)==0)
		{
			kolt++;
			cout << "|" << setw(3) << kolt << "|" << setw(8) << b[i].day << "." << b[i].month << "." << b[i].year << "\t|" << setw(19) << b[i].tovar << "|" << setw(21) << b[i].cost << "|" << endl;
			cout << "|___|___________________|___________________|_____________________|" << endl;
		}
	}
	for (int i = 0; i < kol; i++)
	{
		if (strcmp(b[i].buyer, log) == 0)
		{
			sum = sum + b[i].cost;
		}
	}
	if (kolt == 0)
	{
		system("cls");
		return 0;
	}
	else {
		cout << "Общая сумма покупок: " << sum << endl;
		return 1;
	}
}
int Buy::index(Buy* b, int& kol, int index, char* log)
{
	int kolt = 0;
	for (int i = 0; i < kol; i++)
	{
		if (strcmp(b[i].buyer, log) == 0)
		{
			kolt++;
			if (kolt == index)
				return i;
		}
	}
	return 0;
}
void Buy::del_buy(Buy* b, int &kol, int index)
{
	if (index+1==kol)
	{
		kol--;
	}
	else {
		for (int i = index; i < kol - 1; i++)
		{
			strcpy(b[i + 1].buyer, b[i].buyer);
			b[i].day = b[i + 1].day;
			b[i].month = b[i + 1].month;
			b[i].year = b[i + 1].year;
			b[i].cost = b[i + 1].cost;
			b[i].tovar = b[i + 1].tovar;
		}
		kol--;
	}
}
void Buy::del_buy(Buy* b, int &kol, string tov,char* log)
{
	int count = 0;
	for (int o = 0; o < kol; o++)
	{
		if (b[o].tovar == tov && strcmp(b[o].buyer,log)==0)
		{
			count++;
			if (o == kol-1)
			{
				kol--;
				break;
			}
			else {
				for (int i = o; i < kol - 1; i++)
				{
					strcpy(b[i + 1].buyer, b[i].buyer);
					b[i].day = b[i + 1].day;
					b[i].month = b[i + 1].month;
					b[i].year = b[i + 1].year;
					b[i].cost = b[i + 1].cost;
					b[i].tovar = b[i + 1].tovar;
				}
				kol--;
				break;
			}
		}
	}
	if (count == 0) {
		cout << "Вы не приобретали такой товар!" << endl;
		Sleep(1500);
	}
}
void data::print_data()

{
	cout << day << "." << month << "." << year<<endl;
}
std::ostream& operator<<(std::ostream& out, const Buy& b)
{
	out << b.buyer << " " << b.day << "." << b.month << "." << b.year << " " << b.tovar << " " << b.cost << endl;
	return out;
}
std::istream& operator>>(std::istream& in, Buy& b)
{
	in >> b.buyer;
	in >> b.day;
	in >> b.month;
	in >> b.year;
	in >> b.tovar;
	in >> b.cost;
	return in;
}