#include <iostream>
#include <string>

using namespace std;

//‘ункции вс€ко-разные(объ€влени€)
string transform(istream& s_str);

int main()
{
	cout << "Welcome to this strange program!" << endl;
	cout << "All symbols in text, that you enter here, will be transformed" << endl;
	cout << "in symbols << ( >> (if it's unique symbol) and << ) >> (if symbol occurs more than once)" << endl;

	while (true)
	{
		cout << "Enter your text here:";
		cout << transform(cin) << endl;
	}

	return 0;
}

//‘ункции вс€ко-разные(реализаци€)
string transform(istream& s_str)
{
	//временные переменные
	string out("");
	string tmp("");

	getline(cin, tmp);

	for (int item = 0; item < tmp.length(); item++)
	{
		bool unique(true);

		for (int i = 0; i < tmp.length(); i++)
		{
			if (i != item)
			{
				if (tmp[i] == tmp[item] || tmp[i] == tmp[item] - ('A' - 'a') || tmp[i] == tmp[item] + ('A' - 'a')) //метод костыльный, но по-быстрому ничего другого в голову не идет
				{
					unique = false;
				}
			}
		}

		if (unique == true)
		{
			out += '(';
		}
		else
		{
			out += ')';
		}
	}

	return out;
}
