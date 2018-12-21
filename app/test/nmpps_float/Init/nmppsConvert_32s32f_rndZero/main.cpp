#include <nmtype.h>
#include <malloc32.h>
#include <stdio.h>
#include <nmpp.h>

#define 				SIZE					512

#pragma data_section ".data_imu5"
	nm32f src_32f[SIZE];
#pragma data_section ".data_imu5"
	nm32s dst_32s[SIZE + 11];

int main()
{
	// nm32f* src_32f = (nm32f*) nmppsMalloc_32f(SIZE);
	// //nm32s* dst_32s = (nm32s*) nmppsMalloc_32s(SIZE + 11);
	// nm32f* dst_32s = (nm32f*) nmppsMalloc_32f(SIZE + 11);
	nmppsRand_32f(src_32f, SIZE, -11, 11);
	// float value = -5.0;
	// for(int i = 0; i < SIZE; i++, value += 0.2) {
	// 	src_32f[i] = value;
	// }

	for(int i = 0; i < SIZE + 11; i++) {
		dst_32s[i] = 7;
	}

	unsigned crc = 0;
//	int gr7 = 7;
	for(int iSize = 2; iSize < SIZE; iSize += 2) {
		nmppsConvert_32f32s_rndZero(src_32f, dst_32s, SIZE);
		nmppsCrcAcc_32s(dst_32s, SIZE + 11, &crc);
	}

	// for(int i = 0; i < SIZE + 11; i++) {
	// 	printf("[%d] = %d\n", i, dst_32s[i]);
	// }
	// printf("\n");

	// nmppsFree(src_32f);
	// nmppsFree(dst_32s);

	return crc >> 2;
}

// crc = 223351351
