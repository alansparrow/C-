// StdSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct NoCase
{
	bool operator()(const string& x, const string& y) const
	{
		for (int i = 0; i < x.length(); i++) {
			if (i == y.length()) return false; // y<x
			char xx = tolower(x[i]);
			char yy = tolower(y[i]);
			if (xx < yy) return true; // x<y
			if (yy < xx) return false; // y<x
		}
		if (x.length() == y.length()) return false; // x==y
		return true; // x<y (fewer characters in x)
	}
};

int main()
{
	/*
	list<string> l;
	l.push_back("qwe");
	l.push_back("ewe");
	l.push_back("cxc");

	
	// You can't use std::sort to sort std::list, because std::sort requires iterators to be random access, 
	// and std::list iterators are only bidirectional.
	
	sort(l.begin(), l.end());
	*/

	vector<string> v1;
	v1.push_back("fddFg");
	v1.push_back("qwEqweq");
	v1.push_back("azSd");
	v1.push_back("DafGgweq");

	// sort
	NoCase pred;
	cout << pred("Dabc", "babc") << endl;
	cout << pred("abc", "babc") << endl;
	sort(v1.begin(), v1.end());
	sort(v1.begin(), v1.end(), pred);
	sort(v1.begin(), v1.end(), [](const string& x, const string& y) { return x.length() > y.length(); });

	// print
	for (const auto& s : v1)
	{
		cout << s << endl;
	}
}
