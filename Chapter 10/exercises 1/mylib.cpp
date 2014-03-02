#include "mylib.h"
/*#include <assert.h>


std::string lang1[] = {"spring", "summer", "autumn", "winter"};
std::string lang2[] = {"весна", "лето", "осень", "зима"};
std::string* pLang = lang1;

Seasons& operator++(Seasons &s)
{
	assert(s != Seasons::winter);
	s = static_cast<Seasons>(static_cast<int>(s) + 1);
	return s;
}

Seasons &operator--(Seasons &s)
{
	assert(s != Seasons::spring);
	s = static_cast<Seasons>(static_cast<int>(s) - 1);
	return s;
}

std::ostream& operator<<(std::ostream& stream, Seasons s)
{
	stream << pLang[static_cast<int>(s)];
	return stream;
}

std::istream& operator>>(std::istream& stream, Seasons& s)
{
	std::string input;
	std::cout << "\n\nEnter a season: ";
	stream >> input;
	s = static_cast<Seasons>(lookForSeason(input));
}

short lookForSeason(std::string s)
{
	for (int i = 0; i < 4 sizeof(lang1); ++i)
	{
		if (std::string(pLang[i]) == s )
		{
			return i;
		}
	}

	//std::cout << "\n\nThis \"" << s << "\" isn't a season! Assigning the default season!";
	return 3;
}*/



double expr(bool get)
{
	double left = term(get);
	for (;;)
	{
		switch(ts.current().kind)
		{
			case Kind::plus:
				left += term(true);
				break;
			case Kind::minus:
				left -= term(true);
				break;
			default:
				return left;
		}
	}
}


double term(bool get)
{
	double left = prim(get);
	for (;;)
	{
		switch(ts.current().kind)
		{
			case Kind::mul:
				left *= prim(true);
				break;
			case Kind::div:
				if (auto d = prim(true))
				{
					left /= d;
					break;
				}
				return error("Divide by 0");
			default:
				return left;
		}
	}
}

double prim (bool get)
{
	if (get)
	{
		ts.get(); //read next token
	}

	switch(ts.current().kind)
	{
		case Kind::number:
		{
			double v = ts.current().number_value;
			ts.get();
			return v;
		}
		case Kind::name:
		{
			double& v = table[ts.current().string_value];

			if (ts.get().kind == Kind::assign) v = expr(true);
			
			return v;
		}
		case Kind::minus:
			return -prim(true);
		case Kind::lp:
		{
			auto e = expr(true);

			if (ts.current().kind != Kind::rp) return error("')' expected");

			ts.get();

			return e;
		}
		default:
			return error("primary expected");
	}
}