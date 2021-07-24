#include <iostream>
#include <string>

struct Con_nguoi
{
	Con_nguoi(std::string ht, int t, float v1, float cc) {
		ho_ten = ht;
		tuoi = t;
		vong_mot = v1;
		chieu_cao = cc;
		con_zin = true;
	}

	/*Copy construct implicit*/
	Con_nguoi(const Con_nguoi& nguoi_khac) {
		ho_ten = nguoi_khac.ho_ten;
		tuoi = nguoi_khac.tuoi;
		vong_mot = nguoi_khac.vong_mot;
		chieu_cao = nguoi_khac.chieu_cao;
		con_zin = nguoi_khac.con_zin;

		std::cout << "Tao ban sao cua " << nguoi_khac.ho_ten << std::endl;
		ho_ten = ho_ten + "(ban sao)";
	}

	/*virtual goi den ham cua method overide cua class ke thua*/
	virtual std::string choi_xep_hinh() {
		return "truyen thong";
	}

	int tuoi;
	float vong_mot;
	float chieu_cao;
	std::string ho_ten;
	bool con_zin;
};

struct GaiNgoan : public Con_nguoi {
	GaiNgoan(std::string ht, int t, float v1, float cc) : Con_nguoi(ht, t, v1, cc) {}

	std::string choi_xep_hinh() {
		return "Up thia";
	}
};

struct GaiHu : public Con_nguoi {
	GaiHu(std::string ht, int t, float v1, float cc) : Con_nguoi(ht, t, v1, cc) {}

	std::string choi_xep_hinh() {
		return "69";
	}
};

struct Gay : public Con_nguoi {
	Gay(std::string ht, int t, float v1, float cc) : Con_nguoi(ht, t, v1, cc) {}

	std::string choi_xep_hinh() {
		return "Dau kiem";
	}
};

void pha_zin(Con_nguoi * nguoi) {
	std::cout << "Thuc hien pha zin em " << (*nguoi).ho_ten << " theo kieu " << nguoi->choi_xep_hinh() << std::endl;
	(*nguoi).con_zin = false;
}

/*Cap phat dong (Dynamic alllocation)
*Da hinh (Polymorphism)
*/

int main() {
	Con_nguoi *hoi_cho[5] = {
		new Con_nguoi("Ba Ga", 22, 95, 1.65),
		new GaiNgoan("Hai Ca", 18, 95, 1.70),
		new GaiHu("Sau Luon", 29, 95, 1.62),
		new Con_nguoi("Nam Rau", 16, 95, 1.63),
		new Gay("Bay Mam", 30, 95, 1.65),
	};

	Con_nguoi* nguoi_mua;
	for (int i = 0; i < 5; i++) {
		nguoi_mua = hoi_cho[i];
		pha_zin(nguoi_mua);
	}

	std::cout << "================================" << std::endl;

	Con_nguoi hoi_phu_nu[5] = {
		Con_nguoi("Thao", 22, 95, 1.65),
		Con_nguoi("Lan", 18, 95, 1.70),
		Con_nguoi("Huong", 29, 95, 1.62),
		Con_nguoi("Nhung", 16, 95, 1.63),
		Con_nguoi("Tuyet", 30, 95, 1.65),
	};

	Con_nguoi* bo_nhi = nullptr;

	for (int i = 0; i < 5; i++) {
		std::cout << hoi_phu_nu[i].ho_ten << std::endl;
	}
	
	std::cout << "--------------------" << std::endl;

	for (bo_nhi = hoi_phu_nu; bo_nhi < hoi_phu_nu + 5 ; bo_nhi++) {
		std::cout << (*bo_nhi).ho_ten << std::endl;
	}

	std::cout << "Truoc khi pha, em " << hoi_phu_nu[3].ho_ten << " "
	<< (hoi_phu_nu[3].con_zin ? "con zin" : "mat zin") << std::endl;

	pha_zin(&hoi_phu_nu[3]);

	std::cout << "Sau khi pha, em " << hoi_phu_nu[3].ho_ten << " "
		<< (hoi_phu_nu[3].con_zin ? "con zin" : "mat zin") << std::endl;

	for (int i = 0; i < 5; i++) {
		pha_zin(&hoi_phu_nu[i]);
	}

	return 0;
}