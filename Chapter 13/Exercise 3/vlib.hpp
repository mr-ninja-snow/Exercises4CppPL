
#ifndef VLIB_H
#define VLIB_H

namespace exercise_3{

	enum {
		eStaringIndex = 1
	};

	int ArgProc(const int argc, const char* argv[]) noexcept;
	void PrintHelloForName(const char* name);

}

#endif