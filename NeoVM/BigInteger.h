#pragma once

#include <cstring>
#include "Types.h"

// Ported from 
// - https://referencesource.microsoft.com/#System.Numerics/System/Numerics/BigInteger.cs

class BigInteger
{
public:

	const static BigInteger Min;
	const static BigInteger One;
	const static BigInteger Zero;
	const static BigInteger MinusOne;

	BigInteger(int32 value);
	BigInteger(BigInteger *value);
	BigInteger(uint32 value);
	BigInteger(uint32 * value, int32 size);
	BigInteger(uint32* value, int32 size, bool negative);
	BigInteger(byte * value, int32 byteCount);

	BigInteger *Clone();
	void CopyInternal(int32 sign, uint32 *bits, int32 bitSize);

	bool ToInt32(int32 &ret);
	int32 ToByteArraySize();
	int32 ToByteArray(byte * output, int32 length);

	BigInteger* Div(BigInteger* reg);
	BigInteger* Mul(BigInteger* reg);
	BigInteger* Mod(BigInteger* reg);
	BigInteger* Add(BigInteger* reg);
	BigInteger* Sub(BigInteger* reg);
	BigInteger* And(BigInteger* reg);
	BigInteger* Or(BigInteger* reg);
	BigInteger* Xor(BigInteger* reg);
	BigInteger* Negate();
	BigInteger* Abs();
	BigInteger* Shl(int32 shift);
	BigInteger* Shr(int32 shift);
	int32 GetSign();

	int32 CompareTo(BigInteger bi);
	int32 CompareTo(BigInteger *bi);

	~BigInteger();

private:

	const static int32 Int32MaxValue = 0x7FFFFFFF;
	const static int32 Int32MinValue = 0x80000000;
	const static int32 UInt32MaxValue = 0xFFFFFFFF;
	const static int32 UInt32MinValue = 0x00000000;

	const static int32 knMaskHighBit = Int32MinValue;
	const static uint32 kuMaskHighBit = Int32MinValue;
	const static int32 kcbitUint = 32;
	const static int32 kcbitUlong = 64;
	const static int32 DecimalScaleFactorMask = 0x00FF0000;
	const static int32 DecimalSignMask = 0x80000000;

	int32 _sign;
	uint32 * _bits;
	int32 _bitsSize;

	static bool GetPartsForBitManipulation(BigInteger *x, uint32 * &xd, int32 &xl);

	void DangerousMakeTwosComplement(uint32 *d, int32 dSize);
	int32 ToUInt32Array(uint32 * &output);
	int32 Length(uint32 *rgu, int32 size);
	int32 GetDiffLength(uint32 *rgu1, uint32 * rgu2, int32 cu);
	BigInteger(int32 sign, uint32 *rgu, int32 rguSize);
};