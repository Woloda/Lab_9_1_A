#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1(A)/Lab_9.1(A).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab91A
{
	TEST_CLASS(UnitTestLab91A)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int kil_student = 2;
			student* s = new student[kil_student];
			s[0].prizv = "wowa";                  s[1].prizv = "qqq";
			s[0].kurs = 1;                        s[1].kurs = 2;
			s[0].specialization = (Special)0;     s[1].specialization = (Special)1;
			s[0].phisuka = 4;                     s[1].phisuka = 2;
			s[0].matematic = 4;                   s[1].matematic = 3;
			s[0].informatic = 5;                  s[1].informatic = 5;

			double l = find_prozent(s, kil_student);

			Assert::AreEqual(l, 50.0);
		}
	};
}
