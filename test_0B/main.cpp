#include <iostream>

#include <string>
#include <regex>
#include <map>
#include <fstream>

#define MAX_LENGHT 50
using namespace std;

int main(int argc, char** argv)
{
	ifstream in(argv[1]);
	ofstream out(argv[2]);

	map<string, float>map_;
	char* str = new char;
	float kol = 0;	

	//считываем строку и разбиваем с помощью strok_s
	in.getline(str, MAX_LENGHT);
	const char* separators = " ,.?!/t;:-_)("; 	//разделители 
	char* str_ = new char;				//слово
	char* next = NULL;
	str_ = strtok_s(str, separators, &next); 	//вытаскиваем первое слово
	while (str_)
	{
		if (map_.find(str_) == map_.end())	 //если str нет в map_
			map_.insert(make_pair(str_, 1));
		else
			map_[str_]++;
		kol++;					 //всего слов
		str_ = strtok_s(NULL, separators, &next);//выбираем следующее слово текущей строки		
	}


	//вывод
	out << "word" << "," << "frequency" << "," << "frequency%" << endl;
	if (kol != 0)
	{
		map<string, float>::iterator it = map_.end();
		while (it != map_.begin())
		{
			it--;
			out << fixed;
			out.precision(0);
			out << it->first << "," << it->second << ",";

			float a = it->second / kol;
			out << fixed;
			out.precision(2);
			out << a * 100 << endl;
		}
	}
	in.close();
	out.close();
	return 0;
}
