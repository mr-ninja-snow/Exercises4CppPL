#include <string>
#include <array>
#include "timer.hpp"
#include "helper.hpp"

#ifndef VLIB_H
#define VLIB_H

namespace exercise_7{

	using CFT = int(const void*, const void*);
	int intCmp(const void* a, const void* b);

	void ssort(void* base, size_t n, size_t sz, CFT cmp);
	void newSsort(void* base, size_t n, size_t sz, CFT cmp);

	void printIntArrayWithMsg(int arr[], size_t size,const std::string msg);

	using SSF = void(void*, size_t, size_t, CFT);
	template<typename T, std::size_t SIZE>
	float sort(std::array<T, SIZE> fooArray, SSF sortFunc)
	{
		vTimer::Timer t;
		std::cout <<  "\nBefore sorting:\n\t" << fooArray;

		t.startTimer();
		sortFunc(fooArray.data(), fooArray.size(), sizeof(T), exercise_7::intCmp);
		t.stopTimer();

		std::cout <<  "\nAfter sorting:\n\t" << fooArray;
		std::cout << "duration: " << t.getResult() << "s" << std::endl;

		return t.getResult();
	}

}

#endif