// Copyright (c) 2026 Viliam Lejcik.  Licensed under the MIT License.
// SPDX-License-Identifier: MIT

#ifndef _CERTDUMP_H
#define _CERTDUMP_H

#include <functional>

// functor prototype for password callback handler,
// params:
// - char *buffer - callback stores the password into the buffer
// - int size     - length of the buffer
// return: password length in bytes, or -1 on error
using PasswordCallback = std::function<int(char*, int)>;

// dumps the provided certificate file into output FILE, calls password callback only
// when the file is password protected, returns TRUE on success
bool DumpCertificate(const char *certFile, const char *outFile, PasswordCallback callback);

#endif // _CERTDUMP_H
