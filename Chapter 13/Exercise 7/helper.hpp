#include <iterator>		// std::ostream_iterator

template <class T, std::size_t N>
std::ostream& operator<<(std::ostream& o, const std::array<T, N>& arr)
{
	copy(arr.cbegin(), arr.cend(), std::ostream_iterator<T>(o, " "));
	o << std::endl;
	return o;
}