#include <iostream>
#include <string>

enum class Seasons:short { spring, summer, autumn, winter };

Seasons &operator++(Seasons &s);
Seasons &operator--(Seasons &s);
std::ostream& operator<<(std::ostream& stream, Seasons s);
std::istream& operator>>(std::istream& stream, Seasons& s);
short lookForSeason(std::string s);



enum class Kind : char{ name, number, end, plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')' };

struct Token
{
	Kind kind;
	string string_value;
	double number_value;
};

class Token_stream
{
public:
	Token get();
	const Token& current;
	//
};

double expr(bool get);