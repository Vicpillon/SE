
//#include <iostream>
#include "Control.h"

//#include <string>
//SignUpUI::Client SignUpUI::requestSignup()
using namespace std;

SignUp::SignUp()
{
    arr = new string[4];
    suUI = new SignUpUI;//ui 클래스 포인터
    acc = new Account;
}
void SignUp::setData(string* array)
{
    this->name = *array;
    this->ssd = *(array+1);
    this->id = *(array+2);
    this->password = *(array+3);
}

void SignUp::addNewAccount(map<string, Account*>& accountList)
{
    arr = suUI->requestSignup(); 
    suUI->displaySignup();//출력  
    setData(arr);
    acc->createAccount(accountList, arr);
}

Withdrawal::Withdrawal()
{
    wiUI = new WithdrawalUI;
    acc = new Account;
}

void Withdrawal::userWithdrawal(map<string, Account*>& accountList, string user_type)
{
    wiUI->requestWithdrawal(user_type);
    wiUI->displayWithdrawal();
    acc->removeAccount(accountList, user_type);
};

Login::Login()
{
    liUI = new LoginUI;
    acc = new Account;
    arr = new string[2];
}

string Login::isValid(map<string, Account*>& accountList)
{
    string validID;
    arr = liUI->requestLogin();
    liUI->displayLogin();
    validID = acc->getAccount(accountList, arr);
    return validID;
};

Logout::Logout()
{
    loUI = new LogoutUI;
    acc = new Account;
}

void Logout::logout(map<string, Account*>&  accountList, string user_type)
{
    loUI->requestLogout(user_type);
    acc->logoutAccount(accountList, user_type);
    loUI->displayLogout();
};

RegistProduct::RegistProduct()
{
    rpUI = new RegistProductUI;
    acc = new Account;
    arr = new string[4];
	price = 0;
	remainQuantity = 0;
}

void RegistProduct::addNewProduct(Account* user, Product* product, map<string, Product*> productList)
{
    arr = rpUI->requestRegist();
    rpUI->displayRegist();//출력  
    setData(arr);
	sellerId = user->id;
	product->setProduct(sellerId, productName, company, price, remainQuantity);
    user->addProductSalesList(productName, product);
	productList.insert({ productName, product });
};

void RegistProduct::setData(string* arr)
{
    int P, Q;
    this->productName = arr[0];
    this->company = arr[1];
    P = stoi(arr[2]);
    Q = stoi(arr[3]);
   // price << P;
   // remainQuantity << Q;
    //this->price = arr[2];
    //this->remainingQuantity = arr[3];
}

///////////////////////////////////////////////

RegisterProductCheck::RegisterProductCheck() {}
void RegisterProductCheck::showRegisterProductCheck( Account* user)
{
	RegisterProductCheckUI* rpcUI = new RegisterProductCheckUI;
	rpcUI->requestRegisterProductCheck();

	list = user->getProductSalesList();
	map<string, Product*>::iterator iter;
	for (iter = list.begin(); iter != list.end(); iter++) {
		rpcUI->displayRegisterProductCheck(iter->second);
	}
	fout << endl;

	//map<string, Product*>::iterator iter;
	//for (iter = productList.begin(); iter != productList.end(); iter++)
	//{
	//	if (iter->second->sellerId == account->accountName)
	//	{
	//		rpcUI->displayRegisterProductCheck(iter->second);
	//	}
	//}

	delete rpcUI;
	return;
}
SalesProductHistoryC::SalesProductHistoryC()
{};

void SalesProductHistoryC::showSalesProductHistory(Account* account)
{
	sphlist = account->productSalesList;
	SalesProductHistoryUI* sphUI = new SalesProductHistoryUI;
	sphUI->requestProductOrderHistory();
	map<string, Product*>::iterator iter;
	for (iter = sphlist.begin(); iter != sphlist.end(); iter++) {
		sphUI->displayProductOrderHistory(iter->second);
	}
	fout << endl;
	delete sphUI;
	return;

}
SearchC::SearchC()
{
	//product = nullptr;
	sUI = new SearchUI;
	//name = "";
}

