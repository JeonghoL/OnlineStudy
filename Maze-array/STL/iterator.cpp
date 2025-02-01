#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "Vector.h"
using namespace std;

int main()
{
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	Vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); ++it)
	{
		int data = *it;
		cout << data << endl;
	}

	// it++;
	// v.begin();
	// v.end();
	// it != v.end();
	// *it;
}