#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class String
{
	int dai;
	string kt;
public:
	String(){}
	void Nhap();
	void Print();
	void Character(int x);
};

void String::Nhap()
{
	cout << "Chuoi ki tu: "; cin.ignore(1); getline(cin, kt);
	dai = kt.size();
}

void String::Print()
{
	cout << endl << "Chuoi ki tu: " << kt;
}

void String::Character(int x)
{
	cout << "Ki tu thu " << x << ": " << kt[x - 1];
}

int main()
{
	String s;
	while (1)
	{
		cout << endl << "--------MENU--------";
		cout << endl << "|1. Nhap chuoi.    |";
		cout << endl << "|2. Tim kiem kt.   |";
		cout << endl << "|3. In chuoi.      |";
		cout << endl << "|4. Thoat.         |";
		cout << endl << "--------------------";
		int lc; cout << endl << "Nhap lua chon: "; cin >> lc;
		if (lc == 1)
		{
			s.Nhap();
		}
		if (lc == 2)
		{
			int x; cout << endl << "Nhap vi tri ki tu muon in ra man hinh: "; cin >> x;
			s.Character(x);
		}
		if (lc == 3)
		{
			s.Print();
		}
		if (lc == 4)
		{
			break;
		}
	}
}