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
	void print_data();//������ ���� � ��������� �������
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
	int read_data(Buy* b);//������ ������ � ����������� ��������
	void buy(char* log,string tovar,int cost);//���������� �������
	void zapis(Buy* b,int kol);//������ ������ � ����������� ��������
	void otchet(Buy* b, int kol, char* login);//����� � ��������� �������
	void sort(Buy* b, int kol);//���������� ������ �� ����
	int vivod(Buy* b, int kol,char* log);//����� ������� ���������� ����������
	int index(Buy* b, int& kol, int index, char* log);//����� ������� ��� ��������
	void del_buy(Buy* b, int &kol, int index);//�������� �������
	void del_buy(Buy* b, int &kol, string tov, char* log);//�������� �������
	friend std::ostream& operator<< (std::ostream& out, const Buy& b);//���������� ��������� ������
	friend std::istream& operator>> (std::istream& in, Buy& b);//���������� ��������� �����
};