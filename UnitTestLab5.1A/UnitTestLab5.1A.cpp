#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.1A/intRange.h"
#include "../lab5.1A/intRange.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest21
{
	TEST_CLASS(UnitTest21)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			intRange TEST(0, 4);
			Assert::AreEqual(TEST.rangeCheck(TEST, 3), true);
		}
	};
}
