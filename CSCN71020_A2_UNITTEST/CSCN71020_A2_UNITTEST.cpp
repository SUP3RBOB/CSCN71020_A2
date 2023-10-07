#include "pch.h"
#include "CppUnitTest.h"

extern "C" int getPerimeter(int*, int*);
extern "C" int getArea(int*, int*);
extern "C" void setLength(int, int*);
extern "C" void setWidth(int, int*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CSCN71020A2UNITTEST {
	TEST_CLASS(CSCN71020A2UNITTEST) {
	public:
		
		TEST_METHOD(CheckPerimeterCalculation) {
			int length = 2;
			int width = 2;
			int result = getPerimeter(&length, &width);
			Assert::AreEqual(8, result);
		}

		TEST_METHOD(CheckAreaCalculation) {
			int length = 6;
			int width = 3;
			int result = getArea(&length, &width);
			Assert::AreEqual(18, result);
		}

		TEST_METHOD(CheckLengthValidInput) {
			int length = 1;
			int input = 5;
			setLength(input, &length);
			Assert::AreEqual(input, length);
		}

		TEST_METHOD(CheckWidthValidInput) {
			int width = 1;
			int input = 99;
			setWidth(input, &width);
			Assert::AreEqual(input, width);
		}

		TEST_METHOD(CheckLengthInvalidInputUpperLimit) {
			int length = 1;
			int input = 100;
			setLength(input, &length);
			Assert::AreNotEqual(input, length);
		}

		TEST_METHOD(CheckLengthInvalidInputLowerLimit) {
			int length = 1;
			int input = 0;
			setLength(input, &length);
			Assert::AreNotEqual(input, length);
		}

		TEST_METHOD(CheckWidthInvalidInputUpperLimit) {
			int width = 1;
			int input = 100;
			setWidth(input, &width);
			Assert::AreNotEqual(input, width);
		}

		TEST_METHOD(CheckWidthInvalidInputLowerLimit) {
			int width = 1;
			int input = 0;
			setWidth(input, &width);
			Assert::AreNotEqual(input, width);
		}
	};
}
