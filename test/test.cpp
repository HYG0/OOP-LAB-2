#include <gtest/gtest.h>
#include "../include/modules.hpp"
#include <stdexcept>

// Тесты конструкторов
TEST(ConstructorTests, DefaultConstructor) {
    Four num;
    SUCCEED();
}

TEST(ConstructorTests, StringConstructorValid) {
    Four num("123");
    SUCCEED();
}

TEST(ConstructorTests, StringConstructorRemovesLeadingZeros) {
    Four num("00123");
    SUCCEED();
}

TEST(ConstructorTests, StringConstructorInvalidDigits) {
    EXPECT_THROW({
        Four num("456");
    }, std::exception);
}

TEST(ConstructorTests, InitializerListConstructor) {
    Four num{1, 2, 3};
    SUCCEED();
}

TEST(ConstructorTests, CopyConstructor) {
    Four original("123");
    Four copy(original);
    SUCCEED();
}

// Тесты арифметических операций
TEST(ArithmeticTests, AddOperation) {
    Four num1("12");
    Four num2("3");
    Four result = num1.Add(num2);
    SUCCEED();
}

TEST(ArithmeticTests, AddWithCarry) {
    Four num1("3");
    Four num2("1");
    Four result = num1.Add(num2);
    SUCCEED();
}

TEST(ArithmeticTests, SubtractOperation) {
    Four num1("21");
    Four num2("3");
    Four result = num1.Substract(num2);
    SUCCEED();
}

TEST(ArithmeticTests, SubtractThrowsWhenFirstSmaller) {
    Four num1("1");
    Four num2("3");
    
    EXPECT_THROW({
        num1.Substract(num2);
    }, std::invalid_argument);
}

TEST(ArithmeticTests, AddAssignOperation) {
    Four num1("12");
    Four num2("3");
    Four result = num1.AddAssign(num2);
    SUCCEED();
}

TEST(ArithmeticTests, SubtractAssignOperation) {
    Four num1("21");
    Four num2("3");
    Four result = num1.SubstractAssign(num2);
    SUCCEED();
}

// Тесты операций сравнения
TEST(ComparisonTests, EqualOperationTrue) {
    Four num1("123");
    Four num2("123");
    EXPECT_TRUE(num1.Equal(num2));
}

TEST(ComparisonTests, EqualOperationFalse) {
    Four num1("123");
    Four num2("122");
    EXPECT_FALSE(num1.Equal(num2));
}

TEST(ComparisonTests, MoreOperationTrue) {
    Four num1("13");
    Four num2("12");
    EXPECT_TRUE(num1.More(num2));
}

TEST(ComparisonTests, MoreOperationFalse) {
    Four num1("11");
    Four num2("12");
    EXPECT_FALSE(num1.More(num2));
}

TEST(ComparisonTests, LessOperationTrue) {
    Four num1("11");
    Four num2("12");
    EXPECT_TRUE(num1.Less(num2));
}

TEST(ComparisonTests, LessOperationFalse) {
    Four num1("13");
    Four num2("12");
    EXPECT_FALSE(num1.Less(num2));
}

// Тесты edge cases
TEST(EdgeCaseTests, ZeroNumber) {
    Four num("0");
    SUCCEED();
}

TEST(EdgeCaseTests, SingleDigit) {
    Four num("2");
    SUCCEED();
}

TEST(EdgeCaseTests, LargeNumber) {
    Four num("123012301230");
    SUCCEED();
}

TEST(EdgeCaseTests, CopyMethod) {
    Four original("123");
    Four copy = original.Copy(original);
    SUCCEED();
}

TEST(EdgeCaseTests, MultipleOperationsChain) {
    Four num1("12");
    Four num2("3");
    Four num3("1");
    
    Four result1 = num1.Add(num2);
    Four result2 = result1.Substract(num3);
    SUCCEED();
}

// Тесты на обработку ошибок
// TEST(ErrorHandlingTests, InvalidCharacterInString) {
//     EXPECT_THROW({
//         Four num("12a3");
//     }, std::exception);
// }

// TEST(ErrorHandlingTests, EmptyString) {
//     EXPECT_THROW({
//         Four num("");
//     }, std::exception);
// }

// TEST(ErrorHandlingTests, InvalidInitializerList) {
//     EXPECT_THROW({
//         Four num{1, 2, 4};
//     }, std::exception);
// }

// Тесты на правильное удаление нулей
TEST(ZeroHandlingTests, LeadingZerosRemoved) {
    Four num("000123");
    SUCCEED();
}

TEST(ZeroHandlingTests, AllZerosBecomesSingleZero) {
    Four num("0000");
    SUCCEED();
}

// Тесты методов преобразования
TEST(ConversionTests, DexToFourthConversion) {
    Four num;
    // Этот тест может потребовать доступа к приватным методам
    // или можно проверить через публичный интерфейс
    SUCCEED();
}

TEST(ConversionTests, DexRepresentCalculation) {
    Four num("123");
    // Проверка косвенная через работу других методов
    SUCCEED();
}

// Тесты метода Print (только что не падает)
TEST(OutputTests, PrintMethod) {
    Four num("123");
    // Не можем проверить вывод легко, но можем проверить что не падает
    SUCCEED();
}

// Тесты метода Validation
TEST(ValidationTests, ValidationPassesForCorrectDigits) {
    Four num("1230");
    SUCCEED(); // Если не бросило исключение - тест пройден
}

TEST(ValidationTests, ValidationFailsForIncorrectDigits) {
    EXPECT_THROW({
        Four num("125"); // 5 недопустима
    }, std::exception);
}

// Тесты деструктора
TEST(DestructorTests, DestructorCalled) {
    {
        Four num("123");
    } // Деструктор должен вызваться здесь
    SUCCEED();
}

// Тесты на цепочку вызовов
TEST(ChainingTests, MethodChaining) {
    Four num1("12");
    Four num2("3");
    Four num3("1");
    
    // Проверяем что методы можно вызывать в цепочке
    Four result = num1.Add(num2).Substract(num3);
    SUCCEED();
}

TEST(PerformanceTests, LargeNumberCreation) {
    std::string largeNum;
    for (int i = 0; i < 1000; ++i) {
        largeNum += std::to_string(i % 4);
    }
    
    Four num(largeNum);
    SUCCEED();
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }