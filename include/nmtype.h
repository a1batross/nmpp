//------------------------------------------------------------------------
//
//  $Workfile:: nmtype.h              $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:02 $
//
//------------------------------------------------------------------------

//!
//! \file nmtype.h 
//! \ru ����, ���������� ����������� ����� ����������� ������.
//! \en The file contains definition of packed data type.
//!

#ifndef _NMTYPE_H_INCLUDED2_
#define _NMTYPE_H_INCLUDED2_
 
#define MEM_LOCAL  0
#define MEM_GLOBAL 1
#define HEAP0 0
#define HEAP1 1
#define HEAP2 2
#define HEAP3 3

#ifdef __GNUC__
#define __int64 long long
#endif
// if new compiler
#ifdef __NM6403__
	typedef long INT64;
	typedef unsigned long UINT64;
#endif

// if old compiler
#ifdef NM6403 
	#ifndef __NM6403__
		typedef long __int64;
		typedef long INT64;
		typedef unsigned long UINT64;
	#endif
#endif

// if win32 compiler
#ifndef NM6403 
		typedef __int64 INT64;
		typedef unsigned __int64 UINT64;
#endif




//-----------------------------------------------------------------------------
	/**    
		\~
    \ru NM �������.
    \en NM registry.
	*/
struct nmreg { int nVal; };
//-----------------------------------------------------------------------------

//*****************************************************************************

    /**
		\~
    \if Russian
        \defgroup nmtype1 ���� ������ ��� ����������� 64-� ��������� ��������� ������.
    \endif
    \if English
        \defgroup nmtype1 Data types for packed 64-bit word.
    \endif
	\ingroup types
    
    \ru ����������� ������� ���������� �������� � ����������
        ������� ����������� �����.
        ��������� � ��������� 
        ������ �������� ������ ������������ � ������� ������� 
        ������� � ��������� Getval() and Setval().
	\en Most of the library functions receive and return 
		arrays of packed 64-bit words. To access elements 
		of the words use library support functions Setval()
		and Getval().
    */


//-----------------------------------------------------------------------------
	/**
		\~
	\ingroup nmvectype
    \ru ��� ������������� ��������� ������ ��� ������ ������������� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 64. 
  	\en Type characterizes vec data as array of 1-bit signed numbers.   \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 64.

		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-1,0]\f$
	*/
struct nm1{ int nVal;};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 2-� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 32. 
  	\en Type characterizes vec data as array of 2-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 32.

		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^1,\ldots,+2^1-1]=[-2,\ldots,+1]\f$
	
	
	*/
struct nm2s{ int nVal;};
//-----------------------------------------------------------------------------    
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 4-� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 16. 
  	\en Type characterizes vec data as array of 4-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 16.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^3,\ldots,+2^3-1]=[-8,\ldots,+7]\f$  
*/
typedef struct nm4s {
	unsigned long long vec;
} nm4s;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
 	\ru ��� ������������� ��������� ������ ��� ������ 8-�� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 8. 
  	\en Type characterizes vec data as array of 8-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 8.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^7,\ldots,+2^7-1]=[-128,\ldots,+127]\f$
	*/
	
struct int8x8{
#ifdef __NM__	
	unsigned long items;
#else 
	char item[8];
#endif	
};

typedef char nm8s;
//typedef struct s_nm8s{
//#ifdef __NM__	
//	unsigned long vec;
//#else 
//	char num[8];
//#endif	
//} nm8s;
//


//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 8-�� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 8. 
  	\en Type characterizes vec data as array of 8-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 8.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^6,\ldots,+2^6-1]=[-64,\ldots,+63]\f$
	*/
typedef char nm8s7b;
struct int7in8x8{
#ifdef __NM__	
	unsigned long items;
#else 
	char item[8];
#endif	
};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
 	\ru ��� ������������� ��������� ������ ��� ������ 16-�� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 4. 
  	\en Type characterizes vec data as array of 16-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 4.

		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{15},\ldots,^+2^{15}-1]\f$.
	*/

struct int16x4{
#ifdef __NM__	
	unsigned long items;
#else 
	short item[4];
#endif	
};

typedef short nm16s;
//typedef struct s_nm16s {
//#ifdef __NM__	
//	unsigned long vec;
//#else 
//	short num[4];
//#endif	
//} nm16s;



