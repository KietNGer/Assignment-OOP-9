#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

class Babilon
{
protected:
    string Name;
    int mass;
    int flex;
    int power;
    int ecarry;
    double consumption;
public:
    Babilon();
    ~Babilon();
    virtual void Nhap();
    virtual void Xuat();
    virtual void LinhHoat();
    virtual void SucManh();
    virtual void VanChuyen();
    virtual void TieuThu(int s);
    virtual int XuatNLTieuTHu();
};

Babilon ::Babilon()
{
    Name = "";
    mass = 0;
}

Babilon ::~Babilon()
{
    Name = "";
    mass = 0;
}

void Babilon ::Nhap()
{
    cout << "Chua co\n";
}

void Babilon ::Xuat()
{
    cout << "chua co\n";
}

void Babilon ::LinhHoat()
{
    cout << "chua co\n";
}

void Babilon ::SucManh()
{
    cout << "chua co\n";
}

void Babilon ::VanChuyen()
{
    cout << "chua co\n";
}

void Babilon ::TieuThu(int s)
{
    cout << "chua co\n";
}

int Babilon ::XuatNLTieuTHu()
{
    return this->consumption;
}

class Pedion :public Babilon
{
protected:
    int LH;
public:
    Pedion();
    ~Pedion();
    void Nhap();
    void Xuat();
    void LinhHoat();
    void TieuThu(int s);
    int XuatNLTieuTHu();
};

Pedion ::Pedion()
{
    LH = 0;
}

Pedion ::~Pedion()
{
    LH = 0;
}

void Pedion ::Nhap()
{
    cout << "Ten Robot: Pedion\n";
    cout << "Khoi luong robot: 20\n";
    do
    {
        cout << "Nhap do linh hoat: ";
        cin >> LH;
    }while(LH > 5 || LH < 1);
}

void Pedion ::LinhHoat()
{
    Name = "Pedion";
    mass = 20;
    flex = LH;
}

void Pedion ::TieuThu(int s)
{
    consumption = mass * s + (((flex+1) * s) / 2);
}

void Pedion ::Xuat()
{
    cout << "+Ten Robot: " << Name << endl;
    cout << "+Khoi luong cua robot: " << mass << endl;
    cout << "+Do linh hoat: " << flex << endl;
    cout << "+Nang luong tieu thu: " << consumption << endl;
}

int Pedion ::XuatNLTieuTHu()
{
    return this->consumption;
}

class Zattacker :public Babilon
{
protected:
    int SM;
public:
    Zattacker();
    ~Zattacker();
    void Nhap();
    void Xuat();
    void SucManh();
    void TieuThu(int s);
    int XuatNLTieuTHu();
};

Zattacker ::Zattacker()
{
    SM = 0;
}

Zattacker ::~Zattacker()
{
    SM = 0;
}

void Zattacker ::Nhap()
{
    cout << "Ten Robot: Zattacker\n";
    cout << "Khoi luong robot: 50\n";
    do
    {
        cout << "Nhap suc manh cua Robot: ";
        cin >> SM;
    }while(SM > 30 || SM < 20);
}

void Zattacker ::SucManh()
{
    Name = "Zattacker";
    mass = 50;
    power = SM;
}

void Zattacker ::TieuThu(int s)
{
    consumption = mass * s + power * power * s;
}

void Zattacker ::Xuat()
{
    cout << "+Ten Robot: " << Name << endl;
    cout << "+Khoi luong cua robot: " << mass << endl;
    cout << "+Suc manh cua Robot: " << power << endl;
    cout << "+Nang luong tieu thu: " << consumption << endl;
}

int Zattacker ::XuatNLTieuTHu()
{
    return this->consumption;
}

class Carrier :public Babilon
{
protected:
    int vc;
public:
    Carrier();
    ~Carrier();
    void Nhap();
    void VanChuyen();
    void Xuat();
    void TieuThu(int s);
    int XuatNLTieuTHu();
};

Carrier ::Carrier()
{
    vc = 0;
}

Carrier ::~Carrier()
{
    vc = 0;
}

void Carrier ::Nhap()
{
    cout << "Ten Robot: Carrier\n";
    cout << "Khoi luong robot: 30\n";
    do
    {
        cout << "Nhap khoi luong robot co the van chuyen: ";
        cin >> vc;
    }while(vc > 100 || vc < 50);
}

void Carrier ::VanChuyen()
{
    Name = "Carrier";
    mass = 50;
    ecarry = vc;
}

void Carrier ::TieuThu(int s)
{
    consumption = mass * s + 4 * ecarry * s;
}

void Carrier ::Xuat()
{
    cout << "+Ten Robot: " << Name << endl;
    cout << "+Khoi luong cua robot: " << mass << endl;
    cout << "+Khoi luong hang robot van chuyen duoc: " << ecarry << endl;
    cout << "+Nang luong tieu thu: " << consumption << endl;
}

int Carrier ::XuatNLTieuTHu()
{
    return this->consumption;
}

int main()
{
    cout << "Nhap so luong robot: ";
    int SoLuong;
    cin >> SoLuong;
    vector<Babilon*> b;
    while(SoLuong--)
    {
        Babilon *x = NULL;
        cout << "\t1. Nhap 1 de nhap thong tin robot Pedion\n";
        cout << "\t2. Nhap 2 de nhap thong tin robot Zattacker\n";
        cout << "\t3. Nhap 3 de nhap thong tin robot Carrier\n";

        int choice;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                x = new Pedion;
                x->Nhap();
                x->LinhHoat();
                x->TieuThu(10);
                b.push_back(x);
                break;
            }
        case 2:
            {
                x = new Zattacker;
                x->Nhap();
                x->SucManh();
                x->TieuThu(10);
                b.push_back(x);
                break;
            }
        case 3:
            {
                x = new Carrier;
                x->Nhap();
                x->VanChuyen();
                x->TieuThu(10);
                b.push_back(x);
                break;
            }
        }
    }

    cout << "\n===Danh sach Robot===\n";
    for(int i = 0; i < b.size(); i++)
    {
        b[i]->Xuat();
    }

    int max = 0;
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i]->XuatNLTieuTHu() > b[max]->XuatNLTieuTHu())
            max = i;
    }
    cout << "\nRo bot tieu thu nhieu nang luong nhat: \n";
    b[max]->Xuat();

    long sum = 0;
    for(int i = 0; i < b.size(); i++)
    {
        sum += b[i]->XuatNLTieuTHu();
    }
    cout << "\nTong nang luong da tieu thu cua ca doan Robot: " << sum << endl;
    return 0;
}
