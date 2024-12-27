#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <sstream>

int main()
{
    class Expression
    {
        std::string expression;
    };
    class Calculator
    {
        std::string userInput; 

        // Define a function type
        typedef long double (*FuncPtr)(long double, long double);
        typedef long double (*FuncPtr)(long double);

        // Create a map to store functions
        std::map<std::string, FuncPtr> funcDict;

        public:
        Calculator()
        {
            // Initialize the map with some functions
            funcDict["+"] = [](long double a, long double b) { return a + b; };
            funcDict["-"] = [](long double a, long double b) { return a - b; };
            funcDict["*"] = [](long double a, long double b) { return a * b; };
            funcDict["^"] = [](long double a, long double b) { return std::pow(a,b); };
            funcDict["sin("] = [](long double a) { return std::sin(a); };
            funcDict["cos("] = [](long double a, long double b = NULL) { return std::cos(a); };
        }
        /*
        This function will calculate a simple expression by parsing the relevant operator.
        */
        long double calculate(std::string userInput)
        {
            // calculatorInput calculatorInput;
            // userInput = calculatorInput.parseInput(userInput);
        };


        private:
        double extractUnaryArgs(std::string text, size_t operator_index, bool arg_on_right_side = true)
        {
            const std::string digits = "0123456789";
            double x = 0.0;

            unsigned ipos = text.find_first_not_of( digits, operator_index);

            if ( ipos != std::string::npos ){
                std::stringstream( text.substr( ipos ) ) >> x;
            }
            else{
                std::cout << "No number found\n";
            }

            return x;
        }

        double extractBinaryArgs(std::string text, size_t operator_index )
        {
            const std::string digits = "0123456789";
            double x = 0.0;

            unsigned ipos = text.find_first_not_of( digits );

            if ( ipos != std::string::npos ){
                std::stringstream( text.substr( ipos ) ) >> x;
            }
            else{
                std::cout << "No number found\n";
            }

            return x;
        }

        double extractFuncArgs(std::string text, size_t operator_index, int num_args )
        {
            double args[num_args];

            const std::string digits = "0123456789";
            double x = 0.0;

            unsigned ipos = text.find_first_not_of( digits );

            if ( ipos != std::string::npos ){
                std::stringstream( text.substr( ipos ) ) >> x;
            }
            else{
                std::cout << "No number found\n";
            }

            return x;
        }

        void calculateParantheses(std::string userInput)
        {
            // input.getUserInput();
            size_t parentheses_index = userInput.find('(');
            // size_t parentheses_index = userInput.find_first_of('(',parentheses_index);

            std::string::iterator it = std::find_if( parentheses_index, userInput.end(), isalpha);
            if ( it != userInput.end() ) {
                std::cout << "found\n";
            }
            else {
                std::cout << "not found\n";
            }

        };

        void calculateExponential()
        {
        };

        void calculateMultiplication()
        {
        };

        void calculateDivision()
        {
        };

        void calculateAddition()
        {
        };

        void calculateSubtraction()
        {
        };

    };

    class calculatorInput
    {
        Calculator calculator;

        public:
        std::string calculatorInput;
        
        std::string parseInput(std::string userInput)
        {
            calculatorInput = userInput;
            calculatorInput.erase (std::remove (calculatorInput.begin(), calculatorInput.end(), ' '), calculatorInput.end());
            // calculatorInput.erase (std::remove (calculatorInput.begin(), calculatorInput.end(), isalpha), calculatorInput.end());
            return calculatorInput;
        }

        size_t findInnermostParantheses(std::string userInput)
        {
            const unsigned int totalNumParantheses = count(userInput.begin(), userInput.end(), '(');
            unsigned int numParantheses = 0;
            size_t index = 0;

            for (int i=0; i == totalNumParantheses; ++i)
            {
                index = userInput.find('(',index);
                if (userInput.find(')',index))
                {
                    break;
                } else {
                    ++numParantheses;
                };
            }
            return index;
        };

        std::string simplifyInnermostExpression(std::string userInput )
        {
            size_t expression_index_start = findInnermostParantheses(userInput);
            size_t expression_index_end = userInput.find(')',expression_index_start);
            std::string expression = userInput.substr(expression_index_start,expression_index_end);
            long double result = calculator.calculate(expression);
            return std::to_string(result);
        };

        // std::string getUserInput()
        // {
        //     return userInput;
        // }

        // void settUserInput(std::string input)
        // {
        //     userInput = input;
        // }

    };
    // 
    // class StringParser
    // {
    //     public
    // }

    std::cout << "Enter expression to calculate:" << std::endl;
    // std::cin >> userInput;

    return 0;
}