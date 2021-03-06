#include <iostream>		//std::cout, std::cerr
#include <algorithm>	//std::sort
#include "vlib.hpp"

namespace exercise_7{

	using CFT = int(const void*, const void*);

	int intCmp(const void* a, const void* b)
	{
		const int* _a = reinterpret_cast<const int*>(a);
		const int* _b = reinterpret_cast<const int*>(b);

		return (*_a < *_b) ? -1 : ((*_a > *_b) ? 1 : 0);
	}

	void ssort(void* base, size_t n, size_t sz, CFT cmp)
	{
		for (int gap=n/2; 0<gap; gap/=2)
		{
			for (int i=gap; i!=n; i++)
				for (int j=i-gap; 0<=j; j-=gap)
				{
					char* b = static_cast<char*>(base);     // necessary cast
					char* pj = b+j*sz;                 // &base[j]
					char* pjg = b+(j+gap)*sz;          // &base[j+gap]

					if (cmp(pjg,pj)<0)           // swap base[j] and base[j+gap]:
					{
						for (int k=0; k!=sz; k++)
						{
							char temp = pj[k];

							pj[k] = pjg[k];
							pjg[k] = temp;
						}
					}
				}
		}
	}

	void newSsort(void* base, size_t n, size_t sz, CFT cmp)
	{
		std::sort(reinterpret_cast<int*>(base), reinterpret_cast<int*>(base) + n + 1);
	}

}//namespace exercise_7
