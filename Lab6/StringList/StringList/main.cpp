#include "stdafx.h"
#include <list>
#include <iostream>
#include <string>
#include "StringList.h"


using namespace std;

int main()
{
	//{
	//	unique_ptr<string> ptr1 = make_unique<string>("zzz");
	//	string * ptr2 = new string("ASD");

	//	ptr1.reset(ptr2);
	//	cout << *ptr1 <<" " << *ptr2 << " " << (ptr1.get() == ptr2)<< endl;
	//}


	//{
	//	list<string> lstt = {"2"};
	//	cout << lstt.back() << endl;
	//	std::list<string> lst = { "1222" };
	//	auto end1 = lst.end();
	//	lst.push_back("123123123");	
	//	cout << (lst.end() == end1) << endl;

	//	auto end = lst.end();
	//	cout << *(--lst.end()) << endl;

	//	lstt.emplace(lstt.begin(), "zzz");
	//	cout << lstt.front() << endl;
	//}

	//{
	//	//CStringList lst;
	//	//for (size_t i = 0; i < 99999; ++i)
	//	//{
	//	//	lst.Append("asd");
	//	//}
	//	//lst.Clear();
	//}
	//{
	//	CStringList<std::string> list;
	//	list.Append("123");
	////	cout << *(list.end()) << endl;
	//	cout << *(list.begin()) << endl;
	//}

	{
		std::list<std::string> lst = { "1" };
		//lst.push_back("2");

		lst.erase(lst.begin());
	}

	unique_ptr<int> ptr1 = make_unique<int>(1);
	unique_ptr<int> ptr2;

	ptr2 = move(ptr1);
	{
		CStringList<std::string> lst_;
		lst_.Append("1");
		lst_.Append("2");
		lst_.Append("3");
		lst_.Append("4");
		lst_.Append("5");
		for (auto it = lst_.begin(); it != lst_.end(); ++it)
		{
			cout << *it << endl;
		}
	}

	{
		CStringList<std::string> lst_;
		lst_.AddToFront("1");
		lst_.AddToFront("2");
		lst_.AddToFront("3");
		lst_.AddToFront("4");
		lst_.AddToFront("5");
		for (auto it = lst_.begin(); it != lst_.end(); ++it)
		{
			cout << *it << endl;
		}
		for (auto &it : lst_)
		{
			cout << it << " Range-based-for" << endl;
		}
	}

	{
		CStringList<double> lst;
		auto end = lst.begin();
		auto end1 = lst.end();
	}

	//	auto bb = ++lst_.begin();
	//	lst_.Insert(bb, "WOW22");

	//	cout << lst_.GetFrontElement() << endl;

	//	auto end = lst_.end();
	//	lst_.Append("aaa");
		
		//cout << endl << (end == lst_.end()) << endl;

	return 0;
}

