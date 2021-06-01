#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename T1>
void print(T1 pr)
{
	cout << pr << ' ';
}

template <typename T1, typename ...ARG>
void print(T1 pr, ARG...arg)
{
	cout << pr << ' ';
	print(arg...);
}

template <typename T1>
void PrintToFile(string path, T1 data)
{
	ofstream out(path, ios::app);
	out << data << ' ';

	out.close();
}

template <typename T1, typename ...ARG>
void PrintToFile(string folder, T1 data, ARG...arg)
{
	static ofstream out(folder, ios::app);

	out << data << ' ';

	PrintToFile(folder, arg...); 
}

int main()
{
	PrintToFile("C:\\PrintToFile.txt", 4, "str", 'c', 0);
}





















/*template <typename T1, typename ...ARG>
class PrintTo
{
private:
	ofstream file;
	string path;
public:
	Print(string str, T1 fdata, ARG... arg)
	{
		path = str;
		file.open(path);
		file << fdata;
		Print(arg...);
	}

	Print(T1 data, ARG... arg)
	{
		file << data;
	}
};*/
