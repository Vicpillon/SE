#pragma once
#include "Entity.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class SignUpUI
{
private:
    string* data;
    //void inputData();
public:
    SignUpUI();
    string* requestSignup();
    void displaySignup();
};

class WithdrawalUI
{
private:
    string userID;
public:
    void requestWithdrawal(string);
    void displayWithdrawal();
};

class LoginUI
{
private:
    string* data;
public:
    LoginUI();
    string* requestLogin();
    void displayLogin();
};

class LogoutUI
{
private:
    string id;
public:
    void requestLogout(string);
    void displayLogout();
};

class RegistProductUI
{
private:
    string* data;
public:
    RegistProductUI();
    string* requestRegist();
    void displayRegist();
};

class RegisterProductCheckUI
{
public:
    RegisterProductCheckUI();
    void requestRegisterProductCheck();
    void displayRegisterProductCheck(Product*);
};

/// /////////////////////////////////////

class SalesProductHistoryUI
{
public:
    SalesProductHistoryUI();
    void requestProductOrderHistory();
    void displayProductOrderHistory(Product* product);
};

class SearchUI
{
    string enterName[1];
public:
    SearchUI();
    //파일로부터 상품명 입력받기
    string* requestSearch();
};

class InfoUI
{
public:
    //검색한 상품
    InfoUI(Product*);
    void displayInfo(Product*);
};

class PurchaseUI
{
public:
    PurchaseUI(string, string);
    void displayPurchase(string, string);
};

//----------------------------------

class ProductOrderHistoryUI
{
private:

public:
    void requestProductOrderHistory();
    void displayProductOrderHistory(Product* product);
};

class PurchaseSatisfactionUI
{
private:
    string data[2];
public:
    PurchaseSatisfactionUI();
    string* requestPurchaseSatisfaction();
    void  displayPurchaseSatisfaction(Product* product, int satisfaction);
};


class ProductSalesStatsUI
{
private:

public:
    void requestProductSalesStats();
    void displayProductSalesStats(Product* product, int total);
};

