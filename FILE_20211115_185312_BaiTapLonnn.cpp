#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//LOP DIEM
class Diem
{
  protected:
	float dtb;
	float Dvan;
	float Dtoan;
	float Dly;
	float Dhoa;

  public:
	virtual void Nhap();
	virtual void Xuat();
	void TinhDTB();
	float getDTB()
	{
		return dtb;
	}
};
//LOP NGAY THANG NAM
class Date : public Diem
{
  private:
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;

  public:
	void Nhap();
	void Xuat();
};
//LOP HOC SINH
class HocSinh : public Date
{
  private:
	string hoten;
	string mssv;
	string lop;
	string diachi;
	string gioitinh;

  public:
	void Nhap();
	void Xuat();
	void XepLoai();
	string getMS()
	{
		return this->mssv;
	}
	string getTen()
	{
		return this->hoten;
	}
};
//LOP DANH SACH
class DanhSach
{
  private:
	vector<HocSinh *> HS;

  public:
	void NhapDS();
	void XuatDS();
	int XoaID();
	void CapNhat();
	void SapXepMaSo();
	void TimTen();
	void TimMaSo();
};
//Nhap ten

//Nhap diem
void Diem::Nhap()
{
	cout << "\nNhap diem van : ";
	cin >> Dvan;
	cout << "\nNhap diem toan : ";
	cin >> Dtoan;
	cout << "\nNhap diem ly : ";
	cin >> Dly;
	cout << "\nNhap diem hoa : ";
	cin >> Dhoa;
}
//Xuat diem
void Diem::Xuat()
{
	cout << "\t" << Dvan;
	cout << "\t" << Dtoan;
	cout << "\t" << Dly;
	cout << "\t" << Dhoa;

	TinhDTB();
}
//Tinh diem trung binh
void Diem::TinhDTB()
{
	dtb = 0;
	dtb = (Dvan + Dtoan + Dly + Dhoa) / 4;
	cout << "\t" << dtb;
}
//get Diem Trung Binh

//Nhap ngay
void Date::Nhap()
{
	cout << "\nNhap ngay :";
	cin >> ngay;
	cout << "\nNhap thang :";
	cin >> thang;
	cout << "\nNhap nam: ";
	cin >> nam;
}
//Xuat ngay
void Date::Xuat()
{
	cout << "\t\t" << ngay << "/" << thang << "/" << nam;
}
//Xep loai
void HocSinh::XepLoai()
{
	if (getDTB() < 5.0)
	{
		cout << " Kem ";
	}
	else if (getDTB() >= 5.0 && getDTB() < 6.5)
	{
		cout << " Trung binh ";
	}
	else if (getDTB() >= 6.5 && getDTB() < 8.0)
	{
		cout << " Kha ";
	}
	else
		cout << " Gioi ";
}
//Nhap Thong Tin Hoc Sinh
void HocSinh::Nhap()
{
	cout << "\nNhap ho ten : ";
	fflush(stdin);
	getline(cin, hoten);
	Date::Nhap();
	cout << "\nNhap ma so sinh vien:";
	fflush(stdin);
	getline(cin, mssv);
	cout << "\nNhap lop :";
	fflush(stdin);
	getline(cin, lop);
	cout << "\nNhap dia chi:";
	fflush(stdin);
	getline(cin, diachi);
	cout << "\nNhap gioi tinh :";
	fflush(stdin);
	getline(cin, gioitinh);
	Diem::Nhap();
}
//Xuat Thong Tin Hoc Sinh
void HocSinh::Xuat()
{
	cout << "\t" << hoten;
	cout << "\t\t" << mssv;
	Date::Xuat();
	cout << "\t\t" << gioitinh;
	cout << "\t\t" << lop;
	cout << "\t" << diachi;
	Diem::Xuat();
	cout << "\t";
	XepLoai();
	cout << endl;
}
//Nhap Danh Sach
void DanhSach::NhapDS()
{
	int n;
	HocSinh *a;
	cout << "\nNhap so luong hoc sinh :";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap Hoc Sinh thu " << i + 1 << ":" << endl;
		a = new HocSinh;
		a->Nhap();
		HS.push_back(a);
		cout << endl;
	}
}
//Xuat Danh Sach
void DanhSach::XuatDS()
{
	cout << endl;
	cout << "\n\t\t\t\t\t\t\t********** Danh Sach Hoc Sinh **********";
	cout << endl;
	cout << "\n__________________________________________________________________________________________________________________________________________________________________";
	cout << "\nSTT\tHo ten\t\tMSSV\t\tNam Sinh\tGioi Tinh\tLop\tDia Chi\tToan\tLy\tHoa\tVan\tDiemTB\tHoc luc";
	for (int i = 0; i < HS.size(); i++)
	{
		cout << "\n"
			 << i + 1;
		this->HS.at(i)->Xuat();
		cout << endl;
	}
	cout << "\n__________________________________________________________________________________________________________________________________________________________________";
}

