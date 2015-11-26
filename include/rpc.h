#ifdef RPC
#include <aura/aura.h>
#include <ion/ion.h>
#include <memory.h>

extern struct aura_node *n;


#define RPC_PPI(func,src,dst,size) \
	int ret;	\
    struct aura_buffer *iobuf_src = aura_buffer_request(n, size);	\
	struct aura_buffer *iobuf_dst = aura_buffer_request(n, size);	\
	memcpy(iobuf_src->data,src,size);	\
	struct aura_buffer *retbuf; \
	ret = aura_call(n, func, &retbuf,  iobuf_src, iobuf_dst, size); \
	if (ret != 0) \
	    BUG(n, "Call func failed!"); \
	memcpy(dst,iobuf_dst->data,size); \
	aura_buffer_release(n, iobuf_dst); \
	aura_buffer_release(n, iobuf_src); \
	aura_buffer_release(n, retbuf); \
	slog(0, SLOG_INFO, "ARM: Call func ok"); 



#define RPC_PPPI(func,src0,src1,dst,size) \
	int ret;	\
    struct aura_buffer *iobuf_src0 = aura_buffer_request(n, size);	\
	struct aura_buffer *iobuf_src1 = aura_buffer_request(n, size);	\
	struct aura_buffer *iobuf_dst = aura_buffer_request(n, size);	\
	memcpy(iobuf_src0->data,src0,size);	\
	memcpy(iobuf_src1->data,src1,size);	\
	struct aura_buffer *retbuf; \
	ret = aura_call(n, func, &retbuf,  iobuf_src0, iobuf_src1, iobuf_dst, size); \
	if (ret != 0) \
	    BUG(n, "Call func failed!"); \
	memcpy(dst,iobuf_dst->data,size); \
	aura_buffer_release(n, iobuf_dst); \
	aura_buffer_release(n, iobuf_src1); \
	aura_buffer_release(n, iobuf_src0); \
	aura_buffer_release(n, retbuf); \
	slog(0, SLOG_INFO, "ARM: Call func ok"); 

	
#define RPC_PIPI(func,src,val,dst,size) \
	int ret;	\
    struct aura_buffer *iobuf_src = aura_buffer_request(n, size);	\
	struct aura_buffer *iobuf_dst = aura_buffer_request(n, size);	\
	memcpy(iobuf_src->data,src,size);	\
	struct aura_buffer *retbuf; \
	ret = aura_call(n, "func", &retbuf,  iobuf_src, val, iobuf_dst, size); \
	if (ret != 0) \
	    BUG(n, "Call func failed!"); \
	memcpy(dst,iobuf_dst->data,size); \
	aura_buffer_release(n, iobuf_dst); \
	aura_buffer_release(n, iobuf_src); \
	aura_buffer_release(n, retbuf); \
	slog(0, SLOG_INFO, "ARM: Call func ok"); 

	
#endif