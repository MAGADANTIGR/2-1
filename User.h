#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int vvod(int left, int right);
int menu();//���� ������� ������
int menu_us();//���� ������������
int menu_adm();//���� ��������������
int menu_poisk_filtr();//���� ������/����������/����������
int menu_upr_us();//���� ���������� ��������������
int menu_upr_buy();//���� ���������� ���������
class Human
{
private:
	string name;
	string sername;
public:
	void get_info();//���� ���������� � ��������
	virtual bool avtor() = 0;//����������� �������
};
class User: public Human
{
private:
	int UID;
public:
	bool avtor();//����������� ������������
	void zapis();//������ ������� � ������� � ����
	void read_avt();//������ ������ ��� �����������
};
class Admin : public Human
{
public:
	bool avtor();//����������� ��������������
	void add_user();//���������� ������ ������������
	void vivod_users();//����� ������ � ������ ������������� �� �����
	void dell_user();//�������� ������������
};