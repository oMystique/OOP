// People.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "People.h"
#include <iostream>

using namespace std;

int main()
{
	CAdvancedStudent student("Alexey", "Ildarkin", "Andreevich", "Ust-Barguzin ul. Lenina d. 88 kv. 42", "PGTU", 951045, "Klassificatsiya molluskov");

	cout << student.GetName() << endl;
	cout << student.GetSurName() << endl;
	cout << student.GetPatronymic() << endl;
	cout << student.GetAddress() << endl;
	cout << student.GetUniversityName() << endl;
	cout << student.GetStudentCardNumber() << endl;
	cout << student.GetDissertationTopic() << endl;

	cout << endl << "===" << endl << endl;

	CWorker worker("Alexey", "Ildarkin", "Andreevich", "Uranovaya shahta nomer 9", "Sobiratel alpha-chastic");
	cout << worker.GetName() << endl;
	cout << worker.GetSurName() << endl;
	cout << worker.GetPatronymic() << endl;
	cout << worker.GetAddress() << endl;
	cout << worker.GetSpeciality() << endl;

    return 0;
}

