#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

class SinhVien
{
protected:
    int MSSV;
    string HoTen;
    string DiaChi;
    int SoTC;
    double DiemTB;
    double TN;
    string LV;
    double DLV;
public:
    SinhVien();
    ~SinhVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual void NhapDiemTHiTN();
    virtual void NhapLV();
    friend class QuanLy;
};

SinhVien ::SinhVien()
{
    MSSV = 0;
    HoTen = "";
    DiaChi = "";
    SoTC = 0;
    DiemTB = 0;
}

SinhVien ::~SinhVien()
{
    MSSV = 0;
    HoTen = "";
    DiaChi = "";
    SoTC = 0;
    DiemTB = 0;
}

void SinhVien ::Nhap()
{
    cout << "Nhap ma so sinh vien: ";
    cin >> MSSV;
    cout << "Nhap ho va ten sinh vien: ";
    cin.ignore();
    getline(cin, HoTen);
    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);
    cout << "Nhap so tin chi hien tai cua sinh vien: ";
    cin >> SoTC;
    cout << "Nhap diem trung binh cua sinh vien: ";
    cin >> DiemTB;
}

void SinhVien ::Xuat()
{
    cout << "+Ma so sinh vien: " << MSSV << endl;
    cout << "+Ho va ten sinh vien: " << HoTen << endl;
    cout << "+Dia chi: " << DiaChi << endl;
    cout << "+So tin chi hien tai cua sinh vien: " << SoTC << endl;
    cout << "+So diem trung binh cua sinh vien: " << DiemTB << endl;
}

void SinhVien ::NhapDiemTHiTN()
{
    cout << "chua co\n";
}

void SinhVien ::NhapLV()
{
    cout << "chua co\n";
}

class CaoDang :public SinhVien
{
protected:
    double DiemThiTN;
public:
    CaoDang();
    ~CaoDang();
    void Nhap();
    void Xuat();
    void NhapDiemTHiTN();
};

CaoDang ::CaoDang()
{
    DiemThiTN = 0;
}

CaoDang ::~CaoDang()
{
    DiemThiTN = 0;
}

void CaoDang ::Nhap()
{
    SinhVien ::Nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> DiemThiTN;
}

void CaoDang ::NhapDiemTHiTN()
{
    TN = DiemThiTN;
}

void CaoDang ::Xuat()
{
    SinhVien ::Xuat();
    cout << "+Diem thi tot nghiep cua sinh vien: " << TN << endl;
}

class DaiHoc :public SinhVien
{
protected:
    string LuanVan;
    double DiemLV;
public:
    DaiHoc();
    ~DaiHoc();
    void Nhap();
    void Xuat();
    void NhapLV();
};

DaiHoc ::DaiHoc()
{
    LuanVan = "";
    DiemLV = 0;
}

DaiHoc ::~DaiHoc()
{
    LuanVan = "";
    DiemLV = 0;
}

void DaiHoc ::Nhap()
{
    SinhVien ::Nhap();
    cout << "Nhap ten luan van: ";
    cin.ignore();
    getline(cin, LuanVan);
    cout << "Nhap diem luan van: ";
    cin >> DiemLV;
}

void DaiHoc ::NhapLV()
{
    LV = LuanVan;
    DLV = DiemLV;
}

void DaiHoc ::Xuat()
{
    SinhVien ::Xuat();
    cout << "+Ten luan van: " << LV << endl;
    cout << "+Diem luan van: " << DLV << endl;
}

class QuanLy
{
protected:
    vector<SinhVien *> sv;
    int SoLuong;
public:
    QuanLy();
    ~QuanLy();
    void TienHanh();
};

QuanLy ::QuanLy()
{
    SoLuong = 0;
}

QuanLy ::~QuanLy()
{
    SoLuong = 0;
}

enum LoaiSV
{
    CD, DH
};
LoaiSV type;

istream& operator>> (istream& in, LoaiSV& x)
{
    int val;

    if(in >> val)
    {
        switch(val)
        {
        case CD: case DH:
            x = LoaiSV(val);
            break;
        default:
            throw out_of_range("Invalid value");
        }
    }

    return in;
}

void QuanLy ::TienHanh()
{
    cout << "Nhap so luong sinh vien: ";
    cin >> SoLuong;
    vector<SinhVien *> c;
    vector<SinhVien *> b;
    while(SoLuong != 0)
    {
        SinhVien *x = NULL;
        try
        {
            cout << "Nhap loai sinh vien (0 de nhap sinh vien cao dang, 1 de nhap sinh vien dai hoc:) ";
            cin >> type;
        }
        catch(out_of_range& ex)
        {
            cerr << ex.what() << endl;
        }
        if(type == CD)
        {
            x = new CaoDang;
            x->Nhap();
            x->NhapDiemTHiTN();
            sv.push_back(x);
            c.push_back(x);
        }
        if(type == DH)
        {
            x = new DaiHoc;
            x->Nhap();
            x->NhapLV();
            sv.push_back(x);
            b.push_back(x);
        }
        SoLuong--;
    }

    /*for(int i = 0; i < sv.size(); i++)
    {
        sv[i]->Xuat();
    }*/

    int dem = 0;
    for(int i = 0; i < sv.size(); i++)
    {
        if(sv[i]->SoTC >= 120 && sv[i]->DiemTB >= 5 && sv[i]->TN >= 5 || sv[i]->SoTC >= 170 && sv[i]->DiemTB >= 5 && sv[i]->DLV >= 5)
            dem++;
    }
    cout << "\nSo luong sinh vien du dieu kien tot nghiep: " << dem << endl;

    int cd = 0;
    int dh = 0;
    for(int i = 0; i < c.size(); i++)
    {
        if(c[i]->DiemTB > c[cd]->DiemTB)
           cd = i;
    }
    cout << "\nSinh vien cao dang co diem cao nhat: \n";
    c[cd]->Xuat();

    for(int i = 0; i < b.size(); i++)
    {
        if(b[i]->DiemTB > b[dh]->DiemTB)
            dh = i;
    }
    cout << "\nSinh vien dai hoc co diem cao nhat: \n";
    b[dh]->Xuat();
}

int main()
{
    QuanLy a;
    a.TienHanh();
    return 0;
}
