#include "pch.h"
#include <cmath>
#include "CppUnitTest.h"
#include "C:\Users\user\Desktop\Учеба\ОІПЗ\Лаб 5\Код\Lab5\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestPositiveX)
        {
            double result = calculate_y(2, 10.0);
            Assert::IsTrue(std::isinf(result), L"Результат НЕ нескінченність (як очікувалось)");
        }

        TEST_METHOD(TestNegativeX)
        {
            Assert::AreEqual(0.0, calculate_y(2, -10.0));
        }

        TEST_METHOD(TestInvalidN)
        {
            try {
                calculate_y(0, 5.0);
                Assert::Fail(L"Недопустиме n");
            }
            catch (const invalid_argument& e) {
                Assert::AreEqual("n повинно бути більше 0", e.what());
            }
        }

        TEST_METHOD(TestLargeN)
        {
            double result = calculate_y(100, 3.0);
            Assert::IsTrue(std::isinf(result), L"Результат НЕ нескінченність (як очікувалось)");
        }
    };
}