//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
  	\ru ��� ������������� ��������� ������ ��� ������ 16-�� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 4. 
  	\en Type characterizes vec data as array of 16-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 4.

		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~ \f$[-2^{14},\ldots,+2^{14}-1]\f$
	*/
typedef short nm16s15b;
struct int15in16x4{
#ifdef __NM__	
	unsigned long items;
#else 
	short item[4];
#endif	
};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 32-�� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 2. 
  	\en Type characterizes vec data as array of 32-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 2.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{31},\ldots,+2^{31}-1]\f$.
	*/
typedef int nm32s;
struct int32x2{
//public:
	unsigned long long data;
//	int32x2(){
//		data=0;
//	}
//	int32x2(int item0, int item1){
//		set(0,item0);
//		set(1,item1);
//	}
//	int32x2& operator = (unsigned long long value){
//		data = value;
//		return *this;
//	}
//	int &lo(){
//		return *((int*)&data);
//	}
//	int &hi(){
//		return *(((int*)&data)+1);
//	}
//	void set(int indx, int value){
//		((int*)&data)[indx]=value;
//	}
//	int get(int indx){
//		return ((int*)&data)[indx];
//	}
};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
   \ru ��� ������������� ��������� ������ ��� ������ 32-�� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 2. 
  	\en Type characterizes vec data as array of 32-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 2.

		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{30},\ldots,2^{30}-1]\f$.
	*/
typedef int nm32s31b;
struct int31in32x2{
#ifdef __NM__	
	unsigned long items;
#else 
	int item[2];
#endif	
};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
   \ru ��� ������������� ��������� ������ ��� ������ 32-�� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 2. 
  	\en Type characterizes vec data as array of 32-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 2.

		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{29},\ldots,2^{29}-1]\f$.
	*/
typedef int nm32s30b;
struct int30in32x2{
#ifdef __NM__	
	unsigned long items;
#else 
	int item[2];
#endif	
};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
   \ru ��� ������������� ��������� ������ ��� ������ 64-� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������ ������� ������������ . 
  	\en Type characterizes vec data as array of 64-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers may by arbitrary.
	
		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{63},\ldots,^+2^{63}-1]\f$
	*/
//typedef __int64 nm64s;
typedef INT64 nm64s;


//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
   	  \ru ��� ������������� ��������� ������ ��� ������ 64-� ��������� ����� �� ������. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������ ������� ������������ . 
  	\en Type characterizes vec data as array of 64-bit signed numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers may by arbitrary.
	
		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{62},\ldots,+2^{62}-1]\f$
	*/
typedef nm64s nm64s63b;
//=============================================================================
	/**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 2-� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 32. 
  	\en Type characterizes vec data as array of 2-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 32.


		\~
  	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,+2^2-1]=[0,\ldots,3]\f$
	*/
struct nm2u{
	int nVal;
};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 4-� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 16. 
  	\en Type characterizes vec data as array of 4-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 16.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,+2^4-1]=[0,\ldots,15]\f$
	*/
struct nm4u{ int nVal;};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 8-�� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 8. 
  	\en Type characterizes vec data as array of 8-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 8.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,+2^8-1]=[0,\ldots,255]\f$
	*/
typedef struct s_nm8u {
	#ifdef __NM__	
		unsigned long vec;
	#else 
		unsigned char num[8];
	#endif	
} t_nm8u;
typedef unsigned char nm8u;
//-----------------------------------------------------------------------------

	/**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 8-�� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 8. 
  	\en Type characterizes vec data as array of 8-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 8.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,+2^7-1]=[0,\ldots,127]\f$
	*/
typedef unsigned char nm8u7b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 16-�� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 4. 
  	\en Type characterizes vec data as array of 16-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 4.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^{16}-1]\f$.
	*/

//struct uint16x4{
typedef struct s_nm16u {
#ifdef __NM__	
	unsigned long vec;
#else 
	short num[4];
#endif	
} nm16u_t;
typedef unsigned short  nm16u;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 16-�� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 4. 
  	\en Type characterizes vec data as array of 16-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 4.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{14},\ldots,^+2^{14}-1]\f$.
	*/
typedef unsigned short nm16u15b;
struct uint15in16x4{
#ifdef __NM__	
	unsigned long items;
#else 
	unsigned short item[4];
#endif	
};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype

	\ru ��� ������������� ��������� ������ ��� ������ 32-�� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 2. 
  	\en Type characterizes vec data as array of 32-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 2.

		\~
	\ru �������� ��������
	\en Number range is
		\~
	\~	\f$[0,\ldots,2^{32}-1]\f$.
	*/
