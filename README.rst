
PKCS11 Proxy
============

This fork has the following additional features:

- support for running in "inetd mode", useful for calling directly from stunnel
- seccomp syscall filtering (only tested in inetd-mode)
- getaddrinfo support for IPv6, fallback and DNS resolution
- TLS-PSK support to optionally encrypt communication

Plus a number of important bug fixes. This version passes the SoftHSM test
suite.

An ubuntu PPA that tracks this version is ppa:leifj

Build and Install for windows
=============================

I used crosscompiler on MAC to create 64b staticaly linked (with openssl 
an gcc runtime)  pkcs11-proxy.dll

- set correct compilers binaries in Toolchain-cross-mingw64.cmake file
- set correct paths in CMAKE_FIND_ROOT_PATH variable for toolchain and openssl 
- Comment out all targets except client library (pkcs11-proxy). Only client 
  library is currently supported for 64bit version.   
- build library 

        $ mkdir build
        $ cd build

        $ cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-cross-mingw32.cmake ..
        $ make VERBOSE=1
- install libpkcs11-proxy.dll 
        
        cp libpkcs11-proxy.dll C:/path/to/application




