#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <array>

using namespace std;
class UINT1024
{
private:
	
	const int size = 1024;
	uint32_t Base32[16];

public:
	bitset<1024> num{ 0x0 };
	UINT1024(uint64_t init);
	UINT1024();

#pragma region OPERATORS

	UINT1024 operator+(UINT1024 num2);
	UINT1024 operator+(int num2);
	UINT1024 operator+(long long num2);

	UINT1024 operator-(UINT1024 num2);
	UINT1024 operator-(int num2);
	UINT1024 operator-(long long num2);

	UINT1024 operator/(UINT1024 num2);
	UINT1024 operator/(int num2);
	UINT1024 operator/(long long num2);

	UINT1024 operator*(UINT1024 num2);
	UINT1024 operator*(int num2);
	UINT1024 operator*(long long num2);

	UINT1024 operator%(UINT1024 num2);
	UINT1024 operator%(int num2);
	UINT1024 operator%(long long num2);

	void operator=(UINT1024 num2);
	friend ostream& operator<<(ostream& ss, UINT1024& s);


#pragma endregion

	
	string ToString();

	bool MultBy2(int arr[], int size);
	string BitsToDecimal();
	string FastB2DConversion();
	void DivTwoWords(uint64_t a, uint64_t b, uint32_t c, uint32_t* r, uint32_t* rest);
	bool IsSetToZero(uint32_t& iterator, uint32_t* lista);
	bool Sum2Arr(int arr1[], int arr2[], int size, int resSize);

	long long value();

	uint64_t getMax(const UINT1024* u);
	void leftShift(uint8_t BCD[], uint8_t sizeBCD);

	void set(long long);
	void set(long long,bool);
	void reset(short);
	bool get(short);
};