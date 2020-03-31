## COMPILE PRISMATIC-MASTER FROM SOURCE
## DEPENDENCIES 

You will have to install some tools and libraries in order to build prismatic form source:
 **Tools needed:**
 * Visual Studio 15 2017 (https://visualstudio.microsoft.com/fr/vs/older-downloads/)
 * CMake (https://cmake.org/download/)
 * 7zip (https://www.7-zip.org/)

 **Libraries: **
 * BOOST
 * FFTW3
 * HDF5

### BOOST
ressources:
	https://boostorg.github.io/build/manual/develop/index.html#bbv2.overview.configuration
	https://github.com/boostorg/wiki/wiki/Getting-Started%3A-Overview
	https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html

download from https://sourceforge.net/projects/boost/files/boost/1.72.0/ [boost_1_72_0.zip]

unzip then open a cmd in the directory
```
bootstrap
./b2 --build-dir="D:\Documents\Projets\CEA Grenoble Project\prismatic\required\boost-1.72.0-simple" --build-type=complete msvc stage
```

Use in a VS project: (test code https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html)
	Project properties
	All Configurations:
		- *Windows SDK Version* => 10.0.17763.0
		- *Tools* => Visual Studio 2019 (v142)
		- *C/C++/Additionnal Include Directories* => D:\Documents\Projets\CEA Grenoble Project\prismatic\required\boost_1_72_0
		- *Linker/General/Additionnal Library Directories* => D:\Documents\Projets\CEA Grenoble Project\prismatic\required\boost_1_72_0\stage\lib

### FFTW3
ressources : 
	https://www.youtube.com/watch?v=0qQm5AGB_18
	http://www.fftw.org/download.html

download from http://www.fftw.org/download.html [fftw-3.3.8.tar.gz]

unzip then untar 
```
tar xvf fftw-3.3.8.tar
```
Cmake Build with Visual Studio 15 2017
Check **BUILD_SHARED_LIBS**, **ENABLE_FLOAT** and **ENABLE_THREADS**
[Configure] then [Generate] and open the project in VS 2017

Right Click on the fftw3_threads and go to Properties/General:
	*Windows SDK Version* => 10.0.17763.0
	*Configuration Type* => Dynamic library (dll)

In the up bar, go to *Build/Batch Build* and check all the **fftw3_threads** options

Use in a VS project: (test code https://gist.github.com/damian-dz/a5d7d61993597253747b6dfe400805d9)
	Project properties
	All Configurations:
	- *C/C++/Additionnal Include Directories* => D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8\api
	- *Linker/Input/Additionnal Dependency* => fftw3.lib;...
	Debug
	- *Linker/General/Additionnal Library Directories* => D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8-simple\Debug
	- *Builds Events/Post-Build Event* => xcopy /d /y "D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8-simple\Debug\*.dll" "$(TargetDir)"
	Release
	- *Linker/General/Additionnal Library Directories* => D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8-simple\Release
	- *Builds Events/Post-Build Event* => xcopy /d /y "D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8-simple\Release\*.dll" "$(TargetDir)"

## HDF5
Go through these steps:

1. Change to the development directory "myhdfstuff".

2. Uncompress the HDF5 source file

3. Create a folder  "build" in the "myhdfstuff" directory.

4. Change into the "build" folder.

5. Configure the C library, tools and tests with one of the following commands:

 On Windows 32 bit
   cmake -G "Visual Studio 12 2013" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON ..\hdf5-1.10."X"

 On Windows 64 bit
   cmake -G "Visual Studio 12 2013 Win64" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON ..\hdf5-1.10."X"

 On Linux and Mac
   cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON ../hdf5-1.10."X"

 where "X" is the current release version.

6. Build the C library, tools and tests with this command:
   cmake --build . --config Release

7. Test the C library and tools with this command:
   ctest . -C Release

8. Create an install image with this command:
   cpack -C Release CPackConfig.cmake

9. To install
 On Windows (with WiX installed), execute:
        HDF5-1.10."X"-win32.msi or HDF5-1.10."X"-win64.msi
 By default this program will install the hdf5 library into the
 "C:\Program Files" directory and will create the following
 directory structure:
    HDF_Group
    --HDF5
    ----1.10."X"
    ------bin
    ------include
    ------lib
    ------cmake

 On Linux, change to the install destination directory
 (create if doesn't exist) and execute:
        <path-to>/myhdfstuff/build/HDF5-1.10."X"-Linux.sh
 After accepting the license, the script will prompt:
   By default the HDF5 will be installed in:
   "<current directory>/HDF5-1.10."X"-Linux"
   Do you want to include the subdirectory HDF5-1.10."X"-Linux?
   Saying no will install in: "<current directory>" [Yn]:
 Note that the script will create the following directory structure
 relative to the install point:
    HDF_Group
    --HDF5
    ----1.10."X"
    ------bin
    ------include
    ------lib
    ------share
