#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Data
{
	string ten, msv, lop;
	double diem;
};

class SinhVien
{
	Data dl;
public:
	SinhVien *next;
	void Nhap();
	friend SinhVien* ThemSinhVien(SinhVien* *a);
	friend void In(SinhVien* a);
	friend void SapXep(SinhVien* *a);
};

void SinhVien::Nhap()
{
	cout << "Ho va ten: "; 
	cin.ignore(); getline(cin, dl.ten);
	cout << "Lop: "; cin >> dl.lop;
	cout << "Ma sinh vien: "; cin >> dl.msv;
	cout << "Diem trung binh: "; cin >> dl.diem;
}
 
void In(SinhVien* a)
{
	cout << "-----------------------------------------------" << endl;
	while (a != NULL)
	{
		cout << "|" << setw(5) << a->dl.msv << "|" << setw(23) << a->dl.ten << "|" << setw(5) << a->dl.lop << "|" << setw(9) << a->dl.diem << "|" << endl;
		cout << "-----------------------------------------------" << endl;
		a = a->next;
	}
}

SinhVien* ThemSinhVien(SinhVien* *a)
{
	SinhVien* sv = new SinhVien;
	sv->Nhap();
	sv->next = NULL;
	if (*a == NULL)
	{
		*a = sv;
	}
	else
	{
		SinhVien* p = *a;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = sv;
	}
	return sv;
}

void SapXep(SinhVien* *a)
{
	for (SinhVien* p = *a; p->next != NULL; p = p->next)
	{	
		for (SinhVien* p1 = p->next; p1 != NULL; p1 = p1->next)
		{
			if (p->dl.diem < p1->dl.diem)
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
	SinhVien* head = NULL;
	while (1) 
	{
		cout << "-------------------------MENU------------------------" << endl;
		cout << "|1. Nhap thong tin cho sinh vien!                    |" << endl;
		cout << "|2. Sap xep thong tin sinh vien theo diem trung binh!|" << endl;
		cout << "|3. In thong tin sinh vien!                          |" << endl;
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
			ThemSinhVien(&head);
		}
		if (lc == 3)
		{
			cout << "-----------------------------------------------" << endl;
			cout << "| MSV |       HO VA TEN       | LOP | DIEM TB |" << endl;
			In(head);
		}
		if (lc == 2)
		{
			SapXep(&head);
		}
	}
	for (SinhVien* i = head; i != NULL; i = i->next)
	{
		delete i;
	}
}