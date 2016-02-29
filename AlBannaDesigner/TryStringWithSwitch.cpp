/*

Â–« «·»—‰«„Ã ’„„ ·Ì”„Õ »«” Œœ«„ 
witch case With String
ÊÂÌ Œ«’Ì… €Ì— „œ⁄Ê„… ›Ì ·€… «·”Ì »·” Ê·«ﬂ‰Â« „œ⁄Ê„… ›Ì «·Ã«›« 
«·»—‰«„Ã ·„ Ì‰ÃÕ Ê·« «⁄·„ «·”»» 
—€„« «‰Â ŒÊ«—“„Ì« ’ÕÌÕ
*/
#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct StSt
{
	string st;
	bool BreakOrNot;
};
class StSwitch
{
private:
protected:
	vector<bool>br;
	int Num = -1;
	bool Checking = false;
	void CheckCompactiable()
	{
		if (this->Strings.size() != this->Conditions.size())
		{
			cout << "ERROR::Conditions AND Strings MUST HAVE THE SAME NUMBER OF ELEMENT\n";
		}
		else
		{
			this->Checking = true;
		}
	}
	void DoCond()
	{

		if (this->Strings[this->Num]->BreakOrNot == true)
		{
			this->Conditions[this->Num];
		}
		else
		{
			this->Conditions[this->Num];
			for (int m = 0; m < (this->Strings->size() - (this->Num + 1)); m++)
			{
				this->Conditions[this->Num + m];
				if (this->Strings[this->Num + m]->BreakOrNot == true)
					return;
			}
		}

	}

public:
	vector<void(*)()>Conditions;
	vector<StSt*>*Strings = new vector<StSt*>;
	string Checker;

	void Start()
	{
		this->CheckCompactiable();
		if (this->Checking == false)
			return;
		for (int m = 0; m < this->Strings->size(); m++)
		{
			this->br[m] = this->Strings[m]->BreakOrNot;
		}
		for (int m = 0; m < this->Strings->size(); m++)
		{
			if (this->Checker == this->Strings[m]->st)
			{
				this->Num = m;
			}
		}
		this->DoCond();
	}
};



void m1(){ cout << "This is osama"; }
void m2(){ cout << "this is ahmed"; }
void main()
{
	vector<void(*)()>Con;
	Con.push_back(m1);
	Con.push_back(m2);
	StSwitch *stw = new StSwitch;
	stw->Checker = "osama";
	stw->Conditions = Con;
	stw->Strings[0].BreakOrNot = true;//Â‰« ÌŸÂ— «·Œÿ√
//	stw->Strings[0].st = "osama";
//	stw->Start();
	system("pause");
}
#endif