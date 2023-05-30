#include <iostream>
#include "class_unit.h"
#include "print_operator_unit.h"
#include "method_unit.h"

// общая функция, генерирующая код программы
// в качестве аргумента принимает языковую фабрику,через которую происходит работа с Unit'ами языка
std::string GenerateProgram()
{
    ClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
    );

    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL |
        MethodUnit::CONST ),
        ClassUnit::PUBLIC
    );

    auto method = std::make_shared< MethodUnit >( "testFunc4", "void", MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );

    return myClass.compile();
}

int main(int argc, char *argv[])
{
    std::cout << GenerateProgram() << std::endl;
    std::cout << std::endl;
	return 0;
}
