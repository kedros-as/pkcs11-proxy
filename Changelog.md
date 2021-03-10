# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

# [2.0.0-kdrRC1] - 2021-03-10
### Added
- Add build info in README
- Add debug of ULONG and Attribute array in protocol message
- Add warning on not defined PKCS11_PROXY_SOCKET environmnent variable
- Add support for respawn a new child daemon on a new connection arrival 
  and common cmake config for our building platforms
- add cleaned logs level, dissabled debug logs, on dissabled debug log only into syslog
- add common cmake config for linux mac for windows cross compiling

### Fixed
- Add fix for 64b linux and windows inter-platform compatability and detailed debug logging
- Add forced conversion of ck_ulong type to 64b ecoding at client side
