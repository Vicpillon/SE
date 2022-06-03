// ��� ����
#include "Control.h"
#include <sstream>
#include "Entity.h"
#include <iostream>
#include <sstream>

//�������� ����
map<string, Product*> productList;
map<string, Account*> accountList;
map<string, Product*> ProductOrderList;
map<string, Product*> ProductSalesList;
static Account* currentAccount; 
static Product* currentProduct;
string login();
static int productNum = 0;

//�Լ� ����
void doTask();
void program_exit();
void addProduct(string, Product*);	//productList�� product �߰�
void addAccount(string, Account*);	//accountList�� account �߰�

int main()
{ 
    doTask();
}

void doTask()
{ // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    static string user_type = "";

    while (!is_program_exit)
    {
        //user account Ž��
        auto item = accountList.find(user_type);
        if (item != accountList.end()) {
            currentAccount = (item->second);
            //��ī��Ʈ ����Ʈ�� ����
        }
        else {
            
            //��ī��Ʈ ����Ʈ�� ����
            currentAccount = NULL;
        }

        // �Է����Ͽ��� �޴� ���� 2���� �б�
         fin >> menu_level_1 >> menu_level_2;

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
            case 1:
            {
                switch (menu_level_2)
                {
                    case 1: // "1.1. ȸ�����ԡ� �޴� �κ�
                    {
                        SignUp signup;
                        signup.addNewAccount(accountList);
                        break;
                    }
                    case 2://1.2 ȸ�� Ż��
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
                    case 1://2.1 �α���
                    {
                        Login login;
                        user_type = login.isValid(accountList);
                        break;
                    }
                    case 2://2.2 �α׾ƿ�
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
                    case 1://3.1 �Ǹ� �Ƿ� ���
                    { 
                        Product* productNum = new Product;
                        RegistProduct registProduct;
                        registProduct.addNewProduct(currentAccount,productNum, productList);
                        break;
                    }
                    case 2://3.2 ��� ��ǰ ��ȸ
                    {
                        RegisterProductCheck registerProductCheck;
                        registerProductCheck.showRegisterProductCheck(currentAccount);
                        break;
                    }
                    case 3://3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ
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
                    case 1: //4.1 ��ǰ �˻�
                    {
                        SearchC searchC;
                        searchC.requestSearchUI(productList);
                        searchC.requestInfoUI();
                        currentProduct = searchC.getProduct();
                        break;
                    }
                    case 2: //4.2 ��ǰ ����
                    {
                        PurchaseC purchaseC(currentProduct);
                        purchaseC.requestPurchaseUI(accountList, currentAccount);
                        break;
                    }
                    case 3: //4.3 ��ǰ ���� ���� ��ȸ
                    {
                        ProductOrderHistory poh;
                        poh.showProductOrderHistory(productList, currentAccount);
                        break;
                    }
                    case 4: //4.4 ��ǰ ���Ÿ����� ��
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
                    case 1: //5.1 �Ǹ� ��ǰ ���
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
                    case 1: // "6.1. ���ᡰ �޴� �κ�
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
    fout << "6.1. ����" << endl;
}
