//------------------------------------------------------------------------
//
//  $Workfile:: Abs.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   Abs.Asm
//! \author ������ �������
//! \brief  ���������� �������� ��������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vArithm.h"

extern _VEC_TBL_Diagonal_FFFFFFFFh_G:long;
extern vec_Abs:label;

begin ".text_nmplv"


//! \fn void nmppsAbs (nm32s *pSrcVec, nm32s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsAbs__FPiPii.html

global _nmppsAbs__FPiPii:label;
global _void._.8.8nmppsAbs.1int._.0.9._int._.0.9._int.2 :label;
<_nmppsAbs__FPiPii>
<_void._.8.8nmppsAbs.1int._.0.9._int._.0.9._int.2>
.branch;
	ar5 = sp - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	sb	= 00000002h	with gr0++;
	nb1 = 80000000h	with gr6=gr0;
	ar6 = _VEC_TBL_Diagonal_FFFFFFFFh_G;
	rep 2 wfifo=[ar6++],ftw;
	
	ar0 = [--ar5];	// pSrcVec
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize
	wtw;
						
	delayed call  vec_Abs with gr5>>=1;	// nSize in 64-bit longs
		f1cr= 80000000h;   

	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;


end ".text_nmplv";
