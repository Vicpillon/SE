
#include "Entity.h"
#include <fstream>
#include <map>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
/*
map<string, Account*> AccountList;
map<string, Product*> ProductList;
*/
Account::Account()
{
    pro = new Product;
};

void Account::createAccount(map<string, Account*>& accountList, string* arr)
{
    accountName = arr[0];
    SSN = arr[1];
    id = arr[2];
    password = arr[3];
	accountList.insert(pair<string, Account*>(id, this));
};
//탈퇴하려는 id와 일치하는 account를 AccountList 내에서 삭제
void Account::removeAccount(map<string, Account*>& accountList, string user_type)
{
    accountList.erase(user_type);
};

string Account::getAccount(map<string, Account*>& accountList, string* arr)
//배열을 받아 가입한 계정 내에 있는지 확인하고 있으면 id반환
{
    if (arr[1] == accountList.at(arr[0])->password)
    {
        accountList[arr[0]]->curentLogin = 1;//현재 이 계정에 로그인 중
        return arr[0];
    }
};

void Account::logoutAccount(map<string, Account*>& accountList, string user_type)
{
    accountList[user_type]->curentLogin = 0;
}

void Account::addNewProduct(map<string, Account*>& accountList, map<string, Product*>& productList, string user_type, string* arr)
{
    pro->createProduct(productList, user_type, arr);
};

void Product::createProduct(map<string, Product*>& productList, string user_type, string* arr)
{
    productName = arr[0];
    company = arr[1];
    price = stoi(arr[2]);
    remainQuantity = stoi(arr[3]);
    setProductList(productList, user_type);
};

void Product::getProductDetails()
{

};

void Product::setProductList(map<string, Product*>& productList, string user_type)
{
    productList.insert(pair<string, Product*>(user_type, this));
}
/////////////////////////////////////////////////

Product::Product()
{}
Product::Product(string sellerId, string productName, string company,
	int price, int remainQuantity)
{
	this->sellerId = sellerId;
	this->productName = productName;
	this->company = company;
	this->price = price;
	this->remainQuantity = remainQuantity;
	this->quantity = 0;
	this->satisfactionAvg = 0; //평균 구매만족도 0 초기화
	this->satisfactionNum = 0; //구매만족도 리뷰 개수
}

void Product::setProduct(string m_sellerId, string m_productName, string m_company, int m_price, int m_remainQuantity)
{
	this->sellerId = m_sellerId;
	this->productName = m_productName;
	this->company = m_company;
	this->price = m_price;
	this->remainQuantity = m_remainQuantity;
	this->quantity = 0;
	this->satisfactionAvg = 0;	//평균 구매만족도 0 초기화
	this->satisfactionNum = 0;	//구매만족도 리뷰 개수
}


void Product::setPurchaseSatisfaction(int satisfaction) 	//구매만족도 수정
{
	this->satisfactionNum++;
	this->satisfactionAvg = (this->satisfactionAvg * (this->satisfactionNum - 1) + satisfaction) / this->satisfactionNum;
}

int Product::getTotalPrice()	//판매 총액 계산
{
	int salesQuantity = quantity - remainQuantity;
	int total;
	total = this->price * salesQuantity;

	return total;
}

Account::Account(string accountName, string SSN, string id, string password)
{
	this->accountName = accountName;
	this->SSN = SSN;
	this->id = id;
	this->password = password;
}



void Account::addProductOrderList(string productName, Product* product)	//구매리스트에 상품추가
{
	this->productOrderList.insert({ productName, product });
}

void Account::addProductSalesList(string productName, Product* product)	//판매리스트에 상품추가
{
	this->productSalesList.insert({ productName, product });
}



map<string, Product*> Account::getProductOrderList()
{
	return this->productOrderList;
}


map<string, Product*> Account::getProductSalesList()
{
	return this->productSalesList;
}
