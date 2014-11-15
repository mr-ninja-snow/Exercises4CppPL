
#ifndef VLIB_H
#define VLIB_H

namespace exercise_4{

	enum {
		eStaringIndex = 1
	};

	int ArgProc(const int argc, const char* argv[]) noexcept;
	void OutputContentsOfFile(const char*);

}

#endif