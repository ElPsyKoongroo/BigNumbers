#include "BigNumbers.h"

UINT1024::UINT1024(uint64_t init)
{
	bitset<1000000> aux(init);
	num = aux;
}


UINT1024::UINT1024()
{
	bitset<1000000> aux(0x0);
	num = aux;
}

//UINT1024 UINT1024::operator+(UINT1024 num2)
//{
//	bool carry = false;
//	bool aux = false;
//	UINT1024 result;
//
//	for (int i = 0; i < size; i++)
//	{
//		aux = (num[i] ^ num2.num[i]);
//		result.set(i, aux ^ carry);
//		carry = (num[i] && num2.num[i]) || (carry && aux);
//	}
//	return result;
//}

UINT1024 UINT1024::operator+(UINT1024 num2)
{
	bool carry = false;
	unsigned long long aux = 0;
	uint64_t sizeOfGroup = 0;

	bool num1Smaller = getMax(this) < getMax(&num2);

	UINT1024 result;
	result.num = num1Smaller ? num2.num : this->num;

	uint64_t* r = (uint64_t*)&result.num;
	uint64_t* p = num1Smaller ? (uint64_t*)(&num) : (uint64_t*)(&num2.num);

	for (int i = 0; i < size/64; i++)
	{
		sizeOfGroup = 64 * i;

		if (*p == 0) {
			*r++ = 0;
			continue;
		}

		*r += (*p++ + carry);
		carry = (num[sizeOfGroup + 63] && num2.num[ sizeOfGroup + 63]);

	}
	return result;
}







void UINT1024::operator=(UINT1024 num2)
{
	this->num = num2.num;
}

string UINT1024::ToString()
{
	int max = -1;

	for(int i = size-1; i >= 0; i--)
	{
		if (this->num.test(i))
		{
			max = i;
			break;
		}
	}

	//if (max < 64)
	//{
	//	if (max == -1) return "0";
	//	else { return to_string(this->num.to_ullong()); }
	//}

	int decDigits = max * log10(2) + 1;

	int* res;
	//res = new int[decDigits];

	int* aux; 
	aux = new int[decDigits];

	res = (int*)calloc(decDigits, sizeof(int));

	aux[0] = 1;
	res[0] = 0;
	int resSize = 0;
	int auxSize = 0;

	for (int i = 0; i <= max; i++)
	{
		if(i) auxSize += MultBy2(aux, auxSize);

		if (num.test(i))
		{
			resSize += Sum2Arr(res, aux, auxSize, resSize);
		}
	}

	stringstream stream;

	ofstream file;

	file.open("pipo.txt", ios::trunc);

	for (int i = decDigits-1; i >= 0; i--)
	{
 		stream << res[i];
	}
	file << stream.str().c_str();
	file.close();


	return stream.str();
}

bool UINT1024::MultBy2(int* arr, int size)
{
	short aux, carry = 0;

	if (size == this->size-1) size--;

	for (int i = 0; i <= size; i++)
	{
		aux = arr[i]*2 + carry;

		arr[i] = aux % 10;
		carry = aux / 10;
	}

	if (carry)
	{
		arr[size + 1] = 1;
	}
	return carry;
}

bool UINT1024::Sum2Arr(int arr1[], int arr2[], int size, int resSize)
{
	uint8_t carry = 0;
	uint8_t aux = 0;
	int actualSize = 0;

	for(int x = 0; x <= size; x++){

		aux = (arr1[x] + arr2[x] + carry);
		arr1[x] = (aux) % 10;
	    carry = (aux)/10;
		actualSize++;
	}
	while (carry)
	{
		if (size == this->size) break;
		aux = arr1[actualSize+1] + carry;
		arr1[actualSize+1] = aux % 10;
		carry = aux / 10;
		actualSize++;
	}

	return actualSize - 1 > resSize;
}

long long UINT1024::value()
{
	return this->num.to_ullong();
}

uint64_t UINT1024::getMax(const UINT1024* u)
{
	int max = -1;

	for (int i = size - 1; i >= 0; i--)
	{
		if (u->num.test(i))
		{
			max = i;
			break;
		}
	}

	return max;
}

void UINT1024::set(long long pos)
{
	num.set(pos);
}

void UINT1024::set(long long pos, bool value)
{
	num.set(pos, value);
}

void UINT1024::reset(short pos)
{
	num.reset(pos);
}

bool UINT1024::get(short pos)
{
	return num.test(pos);
}