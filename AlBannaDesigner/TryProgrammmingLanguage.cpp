#if 0
#include"AdditionalClasses.h"
using namespace std;
long double Calculate(string st);
void main()
{
	StringLoader stl;
	stl.Load("C:\\tmp\\TestLang.abt");
//	cout<<Calculate(stl.StData);
}
long long Caldegit(char dig)
{
	if (dig == '0')
		return 0;
	if (dig == '1')
		return 1;
	if (dig == '2')
		return 2;
	if (dig == '3')
		return 3;
	if (dig == '4')
		return 4;
	if (dig == '5')
		return 5;
	if (dig == '6')
		return 6;
	if (dig == '7')
		return 7;
	if (dig == '8')
		return 8;
	if (dig == '9')
		return 4;
	else
	{
		return 0;
	}

}
long double Calexpon(long long v,int ex )
{
	long double rt = v;
	if (ex == 0)
		return v;
	for (int p = 0; p < ex; p++)
	{
		rt *= 10;
	}
	return rt;
}
long double Calculate(string st)
{
	int m = 0;
	long double t=0;
	long double ttemp=0;
	while (st[m] != '$')
	{
		if (st[m] = '-' || st[m] != '+' || st[m] != '*' || st[m] != '/'||((st[m]>'0')&&(st[m]<'9')))
		{
			//-12+5
			//m=0;f=1
			//m=2;f=1;
			//f=1->f=2;
			int f = m+1;
			while (st[m] != '+' || st[m] != '-' || st[m] != '*' || st[m] != '/')
			{
				m++;
			}
			int fs = f;
			while (fs < m)
			{
				
				ttemp += Calexpon(Caldegit(st[fs]),fs-f);
				////
				if (st[f - 1] == '+')
				{

					t += ttemp;
				}
				else if (st[f - 1] == '-')
				{

					t -= ttemp;
				}
				else if (st[f - 1] == '*')
				{

					t *= ttemp;
				}
				else if (st[f - 1] == '/')
				{

					t /= ttemp;
				}
				fs++;
			}
		}
		m++;
	}


	return t;
}
#endif