// HTTPURL.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HttpUrl.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <boost/lexical_cast.hpp>

using namespace std;

vector<string> ParseArgs(string const &inputStr)
{
	string arg;
	istringstream strm(inputStr);
	vector<string> args;

	while (strm >> arg)
	{
		args.push_back(arg);
	}

	return args;
}

unique_ptr<CHttpUrl> MakePtrToUrl(vector<string> &args)
{
	unique_ptr<CHttpUrl> url;

	switch (args.size())
	{
	case (1):
		url = make_unique<CHttpUrl>(args[0]);
		break;
	case (2):
		url = make_unique<CHttpUrl>(args[0], args[1]);
		break;
	case (3):
		url = make_unique<CHttpUrl>(args[0], args[1], url->ToProtocolType(args[2]));
		break;
	case (4):
		url = make_unique<CHttpUrl>(args[0], args[1], url->ToProtocolType(args[2]), boost::lexical_cast<unsigned short>(args[3]));
		break;
	}

	return url;
}

void PrintURLContains(unique_ptr<CHttpUrl> const &url)
{
	cout << "=================" << endl;
	cout << "Protocol: " << url->ToStringProtocol() << endl;
	cout << "Domain name: " << url->GetDomain() << endl;
	cout << "Document: " << url->GetDocument() << endl;
	cout << "Port: " << url->GetPort() << endl;
	cout << "URL: " << url->GetURL() << endl;
	cout << "=================" << endl << endl;
}

void InteractWithUser()
{
	string inputStr;
	while (getline(cin, inputStr))
	{
		try
		{
			if (inputStr.empty())
			{
				throw invalid_argument("Input string+ is empty.");
			}

			auto args = ParseArgs(inputStr);
			auto url = MakePtrToUrl(args);

			if (!url)
			{
				throw invalid_argument("Invalid arguments count.");
			}

			PrintURLContains(url);
		}
		catch (invalid_argument const &err)
		{
			cout << err.what() << endl;
		}
		catch (...)
		{
			cout << "Unknow error type." << endl;
		}
	}
}

int main()
{
	InteractWithUser();
	return 0;
}

