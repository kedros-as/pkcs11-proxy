cmake_minimum_required (VERSION 2.4)
# set(CMAKE_BUILD_TYPE Debug)
set ( VERBOSE 1 )

if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project (pkcs11 C)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package ( OpenSSL REQUIRED)
message(WARNING "OpenSSL_VERSION: ${OPENSSL_VERSION}")
message(WARNING "OpenSSL_INCLUDE_DIR: ${OPENSSL_INCLUDE_DIR}")
message(WARNING "OpenSSL_LIBRARIES: ${OPENSSL_LIBRARIES}")


set ( PKCS11_PROXY_SRCS gck-rpc-module.c gck-rpc-message.c gck-rpc-util.c egg-buffer.c gck-rpc-tls-psk.c )
#set ( PKCS11_DAEMON_SRCS egg-buffer.c gck-rpc-daemon-standalone.c gck-rpc-dispatch.c gck-rpc-message.c gck-rpc-util.c syscall-reporter.c syscall-names.h gck-rpc-tls-psk.c )
#set ( LIBTEST_SRCS libtest.c )

add_definitions(-Wall)
add_library(pkcs11-proxy SHARED ${PKCS11_PROXY_SRCS})

# Disable console when building Win32 binary in release mode
if (WIN32)
  if("${CMAKE_BUILD_TYPE}" MATCHES "^Rel.*")
    set(GUI_TYPE WIN32)
  endif()
endif()

#add_executable (pkcs11-daemon ${GUI_TYPE} ${PKCS11_DAEMON_SRCS})
#add_executable (libtest ${GUI_TYPE} ${LIBTEST_SRCS})

set_target_properties(pkcs11-proxy PROPERTIES VERSION 0.1 SOVERSION 0)

if (WIN32)
  include_directories("ext/include")


  include_directories(${OPENSSL_INCLUDE_DIR})
  list(APPEND LIB_LIST ${OPENSSL_LIBRARIES})

  add_library(dl STATIC IMPORTED)
  set_property(TARGET dl PROPERTY
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/ext/lib/libdl.a)

  #  target_link_libraries (pkcs11-daemon ws2_32)
  # target_link_libraries (pkcs11-proxy ws2_32)
endif (WIN32)

#target_link_libraries (pkcs11-proxy pthread ssl crypto)

target_link_libraries (pkcs11-proxy  -static pthread ${OPENSSL_LIBRARIES} ws2_32 )
#target_link_libraries (pkcs11-daemon dl pthread ssl crypto seccomp)
#target_link_libraries (libtest dl  )

install_targets (/lib pkcs11-proxy)
#install_targets (/bin pkcs11-daemon)
#install_targets (/bin libtest)

add_custom_command(
   OUTPUT syscall-names.h 
   COMMAND ${CMAKE_SOURCE_DIR}/mksyscalls.sh
   WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
