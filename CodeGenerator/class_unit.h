#ifndef CLASS_UNIT_H
#define CLASS_UNIT_H

#include "unit.h"

// конкретная языковая конструкция класса некоторого языка
class ClassUnit : public Unit
{
public:
    // перечисление всех поддерживаемых модификаторов доступа всех поддерживаемых языков
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const std::string& name ) : name_( name ) {
        fields_.resize( ACCESS_MODIFIERS.size() );
    }
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        fields_[ accessModifier ].push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level ) + "class " + name_ + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( fields_[ i ].empty() ) {
                continue;
            }
            result += ACCESS_MODIFIERS[ i ] + ":\n";
            for( const auto& f : fields_[ i ] ) {
                result += f->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }

private:
    std::string name_; // имя создаваемого класса

    using Fields = std::vector<std::shared_ptr<Unit>>; // тип данных для набора полей класса, 1 филдс уже вектор

    std::vector<Fields> fields_; // каждому модификатору доступа соотвествует свой набор полей
};

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public",
"protected", "private" };

#endif // CLASS_UNIT_H
