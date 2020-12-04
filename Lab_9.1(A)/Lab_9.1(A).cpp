﻿#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Special { КІ, КБ, КН, СА, АЕ };

string s_special[] = { "Комп’ютерна інженерія ",
					   "Кібербезпека",
					   "Комп’ютерні науки",
					   "Системний аналіз",
					   "Атомна енергетика " };

struct student
{
	string prizv;
	int kurs;
	Special specialization;
	int phisuka;
	int matematic;
	int informatic;
};

void Create(student* s, const int kilkist);
void Print(student* s, const int kilkist);
double find_prozent(student* s, const int kilkist);
int find_studend(student* s, const int kilkist);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int kil_student;
	cout << "Введіть кількість студентів: "; cin >> kil_student;
	cout << endl;
	student* s = new student[kil_student];

	Create(s, kil_student);
	cout << endl;
	Print(s, kil_student);
	cout << endl;

	cout << "Процент студентів, які вчаться без трійок (на “відмінно” і “добре”): " << setprecision(2) << find_prozent(s, kil_student) << "%" << endl << endl;

	cout << "Прізвища студентів, які отримали з фізики оцінки '5' або '4': " << endl;
	if (find_studend(s, kil_student));
	else
		cout << "Прізвища студентів, які отримали з фізики оцінки '5' або '4' не знайшлося: " << endl << endl;

	delete[] s;
}

void Create(student* s, const int kilkist)
{
	int kurs, special;
	for (int i = 0; i < kilkist; i++)
	{
		cout << endl;
		cout << "студент № " << i + 1 << endl;

		cin.get();
		cin.sync();

		cout << "  прізвище: "; getline(cin, s[i].prizv);
		cout << "  курс: "; cin >> s[i].kurs;
		cout << "  спеціальність (0 - Комп’ютерна інженерія, 1 - Кібербезпека, 2 - Комп’ютерні науки, 3 - Системний аналіз, 4 - Атомна енергетика ): "; cin >> special;
		s[i].specialization = (Special)special;
		cout << "  оцінка з фізики: "; cin >> s[i].phisuka;
		cout << "  оцінка з математики: "; cin >> s[i].matematic;
		cout << "  оцінка з інформатики: "; cin >> s[i].informatic;
	}
}

void Print(student* s, const int kilkist)
{
	cout << "========================================================================================="
		<< endl;
	cout << "| №  | Прізвище     | Курс | Спеціальність         | Фізика | Математика  | Інформатика |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(22) << left << s_special[s[i].specialization] << ""
			<< "| " << setw(4) << right << s[i].phisuka << "   "
			<< "| " << setw(6) << right << s[i].matematic << "      "
			<< "| " << setw(6) << right << s[i].informatic << "      |" << endl;
	}
	cout << "=========================================================================================" << endl;
}

double find_prozent(student* s, const int kilkist)
{
	int k = 0;
	for (int i = 0; i < kilkist; i++)
		if (s[i].phisuka > 3 && s[i].matematic > 3 && s[i].informatic > 3)
			k++;
	return 100.0 * k / kilkist;
}

int find_studend(student* s, const int kilkist)
{
	int l = 0;
	for (int i = 0; i < kilkist; i++)
		if (s[i].phisuka > 3)
		{
			cout << "№ " << i + 1 << " " << s[i].prizv << " --- з фізики " << s[i].phisuka << endl;
			l = 1;
		}

	return l;
}