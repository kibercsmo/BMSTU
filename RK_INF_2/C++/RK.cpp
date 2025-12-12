#include <iostream>
#include <vector>
#include <string>

class BankAccount{
public:
    int acc_id;
    std::string name;
    float balance;

    BankAccount(int acc_id, std::string name, float balance){
        this->acc_id = acc_id;
        this->name = name;
        this->balance = balance;
    };
    BankAccount(int acc_id, std::string name){
        this->acc_id = acc_id;
        this->name = name;
        this->balance = 0;
    };
    BankAccount(int acc_id){
        this->acc_id = acc_id;
        this->name = "Undenified";
        this->balance = 0;
    };
    BankAccount(){
        this->acc_id = -1;
        this->name = "Undenified";
        this->balance = 0;
    };

    void Deposit(float cash){
        if (cash >= 0)
        {
            this->balance = this->balance + cash;
        }
        else{
            std::cerr << "Error!: Deposit cash < 0" << std::endl;
        }
    };

    void Withdraw(float cash){
        if (cash >= 0)
        {
            this->balance = this->balance - cash;
        }
        else{
            std::cerr << "Error!: Withdraw cash < 0" << std::endl;
        }
    };
};

class SavingAccount : public BankAccount{
public:
    float persentage = 0;

    using BankAccount::BankAccount;
    SavingAccount(int acc_id, std::string name, float balance,float persentage) : BankAccount(acc_id, name, balance){
        this->persentage = persentage;
    }

    void AddCash(){
        balance += balance*(persentage/100);
    }
};

int main(){
    SavingAccount semen(1, "Семён", 0, 15);
    semen.Deposit(1000);
    std::cout << semen.balance << std::endl;
    semen.AddCash();
    std::cout << semen.balance << std::endl;
    return 0;
}