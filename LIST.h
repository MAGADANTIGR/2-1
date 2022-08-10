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
	void push_front();//������� � ������
	void push_back();//������� � �����
	void pop_front();//�������� ������� ��������
	void clear();//������� ������
	void removeAt();//�������� �� �������
	int GetSize() { return size; };//��������� �������
	void print(const int index);//����� ���������� �� �������� ������
	void read_data();//������ ������ � ������� �� ����� 
	void zapis_data();//������ ������ � ������� � ����
	void reduct();//��������������
	void poisk();//����� ������ �� ��������
	void filtr();//���������� �� ���������
	void sort_a(List& lst);//���������� ������ � ���������� �������
	void sort_c_v(List& lst);//���������� ������ �� �����������
	void sort_c_u(List& lst);//���������� ������ �� ��������
	void swap(Node*first,Node* second, Node*head,List&lst);
	string get_name(int index);//��������� ����� ������ � ��������� ��������
	int get_cost(int index);//��������� ��������� ������ � ��������� ��������
	bool check_buy(int index);//�������� ������� ������ � �������� ����� ��� ��������
};