typedef unsigned int nm32u;
struct uint32x2{
#ifdef __NM__	
	unsigned long items;
#else 
	unsigned item[2];
#endif	
};
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
	\ru ��� ������������� ��������� ������ ��� ������ 32-�� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������������ ������ � ������� ������ ���� ������ 2. 
  	\en Type characterizes vec data as array of 32-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers have to be multiple to 2.

		\~
	\ru �������� ��������
	\en Number range is
		\~
	\~	\f$[0,\ldots,2^{31}-1]\f$.
	*/
typedef unsigned int nm32u31b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
   \ru ��� ������������� ��������� ������ ��� ������ 64-� ��������� ����� ��� �����. \n ��������� ����� ������� ������ ���� �������� �� ������� 64� �����.  \n �� ��������� ������ ������� ������������ . 
  	\en Type characterizes vec data as array of 64-bit unsigned numbers. \n Pointer to this struct is always aligned to 64-bit address. \n By default amount of numbers may by arbitrary.

		\~
	\ru �������� ��������
	\en Number range is
		\~
	\~	\f$[0,\ldots,2^{64}-1]\f$.
	*/
typedef UINT64 nm64u;
//=============================================================================



//=============================================================================
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ��������.
    \en Type for 32-bit scalar variables with limited value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-1,0]\f$
	*/
typedef int int1b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^1,\ldots,+2^1-1]=[-2,\ldots,+1]\f$
	*/
typedef int int2b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^2,\ldots,+2^2-1]=[-4,\ldots,+3]\f$
	*/
typedef int int3b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^3,\ldots,+2^3-1]=[-8,\ldots,+7]\f$
	*/
typedef int int4b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^6,\ldots,+2^6-1]=[-64,\ldots,+63]\f$
	*/
typedef int int7b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^7,\ldots,+2^7-1]=[-128,\ldots,+127]\f$
	*/
typedef int int8b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{14},\ldots,+2^{14}-1]\f$
	*/
typedef int int15b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{15},\ldots,+2^{15}-1]\f$
	*/
typedef int int16b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{29},\ldots,+2^{29}-1]\f$
	*/
typedef int int30b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{30},\ldots,+2^{30}-1]\f$
	*/
typedef int int31b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{31},\ldots,+2^{31}-1]\f$
	*/
typedef int int32b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 64-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 64-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{62},\ldots,+2^{62}-1]\f$
	*/
typedef INT64 int63b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 64-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 64-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[-2^{63},\ldots,+2^{63}-1]\f$
	*/
typedef INT64 int64b;
//=============================================================================
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,1]=[0,1]\f$
	*/
typedef unsigned int uint1b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^2-1]=[0,\ldots,3]\f$
	*/
typedef unsigned int uint2b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^3-1]=[0,\ldots,7]\f$
	*/
typedef unsigned int uint3b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^4-1]=[0,\ldots,15]\f$
	*/
typedef unsigned int uint4b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^7-1]=[0,\ldots,127]\f$
	*/
typedef unsigned int uint7b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^8-1]=[0,\ldots,255]\f$
	*/
typedef unsigned int uint8b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit sclars with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^{15}-1]\f$
	*/
typedef unsigned int uint15b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^{16}-1]\f$
	*/
typedef unsigned int uint16b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^{31}-1]\f$
	*/
typedef unsigned int uint31b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 32-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 32-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^{32}-1]\f$
	*/
typedef unsigned int uint32b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 64-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 64-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^{63}-1]\f$
	*/
typedef UINT64 uint63b;
//-----------------------------------------------------------------------------
    /**
	\ingroup nmtype
    \ru ��� ��� 64-��������� ��������� ���������� � ������������ ���������� ���������� ��������.
    \en Type for 64-bit scalar variables with limited admissible value range.

		\~
	\ru �������� ��������: 
	\en Number range is: 
		\~
	\~	\f$[0,\ldots,2^{64}-1]\f$
	*/
typedef nm64u uint64b;


//=============================================================================

