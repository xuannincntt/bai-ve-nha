#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Data
{
	int ngay, thang, nam;
public:
	Data()
	{
		ngay = thang = nam = 0;
	}	
	Data(int ngay, int thang, int nam)
	{
		this->ngay = ngay;
		this->thang = thang;
		this->nam = nam;
	}
	int Getthang()
	{
		return thang;
	}
	void Nhap();
	void Normalize(Data x);
	int Dayinmonth(int x);
	void Advance(int lc, int n, Data x);
	int Tinhtoan(Data d1, Data d2);
	void Reset();
	void Print();
};

void Data::Nhap()
{
	cout << "Nhap du lieu cho chuong trinh:\n";
	cout << "Ngay: "; cin >> this->ngay;
	cout << "Thang: "; cin >> this->thang;
	cout << "Nam: "; cin >> this->nam;
}

int Data::Dayinmonth(int x)
{
	switch (x)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31; break;
	case 4: case 6: case 9: case 11:
		return 30; break;
	case 2:
		if (nam % 4 == 0)
		{
			return 29; break;
		}
		else
		{
			return 28; break;
		}
	default:
		return 0; break;
	}
}

void Data::Normalize(Data x)
{
	if (ngay < 1 || thang < 1 || nam < 1 || ngay > x.Dayinmonth(thang) || thang > 12)
	{
		while (thang > 12)
		{
			thang -= 12;
			nam ++;
		}
		while (ngay > x.Dayinmonth(thang))
		{
			ngay -= x.Dayinmonth(thang);
			thang++;
			if (thang > 12)
			{
				thang -= 12;
				nam++;
			}
		}
	}
}

void Data::Print()
{
	cout << endl << ngay << "/" << thang << "/" << nam;
}

void Data::Advance(int lc, int n, Data x)// hàm đang bị lỗi.
{
	if (lc == 4)
	{
		this->ngay += n;
		x.Normalize(x);// tại sao hàm này không chạy.
	}
	if (lc == 5)
	{
		this->thang += n;
		x.Normalize(x);
	}
	if (lc == 6)
	{
		this->nam += n;
	}
}

int Data::Tinhtoan(Data d1, Data d2)
{
	int songay = 0;
	int y = d1.nam + 1;
	int m = d1.thang + 1;
	if (d1.nam != d2.nam)
	{
		for (int i = y; i <= d2.nam; d1.nam++)
		{
			if (y % 4 == 0)
			{
				songay += 366;
			}
			else
			{
				songay += 365;
			}
		}
		
		for (int i = 1; i < d2.thang; i++)
		{
			songay += d2.Dayinmonth(i);
		}
		for (int i = 12; i > d1.thang; i--)
		{
			songay += d1.Dayinmonth(i);
		}
		songay += d2.ngay + d1.Dayinmonth(d1.thang) - d1.ngay;
	}
	else
	{
		for (int i = m; i < d2.thang; i++)
		{
			songay += d1.Dayinmonth(i);
		}
		songay += d2.ngay + d1.Dayinmonth(d1.thang) - d1.ngay;
	}
	return songay;
}

int main()
{
	Data d1;
	Data d2;
	while (1)
	{
		cout << endl << "-------------MENU-------------";
		cout << endl << "|1. Nhap du lieu.            |";
		cout << endl << "|2. Normaliz.                |";
		cout << endl << "|3. Ngay trong thang.        |";
		cout << endl << "|4. Tang ngay len n don vi.  |";
		cout << endl << "|5. Tang thang len n don vi. |";
		cout << endl << "|6. Tang nam len n don vi.   |";
		cout << endl << "|7. Reset.                   |";
		cout << endl << "|8. Hien thi du lieu.        |";
		cout << endl << "|9. Tinh toan.               |";
		cout << endl << "|10. Thoat.                  |";
		cout << endl << "------------------------------";
		int lc;
		cout << endl << "Lua chon cua ban: "; cin >> lc;
		if (lc == 1)
		{
			d1.Nhap();
		}
		if (lc == 2)
		{
			d1.Normalize(d1);
		}
		if (lc == 3)
		{
			cout << endl << "Thang " << d1.Getthang() << " co " << d1.Dayinmonth(d1.Getthang()) << " ngay.";
		}
		if (lc == 4)
		{
			int n; cout << "So ngay muon tang len: "; cin >> n;
			d1.Advance(lc, n, d1);
		}
		if (lc == 5)
		{
			int n; cout << "So thang muon tang len: "; cin >> n;
			d1.Advance(lc, n, d1);
		}
		if (lc == 6)
		{
			int n; cout << "So nam muon tang len: "; cin >> n;
			d1.Advance(lc, n, d1);
		}
		if (lc == 8)
		{
			d1.Print();
		}
		if (lc == 9)
		{
			Data d2;
			d2.Nhap();
			cout << endl << "So ngay giua 2 moc thoi gian d1 den d2: " << d1.Tinhtoan(d1, d2);
		}
		if (lc == 10)
		{
			break;
		}
	}
	return 0;
}