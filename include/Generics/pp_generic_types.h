#pragma once

template<typename T32BITS, typename T64BITS, int ptrSize>
struct SelectIntPointerType
{
	// nothing here are is it an error if the partial specializations fail
};

template<typename T32BITS, typename T64BITS>
struct SelectIntPointerType<T32BITS, T64BITS, 8>
{
	using TIntPtr = T64BITS;
};

template<typename T32BITS, typename T64BITS>
struct SelectIntPointerType<T32BITS, T64BITS, 4>
{
	using TIntPtr = T32BITS;
};

///
struct GenericPlatformTypes
{
	// Unsigned base types
	using uint8 = unsigned char;
	using uint16 = unsigned short int;
	using uint32 = unsigned int;
	using uint64 = unsigned long long;

	// Signed base types
	using int8 = signed char;
	using int16 = signed short int;
	using int32 = signed int;
	using int64 = signed long long;

	// Character types
	using ANSICHAR = char;
	using WIDECHAR = wchar_t;
	using CHAR8 = uint8;
	using CHAR16 = uint16;
	using CHAR32 = uint32;
	using TCHAR = WIDECHAR;

	// Pointers
	using uptrint = SelectIntPointerType<uint32, uint64, sizeof(void*)>::TIntPtr;
	using ptrint = SelectIntPointerType<int32, int64, sizeof(void*)>::TIntPtr;
};