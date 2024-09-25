#include "src/five.cpp"
#include <iostream>
#include <string>

int main()
{
    Five five1 = {2, 3, 4};
    std::cout << "five1 " << five1 << std::endl;

    Five five2 = {1, 1};
    std::cout << "five2 " << five2 << std::endl;
    Five result = five1 - five2;
    std::cout << "res " << result << std::endl;

    Five five3("12340");
    std::cout << "five3 : " << five3 << std::endl;

    Five five4 = five3;
    std::cout << "five4 - copy of five3: " << five4 << std::endl;

    Five five5 = std::move(five4);
    std::cout << "five5 (moved from five4): " << five5 << std::endl;
    std::cout << "five4 after move: " << five4 << std::endl;

    five1 = five2;
    std::cout << "five1 = five2 " << five1 << std::endl;

    five2 = std::move(five5);
    std::cout << "five2 move five5: " << five2 << std::endl;
    std::cout << "five5 after move: " << five5 << std::endl;

    std::cout << "five1 == five2" << (five1 == five2) << std::endl;

    std::cout << "five1 < five3" << (five1 < five3) << std::endl;

    std::cout << "five3 > five1" << (five3 > five1) << std::endl;

    Five five6 = five1 + five3;
    std::cout << "five6 = five1 + five3: " << five6 << std::endl;

    five6 += five2;
    std::cout << "five6 += five2 ==" << five6 << std::endl;

    Five five7 = five3 - five1;
    std::cout << "five7 = five3 - five1:" << five7 << std::endl;

    try
    {
        five7 -= five2;
        std::cout << "five7 after -= five2: " << five7 << std::endl;
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "Number for new object Five";
    std::string userInput;
    std::cin >> userInput;
    Five userFive(userInput);

    Five result = five3 + userFive;
    std::cout << "five3 + new Number: " << result << std::endl;

    return 0;
}
