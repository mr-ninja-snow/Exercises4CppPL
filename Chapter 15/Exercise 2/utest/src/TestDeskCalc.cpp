// #include "LoggerFactory.h"

// namespace
// {
// 	ILogger* g_pLogger = 0;
// 	char const cszLteBuildLabel[] = "test";
// 	char const cszConfigSpec[] = "test";
// }

// #define LOGGER_VAR ::g_pLogger
// #include "log_macros.h"
#include<iostream>
#include<sstream>
#include<string>
#include<iterator>
#include <fstream>
#include <limits>       // std::numeric_limits
#include <cmath>

#include <stdio.h>

#include "CppUTest/TestHarness.h"
#include "desk_calc.hpp"

// namespace desk_calc
// {

// bool g_bGetNextToken = false;

// }

namespace helper
{
	void PushInput(std::string const& inputString)
	{
		for (std::string::const_reverse_iterator rit=inputString.rbegin(); rit!=inputString.rend(); ++rit)
		{
			std::cin.putback(*rit);
		}
	}

	bool AreSame(double a, double b)
	{
		if( a==b || std::abs(a-b)<std::abs(std::min(a,b))*std::numeric_limits<double>::epsilon() ) { return true;}
		else { return false; }
	}

	double CalculateTest(std::string const& inputString)
	{
		helper::PushInput(inputString);

		token_parser::get_token();

		return desk_calc::desk_calc_impl::expr();
	}

	class RedirectCerr
	{
	public:
		RedirectCerr() : m_cerrBuffer{nullptr} {}
		~RedirectCerr()
		{
			ResetRedirect();
		}

		void Redirect()
		{
			m_cerrBuffer = std::cerr.rdbuf(); //save old buf
			std::cerr.rdbuf(m_ss.rdbuf()); //redirect std::cerr to out.txt!
		}

		void ResetRedirect()
		{
			if (m_cerrBuffer)
			{
				std::cerr.rdbuf(m_cerrBuffer);
				m_cerrBuffer = nullptr;
				m_ss.str("");
			}
		}

		std::string const GetLastErrorMsg() const
		{
			return m_ss.str();
		}

	private:
		std::streambuf*   m_cerrBuffer;
		std::stringstream m_ss;
	};

	void test()
	{
		std::string const input(".2.232\n");

		std::cout << helper::CalculateTest(input);
	}
}


TEST_GROUP(DeskCalc)
{
	TEST_SETUP()
	{
	}

	TEST_TEARDOWN()
	{
	}

};

TEST(DeskCalc, TestBasic_1_pluse_1)
{
	std::string const input("1+1\n");

	CHECK(helper::CalculateTest(input) == 2);
}

TEST(DeskCalc, TestBasic_1_times_1)
{
	std::string const input("1*1\n");

	CHECK(helper::CalculateTest(input) == 1);
}

TEST(DeskCalc, TestBasic_2_times_2)
{
	std::string const input("2*2\n");

	CHECK(helper::CalculateTest(input) == 4);
}

TEST(DeskCalc, TestBasic_4)
{
	std::string const input("99999999999-99999999998\n");

	CHECK(helper::CalculateTest(input) == 1);
}

TEST(DeskCalc, TestBasic_5)
{
	std::string const input("1+1+1\n");

	CHECK(helper::CalculateTest(input) == 3);
}

TEST(DeskCalc, TestBasic_6)
{
	std::string const input("1+1+1+1+1+1+1+1+1+1\n");

	CHECK(helper::CalculateTest(input) == 10);
}

TEST(DeskCalc, TestBasic_7)
{
	std::string const input("2/2\n");

	CHECK(helper::CalculateTest(input) == 1);
}

TEST(DeskCalc, TestBasic_8)
{
	std::string const input("1+1+1+1+1+1+1+1+1+1-1-1-1-1-1-1-1-1-1-1-1\n");

	CHECK(helper::CalculateTest(input) == -1);
}

TEST(DeskCalc, TestBasic_9)
{
	std::string const input("1\n");

	CHECK(helper::CalculateTest(input) == 1);
}

TEST(DeskCalc, TestBasic_10)
{
	std::stringstream ss;
	ss << std::numeric_limits<int>::max() << "\n";

	CHECK(helper::CalculateTest(ss.str()) == std::numeric_limits<int>::max());
}

TEST(DeskCalc, TestBasic_11)
{
	std::stringstream ss;
	ss << std::numeric_limits<int>::min() << "\n";

	CHECK(helper::CalculateTest(ss.str()) == std::numeric_limits<int>::min());
}

TEST(DeskCalc, TestBasic_12)
{
	// helper::test();
	std::stringstream ss;
	ss << std::numeric_limits<int>::max() << "+1\n";

	CHECK(int(helper::CalculateTest(ss.str())) == std::numeric_limits<int>::min());
}

TEST(DeskCalc, TestBasic_13)
{
	std::string const input("(1+1)*2\n");

	CHECK(helper::CalculateTest(input) == 4);
}

