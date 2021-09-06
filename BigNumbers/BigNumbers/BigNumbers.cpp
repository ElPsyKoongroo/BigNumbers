#include "BigNumbers.h"

UINT1024::UINT1024(uint64_t init)
{
	bitset<1024> aux(init);
	num = aux;
}
UINT1024::UINT1024()
{
	bitset<1024> aux(0x0);
	num = aux;
}

<<<<<<< Updated upstream
UINT1024 UINT1024::operator+(UINT1024 num2)
{
	bool carry = false;
	uint64_t aux = 0;
	int sizeOfGroup = 0;
	int sizeOfGroupOffset = 0;

=======
#pragma region	OPERATORS

UINT1024 UINT1024::operator+(UINT1024 num2)
{
	bool carry = false;
	unsigned long long aux = 0;
	int sizeOfGroup = 0;
	int sz = 0;
>>>>>>> Stashed changes
	UINT1024 result = 0;
	uint64_t* r = (uint64_t*)&result.num;
	uint64_t* p = (uint64_t*)(&num);
	uint64_t* n = (uint64_t*)(&num2.num);


	for (int i = 0; i < size / 64; i++)
	{
<<<<<<< Updated upstream
		sizeOfGroup += 64;
		sizeOfGroupOffset = sizeOfGroup + 63;
=======
		//if (i == 15) break
		sz = sizeOfGroup + 63;
>>>>>>> Stashed changes
		if (!*p && !*n) {
			*r++ = carry;
			p++; n++;
			continue;
		}

		aux = (*p++ + *n++ + carry);
<<<<<<< Updated upstream
		carry = (num[sizeOfGroupOffset] && num2.num[sizeOfGroupOffset]);
=======
		carry = (num[sz] && num2.num[sz]);
>>>>>>> Stashed changes

		*r++ = aux;
		sizeOfGroup += 64;
	}
	return result;
}


<<<<<<< Updated upstream



=======
>>>>>>> Stashed changes
void UINT1024::operator=(UINT1024 num2)
{
	this->num = num2.num;
}
#pragma endregion

#pragma region PUBLICMETHODS

string UINT1024::ToString()
{
	int max = getMax(this);

	//if (max < 64)
	//{
	//	if (max == -1) return "0";
	//	else { return to_string(this->num.to_ullong()); }
	//}

	int decDigits = max * log10(2) + 2;

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

string UINT1024::BitsToDecimal() {
	int max = getMax(this);
	int DigitsSize = max * log10(2) + 1;
	vector<bool> BCD(DigitsSize * 2, 0);

	for (int i = 0; i <= max; i++) {
		rotate(BCD.begin(), BCD.begin() + 1, BCD.end());
		BCD[0] = num[max - i];
		for (int j = 0; j <= max / 4; j++) {




		}

	}








	return NULL;
}

#pragma endregion

#pragma region PRIVATEMETHODS

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
		aux = arr1[actualSize] + carry;
		arr1[actualSize] = aux % 10;
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
	uint64_t* BitGroup = (uint64_t*)&(u->num);
	BitGroup += 15;

	for (int i = size/64 - 1; i >= 0; i--)
	{
		if (*BitGroup)
		{
			return log2(*BitGroup) + 64*i; // Devuelve la posicion del primer uno.
		}
		BitGroup--;
	}

	return -1;
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

#pragma endregion