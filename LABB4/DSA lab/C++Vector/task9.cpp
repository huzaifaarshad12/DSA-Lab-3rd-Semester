#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
void CreateRandomFile(const  string& fn, int Size, int RN=100) {
	srand(time(0));
	ofstream Writer(fn);
	for (int i = 0; i < Size * 1024 * 1024; ++i)
		Writer << rand() % RN << " ";
}
int main() 
{
	CreateRandomFile("data.txt",2);
	return 0;
}