TEST(DeskCalc, TestBasic_14)
{
	std::string const input("1+1*2\n");

	CHECK(helper::CalculateTest(input) == 3);
}

TEST(DeskCalc, TestBasic_15)
{
	std::string const input("1+1*2/2\n");

	CHECK(helper::CalculateTest(input) == 2);
}

TEST(DeskCalc, TestBasic_16)
{
	std::string const input("((((1+1))))\n");

	CHECK(helper::CalculateTest(input) == 2);
}

TEST(DeskCalc, TestBasic_17)
{
	{
		std::string const input("1.1+1.5559\n");
		CHECK( helper::AreSame( helper::CalculateTest(input), 2.6559));
	}
	{
		std::string const input(" ( 1.1 ) + ( 1.5559 ) \n");
		CHECK( helper::AreSame( helper::CalculateTest(input), 2.6559));
	}
	{
		std::string const input(" ( 1.1 ) * ( 2 ) \n");
		CHECK( helper::AreSame( helper::CalculateTest(input), 2.2));
	}
	{
		std::string const input(" ( 3.33333 ) / ( 3 ) \n");
		CHECK( helper::AreSame( helper::CalculateTest(input), 1.11111));
	}
	{
		std::string const input(".33333\n");
		CHECK( helper::AreSame( helper::CalculateTest(input), 0.33333));
	}
}

// TEST(DeskCalc, TestBasic_18)
// {
// 	// std::string const input('\u0004');
// 	std::stringstream ss;
// 	ss << EOF; // EOF
// 	std::cout << token_parser::g_currToken;

// 	helper::CalculateTest(ss.str());
// 	std::cout << token_parser::g_currToken;
// 	CHECK(token_parser::g_currToken == token_parser::eTokenValue::END);

// 	// g_currToken
// }

TEST(DeskCalc, TestErrorMsg_1)
{
	helper::RedirectCerr redirCerr;
	redirCerr.Redirect();

	std::string const input("4?\n");
	helper::CalculateTest(input);

	CHECK(redirCerr.GetLastErrorMsg() == "error: '?' is a bad token!\n");
}

TEST(DeskCalc, TestErrorMsg_2)
{
	helper::RedirectCerr redirCerr;
	redirCerr.Redirect();

	std::string const input("a=\n");
	helper::CalculateTest(input);

	CHECK(redirCerr.GetLastErrorMsg() == "error: primary expected\n");
}

TEST(DeskCalc, TestErrorMsg_3)
{
	helper::RedirectCerr redirCerr;
	redirCerr.Redirect();

	std::string const input("(1+2\n");
	helper::CalculateTest(input);

	CHECK(redirCerr.GetLastErrorMsg() == "error: ) expected\n");
}

TEST(DeskCalc, TestErrorMsg_4)
{
	helper::RedirectCerr redirCerr;
	redirCerr.Redirect();

	std::string const input("33/0\n");
	helper::CalculateTest(input);

	CHECK(redirCerr.GetLastErrorMsg() == "error: divide by 0\n");
}

TEST(DeskCalc, TestAssign_1)
{
	{
		std::string const input("a=2\n");
		CHECK(helper::CalculateTest(input) == 2);
	}
	{
		std::string const input(" a = 2 \n");
		CHECK(helper::CalculateTest(input) == 2);
	}
	{
		std::string const input("b=4abdfasdkfhasjhd\n");
		CHECK(helper::CalculateTest(input) == 4);
	}
	{
		std::string const input("c=4.5\n");
		CHECK( helper::AreSame( helper::CalculateTest(input), 4.5));
	}

}

TEST(DeskCalc, TestAssign_2)
{
	{
		std::string const input("a=2\n");
		CHECK(helper::CalculateTest(input) == 2);
	}

	{
		std::string const input("a+a\n");
		CHECK(helper::CalculateTest(input) == 4);
	}

	{
		std::string const input("a+a+c\n");
		CHECK(helper::CalculateTest(input) == 4);
	}

	{
		std::string const input("a+a+c-MAX\n");
		CHECK(helper::CalculateTest(input) == 4);
	}

	{
		std::string const input("y*(a+a+c-max)\n");
		CHECK(helper::CalculateTest(input) == 0);
	}
}

TEST(DeskCalc, TestAssign_3)
{
	{
		std::string const input("b\n");
		CHECK(helper::CalculateTest(input) == 0);
	}

	{
		std::string const input("   b    \t\n");
		CHECK(helper::CalculateTest(input) == 0);
	}
}

TEST(DeskCalc, TestAssign_4)
{
	std::stringstream ss;
	ss << " max = " << std::numeric_limits<int>::max() << "\n";
	CHECK(helper::CalculateTest(ss.str()) == std::numeric_limits<int>::max());

	ss.str("");
	ss << " max + max " << "\n";
	CHECK( int(helper::CalculateTest(ss.str())) == std::numeric_limits<int>::min());
}



