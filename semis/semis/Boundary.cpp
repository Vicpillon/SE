
#include "Boundary.h"

ifstream readFile("input.txt");
ofstream writeFile("output.txt");


SignUpUI::SignUpUI()
{
    data = new string[4];
}

string* SignUpUI::requestSignup()//���Ͽ��� ������ �Է¹޾� client�� �ѱ��!
{
    fin >> data[0] >> data[1] >> data[2] >> data[3];
    
    return data;
};

void SignUpUI::displaySignup()
{
    // ��� ����
    fout << "1.1. ȸ������" << endl;
    fout << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << endl;
};

void WithdrawalUI::requestWithdrawal(string user_type)
{
    userID = user_type;
};

void WithdrawalUI::displayWithdrawal()
{
    fout << "1.2. ȸ��Ż��" << endl;
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
    fout << "2.1. �α���" << endl;
    fout << data[0] << " " << data[1] << endl;
};

void LogoutUI::requestLogout(string user_type)
{
    this->id = user_type;
};

void LogoutUI::displayLogout()
{
    fout << "2.2. �α׾ƿ�" << endl;
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
    fout << "3.1. �Ǹ� �Ƿ� ���" << endl;
    fout << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << endl;
};


//////////////////////////////////////////
RegisterProductCheckUI::RegisterProductCheckUI() {}

void RegisterProductCheckUI::requestRegisterProductCheck()
{
	fout << "3.2. ��� ��ǰ ��ȸ" << endl;
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
	fout << "3.3. �Ǹ� �Ϸ�	��ǰ ��ȸ" << endl;
}

void SalesProductHistoryUI::displayProductOrderHistory(Product* product)
{
	//��ǰ��, ����ȸ���, ����, �Ǹŵ� ����, ��� ���Ÿ����� ���
	fout << "> " << product->productName << " " << product->company << " " << product->quantity << " "
		<< product->satisfactionAvg << endl;
}

SearchUI::SearchUI()
{
	//enterName = "";
}

string* SearchUI::requestSearch()
{
	fout << "4.1. ��ǰ ���� �˻�" << endl;
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
	fout << "4.2 ��ǰ ����" << endl;
	displayPurchase(sellerId, productName);
}
void PurchaseUI::displayPurchase(string sellerId, string productName)
{
	fout << "> " << sellerId << " " << productName << endl;
}


//--------------------------------------------------

void ProductOrderHistoryUI::requestProductOrderHistory()
{
	fout << "4.3. ��ǰ ���� ���� ��ȸ" << endl;
}

void ProductOrderHistoryUI::displayProductOrderHistory(Product* product)
{
	//�Ǹ���ID, ��ǰ��, ����ȸ���, ����, ��������, ��� ���Ÿ����� ���
	fout << "> " << product->sellerId << " " << product->productName << " " << product->company << " "
		<< product->price << " " << product->remainQuantity << " " << product->satisfactionAvg << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

PurchaseSatisfactionUI::PurchaseSatisfactionUI() {
	fout << "4.4. ��ǰ ���Ÿ����� ��" << endl;
}
string* PurchaseSatisfactionUI::requestPurchaseSatisfaction()
{
	//��ǰ��, ���Ÿ����� �Է�
	fin >> data[0] >> data[1];
	return data;
}

void PurchaseSatisfactionUI::displayPurchaseSatisfaction(Product* product, int satisfaction)
{
	//�Ǹ���ID, ��ǰ��, ���Ÿ����� ���
	fout << "> " << product->sellerId << " " << product->productName << " " << satisfaction << "\n" << endl;

}


////////////////////////////////////////////////////////////////////////////////////////////

void ProductSalesStatsUI::requestProductSalesStats()
{
	fout << "5.1. �Ǹ� ��ǰ ���" << endl;
}

void ProductSalesStatsUI::displayProductSalesStats(Product* product, int total)
{
	//��ǰ��, ��ǰ �Ǹ� �Ѿ�, ��� ���Ÿ����� ���
	fout << "> " << product->productName << " " << total << " " << product->satisfactionAvg << endl;
}
