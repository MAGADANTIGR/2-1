#include "LIST.h"
#include<fstream>
int vvod(int left, int right) {
	while (1) {
		int a;
		bool flag = true;
		char dat[255];
		cin >> dat;
		for (int i = 0; i < strlen(dat); i++) {
			if (!(dat[i] == '0' || dat[i] == '1' || dat[i] == '2' || dat[i] == '3' || dat[i] == '4' || dat[i] == '5' || dat[i] == '6' || dat[i] == '7' || dat[i] == '8' || dat[i] == '9'))
				flag = false;
		}
		if (flag == false)
			cout << "Введите верное значение. " << endl;
		else {
			a = atoi(dat);
			if (a > left && a < right)
				return a;
			else
				cout << "Введите верное значение. " << endl;
		}
	}
}
List::List()
{
	size = 0;
	head = nullptr;
}
List::~List()
{
	clear();
}
void List::push_front()
{
	string name;
	int kol, cost;
	cout << "Введите название товара: ";
	cin >> name;
	cout << "Введите количество товара: ";
	kol = vvod(0, 200);
	cout << "Введите стоимость товара(рублей): ";
	cost = vvod(0, 3000);
	head = new Node(name, kol, cost, head);
	size++;
}
void List::push_back()
{
	string name;
	int kol, cost;
	cout << "Введите название товара: ";
	cin >> name;
	cout << "Введите количество товара: ";
	kol = vvod(0, 200);
	cout << "Введите стоимость товара(рублей): ";
	cost = vvod(0, 3000);
	if (head == nullptr)
	{
		head = new Node(name, kol, cost);
	}
	else
	{
		Node* current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(name, kol, cost);
	}
	size++;
}
void List::pop_front()
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}
void List::clear()
{
	while (size)
	{
		pop_front();
	}
}
void List::removeAt()
{
	int index;
	cout << "Введите номер товара, который необходимо удалить: ";
	index = vvod(0,size+1);
	if (index-1 == 0) {
		pop_front();
	}
	else {
		Node* previous = head;
		for (int i = 0; i < index-2; i++)
		{
			previous = previous->pNext;
		}
		Node* ToDelete = previous->pNext;
		previous->pNext = ToDelete->pNext;
		delete ToDelete;
		size--;
	}
}
void List::print(const int index)
{
	Node* current = head;
	for (int i = 0; i != index and current != nullptr; i++)
	{
		current = current->pNext;
	}
	cout << "|"<<setw(3) << index+1 << "|" << setw(16) << current->name << "|" << setw(14) << current->kol << "|" << setw(15) << current->cost << "|" << endl;
	cout << "|___|________________|______________|_______________|" << endl;
}
void Print(List& a)
{
	cout << " ___________________________________________________" << endl;
	cout << "| № |    Название    |  Количество  |   Стоимость   |" << endl;
	cout << "|___|________________|______________|_______________|" << endl;
	for (int i = 0; i < a.GetSize(); i++)
	{
		a.print(i);
	}
	cout << std::endl;
}
void List::read_data()
{
	ifstream file("Товары.txt", ios_base::in);
	string name;
	int kol, cost;
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		while (!file.eof())
		{
			file >> name;
			file >> kol;
			file >> cost;
			if (head == nullptr)
			{
				head = new Node(name, kol, cost);
			}
			else
			{
				Node* current = head;

				while (current->pNext != nullptr)
				{
					current = current->pNext;
				}
				current->pNext = new Node(name, kol, cost);
			}
			size++;
		}
	}
	file.close();
}
void List::zapis_data()
{
	ofstream file("Товары.txt");
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		Node* current = head;
		for (int i=0;i<size;i++)
		{
			file << current->name << endl;
			file << current->kol << endl;
			if (i==size-1)
				file << current->cost;
			else
				file << current->cost << endl;
			current = current->pNext;
		}
	}
	file.close();
}
void List::reduct()
{
	cout << "Введите номер товара, который необходимо отредактировать: ";
	int ch = vvod(0, this->GetSize() + 1);
	cout << "Введите:\n1-Редактирование названия\n2-Редактирование количества\n3-Редактирование стоимости\nВаш выбор: ";
	int red = vvod(0, 4);
	if (red == 1)
	{
		string new_name;
		cout << "Введите новое название товара: ";
		cin >> new_name;
		if (ch - 1 == 0) {
			this->head->name = new_name;
		}
		else {
			Node* previous;
			previous = this->head;

			for (int i = 0; i < ch - 2; i++)
			{
				previous = previous->pNext;
			}
			previous->name = new_name;
		}
	}
	else if (red == 2)
	{
		int new_kol;
		cout << "Введите новое количество товара: ";
		new_kol = vvod(-1, 200);
		if (ch - 1 == 0) {
			this->head->kol = new_kol;
		}
		else {
			Node* previous;
			previous = this->head;

			for (int i = 0; i < ch - 1; i++)
			{
				previous = previous->pNext;
			}
			previous->kol = new_kol;
		}
	}
	else
	{
		int new_cost;
		cout << "Введите новую стоимость товара: ";
		new_cost = vvod(0, 3000);
		if (ch - 1 == 0) {
			this->head->cost = new_cost;
		}
		else {
			Node* previous;
			previous = this->head;

			for (int i = 0; i < ch - 2; i++)
			{
				previous = previous->pNext;
			}
			previous->cost = new_cost;
		}
	}
}
void List::poisk()
{
	int count = 0;
	bool check = false;
	string poisk;
	cout << "Введите название товара, о котором вы хотите получить информацию: ";
	cin >> poisk;
	Node* prev = this->head;
	while (prev)
	{
		if (prev->name == poisk)
		{
			cout << " ___________________________________________________" << endl;
			cout << "| № |    Название    |  Количество  |   Стоимость   |" << endl;
			cout << "|___|________________|______________|_______________|" << endl;
			print(count);
			system("pause");
			check =true;
			break;
		}
		prev = prev->pNext;
		count++;
	}
	if (!check) {
		cout << "Товара с таким названием не существует!" << endl;
		Sleep(1500);
	}
}
void List::filtr()
{
	int count = 0;
	bool check = false;
	int max, min;
	cout << "Введите максимальную стоимость товара для вывода: ";
	cin >> max;
	cout << "Введите минимальную стоимость товара для вывода: ";
	cin >> min;
	Node* prev = this->head;
	while (prev)
	{
		if (prev->cost <= max && prev->cost >= min)
		{
			cout << " ___________________________________________________" << endl;
			cout << "| № |    Название    |  Количество  |   Стоимость   |" << endl;
			cout << "|___|________________|______________|_______________|" << endl;
			print(count);
			check = true;
		}
		prev = prev->pNext;
		count++;
	}
	if (!check) {
		cout << "Товаров в диапазоне такой стоимости, которую вы указали, нет!" << endl;
		Sleep(1500);
	}
	else
		system("pause");
}

