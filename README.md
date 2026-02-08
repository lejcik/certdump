# CertViewer

[![Build and test](https://github.com/lejcik/certdump/actions/workflows/test.yml/badge.svg)](https://github.com/lejcik/certdump/actions/workflows/test.yml)

Certificate dumper is a library that dumps information about a certificate file. Currently it supports viewing of X.509 certificates in the following formats: PEM (Base64 encoding), DER (encoded binary).

The library is based on the [OpenSSL project](http://www.openssl.org/) and it automates `openssl` commands,
that parse and dump information from certificate files. Moreover, it does automatic detection of a file format, and supports most of the common certificate file formats.

## Contributing

This is my first project where I used the *OpenSSL* library. I don't feel as a security expert, so your contributions are welcome. Here are some ways you can contribute:

* [Submit Issues](https://github.com/lejcik/certdump/issues)
* [Submit Fixes and New Packages](https://github.com/lejcik/certdump/pulls)

## License

Code licensed under the [MIT license](LICENSE.txt).
