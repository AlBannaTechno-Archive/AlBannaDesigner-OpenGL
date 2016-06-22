#if 0
#include"BasicClass.h"
#include<thread>
class mks
{
public:
	ABTGLC::LightSection mytest;
	mks()
	{
		mytest.InializeStand(800, 600, "FirstCo");
	}
	void Re()
	{
		mytest.DoAll();
	}

};

void main()
{

	ABTGLC::LightSection los(800, 600, "sadsadas");
//	los.InializeStand(800, 600, "sadsadas");
	los.DoAll();

}
#endif