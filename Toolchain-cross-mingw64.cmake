# the name of the target operating system
SET(CMAKE_SYSTEM_NAME Windows)
set(TOOLCHAIN_PREFIX x86_64-w64-mingw32)

# cross compilers to use for C, C++ and Fortran
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++)
set(CMAKE_Fortran_COMPILER ${TOOLCHAIN_PREFIX}-gfortran)
set(CMAKE_RC_COMPILER ${TOOLCHAIN_PREFIX}-windres)

# here is the target environment located
if ( CMAKE_HOST_APPLE )
	SET(CMAKE_FIND_ROOT_PATH   /usr/local/Cellar/mingw-w64/8.0.0/bin/ /opt/kedros/mingw64/openssl)
else ( CMAKE_HOST_APPLE )
	set(CMAKE_FIND_ROOT_PATH /usr/${TOOLCHAIN_PREFIX} /var/tmp/openssl.win)
endif ( CMAKE_HOST_APPLE )


# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

