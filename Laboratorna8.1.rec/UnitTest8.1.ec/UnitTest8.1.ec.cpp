#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna8.1.rec/Laboratorna8.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81ec
{
	TEST_CLASS(UnitTest81ec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "This + is a - test = string";
			char dest[151];
			dest[0] = '\0';

			char* result = Change(dest, str, 0, 0);

			Assert::AreEqual("This + is a - test = string", str);
			Assert::AreEqual("This ** is a ** test ** string", result);
		}
	};
}
