#include <iostream>
#include <vector>

//Forward declaration 
class BankAuditor;

class BankAccount
{
	friend class BankAuditor;
	private:
		int accId;
		std::vector <double> balHist;
	public:
		BankAccount(int id): accId(id)
		{
			balHist.push_back(0.0);
		}
		//this function modifies the existing member of the class
		void withdraw(double amount)
		{
			balHist.push_back(balHist.back()-amount);
		}
		void depoist(double amount)
		{
			balHist.push_back(balHist.back()+amount);
		}
		//this function does not modify any member of the class
		double currentBalance() const
		{
			return balHist.back();
		}

};

class BankAuditor
{
public: 
	//object of the bank account 
	void printReport(const BankAccount& bk) const
	{
		for(size_t i=0; i< bk.balHist.size(); ++i)
		{
			std::cout<<"this name is "<< bk.balHist[i]<<std::endl;
		}
	}
};

int main()
{
	BankAccount bank(100);
	bank.depoist(100);
	bank.withdraw(100);

	BankAuditor audit;
	//this function expects the class of bank 
	audit.printReport(bank);
}
