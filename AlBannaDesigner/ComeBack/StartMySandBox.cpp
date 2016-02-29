#include"MySandBox.h"
#if Compilation
using namespace std;
void helpFunctoion()
{
	std::cout << "This Program Created By Osama Al Banna" << std::endl;
	cout << "This Program Created To Simulate GLSL Shader At Runtime" << endl;
	cout << "You Can Press m to Free Mouse From Program Screen" << endl;
	cout << "You Need To specifying Fragment Shader Path at FSP.osa File" << endl;
	cout << "Be carful you must use double backslash '\\\' instead of single backslash '\\' \n";
	cout << "at Program path (in FSP.osa)" << endl;
	cout << "You Can use gl_FragCoord To Fragment coordinate\n";
	cout << "And gl_FragColor To color RGBA\n";
	cout << "Also You can use mouse for mouse position mouse.x mouse.y \n";
	cout << "Also resolution.x resolution.y To Screen Resolution \n :default 800/600";
	cout << "you specifying at SR.sr file as Width$height ";
	cout << "Also time to get runtime \n";
	cout << "warning::THIS PROGRAM USING FILE CHARACTERS NUMBER METHOD TO CHECK IF FILE\N";
	cout << "ACTUALLY CHANGED OR NOT SO IF YOU CONVERT 3.2 TO 4.6 FOR EXAMPLE \n";
	cout << "THE PROGRAM WON'T CHANGING ANGY THING BECAUSE BOTH HAVE THE SAME NUMBER OF CHARACTER\n";
	cout << "INSTEAD OF THIS YOU MUST CONVERT 3.2 TO 3. ONLY AND SAVE THEN WRITE 4.6 FOR EXAMPLE" << endl;
	cout << "I used this method to optimizing performance of the program\n";
	cout << "VI : if there any error with path or compilng shader the screen of program will be stop \n";
	cout << "at this point press m to scape from window and look to command-Blcak-window for info \n";
	cout << "Press Esc TO Exit\n";
	cout << "Good luck \n Al Banna Techno\n			Start\n";

}

void GetIntNumber(string sts,long &fir,long &second)
{
	string st;
	for (int j = 0; j < sts.size(); j++)
	{
		st.push_back(sts[sts.size()-j-1]);
	}
	long Num=0;
	long frac = 0;
	int Coun=0;
	int togets = 0;
	bool first = true;
	for (int m = 0; m < st.size(); m++)
	{
		if (st[m] == '1' || st[m] == '2' || st[m] == '3' || st[m] == '4' || st[m] == '5' || st[m] == '6' || st[m] == '7' || st[m] == '8' || st[m] == '9' || st[m] == '0')
		{
			for (int s = m; s < st.size(); s++)
			{
				togets = s;
				if (st[s] == '1')
				{
					if (first)
						Num += 1 * powl(10, Coun++);
					else
						frac += 1 * powl(10, Coun++);
				}
				else if (st[s] == '2')
				{
					if (first)
						Num += 2 * powl(10, Coun++);
					else
						frac += 2 * powl(10, Coun++);
				}
				else if (st[s] == '3')
				{
					if (first)
						Num += 3 * powl(10, Coun++);
					else
						frac += 3 * powl(10, Coun++);
				}
				else if (st[s] == '4')
				{
					if (first)
						Num += 4 * powl(10, Coun++);
					else
						frac += 4 * powl(10, Coun++);
				}
				else if (st[s] == '5')
				{
					if (first)
						Num += 5 * powl(10, Coun++);
					else
						frac += 5 * powl(10, Coun++);
				}
				else if (st[s] == '6')
				{
					if (first)
						Num += 6 * powl(10, Coun++);
					else
						frac += 6 * powl(10, Coun++);
				}
				else if (st[s] == '7')
				{
					if (first)
						Num += 7 * powl(10, Coun++);
					else
						frac += 7 * powl(10, Coun++);
				}
				else if (st[s] == '8')
				{
					if (first)
						Num += 8 * powl(10, Coun++);
					else
						frac += 8 * powl(10, Coun++);
				}
				else if (st[s] == '9')
				{
					if (first)
						Num += 9 * powl(10, Coun++);
					else
						frac += 9 * powl(10, Coun++);
				}
				else if (st[s] == '0')
				{
					if (first)
						Num += 0 * powl(10, Coun++);
					else
						frac += 0 * powl(10, Coun++);
				}
				else
					break;
			}
			m = togets; togets = 0;//it's must be togets-1 but there No?
			Coun = 0;
			first = !first;
		}
		
	}
	fir = Num;
	second = frac;
}
void main()
{
	StringLoader res;
	res.Load("SR.sr");
	long WIDTH, HEIGHT;
	GetIntNumber(res.StData, HEIGHT, WIDTH);
	helpFunctoion();
	std::cout <<"Screen Resolution :: "<< WIDTH << " : " << HEIGHT << "\n";
	tup mat(WIDTH, HEIGHT, "AlBannaGLSandBox");
	mat.DoAll();
}
#endif