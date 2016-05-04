#define __STDC_FORMAT_MACROS
#include <aura/aura.h>
#include <ion/ion.h>
#include "nmpp.h"
#include "fft2.h"

struct aura_node *n;
int main() {

	printf("START-%s\n", aura_get_version());
	slog_init(NULL, 0);
       sleep(1);
	int ret; 
		n = aura_open("nmc", "./rpc-demo.abs");
	if (!n) {
		printf("ERROR:Failed to open node\n");
		slog (0, SLOG_ERROR, "Failed to open node");
		exit(1);
	}
	printf("START-1\n");
	aura_wait_status(n, AURA_STATUS_ONLINE);

	printf("START-2\n");
	static signed char  src0_8s[256] , src1_8s[256];
	static signed short src0_16s[256], src1_16s[256];
	static signed int   src0_32s[2*2048] , src1_32s[256];
	long long    src0_64s[256], src1_64s[256];
	static signed char  dst_8s[256];
	signed short dst_16s[256];
	signed int 	 dst_32s[2*2048];
	signed long long dst_64s[256];
	
	int i=0;

	for(i=0; i<256; i++){
		src0_8s[i] =i;  
		src0_16s[i]=i;  
		src0_32s[i]=i;  
		src0_64s[i]=i;  
		            
		src1_8s[i] =8-i;
		src1_16s[i]=8-i;
		src1_32s[i]=8-i;
		src1_64s[i]=8-i;
	}
	//for(i=0; i<256; i++){
	//	src0_8s[i] =1;  
	//	src0_16s[i]=1;  
	//	src0_32s[i]=1;  
	//	src0_64s[i]=1;  
	//	            
	//	src1_8s[i] =1;
	//	src1_16s[i]=1;
	//	src1_32s[i]=1;
	//	src1_64s[i]=1;
	//}

	
//	nmppsAbs_8s ((nm8s* )src0_8s ,(nm8s* )dst_8s ,8);
//	nmppsAbs_16s((nm16s*)src0_16s,(nm16s*)dst_16s,16);
//	nmppsAbs_32s((nm32s*)src0_32s,(nm32s*)dst_32s,16);
//	nmppsAbs_64s((nm64s*)src0_16s,(nm64s*)dst_64s,16);
//	
//	nmppsAdd_8s ((nm8s* )src0_8s ,(nm8s* )src1_8s ,(nm8s* )dst_8s ,8);
//	nmppsAdd_16s((nm16s*)src0_16s,(nm16s*)src1_16s,(nm16s*)dst_16s,16);
//	nmppsAdd_32s((nm32s*)src0_32s,(nm32s*)src1_32s,(nm32s*)dst_32s,16);
//	nmppsAdd_64s((nm64s*)src0_16s,(nm64s*)src1_16s,(nm64s*)dst_64s,16);
//	
//	nmppsSub_8s ((nm8s* )src0_8s ,(nm8s* )src1_8s ,(nm8s* )dst_8s ,8);
//	nmppsSub_16s((nm16s*)src0_16s,(nm16s*)src1_16s,(nm16s*)dst_16s,16);
//	nmppsSub_32s((nm32s*)src0_32s,(nm32s*)src1_32s,(nm32s*)dst_32s,16);
//	nmppsSub_64s((nm64s*)src0_16s,(nm64s*)src1_16s,(nm64s*)dst_64s,16);
//
//	nmppsAddC_8s ((nm8s* )src0_8s ,(nm8s* )1,(nm8s* )dst_8s ,8);
//	nmppsAddC_16s((nm16s*)src0_16s,(nm16s*)1,(nm16s*)dst_16s,16);
//	nmppsAddC_32s((nm32s*)src0_32s,(nm32s*)1,(nm32s*)dst_32s,16);
//	nmppsAddC_64s((nm64s*)src0_16s,(nm64s*)1,(nm64s*)dst_64s,16);
//	                                       
//	nmppsSubC_8s ((nm8s* )src0_8s ,(nm8s* )1,(nm8s* )dst_8s ,8);
//	nmppsSubC_16s((nm16s*)src0_16s,(nm16s*)1,(nm16s*)dst_16s,16);
//	nmppsSubC_32s((nm32s*)src0_32s,(nm32s*)1,(nm32s*)dst_32s,16);
//	nmppsSubC_64s((nm64s*)src0_16s,(nm64s*)1,(nm64s*)dst_64s,16);
//	
//	nmppsSubCRev_8s ((nm8s* )src0_8s ,(nm8s* )1,(nm8s* )dst_8s ,8);
//	nmppsSubCRev_16s((nm16s*)src0_16s,(nm16s*)1,(nm16s*)dst_16s,16);
//	nmppsSubCRev_32s((nm32s*)src0_32s,(nm32s*)1,(nm32s*)dst_32s,16);
//	nmppsSubCRev_64s((nm64s*)src0_16s,(nm64s*)1,(nm64s*)dst_64s,16);
//
//	nmppsMulC_8s 	((nm8s*) src0_8s ,2,(nm8s*) dst_8s, 16); 
//	nmppsMulC_8s16s	((nm8s*) src0_8s ,2,(nm8s*) dst_16s, 16);
//	nmppsMulC_16s	((nm16s*)src0_16s,3,(nm16s*)dst_16s,16); 
//	nmppsMulC_16s32s((nm16s*)src0_16s,3,(nm32s*)dst_32s,16); 
//	nmppsMulC_32s	((nm32s*)src0_32s,4,(nm32s*)dst_32s,16); 
//	nmppsMulC_32s64s((nm32s*)src0_32s,4,(nm64s*)dst_64s,16); 
//	nmppsMulC_64s	((nm64s*)src0_64s,2,(nm64s*)dst_64s,16); 

//	nmppsRShiftC_8s ((nm8s* )src0_8s ,1,(nm8s* )dst_8s ,16);
//	nmppsRShiftC_16s((nm16s*)src0_16s,1,(nm16s*)dst_16s,16);
//	nmppsRShiftC_32s((nm32s*)src0_32s,1,(nm32s*)dst_32s,16);
//	nmppsRShiftC_64s((nm64s*)src0_64s,1,(nm64s*)dst_64s,16);
//
//	nmppsRShiftC_8u ((nm8u* )src0_8s ,1,(nm8u* )dst_8s ,16);
//	nmppsRShiftC_16u((nm16u*)src0_16s,1,(nm16u*)dst_16s,16);
// 	nmppsRShiftC_32u((nm32u*)src0_32s,1,(nm32u*)dst_32s,16);
//	nmppsRShiftC_64u((nm64u*)src0_64s,1,(nm64u*)dst_64s,16);
//
//	int min;
//	nmppsMin_8s ((nm16s*)src0_8s ,32,&min);	//printf("min=%d\r\n",min);
//	nmppsMin_16s((nm16s*)src0_16s,32,&min);	//printf("min=%d\r\n",min);
//	nmppsMin_32s((nm16s*)src0_32s,32,&min);	//printf("min=%d\r\n",min);
//	//-nmppsMin_64s((nm16s*)src0_16s,16,&min);
//
//	nmppsMax_8s ((nm16s*)src0_8s,32, &min); //printf("max=%d\r\n",min);
//	nmppsMax_16s((nm16s*)src0_16s,32,&min); //printf("max=%d\r\n",min);
//	nmppsMax_32s((nm16s*)src0_32s,32,&min); //printf("max=%d\r\n",min);
//	//-nmppsMin_64s((nm16s*)src0_16s,16,&min);
//
//	nmppsAndC_8u((nm8u*)  src0_8s, 5, (nm8s*) dst_8s,16);
//	nmppsAndC_16u((nm16u*)src0_16s,5,(nm16u*)dst_16s,16);
//	nmppsAndC_32u((nm32u*)src0_32s,5,(nm32u*)dst_32s,16);
//	nmppsAndC_64u((nm64u*)src0_64s,5,(nm64u*)dst_64s,16);
//
//	nmppsOrC_8u ((nm8u*)src0_8s,1,  (nm8s*) dst_8s,16);
//	nmppsOrC_16u((nm16u*)src0_16s,1,(nm16u*)dst_16s,16);
//	nmppsOrC_32u((nm32u*)src0_32s,1,(nm32u*)dst_32s,16);
//	nmppsOrC_64u((nm64u*)src0_64s,1,(nm64u*)dst_64s,32);
//
//	nmppsXorC_8u((nm8u*)  src0_8s,1, (nm8s*) dst_8s,16);
//	nmppsXorC_16u((nm16u*)src0_16s,1,(nm16u*)dst_16s,16);
//	nmppsXorC_32u((nm32u*)src0_32s,1,(nm32u*)dst_32s,16);
//	nmppsXorC_64u((nm64u*)src0_64s,1,(nm64u*)dst_64s,32);
//	
//	nmppsNot_8u ((nm8u* )src0_8s, (nm8s* )dst_8s ,16);
//	nmppsNot_16u((nm16u*)src0_16s,(nm16s*)dst_16s,16);
//	nmppsNot_32u((nm32u*)src0_32s,(nm32s*)dst_32s,16);
//	nmppsNot_64u((nm64u*)src0_64s,(nm64s*)dst_64s,16);
//
//	nmppsAnd_8u ((nm8u*) src0_8s, (nm8u*) src1_8s, (nm8s*) dst_8s,16);
//	nmppsAnd_16u((nm16u*)src0_16s,(nm16u*)src1_16s,(nm16u*)dst_16s,16);
//	nmppsAnd_32u((nm32u*)src0_32s,(nm32u*)src1_32s,(nm32u*)dst_32s,16);
//	nmppsAnd_64u((nm64u*)src0_64s,(nm64u*)src1_64s,(nm64u*)dst_64s,32);
//	
//	nmppsOr_8u ((nm8u*) src0_8s, (nm8u*) src1_8s, (nm8s*) dst_8s,16);
//	nmppsOr_16u((nm16u*)src0_16s,(nm16u*)src1_16s,(nm16u*)dst_16s,16);
//	nmppsOr_32u((nm32u*)src0_32s,(nm32u*)src1_32s,(nm32u*)dst_32s,16);
//	nmppsOr_64u((nm64u*)src0_64s,(nm64u*)src1_64s,(nm64u*)dst_64s,32);
//
//	nmppsXor_8u ((nm8u*) src0_8s, (nm8u*) src1_8s, (nm8s*) dst_8s,16);
//	nmppsXor_16u((nm16u*)src0_16s,(nm16u*)src1_16s,(nm16u*)dst_16s,16);
//	nmppsXor_32u((nm32u*)src0_32s,(nm32u*)src1_32s,(nm32u*)dst_32s,16);
//	nmppsXor_64u((nm64u*)src0_64s,(nm64u*)src1_64s,(nm64u*)dst_64s,32);
//
//	nmppsCmpLtC_8s8u ((nm8s*) src0_8s ,1,(nm8u*)dst_8s,16);
//	nmppsCmpLtC_16s8u((nm16s*)src0_16s,1,(nm8u*)dst_8s,16);
//	nmppsCmpLtC_32s8u((nm32s*)src0_32s,1,(nm8u*)dst_8s,16);
//	
//	nmppsCmpNeC_8s8u ((nm8s*) src0_8s ,1,(nm8u*)dst_8s,16);
//	nmppsCmpNeC_16s8u((nm16s*)src0_16s,1,(nm8u*)dst_8s,16);
//	nmppsCmpNeC_16s8u((nm16s*)src0_16s,1,(nm8u*)dst_8s,16);
//	nmppsCmpNeC_32s8u((nm32s*)src0_32s,1,(nm8u*)dst_8s,16);
//	nmppsCmpNeC_64s8u((nm64s*)src0_64s,1,(nm8u*)dst_8s,16);
//	
	nmppsCmpNe_8s8um ((nm8s*)  src0_8s , (nm8s*) src1_8s ,(nm8u*)dst_8s, 16, 0);		for(i=0; i<16; i++)	printf("%d %d %d\r\n", (int)src0_8s [i],(int)src1_8s [i],(int)dst_8s[i]);
	nmppsCmpNe_16s8um((nm16s*) src0_16s, (nm16s*)src1_16s,(nm8u*)dst_8s, 16, 0);		for(i=0; i<16; i++)	printf("%d %d %d\r\n", (int)src0_16s[i],(int)src1_16s[i],(int)dst_8s[i]);
	nmppsCmpNe_32s8um ((nm32s*)src0_32s, (nm32s*)src1_32s,(nm8u*)dst_8s, 16, 0);		for(i=0; i<16; i++)	printf("%d %d %d\r\n", (int)src0_32s[i],(int)src1_32s[i],(int)dst_8s[i]);
	nmppsCmpNe_64s8um ((nm64s*)src0_64s, (nm64s*)src1_64s,(nm8u*)dst_8s, 16, 0);		for(i=0; i<16; i++)	printf("%d %d %d\r\n", (int)src0_64s[i],(int)src1_64s[i],(int)dst_8s[i]);
	                                                                                                                                                                           
	nmppsCmpLt_8s8um  ((nm8s*) src0_8s , (nm8s*) src1_8s ,(nm8u*)dst_8s, 16, 0);		for(i=0; i<16; i++)	printf("%d %d %d\r\n", (int)src0_8s [i],(int)src1_8s [i],(int)dst_8s[i]);
	nmppsCmpLt_16s8um ((nm16s*)src0_16s, (nm16s*)src1_16s,(nm8u*)dst_8s, 16, 0);		for(i=0; i<16; i++)	printf("%d %d %d\r\n", (int)src0_16s[i],(int)src1_16s[i],(int)dst_8s[i]);
	nmppsCmpLt_32s8um ((nm32s*)src0_32s, (nm32s*)src1_32s,(nm8u*)dst_8s, 16, 0);		for(i=0; i<16; i++)	printf("%d %d %d\r\n", (int)src0_32s[i],(int)src1_32s[i],(int)dst_8s[i]);
//
//
//	nmppmMul_mm_8s8s  (src0_8s,8,8,src1_8s, dst_8s, 8);
//	nmppmMul_mm_8s16s (src0_8s,8,8,src1_16s,dst_16s,8);
//	nmppmMul_mm_8s32s (src0_8s,8,8,src1_32s,dst_32s,8);
//	nmppmMul_mm_8s64s (src0_8s,8,8,src1_64s,dst_64s,8);
//	
//	nmppmMul_mm_16s16s(src0_16s,8,8,src1_16s,dst_16s,8);
//	nmppmMul_mm_16s32s(src0_16s,8,8,src1_32s,dst_32s,8);
//	nmppmMul_mm_16s64s(src0_16s,8,8,src1_64s,dst_64s,8);
//	
//	nmppmMul_mm_32s32s(src0_32s,8,8,src1_32s,dst_32s,8);
//	nmppmMul_mm_32s64s(src0_32s,8,8,src1_64s,dst_64s,8);
//	
//	nmppmMul_mv_8s64s (src0_8s, src1_64s,dst_64s,8,8);
//	nmppmMul_mv_16s64s(src0_16s,src1_64s,dst_64s,8,8);
//	nmppmMul_mv_32s64s(src0_32s,src1_64s,dst_64s,8,8);
	
	int sum;
	long long sum64;
	nmppsSum_8s ((nm8s*) src0_8s, 32,&sum  );  	printf("sum=%d\r\n",sum);
	nmppsSum_16s((nm16s*)src0_16s,32,&sum64);	printf("sum=%d\r\n",(int)sum64);
	nmppsSum_32s((nm32s*)src0_32s,32,&sum64);	printf("sum=%d\r\n",(int)sum64);
	nmppsSum_64s((nm64s*)src0_64s,32,&sum64);	printf("sum=%d\r\n",(int)sum64);	
	
	long long ret64;
	nmppsDotProd_8s8sm  ((nm8s*) src0_8s ,(nm8s *)src1_8s , 16 , &ret64,0);      printf("%d\n",(int)ret64);
	nmppsDotProd_8s16sm ((nm8s*) src0_8s ,(nm16s*)src1_16s, 16 , &ret64,0);      printf("%d\n",(int)ret64);
	nmppsDotProd_8s32sm ((nm8s*) src0_8s ,(nm32s*)src1_32s, 16 , &ret64,0);      printf("%d\n",(int)ret64);
	nmppsDotProd_8s64s  ((nm8s*) src0_8s ,(nm64s*)src1_64s, 16 , &ret64);        printf("%d\n",(int)ret64);
                                                                                          
	nmppsDotProd_16s16sm ((nm16s*) src0_16s ,(nm16s*)src1_16s, 16 , &ret64,0);   printf("%d\n",(int)ret64);
	nmppsDotProd_16s32sm ((nm16s*) src0_16s ,(nm32s*)src1_32s, 16 , &ret64,0);   printf("%d\n",(int)ret64);
	nmppsDotProd_16s64s  ((nm16s*) src0_16s ,(nm64s*)src1_64s, 16 , &ret64);     printf("%d\n",(int)ret64);
                                                                                       
	nmppsDotProd_32s32sm ((nm32s*) src0_32s ,(nm32s*)src1_32s, 16 , &ret64,0);   printf("%d\n",(int)ret64);
	nmppsDotProd_32s64s  ((nm32s*) src0_32s ,(nm64s*)src1_64s, 16 , &ret64);     printf("%d\n",(int)ret64); 
	                                                
	nmppsDotProd_64s64s ((nm64s*) src0_32s ,(nm64s*)src1_64s, 16 , &ret64);      printf("%d\n",(int)ret64);
	
	
//	NmppsFFTSpec* specFwd256;
//	ret=nmppsFFT256FwdInitAlloc(&specFwd256, src0_32s, dst_32s, 0);
//	nmppsFFT256Fwd((nm32sc*)src0_32s,(nm32sc*)dst_32s,specFwd256);
//	nmppsFFTFree(specFwd256);
//
//	NmppsFFTSpec *specFFTInv256;
//	ret=nmppsFFT256InvInitAlloc(&specFFTInv256, src0_32s, dst_32s, 0);
//	nmppsFFT256Inv((nm32sc*)dst_32s,(nm32sc*)src0_32s,specFFTInv256);
//	nmppsFFTFree(specFFTInv256);
	
	
//	NmppsFFTSpec* specFwd512;
//	ret=nmppsFFT512FwdInitAlloc(&specFwd512, src0_32s, dst_32s, 0);
//	nmppsFFT512Fwd((nm32sc*)src0_32s,(nm32sc*)dst_32s,specFwd512);
//	nmppsFFTFree(specFwd512);
//	
//	NmppsFFTSpec *specFFTInv512;
//	ret=nmppsFFT512InvInitAlloc(&specFFTInv512, src0_32s, dst_32s, 0);
//	nmppsFFT512Inv((nm32sc*)dst_32s,(nm32sc*)src0_32s,specFFTInv512);
//	nmppsFFTFree(specFFTInv512);
	
//	NmppsFFTSpec* specFwd1024;
//	ret=nmppsFFT1024FwdInitAlloc(&specFwd1024, src0_32s, dst_32s, 0);
//	nmppsFFT1024Fwd((nm32sc*)src0_32s,(nm32sc*)dst_32s,specFwd1024);
//	nmppsFFTFree(specFwd1024);
	
//	NmppsFFTSpec *specFFTInv1024;
//	ret=nmppsFFT1024InvInitAlloc(&specFFTInv1024, src0_32s, dst_32s, 0);
//	nmppsFFT1024Inv((nm32sc*)dst_32s,(nm32sc*)src0_32s,specFFTInv1024);
//	nmppsFFTFree(specFFTInv1024);
	
	
	long t0;//=current_time();

	long t1;//=current_time();
//	printf("msec %d\n", (int)t1-(int)t0);

//	nmppsCmpNeC_8s ((nm8s*) src0_8s ,1200,(nm8s*) dst_8s, 256);
	
	
		//for(i=0; i<16; i++){
	//	printf("8s: %d %d\r\n", (int)src0_8s[i],(int)dst_8s[i]);
	//}


	
	
	//for(i=0; i<16; i++){
	//	printf("8s: %d %d\r\n", (int)src0_8s[i],(int)dst_8s[i]);
	//}

	
	//for(i=0; i<16; i++){
	//	printf("8s: %d %d\r\n", (int)src0_8s[i],(int)dst_8s[i]);
	//}
	
	
	
/*

	
	

	

*/	
//	
//	nmppsSubC_8s ((nm8s* )src0,1,(nm8s* )dst,16);
//	nmppsSubC_16s((nm16s*)src0,1,(nm16s*)dst,16);
//    nmppsSubC_32s((nm32s*)src0,1,(nm32s*)dst,16);
//	//nmppsSubC_64s((nm64s*)src0,1,(nm64s*)dst,16);
//	
//	
/**/

	
//	for(i=0; i<16; i++){
//		printf("8s: %d %d\r\n", (int)src0_8s[i],(int)dst_8s[i]);
//	}
//
//	for(i=0; i<16; i++){
//		printf("16s: %d %d\r\n", (int)src0_16s[i],(int)dst_16s[i]);
//	}
//
//	for(i=0; i<16; i++){
//		printf("32s: %d %d\r\n", (int)src0_32s[i],(int)dst_32s[i]);
//	}
//
//	for(i=0; i<16; i++){
//		printf("64s: %d %d\r\n", (int)src0_64s[i],(int)dst_64s[i]);
//	}
	
	//=====================
/*	
	for(i=0; i<2048*2; i++){
		src0_32s[i]=1;
		dst_32s[i]=0;
	}

	src0_32s[0]=1000;
	src0_32s[1]=1000;
	src0_32s[2]=1000;
	src0_32s[3]=1000;
	src0_32s[4]=1000;
	src0_32s[5]=1000;
	src0_32s[6]=1000;
	src0_32s[7]=1000;
	
	NmppsFFTSpec* specFwd256;
	ret=nmppsFFT256FwdInitAlloc(&specFwd256, src0_32s, dst_32s, 0);
	printf("****** ret=%d Handle=%x\r\n",ret ,specFwd256);
	//clock_t t0,t1;
	uint64_t t0,t1;
	//t0=clock();
	t0=aura_platform_timestamp();
	nmppsFFT256Fwd((nm32sc*)src0_32s,(nm32sc*)dst_32s,specFwd256);
	//t1=clock();
	t1=aura_platform_timestamp();
	printf("[fwd fft:] time=%llu\r\n",t1-t0);
	nmppsFFTFree(specFwd256);
	
	for(i=0; i<64; i++){
		printf("[fwd:] %d %d\r\n",dst_32s[i*2] ,dst_32s[i*2+1]);
	}
	
*/	
/*
	NmppsFFTSpec *specFFTInv256;
	ret=nmppsFFT256InvInitAlloc(&specFFTInv256, src0_32s, dst_32s, NMPP_OPTIMIZE_ALLOCATION_OFF);
	printf("****** ret=%d specFFTInv256=%x\r\n",ret ,(int)specFFTInv256);
	nmppsFFT256Inv((nm32sc*)dst_32s,(nm32sc*)src0_32s,specFFTInv256);
	nmppsFFTFree(specFFTInv256);
	
	for(i=0; i<64; i++){
		printf("[inv:] %d %d\r\n",src0_32s[i*2] ,src0_32s[i*2+1]);
	}
	*/
	//==================================================
	/*
	NmppsFFTSpec* specFwd512;
	ret=nmppsFFT512FwdInitAlloc(&specFwd512, src0_32s, dst_32s, 0);
	printf("****** ret=%d Handle=%x\r\n",ret ,specFwd512);
	nmppsFFT512Fwd((nm32sc*)src0_32s,(nm32sc*)dst_32s,specFwd512);
	nmppsFFTFree(specFwd512);
	
	for(i=0; i<64; i++){
		printf("[fwd:] %d %d\r\n",dst_32s[i*2] ,dst_32s[i*2+1]);
	}

	NmppsFFTSpec *specFFTInv512;
	ret=nmppsFFT512InvInitAlloc(&specFFTInv512, src0_32s, dst_32s, NMPP_OPTIMIZE_DISABLE);
	printf("****** ret=%d specFFTInv512=%x\r\n",ret ,(int)specFFTInv512);
	nmppsFFT512Inv((nm32sc*)dst_32s,(nm32sc*)src0_32s,specFFTInv512);
	nmppsFFTFree(specFFTInv512);
	
	for(i=0; i<64; i++){
		printf("[inv:] %d %d\r\n",src0_32s[i*2] ,src0_32s[i*2+1]);
	}
	
	//==================================================

	NmppsFFTSpec* specFwd1024;
	ret=nmppsFFT1024FwdInitAlloc(&specFwd1024, src0_32s, dst_32s, 0);
	printf("****** ret=%d Handle=%x\r\n",ret ,specFwd1024);
	nmppsFFT1024Fwd((nm32sc*)src0_32s,(nm32sc*)dst_32s,specFwd1024);
	nmppsFFTFree(specFwd1024);
	
	for(i=0; i<64; i++){
		printf("[fwd:] %d %d\r\n",dst_32s[i*2] ,dst_32s[i*2+1]);
	}

	NmppsFFTSpec *specFFTInv1024;
	ret=nmppsFFT1024InvInitAlloc(&specFFTInv1024, src0_32s, dst_32s, NMPP_OPTIMIZE_DISABLE);
	printf("****** ret=%d specFFTInv1024=%x\r\n",ret ,(int)specFFTInv1024);
	nmppsFFT1024Inv((nm32sc*)dst_32s,(nm32sc*)src0_32s,specFFTInv1024);
	nmppsFFTFree(specFFTInv1024);
	
	for(i=0; i<64; i++){
		printf("[inv:] %d %d\r\n",src0_32s[i*2] ,src0_32s[i*2+1]);
	}
*/
	//==================================================
	/*
	NmppsFFTSpec* specFwd2048;
	ret=nmppsFFT2048FwdInitAlloc(&specFwd2048, src0_32s, dst_32s, 0);
	printf("****** ret=%d Handle=%x\r\n",ret ,specFwd2048);
	nmppsFFT2048Fwd((nm32sc*)src0_32s,(nm32sc*)dst_32s,specFwd2048);
	nmppsFFTFree(specFwd2048);
	
	for(i=0; i<64; i++){
		printf("[fwd:] %d %d\r\n",dst_32s[i*2] ,dst_32s[i*2+1]);
	}

	NmppsFFTSpec *specFFTInv2048;
	ret=nmppsFFT2048InvInitAlloc(&specFFTInv2048, src0_32s, dst_32s, NMPP_OPTIMIZE_DISABLE);
	printf("****** ret=%d specFFTInv2048=%x\r\n",ret ,(int)specFFTInv2048);
	nmppsFFT2048Inv((nm32sc*)dst_32s,(nm32sc*)src0_32s,specFFTInv2048);
	nmppsFFTFree(specFFTInv2048);
	
	for(i=0; i<64; i++){
		printf("[inv:] %d %d\r\n",src0_32s[i*2] ,src0_32s[i*2+1]);
	}
*/
	//====================
	
	printf("======123=====\n");
	//int k=500;
	//while(k--)
	//	aura_handle_events_timeout(aura_eventloop_get_data(n), 500);
	aura_close(n);
	
	slog (0, SLOG_INFO, "Finished");

	return 0;
}


