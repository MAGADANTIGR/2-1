#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int vvod(int left, int right);
int menu();//меню первого уровня
int menu_us();//меню пользователя
int menu_adm();//меню администратора
int menu_poisk_filtr();//меню поиска/фильтрации/сортировки
int menu_upr_us();//меню управления пользователями
int menu_upr_buy();//меню управления покупками
class Human
{
private:
	string name;
	string sername;
public:
	void get_info();//ввод информации о человеке
	virtual bool avtor() = 0;//виртуальная функция
};
class User: public Human
{
private:
	int UID;
public:
	bool avtor();//авторизация пользователя
	void zapis();//запись логинов и паролей в файл
	void read_avt();//чтение данных для авторизации
};
class Admin : public Human
{
public:
	bool avtor();//авторизация администратора
	void add_user();//добавление нового пользователя
	void vivod_users();//вывод логина и пароля пользователей на экран
	void dell_user();//удаление пользователя
};