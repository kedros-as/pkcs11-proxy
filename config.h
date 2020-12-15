#ifndef CONFIG_H
# define CONFIG_H

# define DEBUG_OUTPUT 1 // change to 1 to enable debugging

# define PKCS11PROXY_LISTEN_BACKLOG 128
# define PKCS11PROXY_MAX_SESSION_COUNT 256

# define PKCS11PROXY_TLS_PSK_CIPHERS "PSK-AES128-CBC-SHA:PSK-AES256-CBC-SHA";

//# define DEBUG_SECCOMP
//# define SECCOMP

#ifdef __MINGW32__

# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <winsock2.h>
# include <sys/types.h>

typedef uint32_t __uid32_t;
typedef uint32_t __gid32_t;
typedef uint32_t uid_t;

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long  __u64;

//typedef int socklen_t;

union sigval {
	int sival_int;
	void *sival_ptr;
};
typedef struct {
	int si_signo;
	int si_code;
	union sigval si_value;
	int si_errno;
	pid_t si_pid;
	uid_t si_uid;
	void *si_addr;
	int si_status;
	int si_band;
} siginfo_t;

#define O_CLOEXEC 0
#define MSG_NOSIGNAL 0

struct sockaddr_un {
	uint16_t sun_family;
	char sun_path[PATH_MAX];
};

enum  {
	SHUT_RD = 0, /* No more receptions.  */
	SHUT_WR, /* No more transmissions.  */
	SHUT_RDWR /* No more receptions or transmissions.  */
};

#ifdef  __MINGW32__
static inline int inet_aton(const char * cp, struct in_addr *pin)
{
        int rc = inet_addr(cp);
        if (rc == -1 && strcmp(cp, "255.255.255.255"))
                return 0;

        pin->s_addr = rc;
        return 1;
}
#endif

#endif

#endif	/* CONFIG_H */
