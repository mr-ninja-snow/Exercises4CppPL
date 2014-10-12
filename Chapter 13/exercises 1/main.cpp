#include "header.h"

int main(int argc, const char* arfgv[])
{

	exercise_1::pFooFun f = exercise_1::foo;
	exercise_1::pFooFun2 f2 = exercise_1::foo;

	int temp = 33;
	f("\n\nhello ", temp);
	f2("\n\nhello ", temp);

	exercise_1::fooOfFoo(exercise_1::foo);

	exercise_1::pFooFun2 f3 = exercise_1::fooRetFoo(1);
	temp = 9;
	f3("\n\nf3 ", temp);

	exercise_1::pFooFun2 f4 = exercise_1::fooRetFoo(4);
	temp = 52;
	f4("\n\nf4 ", temp);

	return 0;
}
