#include <iostream>
#include "../StaticLib/HeaderMT.h"
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{

	string str;
	int kod, kod1, kod2, kod3, position;
	char symbol;
	ifstream fs("D:\\œœŒ»—\\Lib1\\StaticLib\\Test\\file.txt");
	ifstream in("D:\\œœŒ»—\\Lib1\\StaticLib\\Test\\rule.txt");

	MT tp = MT(); 
	while(true)
	{
		cout << "Menu\n 1-Loading program from stream\n 2-Rules\n 3-Value on tape\n 4-Program interpritation\n 5-Exit\n";
		cin >> kod;
		switch (kod)
		{
		case 1:
		{
			tp.LoadTape(fs); 
			tp.LoadRules(in); 
			tp.LoadState(in);
			break;
		}
		case 2:
		{
			cout << "What to do with the rule:\n 1-Add\n 2-Delete\n 3-View\n";
			cin >> kod1;
			switch (kod1)
			{
			case 1:
			{
				string rule;
				cout << "Enter the rule you want to add\n";
				cin.get();
				getline(cin, rule);
				tp.AddRule(rule);
				break;
			}
			case 2:
			{
				
				tp.deleteRule();

				break;
			}
			case 3:
			{
				tp.ShowRules();
				break;
			}
			}
			break;
		}
		case 3:
		{
			cout << "What to do with the tape:\n 1-Write symbol\n 2-Change symbol\n";
			cin >> kod2;
			switch (kod2)
			{
			case 1:
			{
				cout << "Enter the symbol you want to write and it's position\n";
				tp.PrintTape();
				cin >> position >> symbol;
				tp.writeSymb(in, position, symbol);
				tp.PrintTape();
				break;
			}
			case 2:
			{
				cout << "Enter the symbol's position you want to change and new symbol\n";
				cin >> symbol >> position;
				tp.PrintTape();
				tp.changeSymb(position, symbol); 
				tp.PrintTape();
				break;
			}
			}
			break;
		}
		case 4:
		{
			cout << "How to run the machine:\n 1-all at once\n 2-step by step\n";
			cin >> kod3;
			switch (kod3)
			{
			case 1:
			{
				tp.PrintTape();
				tp.Run(0);
				tp.PrintTape();
				break;
			}
			case 2:
			{
				bool log_check = 0;
				if (argc > 1)
				{
					string s = argv[1];
					if (s == "-log")
					{
						log_check = 1;
						tp.Run(log_check);
					}
				else 
					cout << "non-existen argument";
					}
				break;
			}
			}
			break;
		}
		case 5:
		{
			return false;
		}
	}
}
	
}