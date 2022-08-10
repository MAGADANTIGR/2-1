#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class List
{
private:
	int size;
public:
	class Node
	{
	public:
		Node* pNext;
		string name;
		int kol;
		int cost;
		Node(string name=nullptr,int kol=0,int cost=0, Node* pNext = nullptr)
		{
			this->name = name;
			this->kol = kol;
			this->cost = cost;
			this->pNext = pNext;
		}
	};
	Node* head;	
	List();
	~List();
	void push_front();//вставка в начало
	void push_back();//вставка в конец
	void pop_front();//удаление первого элемента
	void clear();//очистка списка
	void removeAt();//удаление по индексу
	int GetSize() { return size; };//получение размера
	void print(const int index);//вывод информации об элементе списка
	void read_data();//чтение данных о товарах из файла 
	void zapis_data();//запись данных о товарах в файл
	void reduct();//редактирование
	void poisk();//поиск товара по названию
	void filtr();//фильтрация по стоимости
	void sort_a(List& lst);//сортировка товара в алфавитном порядке
	void sort_c_v(List& lst);//сортировка товара по возрастанию
	void sort_c_u(List& lst);//сортировка товара по убыванию
	void swap(Node*first,Node* second, Node*head,List&lst);
	string get_name(int index);//получение имени товара с введенным индексом
	int get_cost(int index);//получение стоимости товара с введенным индексом
	bool check_buy(int index);//проверка наличия товара в магазине перед его покупкой
};