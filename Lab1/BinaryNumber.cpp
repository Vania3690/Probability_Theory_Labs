#include "BinaryNumber.h"

BinaryNumber BinaryNumber::complement(BinaryNumber b)
{
	if (data.size() >= b.data.size())
		throw BoundsException();

	data.resize(b.data.size());

	return *this;
}

std::string BinaryNumber::cutZeros(std::string s)
{
	int i = 0;
	std::string res;
	while (s[i] != '1' & i < s.size()) i++;
	while (i < s.size()) res += s[i++];
	return res;
}

/*Unused
std::string BinaryNumber::invert(std::string s)
{
	std::string res;
	for (int i = s.size() - 1; i >= 0; i--)
		res += s[i];
	return res;
}
*/
BinaryNumber::BinaryNumber() : data(0)
{
}

BinaryNumber::BinaryNumber(uint64_t num) : data(num)
{
}

BinaryNumber::BinaryNumber(std::initializer_list<uint64_t> list)
{
	for each (auto var in list)
		data.push_front(var);
}

BinaryNumber BinaryNumber::operator+(BinaryNumber n)
{
	if (n.data.size() > data.size())
		complement(n);
	else
		n.complement(*this);

	for (auto i1 = n.data.begin(), i2 = data.begin();
		 i1 != n.data.end() & i2 != data.end();
		 i1++, i2++)
		*i1 += *i2;

	return n;
}

bool BinaryNumber::operator[](size_t el)
{
	size_t num = el / BITS_PER_NUMBER;
	el %= BITS_PER_NUMBER;
	if (num < data.size())
		return ((1 << el) & data[num]) >> el;
	else
		return 0;
}

std::string BinaryNumber::print()
{
	std::string s;
	for each (auto var in data)
		for (int i = 0; i < BITS_PER_NUMBER; i++)
			s = ((1 << i & var) >> i ? '1' : '0') + s;
	return cutZeros(s);
}

BinaryNumber::~BinaryNumber()
{
}
