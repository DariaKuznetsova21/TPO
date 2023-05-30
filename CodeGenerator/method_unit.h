#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H

#include "unit.h"

// конкретная языковая конструкция метода некоторого языка
class MethodUnit : public Unit
{
public:
	// перечисление всех поддерживаемых модификаторов методов всех поддерживаемых языков
	enum Modifier
	{
		STATIC = 1,
		CONST = 1 << 1, // используются битовые флаги, то есть они могут быть установлены независимо, например STATIC | CONST
		VIRTUAL = 1 << 2,
	};

public:
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags)//конструктор по умолчанию с 3 переменными
		: name_(name)
		, return_type_(returnType)
		, flags_(flags)
	{}

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {
        body_.push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift( level );
        if( flags_ & STATIC ) {
            result += "static ";
        } else if(flags_ & VIRTUAL ) {
            result += "virtual ";
        }
        result += return_type_ + " ";
        result += name_ + "()";
        if( flags_ & CONST ) {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : body_ ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
        }
private:
	std::string name_; // имя метода
	std::string return_type_; // тип возвращаемого методом значения

	Flags flags_; // выбранные модификаторы метода

	std::vector<std::shared_ptr<Unit>> body_; // тело метода в котором хранятся принадлежащие ему языковые конструкции
};

#endif // METHOD_UNIT_H
