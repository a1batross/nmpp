//***************************************************************************/
//*                     RC Module Inc., Moscow, Russia                      */
//*                     NeuroMatrix(r) NM6403 Software                      */
//*                                                                         */
//*   Vector Processing  Library                                            */
//*   (C-callable functions)                                                */
//*                                                                         */
//*   $Workfile:: Prod64.asm                                               $*/
//*                                                                         */
//*   Contents:        Shift routines                                       */
//*                                                                         */
//*   Software design: Lukashevich Pavel                                    */
//*                                                                         */
//*   Version          1.0                                                  */
//*   Start date:      17.0.2002                                            */
//*   Release  $Date: 2004/11/22 13:50:11 $*/
//*                                                                         */
//*                                                                         */
//***************************************************************************/
//#include "vProd.h"

import from macros.mlb;

begin ".text_nmplv"
.branch;

//! \fn void nmppsDotProd (nm8s *pSrcVec1, nm64s *pSrcVec2, int nSize, int64b *pnRes) 
//!
//! \perfinclude _nmppsDotProd__FPcPliPl.html

global _nmppsDotProd__FPcPliPl:label;
global _void._.8.8nmppsDotProd.1char._.0.9._long._.0.9._int.9._long._.0.2 :label;
<_nmppsDotProd__FPcPliPl>
<_void._.8.8nmppsDotProd.1char._.0.9._long._.0.9._int.9._long._.0.2>
	ar5 = sp - 2;

	PUSH_REGS();

	ar0 = [--ar5];	// Input0 buffer
	ar4 = [--ar5];	// Input1 buffer
	gr6 = [--ar5];	// V0,V1 vectors Size
	ar6 = [--ar5];	// Output buffer 

	sb	= 02020202h;
	gr7 = 00000000h;
	nb1 = gr7 with gr6>>=3;


	rep 8 wfifo=[ar4++],ftw;
	.wait;
		nb1 = gr7 with gr6--;
		rep 1 wtw with vfalse;
	.branch;

<NextMul08>
	rep 1 data=[ar0++] with vsum, data,afifo;
	rep 8 wfifo=[ar4++],ftw;
	if > delayed goto NextMul08;
		.wait;
			nb1 = gr7 with gr6--;
			wtw;
		.branch;
	
	rep 1 [ar6] = afifo;

	POP_REGS();

return;

.wait;
end ".text_nmplv"; 
