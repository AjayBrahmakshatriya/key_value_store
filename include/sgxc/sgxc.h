#ifndef SGXC
#define SGXC

#define SECRET
#define NONSECRET

#define secret_malloc(x) malloc(x)
#define nonsecret_malloc(x) malloc(x)


#endif
