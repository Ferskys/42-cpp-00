#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) 
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string str(argv[i]);
            for (std::string::size_type j = 0; j < str.length(); j++)
            {
                if (std::isalpha(str[j]))
                {
                    if (std::islower(str[j]))
                        std::cout << static_cast<char>(std::toupper(str[j]));
                    else
                        std::cout << str[j];
                }
                else
                    std::cout << str[j];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
}