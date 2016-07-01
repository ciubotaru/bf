bitfield
========

Version 0.4.0 (March 20, 2016)

bitfield is a library of functions for creating, modifying and destroying bit 
fields (or bit arrays), i.e. series of zeroes and ones spread across an array 
of storage units (unsigned long integers).

Installation
------------

To compile bitfield from source code:

    $ autoconf
    $ ./configure --prefix=DIRECTORY
    $ make

This will build both a static and a shared version. To build just one of them, 
replace "make" with "make static" or "make shared".

To test the compiled library:

    $ make check

The generic way to install the compiled files is:

    $ make install
    $ ldconfig

However, one might prefer to use distro-specific installation mechanism (like 
"checkinstall") instead.

Usage
-----

Using the functions provided by bitfield library in a project is 
straightforward.
If bitfield library files are installed system-wide in standard locations, then 
one needs to (1) include a system version of the header file to the source

    #include <bitfield.h>

and (2) add the "-lbitfield" flag to compiler instructions

    gcc ... -lbitfield

Alternatively, if bitfield library is integrated into a project, then one needs 
to (1) include a local version of the header file to the source

    #include "PATH_TO_HEADER/bitfield.h"

and (2) add the "-lbitfield" flag, along with the path to the header and path 
to the library to compiler instructions

    gcc ... -I$(PATH_TO_HEADER) -L$(PATH_TO_LIBRARY) -lbitfield

Functions
---------

For function syntax, see "bitfield.h". For details on every function, see its 
manual page.

bf2int() converts the bit array to an array of integers.

bf2long() converts the bit array to an array of long integers.

bf2str() converts a bitfield into a character string of ones and zeroes,
starting from the least significant bit.

bf2str_ip() converts a bitfield into a character string of ones and zeroes,
starting from the least significant bit "in-place".

bfand() performs bitwise AND over a pair of bitfields.

bfcat() concatenates two bitfields into one.

bfclearall() clears all bits in a bitfield (i.e. fills the bitfield with 
zeroes).

bfclearbit() clears one bit in a bitfield.

bfclone() creates a copy of an existing bitfield.

bfcmp() compares two bitfields and returns 0 if same or non-zero and error 
message if different.

bfcpy() copies the contents of a bitfield into another pre-existing bitfield.

bfdel() destroys a bitfield structure and frees memory.

bfgetbit() checks the state of a bit in a bitfield.

bfhamming() counts the Hamming distance between two bitfields.

bfisempty() checks whether all bit of an array are unset.

bfnew() creates an empty bitfield structure, and returns a pointer to it.

bfnew_ones() creates a bitfield structure, sets all its bits to true with and 
returns a pointer to it.

bfnew_quick() creates a bitfield structure and returns a pointer to it.

bfnormalize() represents a bitfield as a smallest value of a closed ring.

bfnot() reverses all bits in a bitfield and return the result in new bitfield.

bfnot_ip() reverses all bits in a bitfield "in place".

bfor() performs bitwise inclusive OR over a pair of bitfields.

bfpopcount() counts the set bits in a bitfield.

bfpos() checks whether an array of bits contains a sub-array.

bfprint() prints a bitfield as a series of ones and zeroes, left to right, the
least significant bit first.

bfresize() resizes an existing bitfield.

bfrev() reverses the order of bits in a bitfield and returns result in new 
bitfield.

bfrev_ip() reverses the order of bits in a bitfield.

bfsetall() sets all bits in a bitfield (i.e. fills it with ones).

bfsetbit() sets one bit in a bitfield.

bfshift() circular-shifts the contents of a bitfield and return the result in 
new bitfield.

bfshift_ip() circular-shifts the contents of a bitfield "in place".

bfsize() obtains the number of bits of a bitfield.

bfsub() extracts a sub-bitfield from a bitfield.

bftogglebit() toggles (i.e. reverses the state of) a bit in a bitfield.

bfxor() performs bitwise exclusive OR over a pair of bitfields.

int2bf() converts an array of integers into a bitfield structure.

long2bf() converts an array of long integers into a bitfield structure.

str2bf() converts a character string of ones and zeroes into a bitfield,
starting from the least significant bit.

str2bf_ip() converts a character string of ones and zeroes into a bitfield,
starting from the least significant bit "in-place".

Please, see "examples" directory for working examples.

Licensing
---------

bitfield is free software, and is released under the terms of the GNU General 
Public License version 3 or any later version. Please see the file called 
LICENSE.
