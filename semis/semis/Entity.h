
// 헤더 선언

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
extern ifstream fin;
extern ofstream fout;

class Product
{
private:
    string productName;
    string company;
    string sellerId;
    int price;
    int remainQuantity;
    int quantity;
    int satisfactionAvg;
    int satisfactionNum;  
    void setProductList(map<string, Product*>&, string);
    friend class SearchUI;
    friend class InfoUI;
    friend class PurchaseUI;
    friend class ProductOrderHistoryUI;
    friend class PurchaseSatisfactionUI;
    friend class ProductSalesStatsUI;
    friend class RegisterProductCheck;
    friend class PurchaseC;
    friend class SalesProductHistoryUI;
    friend class RegisterProductCheckUI;
public:
    Product();
    Product(string, string, string, int, int);
    void createProduct(map<string, Product*>&,string, string*);
    void getProductDetails();
    void setPurchaseSatisfaction(int satisfaction);
    int getTotalPrice();
    void setProduct(string, string, string, int, int);
};

class Account
{
private:
    int curentLogin = 0;//1이면 로그인 중
    string accountName;
    string SSN;
    string id;
    string password;
    Product* pro; 
    map<string, Product*> productOrderList;
    map<string, Product*> productSalesList;
    friend class SalesProductHistoryC;
    friend class SearchC;
    friend class PurchaseC;
    friend class ProductOrderHistory;
    friend class PurchaseSatisfaction;
    friend class ProductSalesStats;
    friend class RegisterProductCheck;
    friend class PurchaseC;
    friend class RegistProduct;
public:
    Account();
    Account(string, string, string, string);
    void createAccount(map<string, Account*>&, string*);
    void removeAccount(map<string, Account*>&, string);
    string getAccount(map<string, Account*>&, string*);
    void logoutAccount(map<string, Account*>&, string);
    void addNewProduct(map<string, Account*>&, map<string, Product*>&, string, string*);
    void addProductOrderList(string, Product*);
    void addProductSalesList(string, Product*);
    map<string, Product*> getProductOrderList();
    map<string, Product*> getProductSalesList();
};