//Xoa Theo Ma So Sinh Vien
int DanhSach::XoaID()
{
	int tim = 0;
	string msv;
	cout << "\nNhap ma so sinh vien can xoa:";
	cin.ignore();
	getline(cin, msv);
	int n = HS.size();
	for (int i = 0; i < n; i++)
	{
		if (HS.at(i)->getMS() == msv)
		{
			tim = 1;
			for (int j = i; j < n - 1; j++)
			{
				HS.at(j) = HS.at(j + 1);
			}
			HS.erase(HS.begin() + n - 1);
			cout << "\nDanh Sach Sau Khi Xoa La !!!";
			XuatDS();
			break;
		}
	}
	if (tim == 0)
	{
		cout << "\nKhong tim thay ma so nay !!";
	}
}
// Cap Nhat Thong Tin Theo Ma So
void DanhSach::CapNhat()
{
	string msv;
	int tim = 0;
	cout << "\nNhap ma so sinh vien can cap nhat: ";
	cin.ignore();
	getline(cin, msv);
	for (int i = 0; i < HS.size(); i++)
	{
		tim = 1;
		if (HS.at(i)->getMS() == msv)
		{
			HS.at(i)->Nhap();
			cout << "\nDanh Sach Sau Khi Cap Nhat La !!!";
			XuatDS();
			break;
		}
	}

	if (tim == 0)
	{
		cout << "\nKhong tim thay ma so nay";
	}
}
//Ham Sap Xep Theo Ma So Tang Dan
void DanhSach::SapXepMaSo()
{
	for (int i = 0; i < HS.size() - 1; i++)
	{
		for (int j = i + 1; j < HS.size(); j++)
		{
			if (HS.at(i)->getMS() > HS.at(j)->getMS())
			{
				HocSinh *t = HS.at(i);
				HS.at(i) = HS.at(j);
				HS.at(j) = t;
			}
		}
	}
	cout << "\nDanh Sach sau khi sap xep la";
	XuatDS();
}
//Tim theo Ho Ten
void DanhSach::TimTen()
{
	string ten;
	int tim = 0;
	cout << "\nNhap Ten  can tim: ";
	cin.ignore();
	getline(cin, ten);
	for (int i = 0; i < HS.size(); i++)
	{
		tim = 1;
		if (HS.at(i)->getTen() == ten)
		{
			cout << "\nSTT\tHo ten\t\tMSSV\t\tNam Sinh\tGioi Tinh\tLop\tDia Chi\tToan\tLy\tHoa\tVan\tDiemTB\tHoc luc";
			cout << "\n"
				 << i + 1;
			HS.at(i)->Xuat();
		}
		else if (tim == 0)
		{
			cout << "\nTen khong ton tai !!!";
		}
	}
}
//Tim theo Ma So
void DanhSach::TimMaSo()
{
	string msv;
	int tim = 0;
	cout << "\nNhap ma so hoc sinh  can tim: ";
	cin.ignore();
	getline(cin, msv);
	for (int i = 0; i < HS.size(); i++)
	{
		tim = 1;
		if (HS.at(i)->getMS() == msv)
		{
			cout << "\nSTT\tHo ten\t\tMSSV\t\tNam Sinh\tGioi Tinh\tLop\tDia Chi\tToan\tLy\tHoa\tVan\tDiemTB\tHoc luc";
			cout << "\n"
				 << i + 1;
			HS.at(i)->Xuat();
		}
		else if (tim == 0)
		{
			cout << "\nMa So khong ton tai !!!";
		}
	}
}
//Ham Main
int main()
{
	DanhSach ds;
	ds.NhapDS();
	ds.XuatDS();
	ds.CapNhat();
	ds.XoaID();
	ds.SapXepMaSo();
	ds.TimTen();
	ds.TimMaSo();
}
