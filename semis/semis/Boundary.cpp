
#include "Boundary.h"

ifstream readFile("input.txt");
ofstream writeFile("output.txt");


SignUpUI::SignUpUI()
{
    data = new string[4];
}

string* SignUpUI::requestSignup()//파일에서 데이터 입력받아 client로 넘기기!
{
    fin >> data[0] >> data[1] >> data[2] >> data[3];
    
    return data;
};

void SignUpUI::displaySignup()
{
    // 출력 형식
    fout << "1.1. 회원가입" << endl;
    fout << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << endl;
};

void WithdrawalUI::requestWithdrawal(string user_type)
{
    userID = user_type;
};

void WithdrawalUI::displayWithdrawal()
{
    fout << "1.2. 회원탈퇴" << endl;
    fout << userID << endl;
};

LoginUI::LoginUI()
{
    data = new string[2];
}
string* LoginUI::requestLogin()
{
    fin >> data[0] >> data[1];
    return data;
};
void LoginUI::displayLogin()
{
    fout << "2.1. 로그인" << endl;
    fout << data[0] << " " << data[1] << endl;
};

void LogoutUI::requestLogout(string user_type)
{
    this->id = user_type;
};

void LogoutUI::displayLogout()
{
    fout << "2.2. 로그아웃" << endl;
    fout << id << endl;
};

RegistProductUI::RegistProductUI()
{
    data = new string[4];
}

string* RegistProductUI::requestRegist()
{
    fin >> data[0] >> data[1] >> data[2] >> data[3];
    return data;
};

void RegistProductUI::displayRegist()
{
    fout << "3.1. 판매 의류 등록" << endl;
    fout << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << endl;
};


//////////////////////////////////////////
RegisterProductCheckUI::RegisterProductCheckUI() {}

void RegisterProductCheckUI::requestRegisterProductCheck()
{
	fout << "3.2. 등록 상품 조회" << endl;
}

void RegisterProductCheckUI::displayRegisterProductCheck(Product* product)
{
	fout << "> " << product->productName << " " << product->company << " " << product->quantity << " " << endl;
}

SalesProductHistoryUI::SalesProductHistoryUI()
{

}
void SalesProductHistoryUI::requestProductOrderHistory()
{
	fout << "3.3. 판매 완료	상품 조회" << endl;
}

void SalesProductHistoryUI::displayProductOrderHistory(Product* product)
{
	//상품명, 제작회사명, 가격, 판매된 수량, 평균 구매만족도 출력
	fout << "> " << product->productName << " " << product->company << " " << product->quantity << " "
		<< product->satisfactionAvg << endl;
}

SearchUI::SearchUI()
{
	//enterName = "";
}

string* SearchUI::requestSearch()
{
	fout << "4.1. 상품 정보 검색" << endl;
	fin >> enterName[0];
	//fout << enterName[0] << endl;
	return enterName;
}
InfoUI::InfoUI(Product* product)
{
	displayInfo(product);
}
void InfoUI::displayInfo(Product* product)
{
	fout << "> " << product->sellerId << " " << product->productName << " " << product->company << " "
		<< product->price << " " << product->remainQuantity << " " << endl;
}
PurchaseUI::PurchaseUI(string sellerId, string productName)
{
	fout << "4.2 상품 구매" << endl;
	displayPurchase(sellerId, productName);
}
void PurchaseUI::displayPurchase(string sellerId, string productName)
{
	fout << "> " << sellerId << " " << productName << endl;
}


//--------------------------------------------------

void ProductOrderHistoryUI::requestProductOrderHistory()
{
	fout << "4.3. 상품 구매 내역 조회" << endl;
}

void ProductOrderHistoryUI::displayProductOrderHistory(Product* product)
{
	//판매자ID, 상품명, 제작회사명, 가격, 남은수량, 평균 구매만족도 출력
	fout << "> " << product->sellerId << " " << product->productName << " " << product->company << " "
		<< product->price << " " << product->remainQuantity << " " << product->satisfactionAvg << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

PurchaseSatisfactionUI::PurchaseSatisfactionUI() {
	fout << "4.4. 상품 구매만족도 평가" << endl;
}
string* PurchaseSatisfactionUI::requestPurchaseSatisfaction()
{
	//상품명, 구매만족도 입력
	fin >> data[0] >> data[1];
	return data;
}

void PurchaseSatisfactionUI::displayPurchaseSatisfaction(Product* product, int satisfaction)
{
	//판매자ID, 상품명, 구매만족도 출력
	fout << "> " << product->sellerId << " " << product->productName << " " << satisfaction << "\n" << endl;

}


////////////////////////////////////////////////////////////////////////////////////////////

void ProductSalesStatsUI::requestProductSalesStats()
{
	fout << "5.1. 판매 상품 통계" << endl;
}

void ProductSalesStatsUI::displayProductSalesStats(Product* product, int total)
{
	//상품명, 상품 판매 총액, 평균 구매만족도 출력
	fout << "> " << product->productName << " " << total << " " << product->satisfactionAvg << endl;
}
