#include <string>

#ifndef VLIB_H
#define VLIB_H

namespace exercise_7{

	using CFT = int(const void*, const void*);
	int intCmp(const void* a, const void* b);

	void ssort(void* base, size_t n, size_t sz, CFT cmp);
	void newSsort(void* base, size_t n, size_t sz, CFT cmp);

	void printIntArrayWithMsg(int arr[], size_t size,const std::string msg);

}

#endif