//================= nmget ===========================================    
/*
int2b	nmget_2s(struct nm2s*  pVec, int nIndex)
{
	nm32u nBase=((nm32u)nIndex)/16;
	nm32u nDisp=((nm32u)nIndex)%16;
	nm32s nVal=((nm32s*)pVec)[nBase];
	nDisp<<=1;
	nVal<<=(32-2-nDisp);
	nVal>>=30;
	return nVal;
}

inline int4b nmget_4s(nm4s*  pVec, int nIndex)
{
	nm32u nBase=((nm32u)nIndex)/8;
	nm32u nDisp=((nm32u)nIndex)%8;
	nm32s nVal=((nm32s*)pVec)[nBase];
	nDisp<<=2;
	nVal<<=(32-4-nDisp);
	nVal>>=28;
	return nVal;
}

inline int8b	nmget_8s(nm8s*  pVec, int nIndex)
{
	return (char*)pVec[nIndex];
}

inline int16b	nmget_16s(nm16s* pVec, int nIndex)
{
	return (hsort)pVec[nIndex];
}

---------------- uint ------------------------------------ 
inline uint1b nmget_1u(nm1*   pVec, int nIndex)
{
	nm32u nBase=((nm32u)nIndex)/32;
	nm32u nDisp=((nm32u)nIndex)%32;
	nm32u nVal=((nm32u*)pVec)[nBase];
	nVal>>=nDisp;
	nVal&=1;
	return nVal;
}
inline uint2b	nmget_2u(nm2u*  pVec, int nIndex)
{
	nm32u nBase=((nm32u)nIndex)/16;
	nm32u nDisp=((nm32u)nIndex)%16;
	nm32u nVal=((nm32u*)pVec)[nBase];
	nVal>>=nDisp*2;
	nVal&=3;
	return nVal;
}


inline uint4b	nmget_4u(nm4u*  pVec, int nIndex)
{
	nm32u nBase=((nm32u)nIndex)/8;
	nm32u nDisp=((nm32u)nIndex)%8;
	nm32u nVal=((nm32u*)pVec)[nBase];
	nVal>>=nDisp*4;
	nVal&=15;
	return nVal;
}

inline uint8b	nmget_8u(nm8u*  pVec, int nIndex)
{
	return pVec[nIndex];
}

inline uint16b	nmget_16u(nm16u* pVec, int nIndex)
{
	return pVec[nIndex];
}
*/

//=============================================================================
#define VEC_NM1(X)  unsigned data[(X)/32];  
#define VEC_NM2U(X) unsigned data[(X)/16];
#define VEC_NM2S(X) int data[(X)/16];
#define VEC_NM4U(X) \
	unsigned data[(X)/8]; \
	uint4b get(int nIndex){return nmget((nm4u*)data,nIndex); }\
	uint4b operator[] (int index){ return nmget((nm4u*)data,index);}


#define VEC_NM4S(X) int data[(X)/8]; 
#define VEC_NM8U(X) unsigned int data[(X)/4]; 
#define VEC_NM8S(X) \
	int data[(X)/4]; \
	void set(int i, int val){ ((char*)data)[i]=val;}		\
	char operator[] (int index){ return ((char*)data)[index];}

#define VEC_NM16U(X) \
	unsigned int data[(X)/2]; \
	void set(int i, int val){ ((unsigned short*)data)[i]=val;}		\
	unsigned short operator[] (int index){ return ((unsigned short*)data)[index];}

#define VEC_NM16S(X) \
	int data[(X)/2]; \
	void set(int i, int val){ ((unsigned short*)data)[i]=val;}		\
	short operator[] (int index){ return ((unsigned short*)data)[index];}

#define VEC_NM32U(X) nm32u data[(X)];  
#define VEC_NM32S(X) \
	int data[(X)];  \
	void set(int i, int val){ ((int*)data)[i]=val;}		\
	int operator[] (int index){ return ((int*)data)[index];}




//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 4-�. ����� �� ������. 
    \en Type of vec structure consisting of 16 4-bit sigened words.
	*/
//struct v16nm4s {VEC_NM4S(16)};
struct v16nm4s {
	unsigned long long vec[1];
};

//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 4-� 8�. ����� �� ������. 
    \en Type of vec structure consisting of 4 8-bit sigened words.
	*/
