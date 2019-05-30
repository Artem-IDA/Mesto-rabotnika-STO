// Место работника СТО.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

struct Zakaz
{
	string NameCar;
	string nomer;
	int stoimost;
	string Opispolomki;
};

vector<Zakaz>AllZakazi;

void zapolnZaiavki()
{
	Zakaz NEW;
	cout << "Vvidite nazvanie transporta" << endl;
	cin.ignore();
	getline(cin , NEW.NameCar);
	cout << "Vvedite nomer transporta" << endl;
	getline(cin, NEW.nomer);
	cout << "Vvedite stoimost remonta" << endl;
	cin >> NEW.stoimost;
	cin.ignore();
	cout << "Opishite polomku" << endl;
	getline(cin, NEW.Opispolomki);
	AllZakazi.push_back(NEW);
}

void vivodInf(int i)
{
	cout << "Nazvanie transporta: " << AllZakazi[i].NameCar << endl;
	cout << "Nomer transporta: " << AllZakazi[i].nomer << endl;
	cout << "Stoimost remonta: " << AllZakazi[i].stoimost << endl;
	cout << "Opisanie polomki" << endl << AllZakazi[i].Opispolomki << endl;
}

void poisk(string name)
{
	cout << "Po zadanomu nazvaniu naideno takie zakazi:" << endl;
	int count = 0;
	for (int i = 0; i < AllZakazi.size(); i++)
	{
		if (AllZakazi[i].NameCar == name)
		{
			vivodInf(i);
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Po zadanomu nazvaniu ne naideno zakazi!" << endl;
	}
}

void sortZak(int type)
{
	if (type == 1)
	{
		for (int i = 0; i < AllZakazi.size() - 1; i++) {
			for (int j = 0; j < AllZakazi.size() - i - 1; j++) {
				if (AllZakazi[j].NameCar > AllZakazi[j + 1].NameCar) {
					swap(AllZakazi[j], AllZakazi[j + 1]);
				}
			}
		}
	}
	else if (type == 2)
	{
		for (int i = 0; i < AllZakazi.size() - 1; i++) {
			for (int j = 0; j < AllZakazi.size() - i - 1; j++) {
				if (AllZakazi[j].nomer > AllZakazi[j + 1].nomer) {
					swap(AllZakazi[j], AllZakazi[j + 1]);
				}
			}
		}
	}
	else if (type == 3)
	{
		for (int i = 0; i < AllZakazi.size() - 1; i++) {
			for (int j = 0; j < AllZakazi.size() - i - 1; j++) {
				if (AllZakazi[j].stoimost > AllZakazi[j + 1].stoimost) {
					swap(AllZakazi[j], AllZakazi[j + 1]);
				}
			}
		}
	}
}

void UdalenieZakaza(string name)
{
	vector<Zakaz>::iterator it = AllZakazi.begin();
	for (int i = 0; i < AllZakazi.size(); i++)
	{
		if (AllZakazi[i].NameCar == name)
		{
			advance(it, i);
			AllZakazi.erase(it);
			cout << "Zakaz udalen USPESHNO!" << endl;
			return;
		}
	}
	cout << "Udalit zakaz s zadanim imenem ne vozmojno!" << endl;
}

void Menu(void)
{
	system("cls");
	cout << "Zapolnenie zaiavki (1)" << endl;
	cout << "Vivod spiska zaiavok (2)" << endl;
	cout << "Sortirovka spiska (3)" << endl;
	cout << "Udalenie zakaza (4)" << endl;
	cout << "Vihod (0)" << endl;
}


int main()
{
	bool lever = true;
	while (lever)
	{
		int lever_m;
		Menu();
		cin >> lever_m;
		if (lever_m == 1)
		{
			system("cls");
			zapolnZaiavki();
		}
		else if (lever_m == 2)
		{
			system("cls");
			if (AllZakazi.size() != 0)
			{
				cout << "-----------------------------------------------------" << endl;
				for (int i = 0; i < AllZakazi.size(); i++)
				{
					vivodInf(i);
					cout << "-----------------------------------------------------" << endl;
				}
			}
			else
				cout << "Spisok pust!" << endl;
			system("pause");
		}
		else if (lever_m == 3)
		{
			cout << "Po imeni (1)" << endl;
			cout << "Po nomeru (2)" << endl;
			cout << "Po stoimosti (3)" << endl;
			int otv;
			cin >> otv;
			sortZak(otv);
		}
		else if (lever_m == 4)
		{
			cout << "Vvedite nazvanie transporta dlia udalenia" << endl;
			string name;
			cin.ignore();
			getline(cin, name);
			UdalenieZakaza(name);
			system("pause");
		}
		else if (lever_m == 0)
		{
			lever = false;
		}
	}



	system("pause");
	return 0;
}


