## Compile Prismatic-master from source
You will have to install some tools and libraries in order to build prismatic from source:
 
 **Tools needed :**
 * *Visual Studio 15 2017* (https://visualstudio.microsoft.com/fr/vs/older-downloads/)
 * *CMake* (https://cmake.org/download/)
 * *7zip* (https://www.7-zip.org/)

 **Libraries :**
 * [BOOST](#boost)
 * [FFTW3](#fftw3)
 * [HDF5](#hdf5)
 
 **Compilation :**
 * [Prismatic](#prismatic)
 * [Pyprismatic]()

## BOOST
### Ressources:
* https://boostorg.github.io/build/manual/develop/index.html#bbv2.overview.configuration  
* https://github.com/boostorg/wiki/wiki/Getting-Started%3A-Overview  
* https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html  

### Compile: 
#### 1. Download [boost_1_72_0.zip](https://sourceforge.net/projects/boost/files/boost/1.72.0/)  
#### 2. Unzip the file
#### 3. Open a cmd in the directory  
```
bootstrap

./b2 --build-dir="Path\to\the\build\directory" --build-type=complete msvc stage
```

### Test: 
#### 4. Create a new VS 2017 project
#### 4.1 Add the test code from https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html
#### 4.2 Edit the project properties
**All Configurations:**  
* *Windows SDK Version* => ```10.0.17763.0```    
* *Tools* => ```Visual Studio 2019 (v142)```  
* *C/C++/Additionnal Include Directories* => ```Path\to\boost```   
* *Linker/General/Additionnal Library Directories* => ```Path\to\boost\stage\lib```  

## FFTW3

### Ressources:
* https://www.youtube.com/watch?v=0qQm5AGB_18
* http://www.fftw.org/download.html

### Compile:  
#### 1. Download [fftw-3.3.8.tar.gz](http://www.fftw.org/download.html)  
#### 2. Unzip then Untar the file with
```
tar xvf fftw-3.3.8.tar
```
#### 3. Open the Cmake GUI  
#### 3.1 Complete the links with the code source directory and the build directory  
#### 3.2 Click on Configure and select Visual Studio 15 2017  
#### 3.3 Check **BUILD_SHARED_LIBS**, **ENABLE_FLOAT** and **ENABLE_THREADS**  
#### 3.4 Click again on Configure and if nothing is red, click on Generate
#### 4. Open the project in VS 2017
#### 4.1 Right Click on the fftw3_threads and go to Properties/General:  
* *Windows SDK Version* => ```10.0.17763.0```
* *Configuration Type* => ```Dynamic library (dll)```

#### 4.2 In the menu bar, go to *Build/Batch Build* and check all the **fftw3_threads** options and compile


### MINGW:
#### Go to \Mingw\msys\1.0 and launch the linux simulated environnement with msys.bat 
#### Info compilation: path to the fftw source code
```
./configure --help
```
#### Redefine the right options
```
--disable-alloca: as of this writing (14 July 2009), the alloca function seems to be broken under the 64-bit MinGW compilers, so when compiling for Win64 you should pass --disable-alloca to tell FFTW not to use that function  
--with-our-malloc16: this is required in order to allocate properly aligned memory (for SSE) with gcc  
--with-windows-f77-mangling: this will include Fortran wrappers for some common Windows Fortran compilers (GNU, Intel, and Digital).  
--enable-shared --disable-static: this will create DLLs instead of static libraries (since MinGW's static-library format seems to be different from Microsoft's).  
--enable-threads --with-combined-threads: this will include multi-threading support. The second option puts the multi-threading functions into the main FFTW DLL rather than into a separate DLL (the default under Unix); this is required because MinGW can't create DLLs that depend on one another.  
--enable-portable-binary: required if you want to create DLLs that will work on any Intel processor.  
--with-incoming-stack-boundary=2: compile FFTW assuming a 4-byte alignment. On win32, some versions of gcc assume that the stack is 16-byte aligned, but code compiled with other compilers may only guarantee a 4-byte alignment, resulting in mysterious segfaults.  
```
```
./configure --disable-alloca --with-our-malloc16 --enable-shared --disable-static --enable-float --enable-threads --with-combined-threads
make
make install
```


### Test:   
#### 5. Create a new VS 2017 project
#### 5.1 Add test code https://gist.github.com/damian-dz/a5d7d61993597253747b6dfe400805d9
#### 5.2 Edit the project properties
*All Configurations:*  
* *C/C++/Additionnal Include Directories* => ```Path\to\fftw\api```  
* *Linker/Input/Additionnal Dependency* => ```fftw3.lib;...```  
	
*Debug:*  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\compiled\Debug```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "Path\to\fftw\compiled\Debug\*.dll" "$(TargetDir)"```  
	
*Release:*  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\compiled\Release```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "Path\to\fftw\compiled\Release\*.dll" "$(TargetDir)"``` 

## HDF5
### Ressources:
* https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/release_docs/INSTALL_CMake.txt  
* https://support.hdfgroup.org/HDF5/release/cmakebuild.html    
* https://stackoverflow.com/questions/24325508/getting-stared-with-hdf5-on-visual-studio-2013-with-visual-c-2013
* https://stackoverflow.com/questions/7397296/linking-hdf5-library-into-visual-c-dll-project-unresolved-external-symbol-i
* https://svn.oss.deltares.nl/repos/openearthtools/trunk/fortran/io/netcdf/win32/visual_fortran_6/lib/win32/all/

(Not necessary: zlib : http://gnuwin32.sourceforge.net/packages/zlib.htm)

### Compile:    
#### 1. Download [hdf5-1.12.0.zip](https://hdf-wordpress-1.s3.amazonaws.com/wp-content/uploads/manual/HDF5/HDF5_1_12_0/source/hdf5-1.12.0.zip)  
#### 2. Unzip the file
#### 2.1 Create a new folder where the library will be compiled
#### 2.2 Open a cmd in the created directory
```  
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON -DHDF5_ENABLE_THREADSAFE:BOOL=ON -DALLOW_UNSUPPORTED:BOOL=ON -DBUILD_TESTING:BOOL=ON path\to\hdf5

cmake --build . --config Release

cpack -C Release CPackConfig.cmake
```

### Test:  
#### 3. Open a cmd in the compiled directory
```ctest . -C Release``` 
#### 3.1 Check that 2027/2027 Tests are *Passed* 

#### 5. Create a new VS 2017 project
#### 5.1 Add test code https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/c++/examples/h5tutr_crtdat.cpp
#### 5.2 Edit the project properties
*All Configurations:*  
* *C/C++/Additionnal Include Directories* => ```Path\to\hdf5\include```  
* *Linker/Genral/Additionnal Libraries repertory* => Path\to\hdf5\lib
* *Linker/Input/Additionnal Dependency* => ```libhdf5.lib;libhdf5_cpp.lib;...```  


#### TEMPORARY
* https://sourceforge.net/projects/nsis/files/NSIS%203/3.05/nsis-3.05-setup.exe/download?use_mirror=netix&download=
* https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/release_docs/USING_HDF5_VS.txt  
* https://www.youtube.com/watch?v=BAjsCldRMMc  

#### TODO...


## PRISMATIC
https://prism-em.com/docs-compiling/

In the MakeFile replace 
FIND_PACKAGE(Boost) 
by
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()
