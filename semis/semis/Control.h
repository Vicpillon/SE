
// 헤더 선언
#pragma once

#include "Entity.h"
#include "Boundary.h"


class SignUp
{
private:
    string name, ssd, id, password;
    string* arr;
    SignUpUI* suUI;//ui 클래스 포인터
    Account* acc;//account 클래스 포인터

    void setData(string* array);
public:
    SignUp();
    void addNewAccount(map<string, Account*>&);
};

class Withdrawal 
{
private:
    WithdrawalUI* wiUI;
    Account* acc;

public:
    Withdrawal();
    void userWithdrawal(map<string, Account*>&, string);
};

class Login
{
private:
    LoginUI* liUI;
    Account* acc;
    string* arr;

public:
    Login();
    string isValid(map<string, Account*>&);
};

class Logout
{
private:
    LogoutUI* loUI;
    Account* acc;
    
public:
    Logout();
    void logout(map<string, Account*>& ,string);
};

class RegistProduct
{
private:
	string productName, company, sellerId;
    int price, remainQuantity;
    RegistProductUI* rpUI;
    Account* acc;
    string* arr;
public:
	void setData(string*);
    RegistProduct();
    void addNewProduct(Account* user, Product* product, map<string, Product*> productList);
};

////////////////////////////////////////////////////////
class RegisterProductCheck
{
private:
	map<string, Product*> list;
public:
	RegisterProductCheck();
	void showRegisterProductCheck(Account*);

};

class SalesProductHistoryC
{
	map<string, Product*> sphlist;
public:
	SalesProductHistoryC();
	void showSalesProductHistory(Account*);

};
class SearchC
{
	SearchUI* sUI;
	Product* product;
	string* name;

	map<string, Product*> list;
public:
	SearchC();
	~SearchC();
	//상품검색 UI를 호출
	void requestSearchUI(map<string, Product*>& productList);
	void requestInfoUI();
	Product* getProduct();
};

class PurchaseC
{
	Product* product;
	Account* seller;
	Account* buyer;
public:
	PurchaseC(Product*);
	void requestPurchaseUI(map<string, Account*>& , Account*);
};

//-----------

class ProductOrderHistory
{
private:
	ProductOrderHistoryUI* poUI;
	map<string, Product*> polist;
public:
	ProductOrderHistory();
	void showProductOrderHistory(map<string, Product*>, Account* user);
};

class PurchaseSatisfaction
{
private:
	PurchaseSatisfactionUI* psUI;
	string* data;
	string m_productName;
	int m_satisfaction;
	map<string, Product*> pslist;
	Product* purchaseProduct;
public:
	PurchaseSatisfaction();
	//PurchaseSatisfaction(,string productName, int satisfaction);
	void showPurchaseSatisfaction(map<string, Product*>, Account* user);
};


class ProductSalesStats
{
private:
	ProductSalesStatsUI* pssUI;
	map<string, Product*> psslist;


public:
	ProductSalesStats();
	void showProductSalesStats(map<string, Product*>, Account* user);
};




