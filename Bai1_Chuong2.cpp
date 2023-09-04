#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Time
{
	int h, p, s;
public:
	Time()
	{
		h = p = s = 0;
	}
	void Nhap()
	{
		cout << "Nhap du lieu cho chuong trinh:\n";
		cout << endl;
		cout << "Gio: "; cin >> this->h;
		cout << "Phut: "; cin >> this->p;
		cout << "Giay: "; cin >> this->s;
	}
	void advance(int n, string a)
	{
		if (a == "h")
		{
			this->h += n;
		}
		if (a == "p")
		{
			this->p += n;
		}
		if (a == "s")
		{
			this->s += n;
		}
	}
	void normalize()//hàm này chưa đúng yêu cầu đề bài.
	{
		if (h >= 24 || p >= 60 || s >= 60)
		{
			while (p > 60)
			{
				p -= 60;
				h++;
			}
			while (s > 60)
			{
				s -= 60;
				p++;
				if (p > 60)
				{
					p -= 60;
					h++;
				}
			}
		}
	}
	void truyxuat(string a)
	{
		if (a == "h")
		{
			cout << this->h;
		}
		if (a == "p")
		{
			cout << this->p;
		}
		if (a == "s")
		{
			cout << this->s;
		}
	}
	void print()
	{
		string x = to_string(h);
		string y = to_string(p);
		string z = to_string(s);

		if (this->h < 10)
		{
			string ht = "0" + x;
			cout << ht << ":";
		}
		if (this->h >= 10)
		{
			cout << this->h << ":";
		}
		if (this->p < 10)
		{
			string pt = "0" + y;
			cout << pt << ":";
		}
		if (this->p >= 10)
		{
			cout << this->p << ":";
		}
		if (this->s < 10)
		{
			string st = "0" + z;
			cout << st << endl;
		}
		if (this->s >= 10)
		{
			cout << this->s << endl;
		}
	}
	void reset()
	{

	}
};

int main()
{
	Time t;
	t.Nhap();
	while (1)
	{
		cout << endl << "-------------MENU-------------";
		cout << endl << "|1. Truy xuat toi gio.       |";
		cout << endl << "|2. Truy xuat toi phut.      |";
		cout << endl << "|3. Truy xuat toi giay.      |";
		cout << endl << "|4. Tang gio len n don vi.   |";
		cout << endl << "|5. Tang phut len n don vi.  |";
		cout << endl << "|6. Tang giay len n don vi.  |";
		cout << endl << "|7. Reset.                   |";
		cout << endl << "|8. Hien thi du lieu.        |";
		cout << endl << "|9. Thoat.                   |";
		cout << endl << "------------------------------";
		cout << endl;
		int lc;
		cout << endl << "Lua chon cua ban: "; cin >> lc;
		if (lc == 1)
		{
			t.normalize();
			string a = "h";
			t.truyxuat(a);
		}
		if (lc == 2)
		{
			t.normalize();
			string a = "p";
			t.truyxuat(a);
		}
		if (lc == 3)
		{
			t.normalize();
			string a = "s";
			t.truyxuat(a);
		}
		if (lc == 4)
		{
			int n; string a = "h";
			cout << endl << "Tang len bao nhieu don vi: ";
			cin >> n;
			t.advance(n, a);
		}
		if (lc == 5)
		{
			int n; string a = "p";
			cout << endl << "Tang len bao nhieu don vi: ";
			cin >> n;
			t.advance(n, a);
		}
		if (lc == 6)
		{
			int n; string a = "s";
			cout << endl << "Tang len bao nhieu don vi: ";
			cin >> n;
			t.advance(n, a);
		}
		if (lc == 7)
		{

		}
		if (lc == 8)
		{
			t.normalize();
			t.print();
		}
		if (lc == 9)
		{
			break;
		}
	}
	return 0;
}