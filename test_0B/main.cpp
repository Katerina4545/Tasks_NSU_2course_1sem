#include <iostream>
#include <string>
#include <fstream>
#include <map>

#define MAX_LENGHT 50
using namespace std; 

int main(int argc, char** argv)
{
	ifstream in(argv[1]);
	ofstream out(argv[2]);

	map<string, float>map_;
	char* str = new char;
	float kol = 0;
	while (in.getline(str, MAX_LENGHT, ' '))
	{
		if (map_.find(str) == map_.end())		//���� str ��� � map_
			map_.insert(make_pair(str, 1));		
		else 
			map_[str]++;
		kol++;								//����� ����
	}


	//�����
	out << "word" << "," << "frequency" << "," << "frequency%" << endl;
	if (kol!=0)
	{
		map<string, float>::iterator it = map_.end();
		while (it!= map_.begin())
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