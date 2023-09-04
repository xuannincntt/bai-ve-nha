#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class SinhVien
{
	string ten, namsinh;
	double diem1, diem2, diem3, diem4, diem5, diem6, diem7, diem8, diem9;
public:
	void Nhap();
	double Dtb();
	void Print(SinhVien x);
};

void SinhVien::Nhap()
{
	cout << "Ho va ten: "; cin.ignore(1); getline(cin, ten);
	cout << "Nam sinh: "; cin >> namsinh;
	cout << "Diem mon 1: "; cin >> diem1;
	cout << "Diem mon 2: "; cin >> diem2;
	cout << "Diem mon 3: "; cin >> diem3;
	cout << "Diem mon 4: "; cin >> diem4;
	cout << "Diem mon 5: "; cin >> diem5;
	cout << "Diem mon 6: "; cin >> diem6;
	cout << "Diem mon 7: "; cin >> diem7;
	cout << "Diem mon 8: "; cin >> diem8;
	cout << "Diem mon 9: "; cin >> diem9;
}

double SinhVien::Dtb()
{
	double dtb = (diem1 + diem2 + diem3 + diem4 + diem5 + diem6 + diem7 + diem8 + diem9) / 9;
	return dtb;
}

void SinhVien::Print(SinhVien x)
{
	if (x.Dtb() >= 7 && diem1 >= 5 && diem2 >= 5 && diem3 >= 5 && diem4 >= 5 && diem5 >= 5 && diem6 >= 5 && diem7 >= 5 && diem8 >= 5 && diem9 >= 5)
	{
		cout << endl << "Sinh vien " << x.ten << " sinh nam " << x.namsinh;
		cout << endl << "Sinh vien du dieu kien lam khoa luan.";
	}
	else if (x.Dtb() < 7 && diem1 >= 5 && diem2 >= 5 && diem3 >= 5 && diem4 >= 5 && diem5 >= 5 && diem6 >= 5 && diem7 >= 5 && diem8 >= 5 && diem9 >= 5)
	{
		cout << endl << "Sinh vien " << x.ten << " sinh nam " << x.namsinh;
		cout << endl << "Sinh vien thi tot nghiep.";
	}
	else
	{
		cout << endl << "Sinh vien " << x.ten << " sinh nam " << x.namsinh;
		cout << endl << "Sinh vien thi lai.";
	}
}

int main()
{
	int n;
	cout << "Nhap so sinh vien xet dieu kien: "; cin >> n;
	SinhVien* sv = new SinhVien[n];
	for (int i = 0; i < n; i++)
	{
		sv[i].Nhap();
		sv[i].Print(sv[i]);
	}
	delete[]sv;
	return 0;
}