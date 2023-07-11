// Nguyen Van Duy 20215334

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// kieu du lieu NhanVien
struct NhanVien
{
    string maNV;
    string hoTen;
    int namSinh;
    double heSoLuong;
    string chucDanh;

    // luong = hsLuong * LuongTT
    int luong(int luongTT)
    {
        return round(heSoLuong * luongTT);
    }

    // PCCV dua vao Chuc danh
    int PCCV()
    {
        if (chucDanh == "GVCC")
            return 2000;
        else if (chucDanh == "GVC")
            return 1500;
        else if (chucDanh == "GV")
            return 1000;
        else if (chucDanh == "CBKT")
            return 750;
        else if (chucDanh == "CBHC")
            return 500;
        else
            return 0;
    }

    // tong luong = Luong + PCCV
    int tongLuong(int luongTT)
    {
        return luong(luongTT) + PCCV();
    }

    // cong doan phu = 1% TongLuong
    double CPD(int luongTT)
    {
        return tongLuong(luongTT) / 100.0;
    }

    // luong cuoi cung nhan duoc
    double conNhan(int luongTT)
    {
        return luong(luongTT) - CPD(luongTT);
    }

    // nhap du lieu cho kieu du lieu NhanVien
    friend istream &operator>>(istream &is, NhanVien &nhanVien)
    {
        cout << "\t\t\t\t"
             << "MaNV:";
        is >> nhanVien.maNV; // maNV
        is.ignore();
        cout << "\t\t\t\t"
             << "Ho ten Nhan vien:";
        getline(is, nhanVien.hoTen); // hoTen
        cout << "\t\t\t\t"
             << "Nhap nam sinh:";
        is >> nhanVien.namSinh; // nhap nam sinh
        cout << "\t\t\t\t"
             << "Nhap HS Luong:";
        is >> nhanVien.heSoLuong; // he so Luong
        cout << "\t\t\t\t"
             << "Nhap chuc danh:";
        is >> nhanVien.chucDanh; // chuc danh

        return is; // return istream
    }
};

// kieu du lieu phong ban
struct PhongBan
{
    string ten;
    string diaChi;
    int soLuongNV;
    int luongTT;
    vector<NhanVien> list_nhanVien; // ds nhan vien

    // nhap du lieu cho kieu du lieu PhongBan
    friend istream &operator>>(istream &is, PhongBan &phongBan)
    {
        cout << "\t\t"
             << "Ten Phong Ban:";
        is >> phongBan.ten; // ten phong ban
        cout << "\t\t"
             << "Dia chi:";
        is >> phongBan.diaChi; // dia chi
        cout << "\t\t"
             << "Luong toi thieu:";
        is >> phongBan.luongTT; // luong toi thieu
        cout << "\t\t"
             << "So nhan vien:";
        is >> phongBan.soLuongNV; // so luong nhan vien

        phongBan.list_nhanVien.clear();                    // xoa du lieu cu
        phongBan.list_nhanVien.resize(phongBan.soLuongNV); // chinh lai kich thuoc ds Nhan vien
        cout << "\t\t"
             << "Nhap ds Nhan vien:" << endl;
        for (int i = 0; i < phongBan.soLuongNV; ++i)
        {
            cout << "\t\t"
                 << "Nhan vien thu " << i + 1 << endl;
            is >> phongBan.list_nhanVien[i]; // nhap du lieu cho tung nhan vien
        }

        return is; // return istream
    }
};

vector<PhongBan> phongBanList; // danh sanh phong ban

// nhap du lieu cac phong ban
inline void input()
{
    cout << " Nguyen Van Duy - 20215334 - 2022.2 - IT3040 - 727638" << endl
         << endl;
    phongBanList.clear();
    int soPhongBan;
    cout << "Nhap so phong ban: ";
    cin >> soPhongBan;
    phongBanList.resize(soPhongBan);
    for (int i = 0; i < soPhongBan; i++)
    {
        cout << "Nhap thong tin phong ban thu " << i + 1 << " : " << endl;
        cin >> phongBanList[i];
    }
}

// in thong tin nhan vien tung phong ban, co tong luong, tong CDP, ...
inline void output()
{
    cout << " Nguyen Van Duy - 20215334 - 2022.2 - IT3040 - 727638" << endl
         << endl;
    cout << "Ban da chon xuat DS phong ban" << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    for (auto phongBan : phongBanList)
    {
        int tongLuongPhongBan = 0;
        double tongCDP = 0;

        cout << "\t\t"
             << "Ten phong ban: " << phongBan.ten << endl;
        cout << "\t\t"
             << "Dia chi: " << phongBan.diaChi << endl;
        cout << "\t\t"
             << "Luong TT: " << phongBan.luongTT << endl
             << endl;

        cout << "\t\t"
             << "Bang luong nhan vien:" << endl;
        cout << "\t\t"
             << "MaNV"
             << "\t"
             << "HotenNV"
             << "\t\t"
             << "Chuc danh"
             << "\t"
             << "PCCV"
             << "\t"
             << "HesoL"
             << "\t"
             << "Luong"
             << "\t"
             << "CDP"
             << "\t"
             << "Con nhan" << endl;
        for (auto nV : phongBan.list_nhanVien)
        {
            cout << "\t\t" << nV.maNV << "\t" << nV.hoTen << "\t\t" << nV.chucDanh << "\t\t" << nV.PCCV() << "\t" << nV.heSoLuong << "\t" << nV.tongLuong(phongBan.luongTT) << "\t" << nV.CPD(phongBan.luongTT) << "\t" << nV.conNhan(phongBan.luongTT) << endl;
            tongLuongPhongBan += nV.tongLuong(phongBan.luongTT);
            tongCDP += nV.CPD(phongBan.luongTT);
        }

        cout << endl;
        cout << "\t\t"
             << "Tong luong PB: " << tongLuongPhongBan << endl;
        cout << "\t\t"
             << "Tong CP Phi: " << tongCDP << endl;

        cout << "_________________________________________________________________________________________________" << endl;
    }
}

int main()
{
    int selection;
    do
    {
        cout << endl;
        cout << " Nguyen Van Duy - 20215334 - 2022.2 - IT3040 - 727638" << endl;
        cout << "**  CHUONG TRINH QUAN LY Phong Ban - Nhan Vien   **" << endl;
        cout << "** 1. Nhap cac phong ban                         **" << endl;
        cout << "** 1. In ket qua ds Phong ban va Nhan vien       **" << endl;
        cout << "** 0. Thoat                                      **" << endl;
        cout << "***************************************************" << endl;
        cout << "**              Nhap lua chon cua ban            **" << endl;
        cout << endl;
        cin >> selection;
        if (selection == 1)
            input(); // lua chon 1
        if (selection == 2)
            output();         // lua chon 2
    } while (selection != 0); // lap neu nguoi dung chua thoat

    // thoat CT
    cout << endl;
    cout << " Nguyen Van Duy - 20215334 - 2022.2 - IT3040 - 727638" << endl
         << endl;
    cout << "Ban da chon thoat chuong trinh!" << endl;
}
// Nguyen Van Duy - 20215334
