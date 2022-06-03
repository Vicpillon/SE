// 헤더 선언
#include "Control.h"
#include <sstream>
#include "Entity.h"
#include <iostream>
#include <sstream>

//전역변수 선언
map<string, Product*> productList;
map<string, Account*> accountList;
map<string, Product*> ProductOrderList;
map<string, Product*> ProductSalesList;
static Account* currentAccount; 
static Product* currentProduct;
string login();
static int productNum = 0;

//함수 선언
void doTask();
void program_exit();
void addProduct(string, Product*);	//productList에 product 추가
void addAccount(string, Account*);	//accountList에 account 추가

int main()
{ 
    doTask();
}

void doTask()
{ // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    static string user_type = "";

    while (!is_program_exit)
    {
        //user account 탐색
        auto item = accountList.find(user_type);
        if (item != accountList.end()) {
            currentAccount = (item->second);
            //어카운트 리스트에 존재
        }
        else {
            
            //어카운트 리스트에 없음
            currentAccount = NULL;
        }

        // 입력파일에서 메뉴 숫자 2개를 읽기
         fin >> menu_level_1 >> menu_level_2;

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
            case 1:
            {
                switch (menu_level_2)
                {
                    case 1: // "1.1. 회원가입“ 메뉴 부분
                    {
                        SignUp signup;
                        signup.addNewAccount(accountList);
                        break;
                    }
                    case 2://1.2 회원 탈퇴
                    {
                        Withdrawal withdrawal;
                        withdrawal.userWithdrawal(accountList, user_type);
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                switch (menu_level_2)
                {
                    case 1://2.1 로그인
                    {
                        Login login;
                        user_type = login.isValid(accountList);
                        break;
                    }
                    case 2://2.2 로그아웃
                    {
                        Logout logout;
                        logout.logout(accountList, user_type);
                        user_type.clear();
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                switch (menu_level_2)
                {
                    case 1://3.1 판매 의류 등록
                    { 
                        Product* productNum = new Product;
                        RegistProduct registProduct;
                        registProduct.addNewProduct(currentAccount,productNum, productList);
                        break;
                    }
                    case 2://3.2 등록 상품 조회
                    {
                        RegisterProductCheck registerProductCheck;
                        registerProductCheck.showRegisterProductCheck(currentAccount);
                        break;
                    }
                    case 3://3.3 판매 완료 상품 조회
                    {
                        SalesProductHistoryC salesProductHistoryC;
                        salesProductHistoryC.showSalesProductHistory(currentAccount);
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                switch (menu_level_2)
                {
                    case 1: //4.1 상품 검색
                    {
                        SearchC searchC;
                        searchC.requestSearchUI(productList);
                        searchC.requestInfoUI();
                        currentProduct = searchC.getProduct();
                        break;
                    }
                    case 2: //4.2 상품 구매
                    {
                        PurchaseC purchaseC(currentProduct);
                        purchaseC.requestPurchaseUI(accountList, currentAccount);
                        break;
                    }
                    case 3: //4.3 상품 구매 내역 조회
                    {
                        ProductOrderHistory poh;
                        poh.showProductOrderHistory(productList, currentAccount);
                        break;
                    }
                    case 4: //4.4 상품 구매만족도 평가
                    {
                        PurchaseSatisfaction ps;
                        ps.showPurchaseSatisfaction(productList, currentAccount);
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                switch (menu_level_2)
                {
                    case 1: //5.1 판매 상품 통계
                    {
                        ProductSalesStats pss;
                        pss.showProductSalesStats(productList, currentAccount);
                        break;
                    }
                }
                break;
            }
            case 6:
            {
                switch (menu_level_2)
                {
                    case 1: // "6.1. 종료“ 메뉴 부분
                    {
                        program_exit();
                        is_program_exit = 1;
                        break;
                    }
                }
                break;
            }

         }
       
    }
}
void addProduct(string productName, Product* product)
{
    productList.insert({ productName, product });
}

void addAccount(string accountName, Account* account)
{
    accountList.insert({ accountName, account });
}

void program_exit()
{
    fout << "6.1. 종료" << endl;
}
