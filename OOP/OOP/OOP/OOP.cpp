#include <iostream>
#include <string>

/*1. Tinh dong goi (encapsulation): class phai duoc an toan bo du lieu,
	Cac thuoc tinh khong duoc truy xuat tu ben ngoai class
*/

/*2. Tinh truu tuong (abstraction): co che sua doi du lieu, kiem soat thay doi du lieu,
moi thuoc tinh du lieu cua class duoc xu ly o ben trong method*/

/*3. Tinh ke thua (inheritance): nhiu class co dac diem chung, gom lai thanh class Base,
cac class ke thua cac thuoc tinh method class Base*/

/*4. Tinh da hinh (Polymorphism): nhiu hinh thai, cung 1 method o lop co so 
co nhiu hinh thai o lop dan xuat*/

class Phu_nu {
	/*Access Modifiers*/
public:
	Phu_nu() {}

	Phu_nu(const std::string& ht, int t, const std::string &dc, bool z = true) : ho_ten(ht), tuoi(t), dia_chi(dc), con_zin(z) {}

	~Phu_nu() {
		std::cout << "Chia tay " << ho_ten << " " << std::endl;
	}

	void trang_diem() {

	}

	std::string choi_nhac_cu(std::string nhac_cu) {
		return "AAAAA";
	}

	void va_zin() {
		if (tuoi < 25) {
			con_zin = true;
		}
	}

	void show_hang() {
		std::cout << ho_ten << " " << (con_zin ? "con zin" : "mat zin") << std::endl;
	}

private:
	std::string ho_ten;
	bool con_zin;
	int tuoi;

protected:
	std::string dia_chi;
};

class Gai_Ngoan : public Phu_nu {	/*Inheritance*/
	/*Ke thua kieu private toan bo method, properties Gai_Ngoan ke thua duoc deu o private het*/
	public:
		/* Gai_Ngoai: lop dan xuat (Derived class)
		*  Phu_nu: lop co so (Base class)
		*/
		Gai_Ngoan(const std::string &ht, int t, const std::string &dc, bool z = true): Phu_nu(ht, t, dc, z) {

		}

		std::string choi_nhac_cu(std::string nhac_cu) {
			return "000000";
		}

		void noi_tro() {
			std::cout << dia_chi << " " << std::endl;
		}

};

class Gai_Hu : public Phu_nu {
public:
	Gai_Hu(const std::string& ht, int t, const std::string &dc, bool z = true) : Phu_nu(ht, t, dc, z) {

	}

	std::string choi_nhac_cu(std::string nhac_cu) {
		return "UUUUUUUh";
	}

	void di_bar() {}

};

/*Dimond Inheritance: xung dot khi su dung da ke thua*/
class Banh_Beo :public Gai_Ngoan, public Gai_Hu {

};

/*Multilevel Inheritance*/
class Gai_Di_Tour : public Gai_Hu {
	 
};

class Dan_ong {};

int main() {
	/* Cap phat tinh */
	//Phu_nu thao;

	/* Cap phat dong */
	Phu_nu* yua_mikami = new Gai_Hu("Yua Mikami", 23, "2B Nguyen Van B", false);
	std::cout << yua_mikami->choi_nhac_cu("ken") << std::endl;

	Gai_Ngoan * maria_ozawa = new Gai_Ngoan("Maria Ozawa", 22, "1A Nguyen Van A", false);
	maria_ozawa->choi_nhac_cu("Ken");
	maria_ozawa->va_zin();
	maria_ozawa->show_hang();

	std::cout << maria_ozawa->choi_nhac_cu("ken") << std::endl;

	delete maria_ozawa;	/*Huy object*/

	Dan_ong* marc = new Dan_ong;

	return 0;
}