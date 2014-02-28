// ConsoleApplicationTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class A
{
public:
	static int needle;

	A()
	{
		cout << "*";
	}

	A(int i)
	{
		cout << "$";
	}

	A(const A& a)
	{
		cout << "#";
	}

	~A()
	{
		cout << "~";
	}
};

typedef unique_ptr<A> _A;
typedef vector<_A> _AVec;
typedef unique_ptr<_AVec> _AVecPtr;

int _tmain(int argc, _TCHAR* argv[])
{
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();

	_AVecPtr v1 = make_unique<_AVec>();
	unsigned int n = std::thread::hardware_concurrency();

	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	
	cout << elapsed_seconds.count() << endl;

	return 0;
}

