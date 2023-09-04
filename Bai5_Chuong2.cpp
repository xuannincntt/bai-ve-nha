#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Data
{
	string shd, tenhang;
	double gia;
};

class HoaDon
{
	Data dl;
public:
	HoaDon* next;
	void Nhap();
	friend HoaDon* ThemHoaDon(HoaDon** a);
	friend void Print(HoaDon* a);
	friend void SapXep(HoaDon** a);
};

void HoaDon::Nhap()
{
	cout << "Ten hang: ";
	cin.ignore(); getline(cin, dl.tenhang);
	cout << "So hoa don: "; cin >> dl.shd;
	cout << "Gia ban: "; cin >> dl.gia;
}

void Print(HoaDon* a)
{
	cout << "-----------------------------------------------" << endl;
	while (a != NULL)
	{
		cout << "|" << setw(5) << a->dl.shd << "|" << setw(23) << a->dl.tenhang << "|" << setw(14) << a->dl.gia << "|" << endl;
		cout << "-----------------------------------------------" << endl;
		a = a->next;
	}
}

HoaDon* ThemHoaDon(HoaDon** a)
{
	HoaDon* hd = new HoaDon;
	hd->Nhap();
	hd->next = NULL;
	if (*a == NULL)
	{
		*a = hd;
	}
	else
	{
		HoaDon* p = *a;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = hd;
	}
	return hd;
}

void SapXep(HoaDon** a)
{
	for (HoaDon* p = *a; p->next != NULL; p = p->next)
	{
		for (HoaDon* p1 = p->next; p1 != NULL; p1 = p1->next)
		{
			if (p->dl.gia < p1->dl.gia)
			{
				Data tmp = p->dl;
				p->dl = p1->dl;
				p1->dl = tmp;
			}
		}
	}
}

int main()
{
	HoaDon* head = NULL;
	while (1)
	{
		cout << "-------------------------MENU------------------------" << endl;
		cout << "|1. Nhap thong tin cho hang hoa!                     |" << endl;
		cout << "|2. Sap xep gio hang theo gia hang hoa!              |" << endl;
		cout << "|3. In thong tin hoa don!                            |" << endl;
		cout << "|4. Thoat!                                           |" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Nhap lua chon: ";
		int lc; cin >> lc;
		if (lc == 4)
		{
			break;
		}
		if (lc == 1)
		{
			ThemHoaDon(&head);
		}
		if (lc == 3)
		{
			cout << "-----------------------------------------------" << endl;
			cout << "| SHD |        TEN HANG        |    GIA BAN   |" << endl;
			Print(head);
		}
		if (lc == 2)
		{
			SapXep(&head);
		}
	}
	for (HoaDon* i = head; i != NULL; i = i->next)
	{
		delete i;
	}
}