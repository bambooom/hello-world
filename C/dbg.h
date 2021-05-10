// first two line means if not define it, then define it
#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

// commonly use NDEBUG for not debugging
#ifdef NDEBUG
#define debug(M, ...) // then do nothing with debug()
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d:%s " M "\n", \
    __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ )
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

// log_err log_warn log_info will not be compiled out like debug
// study errno: `man 3 strerror`
#define log_err(M, ...) fprintf(stderr, \
    "[ERROR] (%s:%d:%s errno: %s) " M "\n", __FILE__, __LINE__, __FUNCTION__, \
    clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, \
    "[WARN] (%s:%d:%s errno: %s) " M "\n", __FILE__, __LINE__, __FUNCTION__, \
    clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, \
    "[INFO] (%s:%d:%s) " M "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

// check is like assert, check A, if is true nothing, if false, goto error part
// errno=0 means clear the err
#define check(A, M, ...) if (!(A)) {\
    log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); \
    errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

// soft error, clear error
#define check_debug(A, M, ...) if (!(A)) { debug(M, ##__VA_ARGS__);\
    errno=0; goto error; }

#endif