//struct v4{VEC_NM8S(4)};
struct v4nm8s {
	unsigned long long vec[1];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 8-�� 8�. ����� �� ������. 
    \en Type of vec structure consisting of 8 8-bit sigened words.
	*/
//struct v8nm8s {VEC_NM8S(8)};
struct v8nm8s {
	unsigned long long vec[1];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 8�. ����� �� ������. 
    \en Type of vec structure consisting of 16 8-bit sigened words.
	*/
//struct v16nm8s {VEC_NM8S(16)};
struct v16nm8s {
	unsigned long long vec[2];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 4-� 16�. ����� �� ������. 
    \en Type of vec structure consisting of 4 16-bit sigened words.
	*/
//struct  v4nm16s {VEC_NM16S(4)};
struct  v4nm16s {
	unsigned long long vec[1];
};


//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 8-�� 16�. ����� �� ������. 
    \en Type of vec structure consisting of 8 16-bit sigened words.
	*/
//struct v8nm16s {VEC_NM16S(8)};
struct v8nm16s {
	unsigned long long vec[2];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 16�. ����� �� ������. 
    \en Type of vec structure consisting of 16 16-bit sigened words.
	*/
//struct v16nm16s {VEC_NM16S(16)};
struct v16nm16s {
	unsigned long long vec[4];
};

//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 2-� 32�. ����� �� ������. 
    \en Type of vec structure consisting of 2 32-bit sigened words.
	*/
//struct v2nm32s {VEC_NM32S(2)};
struct v2nm32s {
	unsigned long long vec[1];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 4-� 32�. ����� �� ������. 
    \en Type of vec structure consisting of 4 32-bit sigened words.
	*/
//struct v4nm32s {VEC_NM32S(4)};
struct v4nm32s {
	unsigned long long vec[2];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 8-�� 32�. ����� �� ������. 
    \en Type of vec structure consisting of 8 32-bit sigened words.
	*/
//struct v8nm32s {VEC_NM32S(8)	};
struct v8nm32s {
	unsigned long long vec[4];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 32�. ����� �� ������. 
    \en Type of {VECtor structure consisting of 16 32-bit sigened words.
	*/
//struct v16nm32s {VEC_NM32S(16)	};
struct v16nm32s {
	unsigned long long data[8];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 32�. ����� �� ������. 
    \en Type of {VECtor structure consisting of 16 32-bit sigened words.

		\~
	\ru �������� �������� ��������� ���������: 
	\en Number range of structure elements is: 
		\~
	\~	\f$[-64,\ldots,+63]\f$
	*/
typedef v16nm8s v16nm8s7b;

//=============================================================================

//-----------------------------------------------------------------------------
    /**
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 4-�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 16 4-bit unsigened words.
	*/
//struct v16nm4u {VEC_NM4U(16)	};
struct v16nm4u {
	unsigned long long vec[1];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 4-� 8�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 4 8-bit unsigened words.
	*/
//struct v4nm8u {VEC_NM8U(4)		};
struct v4nm8u {
	unsigned long long vec[1];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 8-�� 8�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 8 8-bit unsigened words.
	*/
//struct v8nm8u {VEC_NM8U(8)		};
struct v8nm8u {
	unsigned long long vec[1];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 8�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 16 8-bit unsigened words.
	*/
//struct v16nm8u {VEC_NM8U(16)	};
struct v16nm8u {
	unsigned long long vec[2];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 4-� 16�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 4 16-bit unsigened words.
	*/
//struct v4nm16u {VEC_NM16U(4)	};
struct v4nm16u {
	unsigned long long vec[1];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 8-�� 16�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 8 16-bit unsigened words.
	*/
//struct v8nm16u {VEC_NM16U(8)	};
struct v8nm16u {
	unsigned long long vec[2];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 16�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 16 16-bit unsigened words.
	*/
//struct v16nm16u {VEC_NM16U(16)	};
struct v16nm16u {
	unsigned long long vec[4];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 2-� 32�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 2 32-bit unsigened words.
	*/
//struct v2nm32u {VEC_NM32U(2)	};
struct v2nm32u {
	unsigned long long vec[1];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 4-� 32�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 4 32-bit unsigened words.
	*/
//struct v4nm32u {VEC_NM32U(4)	};
struct v4nm32u {
	unsigned long long vec[2];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 8-�� 32�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 8 32-bit unsigened words.
	*/
//struct v8nm32u {VEC_NM32U(8)	};
struct v8nm32u {
	unsigned long long vec[4];
};
//-----------------------------------------------------------------------------
    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 32�. ����� ��� �����. 
    \en Type of {VECtor structure consisting of 16 32-bit unsigened words.
	*/
//struct v16nm32u {VEC_NM32U(16)	};
struct v16nm32u {
	unsigned long long vec[8];
};
//-----------------------------------------------------------------------------

    /**
		\~
	\ingroup nmvectype
    \ru ��� ��������� ���������, ��������� �� 16-�� 32�. ����� �� ������. 
    \en Type of vec structure consisting of 16 32-bit sigened words.

		\~
	\ru �������� �������� ��������� ���������: 
	\en Number range of structure elements is: 
		\~
	\~	\f$[0,\ldots,7]\f$
	*/
typedef v16nm4u v16nm4b3u;
//=============================================================================
//-----------------------------------------------------------------------------
	/**
	\internal
	\ingroup nmvectype
    \ru ��� ��� ���� 64-� ������ ��������� ������, ��������������� ������������ � ������
		����� ������ ������������ ������ �� ������� �������
		�� ������� ����������� 16-� ������� ����������� �������� ����� 
        � ���������� �������� \f$[-2^{15},\ldots,^+2^{15}-1]\f$. 
    \en Packed 16-bit complex signed numbers with
		\~
       \f$[-2^{15},\ldots,^+2^{15}-1]\f$ value range.

	\ru �������� �������� [-128,\ldots,127]. 
	\en Number range is [-128,\ldots,127].
	*/
struct nm16sc
{

	short r;
	short c;
	
	//nm16sc() : r(0), c(0) {}
	//nm16sc(nm16s b) : r(b), c(0) {}
};
//-----------------------------------------------------------------------------
	/**
	\internal
	\ingroup nmvectype
    \ru ��� ��� ���� 64-� ��������� ��������� ������, ���������� ����������� ������������ � 
		������ ����� 2-� ����������� �����.
    \en Type for pair of 64-bit words with packed real and imaginary parts of
		two complex numbers.

		\~
	\ru �������� �������� ��� ������������ � ������ ������ ������������ �����
	\en Number range for real and imaginary parts of complex number is
		\~
	\~	\f$[-2^{31},\ldots,^+2^{31}-1]\f$
	*/
struct nm32sc
{

	nm32s re;
	nm32s im;
	
	nm32sc() : re(0), im(0) {}
	nm32sc(nm32s b) : re(b), im(0) {}
};

//-----------------------------------------------------------------------------

	/**
	\internal
	\ingroup nmvectype
    \ru ��� ��� ���� 64-� ��������� ��������� ������, ���������� ������������ � ������ ����� 
		������������ �����.
    \en Type for pair of 64-bit words with real and imaginary parts of complex number.
		\~
       \f$[-2^{63},\ldots,^+2^{63}-1]\f$ value range.

	\ru �������� �������� ��� ������������ � ������ �����
	\en Number range is for real and imaginary parts is 
		\~
	\~ \f$[-2^{63},\ldots,+2^{63}-1]\f$.
	*/
struct nm64sc
{

		//!
		//! \ru ������������ ����� ������������� �����.
		//! \en Real part of complex number.
		//! \~
	long long re;

		//!
		//! \ru ������ ����� ������������ �����.
		//! \en Imaginary part of complex number.
		//! \~
	long long im;
//	
//	nm64sc() : re(0), im(0) {}
//	nm64sc(nm64s b) : re(b), im(0) {}
//
//	int Print();
//
};
//
///*
inline int NM_CAPACITY(nm1*)  {return 64;}

inline int NM_CAPACITY(nm2s*)  {return 32;}
inline int NM_CAPACITY(nm4s*)  {return 16;}
inline int NM_CAPACITY(nm8s*)  {return 8;}
inline int NM_CAPACITY(nm16s*) {return 4;}
inline int NM_CAPACITY(nm32s*) {return 2;}
inline int NM_CAPACITY(nm64s*) {return 1;}

inline int NM_CAPACITY(nm2u*)  {return 32;}
inline int NM_CAPACITY(nm4u*)  {return 16;}
inline int NM_CAPACITY(nm8u*)  {return 8;}
inline int NM_CAPACITY(nm16u*) {return 4;}
inline int NM_CAPACITY(nm32u*) {return 2;}
inline int NM_CAPACITY(nm64u*) {return 1;}
//*/
//#define CAPACITY_nm64s 1
//#define CAPACITY_nm32s 2
//#define CAPACITY_nm16s 4
//#define CAPACITY_nm8s 8
//#define CAPACITY_nm4s 16
//#define CAPACITY_nm2s 32
//#define CAPACITY_nm1 64
//
//

#endif

 // _NMTYPE_H_INCLUDED_


