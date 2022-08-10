#include "User.h"
#include"LIST.h"
#include"Buy.h"
#include<fstream>
#include <conio.h>
List lst;
Admin a;
User u;
Buy b[20];
int kol = 0;
struct avtorizaciya
{
	char log[20], pass[20];
};
struct avtorizaciya avt_us[10];
char work_log[20];
char work_log_adm[20];
int use = 0;
void Print(List& a);//����� ������ � ������� �� �����
bool User::avtor()
{	
	bool check = false;
	char check_log[20],check_pass[20];
	string pass;
	cout << "���� �� ������ ������������������, �� ������� 1, \n���� � ��� ��� ���� �������, �� ������� 2.\n����: ";
	int tmp = vvod(0, 3);
	if (tmp==2)
	{
		cout << "������� �����:" << endl;
		cin >> check_log;

		int c = 0;
		cout << "\n������� ������:" << endl;
		while (true)
		{
			c = _getch();
			if (c == 0)
				c = _getch();
			if (c == '\r' || c == '\n')
				break;
			cout << "*";
			pass += c;
		}
		strcpy(check_pass, pass.c_str());
		for (int j = 0; j < use; j++)
		{
			if (strcmp(check_log, avt_us[j].log) == 0)
			{
				if (strcmp(check_pass, avt_us[j].pass) == 0)
				{
					strcpy(work_log, check_log);
					return true;
				}
			}
			else
				check = false;
		}
		return check;
	}
	else
	{
		char pass[20], log[20];
		cout << "������� �����: ";
		cin >> log;
		cout << "������� ������: ";
		cin >> pass;
		use++;
		strcpy(avt_us[use - 1].log, log);
		strcpy(avt_us[use - 1].pass, pass);
		strcpy(work_log, log);
		
		return true;
	}
}
void User::zapis()
{
	int KEY = 10;
	ofstream out("������������.txt", ios_base::trunc| ios_base::out);
	if (!out.is_open())
		cout << "���� �� ����� ���� ������!\n";
	else {
		for (int r = 0; r < use; r++)
		{
			for (int n = 0; n < strlen(avt_us[r].pass); n++)
			{
				int symbol = int(avt_us[r].pass[n]) + KEY;
				avt_us[r].pass[n] = symbol;
			}
			out << avt_us[r].log << endl;
			if (r == use - 1)
				out << avt_us[r].pass;
			else
				out << avt_us[r].pass << endl;
		}
	}
	out.close();
}
void User::read_avt()
{
	int KEY = 10;
	ifstream file("������������.txt", ios_base::in);
	if (!file.is_open())
		cout << "���� �� ����� ���� ������!\n";
	else {
		while (!file.eof())
		{
			file >> avt_us[use].log;
			file >> avt_us[use].pass;
			use++;
		}
	}
	for (int r = 0; r < use; r++)
	{
		for (int n = 0; n < strlen(avt_us[r].pass); n++)
		{
			int symbol = int(avt_us[r].pass[n]) - KEY;
			avt_us[r].pass[n] = symbol;
		}
	}
	file.close();
}
bool Admin::avtor()
{
	int KEY = 3;
	struct avtorizaciya
	{
		char log[20], pass[20];
	};
	struct avtorizaciya avt[5];
	int i = 0;
	ifstream file("���������.txt", ios_base::in);
	if (!file.is_open())
		cout << "���� �� ����� ���� ������!\n";
	else {
		while (!file.eof())
		{
			file >> avt[i].log;
			file >> avt[i].pass;
			i++;
		}
	}
	file.close();
	for (int r = 0; r < i; r++)
	{
		for (int n = 0; n < strlen(avt[r].pass); n++)
		{
			int symbol = int(avt[r].pass[n])-KEY;
			avt[r].pass[n] = symbol;
		}
	}
	bool check = false;
	char check_log[20], check_pass[20];
	string pass;
	cout << "������� �����:" << endl;
	cin >> check_log;
	int c = 0;
	cout << "\n������� ������:" << endl;
	while (true)
	{
		c = _getch();
		if (c == 0)
			c = _getch();
		if (c == '\r' || c == '\n')
			break;
		cout << "*";
		pass += c;
	}
	strcpy(check_pass, pass.c_str());
	for (int j = 0; j < i; j++)
	{
		if (strcmp(check_log, avt[j].log) == 0)
		{
			if (strcmp(check_pass, avt[j].pass) == 0)
			{
				strcpy(work_log_adm, check_log);
				return true;
			}
		}
		else
			check = false;
	}
	return check;
}
void Human::get_info()
{
	cout << "������� ���: ";
	cin >> name;
	cout << "������� �������: ";
	cin >> sername;
}
int menu()
{
	while (1)
	{
		system("cls");
		cout << "*** ������� ���� ***" << endl;
		cout << "1-���� ��� ���������������" << endl;
		cout << "2-���� ��� �������������" << endl;
		cout << "3-�����" << endl;
		cout << "��� �����: ";
		switch (vvod(0,4))
		{
		case 1:
		{
			if (a.avtor())
				menu_adm();
			else
			{
				cout << "\n��������� ������ ��� �����������!";
				Sleep(1500);
			}
		}break;
		case 2:
		{
			if (u.avtor())
				menu_us();
			else
			{
				cout << "\n��������� ������ ��� �����������!";
				Sleep(1500);
			}
		}break;
		case 3:
			return 0; break;
		default: system("cls"); cout << "������� ���������� ��������" << endl; break;
		}
	}
	return 0;
}
int menu_us()
{
	int flag2 = 1;
	while (flag2)
	{
		system("cls");
		cout << "*** ���� ������������ ***" << endl;
		cout << "1-�������� �������" << endl;
		cout << "2-��������� ������, ���������� � ���������� ������" << endl;
		cout << "3-������� ������" << endl;
		cout << "4-���������� ���������" << endl;
		cout << "5-����� � ���� 1-�� ������" << endl;
		cout << "��� �����: ";
		switch (vvod(0,6))
		{
		case 1:	Print(lst); system("pause"); break;
		case 2: menu_poisk_filtr(); break;
		case 3:
		{
			Print(lst);
			cout << "������� ����� ������, ������� ������ ����������: ";
			int oper = vvod(0, lst.GetSize()+1);
			if (lst.check_buy(oper))
			{
				b[kol].buy(work_log, lst.get_name(oper), lst.get_cost(oper));
				kol++;
				cout << "������� ������ �������." << endl;
			}
			else
				cout << "� ��������� ����� ����������� � ��������." << endl;
			Sleep(1500);
		}break;
		case 4:  menu_upr_buy(); break;
		case 5:  flag2 = 0; break;
		default:system("cls"); cout << "������� ���������� ��������" << endl; break;
		}
	}
	return 0;
}
int menu_adm()
{
	int flag1 = 1;
	while (flag1)
	{
		system("cls");
		cout << "*** ���� �������������� ***" << endl;
		cout << "1-���������� ������" << endl;
		cout << "2-�������������� ������" << endl;
		cout << "3-�������� ������" << endl;
		cout << "4-�������� ������ � �������" << endl;
		cout << "5-����� � ��������� �������" << endl;
		cout << "6-��������� ������, ���������� � ���������� ������" << endl;
		cout << "7-���������� ��������������" << endl;
		cout << "8-����� � ���� 1-�� ������" << endl;
		cout << "��� �����: ";
		switch (vvod(0,9))
		{
		case 1:	lst.push_back(); cout << "����� ������� ��������!" << endl; Sleep(1500); break;
		case 2: {
			Print(lst);
			lst.reduct();
		}break;
		case 3:{
			Print(lst);
			lst.removeAt();
			cout << "������ ������� �������!" << endl;
			Sleep(1500);
		}break;
		case 4: Print(lst); system("pause"); break;
		case 5:
		{
			b->sort(b, kol);
			b->otchet(b, kol,work_log_adm); 
			system("pause");
		}  break;
		case 6:	menu_poisk_filtr(); break;
		case 7: menu_upr_us(); break;
		case 8: flag1 = 0; break;
		default: system("cls"); cout << "������� ���������� ��������" << endl; Sleep(1500); break;
		}
	}
	return 0;
}
int menu_poisk_filtr()
{
	int flag = 1;
	while (flag)
	{
		system("cls");
		cout << "*** ���� ������, ���������� � ���������� ***" << endl;
		cout << "1-����� ������ �� ��������" << endl;
		cout << "2-���������� ������� �� ������������ ��������� � ����������� ���������" << endl;
		cout << "3-���������� �������" << endl;
		cout << "4-����� � ���� ������� ������" << endl;
		cout << "��� �����: ";
		switch (vvod(0,5))
		{
		case 1:	lst.poisk(); break;
		case 2: lst.filtr(); break;
		case 3: {
			system("cls");
			cout << "*** ���� ���������� ***" << endl;
			cout << "1-����������� �� ��������" << endl;
			cout << "2-C���������� �� ��������� (�� �����������)" << endl;
			cout << "3-C���������� �� ��������� (�� ��������)" << endl;
			switch(vvod(0,4))
			{
			case 1: lst.sort_a(lst);
				cout << "������ �������������� �� ��������." << endl;
				Sleep(1500); break;
			case 2: lst.sort_c_v(lst);
				cout << "������ �������������� �� ��������� (�� �����������)." << endl;
				Sleep(1500); break;
			case 3: lst.sort_c_u(lst);
				cout << "������ �������������� �� ��������� (�� ��������)." << endl;
				Sleep(1500); break;
			default: cout << "������� ���������� ��������" << endl;  break;
			}
			
		}break;
		case 4: flag = 0; break;
		default: cout << "������� ���������� ��������" << endl;  break;
		}
	}
	return 0;
}
int menu_upr_us()
{
	int flag = 1;
	while (flag)
	{
		system("cls");
		cout << "@@@ ���� ���������� �������������� @@@" << endl;
		cout << "1-���������� ������������" << endl;
		cout << "2-�������� ������ � �������������" << endl;
		cout << "3-�������� ������������" << endl;
		cout << "4-����� � ���� ��������������" << endl;
		cout << "��� �����: ";
		switch (vvod(0,5))
		{
		case 1: a.add_user(); break;
		case 2: a.vivod_users(); system("pause"); break;
		case 3: a.dell_user(); cout << "������������ ������!" << endl; Sleep(1500); break;
		case 4: flag = 0; break;
		default:system("cls"); cout << "������� ���������� ��������" << endl; Sleep(1500); break;
		}
	}
	return 0;
}
int menu_upr_buy()
{
	int flag = 1;
	while (flag)
	{
		system("cls");
		cout << "@@@ ���� ���������� ��������� @@@" << endl;
		cout << "1-�������� ����������� �������" << endl;
		cout << "2-������ �������" << endl;
		cout << "3-����� � ���� ������������" << endl;
		cout << "��� �����: ";
		switch (vvod(0, 4))
		{
		case 1:
		{
			b->vivod(b, kol, work_log);
			system("pause");
		}break;
		case 2:
		{
			int ch, index;
			string tov;
			if (b->vivod(b, kol, work_log)==1)
			{
				cout << "������� '1', � ����� ����� ��� '2', � ����� �������� ������, ������� ������ �������" << endl;
				ch = vvod(0, 3);
				if (ch == 1) {
					index = vvod(0, kol);
					b->del_buy(b, kol, b->index(b,kol,index,work_log));
				}
				else {
					cin >> tov;
					b->del_buy(b, kol, tov, work_log);
				}
			}
			else cout << "�� �� ��������� �������." << endl;
		}break;
		case 3: flag = 0; break;
		default:system("cls"); cout << "������� ���������� ��������" << endl; Sleep(1500); break;
		}
	}
	return 0;
};
void Admin::add_user()
{
	char pass[20], login[20];
	cout << "������� �����: ";
	cin >> login;
	cout << "������� ������: ";
	cin >> pass;
	use++;
	strcpy(avt_us[use - 1].log, login);
	strcpy(avt_us[use-1].pass, pass);	
}
void Admin::vivod_users()
{
	cout << " _____________________________________________" << endl;
	cout << "|  �  |       �����       |       ������      |" << endl;
	cout << "|_____|___________________|___________________|" << endl;
	for (int j = 0; j < use; j++)
	{
		cout << "|" <<setw(5)<< j + 1 << "|"<<setw(19) << avt_us[j].log << "|" << setw(19) << avt_us[j].pass << "|" << endl;
		cout << "|_____|___________________|___________________|" << endl;
	}
}
void Admin::dell_user()
{
	cout << " _____________________________________________" << endl;
	cout << "|  �  |       �����       |       ������      |" << endl;
	cout << "|_____|___________________|___________________|" << endl;
	for (int j = 0; j < use; j++)
	{
		cout << "|" << setw(5) << j + 1 << "|" << setw(19) << avt_us[j].log << "|" << setw(19) << avt_us[j].pass << "|" << endl;
		cout << "|_____|___________________|___________________|" << endl;
	}
	int num;
	cout << "������� ����� ������������, �������� ������ �������: ";
	num = vvod(0,use+1);
	if (num > use+1)
	{
		cout << "������������ � ����� ������� ����" << endl;
		Sleep(1500);
	}
	else
	{
		for (int j = num - 1; j < use; j++)
		{
			strcpy(avt_us[j].log, avt_us[j + 1].log);
			strcpy(avt_us[j].pass, avt_us[j + 1].pass);
		}
		use--;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	u.read_avt();
	lst.read_data();
	kol= b->read_data(b);
	
	menu();

	lst.zapis_data();
	u.zapis();
	b->zapis(b,kol);
	return 0;
}