SearchC::~SearchC()
{
	delete sUI;
}

Product* SearchC::getProduct()
{
	return this->product;
}

void SearchC::requestSearchUI(map<string, Product*>& productList)
{
	//UI에서 검색어 입력
	list = productList;
	name = sUI->requestSearch();
	//fout << name[0]<<endl;
	auto item = list.find(name[0]);
	if (item != list.end()) {
	//	fout << " 있음" << endl;
		product = (item->second);
	}
	else {
	//	fout << " 없음" << endl;
		return;
	}
	
	//controller 내부의 멤버 product에 검색한 상품을 등록
	this->product = productList.at(name[0]);
}
void SearchC::requestInfoUI()
{
	InfoUI infoUI(this->product);
}

PurchaseC::PurchaseC(Product* product)
{
	this->product = product;
	seller = nullptr;
	buyer = nullptr;
}

void PurchaseC::requestPurchaseUI(map<string, Account*>& accountList, Account* buyer)
{
	//accountList를 탐색하며
	for (auto iter = accountList.begin(); iter != accountList.end(); ++iter)
	{
		if (iter->second->accountName == this->product->sellerId)
		{
			this->seller = iter->second;
			break;
		}
	}
	//판매자 계정의 판매리스트에 상품 추가
	seller->addProductSalesList(product->productName, product);
	//구매자 계정의 구매리스트에 상품 추가
	buyer->addProductOrderList(product->productName, product);
	product->remainQuantity -= product->remainQuantity;
	PurchaseUI pUI(product->sellerId, product->productName);
}

//---------------------------------

/////////////////////////////////////////////////////////////
//상품 구매 내역 조회
ProductOrderHistory::ProductOrderHistory()
{
	poUI = new ProductOrderHistoryUI;
}


void ProductOrderHistory::showProductOrderHistory(map<string, Product*> productList, Account* user)
{
	poUI->requestProductOrderHistory();
	//polist = user->getProductOrderList();
	polist = productList;
	map<string, Product*>::iterator iter;
	for (iter = polist.begin(); iter != polist.end(); iter++) {
		poUI->displayProductOrderHistory(iter->second);
	}
	fout << endl;
	return;
}


/////////////////////////////////////////////////////////////
//상품 구매만족도 평가
PurchaseSatisfaction::PurchaseSatisfaction()
{
	psUI = new PurchaseSatisfactionUI;
	data = new string[4];
	m_productName = "";
	m_satisfaction = 0;
	//pslist = new map<string, Product*>;
	//purchaseProduct = new Product*;
}

void PurchaseSatisfaction::showPurchaseSatisfaction(map<string, Product*> productList, Account* user)
{
	string* inputData = psUI->requestPurchaseSatisfaction();
	//pslist = user->getProductOrderList();
	pslist = productList;
	auto item = pslist.find(inputData[0]);
	if (item != pslist.end()) {
		purchaseProduct = (item->second);
	}
	else {
		return;
	}
	purchaseProduct->setPurchaseSatisfaction(stoi(inputData[1]));
	psUI->displayPurchaseSatisfaction(purchaseProduct, stoi(inputData[1]));
}

/////////////////////////////////////////////////////////////
//판매 상품 통계
ProductSalesStats::ProductSalesStats()
{
	pssUI = new ProductSalesStatsUI;
}


void ProductSalesStats::showProductSalesStats(map<string, Product*> productList, Account* user)
{
	pssUI->requestProductSalesStats();
	//psslist = user->getProductSalesList();
	psslist = productList;
	map<string, Product*>::iterator iter;
	for (iter = psslist.begin(); iter != psslist.end(); iter++) {
		int total;
		total = (*iter).second->getTotalPrice();
		pssUI->displayProductSalesStats(iter->second, total);
	}
	fout << endl;
}