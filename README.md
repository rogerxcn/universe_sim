# Simulator for Hilariously Interesting extraTerrestrial Objects
---
### Environment Setup and Compilation

We used C++ to program this simulator. All compilation and testing are conducted under Windows 10 + Jetbrains CLion + mingw-w64 environment, with library glu (-lglu32), freeglut (-lfreeglut), and OpenGL (-lopengl32). The specific steps are reproduced in the following section:

#### 1. Install mingw-w64
First, install mingw-w64 at https://sourceforge.net/projects/mingw-w64/ (the same installer is included in the dependencies folder) and make sure all integrated gl & glu libraries are installed. They should appear under
${mingw-w64}\i686-7.3.0-posix-dwarf-...-rev0\mingw32\i686-w64-mingw32\include\GL.
(Note that using mingw32 instead of mingw-w64 will cause runtime error. )

#### 2. Install freeglut library
Unzip freeglut library and copy all the include\, bin\, lib\ folders into the corresponding directories under
${mingw-w64}\i686-7.3.0-posix-dwarf-rt_v5-rev0\mingw32\, and
${mingw-w64}\i686-7.3.0-posix-dwarf-rt_v5-rev0\mingw32\i686-w64-mingw32.

#### 3. Compile with CLion
Update toolchain settings in CLion (and restart CLion if necessary) and use mingw-w64 to compile the project. The project should compile and run without any error.

---

### Pre-compiled executable
A compiled UniSim.exe executable is also included with the submission. It should be launched from a mingw-w64 terminal with libraries installed from step 2.