void List::sort_a(List& lst)
{
	Node* n1, *n2;
	for (int i = 0; i < size; i++)
	{
		n1 = head;
		n2 = n1->pNext;
		for (int j = 0; j < size - 1; j++)
		{
			if (n1->name > n2->name)
			{
				swap(n1, n2, this->head, lst);
				n2 = n1->pNext;
			}
			else
			{
				n1 = n1->pNext;
				n2 = n2->pNext;
			}
		}
	}
}
void List::sort_c_v(List& lst) {
	Node* n1, * n2;
	for (int i = 0; i < size; i++)
	{
		n1 = head;
		n2 = n1->pNext;
		for (int j = 0; j < size - 1; j++)
		{
			if (n1->cost > n2->cost)
			{
				swap(n1, n2, this->head, lst);
				n2 = n1->pNext;
			}
			else
			{
				n1 = n1->pNext;
				n2 = n2->pNext;
			}
		}
	}
}
void List::sort_c_u(List& lst) {
	Node* n1, * n2;
	for (int i = 0; i < size; i++)
	{
		n1 = head;
		n2 = n1->pNext;
		for (int j = 0; j < size - 1; j++)
		{
			if (n1->cost < n2->cost)
			{
				swap(n1, n2, this->head, lst);
				n2 = n1->pNext;
			}
			else
			{
				n1 = n1->pNext;
				n2 = n2->pNext;
			}
		}
	}
}
void List::swap(Node* first, Node* second, Node* head, List& lst)
{
	Node* prev1, * prev2, * next1, * next2;
	prev1 = head;
	prev2 = head;
	if (prev1 == first)
		prev1 = NULL;
	else
		while (prev1->pNext != first)
			prev1 = prev1->pNext;
	if (prev2 == second)
		prev2 = NULL;
	else
		while (prev2->pNext != second)
			prev2 = prev2->pNext;
	next1 = first->pNext;
	next2 = second->pNext;
	if (second==next1)
	{
		second->pNext = first;
		first->pNext = next2;
		if (first != head)
			prev1->pNext = second;
	}
	else
	{
		if (first != head)
			prev1->pNext = second;
		second->pNext = next1;
		if (second != head)
			prev2->pNext = first;
		first->pNext = next2;
	}
	if (first == head)
		lst.head=second;
	else if (second == head)
		lst.head = first;
	else
		lst.head = head;
}
string List::get_name(int index)
{
	if (index - 1 == 0) {
		return head->name;
	}
	else {
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		return previous->name;
	}
}
int List::get_cost(int index)
{
	if (index - 1 == 0) {
		return head->cost;
	}
	else {
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		return previous->cost;
	}
}
bool List::check_buy(int index)
{
	if (index - 1 == 0) {
		if (head->kol>0)
		{
			head->kol--;
			return true;
		}
		return false;
	}
	else {
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		if (previous->kol>0)
		{
			previous->kol--;
			return true;
		}
		return false;
	}
}