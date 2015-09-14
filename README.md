bitfield Version 0.1 September 1, 2015
======================================

bitfield is a library of functions for creating, modifying and destroying bit 
fields (or bit arrays), i.e. series of zeroes and ones spread across an array 
of storage units (unsigned long integers).

Usage
-----

To use functions provided by bitfield library in a project, one needs to:
- add "#include <bitfield.h>" to the source file, and
- compile the program with a "-lbitfield" flag.

Please, see "examples" directory for working examples.

Installation
------------

To compile and install bitfield from source code, issue:

$ ./configure --prefix=PREFIX
$ make
$ make install
$ ldconfig

Please see the file called INSTALL.

Licensing
---------

bitfield is free software, and is released under the terms of the GNU General 
Public License version 3. Please see the file called LICENSE.
