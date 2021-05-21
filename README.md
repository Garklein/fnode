# fnode

## Setup

Clone or download this repository

### Fortran setup

You will need a Fortran compiler (I used [GFortran](https://gcc.gnu.org/wiki/GFortran))  
You need to install a version building for 64 bit, otherwise this will break. If you're using GFortran, you can do this by choosing the "x86_64" architecture on the settings screen.

### Node setup

I used [node-gyp](https://github.com/nodejs/node-gyp) for creating the addon, but you could also use something like [CMake.js](https://github.com/cmake-js/cmake-js)  
For whichever you choose to use, just follow all the instructions on its Github page to install it.  

Note: don't try to actually build the addon yet, you'll get tons of errors.

## Building this stencil

### Building the Fortran

Compile [main.f90](./src/main.f90) into an object file. With GFortran: `gfortran -c main.f90 -o fortran.o -m64`  

### Building the actual addon

To build the addon (these commands for node-gyp but just follow the corresponding instructions for anything else you might be using,) run `node-gyp configure` followed by `node-gyp build`.

## Errors you might get

### debugging info corrupt

I have no idea why this happens, but to fix this, I run `node-gyp rebuild`

### module machine type 'X86' conflicts with target machine type 'x64'

Your Fortran compiler is not compiling for 64 bits. Make sure you have the (if you're using GFortran) -m64 flag at the end.

#### sorry, unimplemented: 64 bit mode not compiled in

If compiling with GFortran, this means you've installed the 32 bit architecture. Reinstall it with 64 bit architecture (see above).

## Also check out the [Node.js addon documentation](https://nodejs.org/api/addons.html)

where I stole most of the c++ code from
