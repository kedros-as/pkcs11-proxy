/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
#ifndef GCKRPC_UTIL__H_
#define GCKRPC_UTIL_H_

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"


void gck_rpc_info(const char *msg, ...);
void gck_rpc_warn(const char *msg, ...);
void gck_rpc_debug(const char *msg, ...);

void log_buff_hex(const char *data, size_t len);
void log_buff_hexs(const char *label, const char *data, size_t len);



#ifndef DEBUG_OUTPUT
#define DEBUG_OUTPUT 0
#endif

#if (DEBUG_OUTPUT == 1)
#define debug(x) gck_rpc_debug x
#else
#define debug(x)
#endif
#define info(x) gck_rpc_info x
#define warning(x) gck_rpc_warn x

#endif /* GCKRPC_UTIL_H_ */
