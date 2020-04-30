## Compile Prismatic-master from source
### Tools:   
You will have to install some tools and libraries in order to build prismatic from source:
 
 **Tools needed :**
 * *Visual Studio 15 2017* (https://visualstudio.microsoft.com/fr/vs/older-downloads/)
 * *CMake* (https://cmake.org/download/)
 * *7zip* (https://www.7-zip.org/)
 
  **Others Tools (Python library and GPU) :**
  * *Anaconda 3.7* (https://visualstudio.microsoft.com/fr/vs/older-downloads/)
  * *CUDA* (https://visualstudio.microsoft.com/fr/vs/older-downloads/)

 **Libraries :**
 * [BOOST](#boost)
 * [FFTW3](#fftw3)
 * [HDF5](#hdf5)
 
 **Compilation :**
 * [Prismatic](#prismatic)
 * [Prismatic Gui](#prismatic-gui)
 * [Pyprismatic]()   
 
### Folder organisation: 
For a clarity matter, and to help the user to do the process without having errors from the links, I will put my personal config for this configuration with the links like that: ```D:\...\```**```fftw\Build64\```**
> You can edit the first part if you don't want the same config than me, if not, you can put your folders wherever you want.

The global organisation of my folders look like that: 
```
(TODO)

```   

## BOOST
### Ressources:
* https://boostorg.github.io/build/manual/develop/index.html#bbv2.overview.configuration  
* https://github.com/boostorg/wiki/wiki/Getting-Started%3A-Overview  
* https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html  
* https://stackoverflow.com/questions/43946538/how-to-build-boost-1-64-in-64-bits/43950508

### Compile BOOST: 
#### 1. Download [boost_1_72_0.zip](https://sourceforge.net/projects/boost/files/boost/1.72.0/)  
#### 2. Unzip the file and put it in ```D:\Libraries\```
#### 3. Create a new folder where the library will be compiled 
```
mkdir D:\Libraries\boost_1_72_0\Build64
mkdir D:\Libraries\boost_1_72_0\Build32
```
#### 3.1 Open a cmd in the *Boost* directory  
```
cd D:\Libraries\boost_1_72_0
bootstrap
```
> We use there the automatic compiler for boost: b2 (previously named bjam).   
> Edit --build-dir="BuildXX" with the path (absolute or relative) to the folder where the library will be built.   
> It's recommanded not to change the followings parameters and do not edit the ```stage``` at the end.   
> The build will be in a subfolder named "stage".  

**Win32bit system:**
```
b2 -j8 --build-dir="Build32" toolset=msvc-14.1 threading=multi runtime-link=shared --build-type=complete stage 
```  
**Win64bit system**
```
b2 -j8 --build-dir="Build64" toolset=msvc-14.1 address-model=64 architecture=x86 link=static threading=multi runtime-link=shared --build-type=complete stage 
```
   
> ```-j8``` indicate the number of threads availlable to compile this library to faster the build (boost is a raltively big library so the process take some time to compile, but don't put more threas than availlable because it can result in errors.   
> ```build-dir``` is the directory for the temporaryy files and the build settings.  
> ```toolset``` is the compilator, mscv-14.1 (to 15) for the Visual Studio 2017 compilator.   
> ```address-model``` and architecture permit to have the library in x64 while building on a x86 machine.  
> ```link``` is for building the library into static mode (I also want to build fftw in static instead of dynamic but I don't know if it is possible).   
> ```theading``` is for using the threads (compilation of library use?)   
> ```stage``` at the end is the folder where the library will be built. I though I could change it to put my own name for the compilation folder but then the library didn't worked well... (to test?)   

  
**Linux system**
```
(TODO)
```

### Test BOOST: 
#### 4. Open Visual Studio 2017 and create a new C++ console application project into a new directory
```
mkdir D:\Libraries\boost_1_72_0\BuildTest
```
#### 4.1 Add the test code from [here](https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html) at the point 6 (Link Your Program to a Boost Library)   
```
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }
}
```   
#### 4.2 Edit the project properties
Select **All Configurations:** in the top menu and also select the right **Plateform**
* *Windows SDK Version* => ```10.0.17763.0```    
* *Tools* => ```Visual Studio 2019 (v142)```  
* *C/C++/Additionnal Include Directories* => ```D:\Libraries\boost_1_72_0```   
* *Linker/General/Additionnal Library Directories* => ```D:\Libraries\boost_1_72_0\stage\lib```  

Select the right plateform at the left of the Run button and then run the code. You can write your mail as a string and it will extract the subject with the regex library from boost.  
*Try with this:*
```
This is some test text, only for test purposes. This shouldn't be re-printed by the regex program.
```
*Then test with this:*
```
Subject: This is the subject of the mail that should be printed.
``` 

## FFTW3
### Ressources:
* https://www.youtube.com/watch?v=0qQm5AGB_18
* http://www.fftw.org/download.html

### Compile FFTW:  
#### 1. Download [fftw-3.3.8.tar.gz](http://www.fftw.org/download.html)  
#### 2. Unzip, extract the file then Untar it in ```D:\Libraries``` with
```
tar xvf fftw-3.3.8.tar (or tar xvf fftw-3.3.8.tar.gz to do the whole process)
```
#### 3. Create a new folder (ex: *fftw-3.3.8/Build64*) where the library will be compiled
```
mkdir D:\Libraries\fftw-3.3.8\Build64
mkdir D:\Libraries\fftw-3.3.8\Build32
```
#### 3.1 Open a cmd in this folder
> We use the cmake tool to build the fftw library. 
> If cmake is not found in the command, add it to the PATH environment variable the link to 'path\to\CMake\bin'. 
> All the parameters of the compilation must begin with -D.     

**Win32bit system:**
```
cd D:\Libraries\fftw-3.3.8\Build32

(TOCHECK)
cmake -DBUILD_SHARED_LIBS:BOOL=ON -DENABLE_FLOAT:BOOL=ON -DENABLE_THREADS:BOOL=ON D:\Libraries\fftw-3.3.8"

cmake --build . --config Release & cmake --build . --config Debug
```
**Win64bit system:**
```
cd D:\Libraries\fftw-3.3.8\Build64

cmake -DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_TESTS:BOOL=ON -DDISABLE_ALLOCA:BOOL=ON -DDISABLE_STATIC:BOOL=ON -DENABLE_FLOAT:BOOL=ON -DENABLE_SHARED:BOOL=ON -DENABLE_THREADS:BOOL=ON -DWITH_COMBINED_THREADS:BOOL=ON -DWITH_OUR_MALLOC16:BOOL=ON "D:\Libraries\fftw-3.3.8"

cmake --build . --config Release & cmake --build . --config Debug
```

**Linux system**
```
--disable-alloca: as of this writing (14 July 2009), the alloca function seems to be broken under the 64-bit MinGW compilers, so when compiling for Win64 you should pass --disable-alloca to tell FFTW not to use that function  
--with-our-malloc16: this is required in order to allocate properly aligned memory (for SSE) with gcc  
--with-windows-f77-mangling: this will include Fortran wrappers for some common Windows Fortran compilers (GNU, Intel, and Digital).  
--enable-shared --disable-static: this will create DLLs instead of static libraries (since MinGW's static-library format seems to be different from Microsoft's).  
--enable-threads --with-combined-threads: this will include multi-threading support. The second option puts the multi-threading functions into the main FFTW DLL rather than into a separate DLL (the default under Unix); this is required because MinGW can't create DLLs that depend on one another.  
--enable-portable-binary: required if you want to create DLLs that will work on any Intel processor.  
--with-incoming-stack-boundary=2: compile FFTW assuming a 4-byte alignment. On win32, some versions of gcc assume that the stack is 16-byte aligned, but code compiled with other compilers may only guarantee a 4-byte alignment, resulting in mysterious segfaults.  

-----------------------------------------------------------------------------
./configure --disable-alloca --with-our-malloc16 --enable-shared --disable-static --enable-float --enable-threads --with-combined-threads
make
make install
```

### Test FFTW:   
> To build the default version of this library in x32, use 
```
mkdir D:\Libraries\fftw-3.3.8\Build32Default & cd D:\Libraries\fftw-3.3.8\Build32Default

cmake -DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_TESTS:BOOL=ON -DDISABLE_ALLOCA:BOOL=ON -DDISABLE_STATIC:BOOL=ON -DENABLE_SHARED:BOOL=ON -DENABLE_THREADS:BOOL=ON -DWITH_COMBINED_THREADS:BOOL=ON -DWITH_OUR_MALLOC16:BOOL=ON "D:\Libraries\fftw-3.3.8"

cmake --build . --config Release & cmake --build . --config Debug
```  
> You can't test the float version of fftw <-DENABLE_FLOAT> with the test code I give, so build a default version for test is a good idea   

#### 4. Open Visual Studio 2017 and create a new C++ console application project into a new directory
```
mkdir D:\Libraries\fftw-3.3.8\BuildTest
```
#### 4.1 Add the test code from [here](https://gist.github.com/damian-dz/a5d7d61993597253747b6dfe400805d9) 
#### 4.2 Edit the project properties
Select **All Configurations:** in the top menu and also select the right **Plateform**
* *C/C++/Additionnal Include Directories* => ```D:\Libraries\fftw-3.3.8\api```  
* *Linker/Input/Additionnal Dependency* => ```fftw3.lib;(default system libraries)```  
	
Select **Debug:** in the top menu
* *Linker/General/Additionnal Library Directories* => ```D:\Libraries\fftw-3.3.8\Build32Default\Debug```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "D:\Libraries\fftw-3.3.8\Build32Default\Debug\*.dll" "$(TargetDir)"```  
	
Select **Release:** in the top menu 
* *Linker/General/Additionnal Library Directories* => ```D:\Libraries\fftw-3.3.8\Build32Default\Release```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "D:\Libraries\fftw-3.3.8\Build32Default\Release\*.dll" "$(TargetDir)"``` 

> Make sure that the compilation is done on the right plateform (x64 or x84) on the top bar or you will have an conflict error message. Also, make sure that the rights .dll are linked at the right compilation version (Debug and Release).   
> FFTW is only compilable in the dynamic version, so the program .exe need the fftw3.dll (or fftw3d.dll for the float version) on the same folder in order to work.   
> the post build event with ```xcopy``` copy the .dll in the .exe folder, but if it don't work, you will have an error when launching the .exe that say that the fftw3.dll is missing. You will have to search for this dll in the compiled fftw folder and manually copy it to the .exe program folder.   

## HDF5
### Ressources:
* https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/release_docs/INSTALL_CMake.txt  
* https://support.hdfgroup.org/HDF5/release/cmakebuild.html    
* https://stackoverflow.com/questions/24325508/getting-stared-with-hdf5-on-visual-studio-2013-with-visual-c-2013
* https://stackoverflow.com/questions/7397296/linking-hdf5-library-into-visual-c-dll-project-unresolved-external-symbol-i
* https://svn.oss.deltares.nl/repos/openearthtools/trunk/fortran/io/netcdf/win32/visual_fortran_6/lib/win32/all/

*Not necessary*: [zlib](http://gnuwin32.sourceforge.net/packages/zlib.htm)

### Compile HDF5:    
#### 1. Download [hdf5-1.12.0.zip](https://hdf-wordpress-1.s3.amazonaws.com/wp-content/uploads/manual/HDF5/HDF5_1_12_0/source/hdf5-1.12.0.zip)  
#### 2. Unzip the file and put it in ```D:\Libraries\```
#### 2.1 Create a new folder (ex: *hdf5-1.12.0/Build64*) where the library will be compiled
```
mkdir 
mkdir D:\Libraries\hdf5-1.12.0\Build32
```
#### 2.2 Open a cmd in this directory
> Once again we use the cmake tool, this time it's to build hdf5.   
> All the parameters of the compilation must begin with -D.   
> We only build the Release version for prismatic, if you want both versions, edit ```-DCMAKE_BUILD_TYPE:STRING```  

**Win32bit system:**
```  
cd D:\Libraries\hdf5-1.12.0\Build32

cmake -G "Visual Studio 15 2017 Win32" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON -DHDF5_ENABLE_THREADSAFE:BOOL=ON -DALLOW_UNSUPPORTED:BOOL=ON -DBUILD_TESTING:BOOL=ON "D:\Libraries\hdf5-1.12.0"

cmake --build . --config Release
```  
**Win64bit system:**
```  
cd D:\Libraries\hdf5-1.12.0\Build64

cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON -DHDF5_ENABLE_THREADSAFE:BOOL=ON -DALLOW_UNSUPPORTED:BOOL=ON -DBUILD_TESTING:BOOL=ON "D:\Libraries\hdf5-1.12.0"

cmake --build . --config Release 
```
**Linux system**
```
(TODO)
```
> This will take some time... If you want to build the Debug library, replace in the commands the ```Release``` by ```Debug```*

#### 2.3 Now, we will use the cpack tool to build a Package with the compiled library:
```
cpack -C Release CPackConfig.cmake 
```
> A package with the compiled library has been created (ex: *hdf5-1.12.0/Build64/HDF5-1.12.0-win64.zip*).   
> Extract it to the same directory: ```D:\Libraries\hdf5-1.12.0\Build64\HDF5-1.12.0-win64```

### Test HDF5:  
#### 3. Open a cmd in the compiled directory
```
cd D:\Libraries\hdf5-1.12.0\Build64
ctest . -C Release 
``` 
#### 3.1 Check that all Tests are *Passed* 
#### 4. Open Visual Studio 2017 and create a new C++ console application project into a new directory
```
mkdir D:\Libraries\hdf5-1.12.0\BuildTest
```
#### 4.1 Add the test code from [here](https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/c++/examples/h5tutr_crtdat.cpp)
#### 4.2 Edit the project properties
Select **All Configurations:** in the top menu and also select the right **Plateform**
* *C/C++/Additionnal Include Directories* => ```D:\Libraries\hdf5-1.12.0\Build64\HDF5-1.12.0-win64\include```  
* *Linker/Genral/Additionnal Libraries repertory* => ```D:\Libraries\hdf5-1.12.0\Build64\HDF5-1.12.0-win64\lib```
* *Linker/Input/Additionnal Dependency* => ```libhdf5.lib;libhdf5_cpp.lib;(default system libraries)```  

#### (TEMPORARY PASTEBIN)
* https://sourceforge.net/projects/nsis/files/NSIS%203/3.05/nsis-3.05-setup.exe/download?use_mirror=netix&download=
* https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/release_docs/USING_HDF5_VS.txt  
* https://www.youtube.com/watch?v=BAjsCldRMMc  

## PRISMATIC
### Ressources:
* https://prism-em.com/docs-compiling/
* https://www.it-swarm.dev/fr/visual-c%2B%2B/erreur-fatale-lnk1112-le-type-de-machine-du-module-x64-est-en-conflit-avec-le-type-de-machine-cible-x86/969200768/

*You can add the libraries directory to the PATH if you want, otherwise you will have to complete the links manually later...*
* <kbd>Windows</kbd> + "Path" => Edit environment variables/Environment variables/Path/Edit/New

#### 1. Download [prismatic](https://github.com/prism-em/prismatic)
```
git clone https://github.com/prism-em/prismatic.git 
```
#### 2. Create a new folder (ex: *prismatic-master/Build64*) where the library will be compiled
#### 3. Open the CMake GUI  
#### 3.1 Complete the links with the code source directory and the build directory  
#### 3.2 Click on *Configure* and select *Visual Studio 15 2017*
**Win32 system**
* Select ```Win32``` in the Optional Plateform Generator

**Win64 system**
* Select ```x64``` in the Optional Plateform Generator

**Linux system**
```
(TODO)
```
#### 3.3 Complete the missing links to the compiled libraries:
**FFTW:**  
* *FFTW_INCLUDE_DIR* => ```path/to/fftw/api```
* *FFTW_LIBRARY* => ```path/to/fftw```

**HDF5:**  
* *HDF5_hdf5_LIBRARY_DEBUG* => ```path/to/hdf5/Debug```
* *HDF5_hdf5_LIBRARY_RELEASE* => ```path/to/hdf5/Release```

**CHECK:**  
**Win32 system**
* *CMAKE_EXE_LINKER_FLAGS* => ```/machine:X86```
* *CMAKE_SHARED_LINKER_FLAGS* => ```/machine:X86```
* *CMAKE_MODULE_LINKER_FLAGS* => ```/machine:X86```
* *CMAKE_STATIC_LINKER_FLAGS* => ```/machine:X86```

**Win64 system**
* *CMAKE_EXE_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_SHARED_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_MODULE_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_STATIC_LINKER_FLAGS* => ```/machine:X64```

**Linux system**
```
(TODO)
```


#### 3.4 Click again on *Configure* and if nothing is red, click on *Generate*
#### 4. Open the project in Visual Studio 2017
#### 4.1 Right Click on the **prismatic** project and go to Properties/General:

* *Windows SDK Version* => ```10.0.17763.0```
* *Configuration Type* => ```Dynamic library (dll)```
* *Plateform tools* => ```Visual Studio 2017 (v141)```
* *Configurations tools* => ```Application (.exe)```

**All Configurations:**  
* *C/C++/Additionnal Include Directories* => ```Path\to\prismatic\include; Path\to\fftw\api; Path\to\hdf5\include; Path\to\boost\```  
* *Linker/Input/Additionnal Dependency* => ```fftw3f.lib; libhdf5.lib; libhdf5_cpp.lib; libhdf5_hl_cpp.lib; libhdf5_hl.lib;...```  
> The order in wich the libraries are linked is realy important, that's even more true when you have like here a program with many links to others libraries, and that these libraries use the base functions of others libraries.   
> Like always, the ```...``` at the end are the base system libraries added by default by VS, just add the new before these.   

* **Win32 system**
* *Linker/Input/Advanced/Target computer* => ```MachineX86 (/MACHINE:X86)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X64```

* **Win64 system**
* *Linker/Input/Advanced/Target computer* => ```MachineX64 (/MACHINE:X64)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X86```

* **Linux system**
```
(TODO)
```


**Debug:**  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\compiled\Debug```  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\hdf5(Debug)\lib```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "Path\to\fftw\compiled\Debug\*.dll" "$(TargetDir)"```  
  
**Release:**   
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\compiled\Release```  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\hdf5(Release)\lib```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "Path\to\fftw\compiled\Release\*.dll" "$(TargetDir)"``` 


#### 5. In the top bar, select: 
**Win32 system**
* **Release x32** then Run  

**Win64 system**
* **Release x64** then Run  

**Linux system**
```
(TODO)
```

#### 6. Get the **prismatic.exe** and **fftwf.dll** files at Path\to\prismatic\compiled\x64\Release

### Test:  
#### 7. Copy the **prismatic.exe** and **fftwf.dll** files in a new directory
#### 7.1 Create a new file "SI100.XYZ" in this directory
#### 7.1 Open it and paste these datas:
```
one unit cell of (100) silicon
      5.43    5.43    5.43
  14  0.0000  0.0000  0.0000  1.0  0.076
  14  2.7150  2.7150  0.0000  1.0  0.076
  14  1.3575  4.0725  1.3575  1.0  0.076
  14  4.0725  1.3575  1.3575  1.0  0.076
  14  2.7150  0.0000  2.7150  1.0  0.076
  14  0.0000  2.7150  2.7150  1.0  0.076
  14  1.3575  1.3575  4.0725  1.0  0.076
  14  4.0725  4.0725  4.0725  1.0  0.076
  -1
```

#### 8. Open a cmd in the directory
```
prismatic.exe --input-file "Path\to\the\directory\SI100.XYZ"
```

#### 8.1 Wait for the *PRISM Calculation complete* message to be displayed
#### 8.2 If you have python with the hdf5 library, you can use this to explore the HDF file
```
import h5py

#Recursively find the subfiles and display the structure like the tree function
def recursiveHDF(f, pathstring=''):
    #Test if it is an hdf subfolder
    if hasattr(f, 'keys'):
        
        #List the subkeys of this folder
        subkeys = list(f.keys())
        
        #Test if it is empty
        if len(subkeys) == 0:
            print(pathstring + '└─── empty')
        else:
            #Print every subdirectory
            for s in range(len(subkeys)):
                subkey = subkeys[s]
                if(s+1==len(subkeys)):
                    print(pathstring + '└─── ' + subkey)
                    recursiveHDF(f[subkey], pathstring+'     ')
                else:
                    print(pathstring + '├─── ' + subkey) 
                    recursiveHDF(f[subkey], pathstring+'│    ')
    else:
        print(pathstring + '└─── matrix' + str(f.shape))

f = h5py.File('path\to\output.h5', 'r')
recursiveHDF(f)
```

#### (TEMPORARY PASTEBIN)
* git clone https://code.qt.io/qt/qt5.git
* https://www.qt.io/download-qt-installer
* https://wiki.qt.io/Building_Qt_5_from_Git

## PRISMATIC GUI
### Ressources:
* https://www.qt.io/
* https://stackoverflow.com/questions/6626397/error-lnk2019-unresolved-external-symbol-winmain16-referenced-in-function

#### 1. Download [Qt](http://ftp.fau.de/qtproject/archive/online_installers/3.2/qt-unified-windows-x86-3.2.2-online.exe)
#### 1.1 Create an Qt account [here](https://login.qt.io/register)
#### 1.2 Select in the installer:
**Win32 system**
* **Qt 5.14.2 mscv2017 x32**

**Win64 system**
* **Qt 5.14.2 mscv2017 x64**

**Linux system**
```
(TODO)
```
#### 2. Create a new folder (ex: *prismatic-master/Build64GUI*) where the library will be compiled
#### 2.1 Open **prismatic-master.pro** (Path/to/prismatic/Qt/*) in a text editor and add ```CONFIG += console```
#### 2.2 (Optional) Open CMakeLists.txt in the prismatic-master source code and check that the paths to the icons are good (if not replace ../Qt by Qt).

#### 3. Open the CMake GUI  
#### 3.1 Complete the links with the code source directory and the build directory  
#### 3.2 Click on Configure and select Visual Studio 15 2017
**Win32 system**
* Select ```Win32``` in the Optional Plateform Generator

**Win64 system**
* Select ```x64``` in the Optional Plateform Generator

**Linux system**
```
(TODO)
```

#### 3.3 Check **PRISMATIC_ENABLE_CLI** and **PRISMATIC_ENABLE_GUI**
#### 3.4 Complete the missing links to the compiled libraries:
**QT5:**
**Win32 system**
* *QT5Widgets_DIR* => ```path/to/Qt/5.14.2/msvc2017_32/lib/cmake/Qt5Widgets```

**Win64 system**
* *QT5Widgets_DIR* => ```path/to/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5Widgets```

**Linux system**
```
(TODO)
```

**FFTW:**
* *FFTW_INCLUDE_DIR* => ```path/to/fftw/api```
* *FFTW_LIBRARY* => ```path/to/fftw```

**HDF5:**
* *HDF5_hdf5_LIBRARY_DEBUG* => ```path/to/hdf5/Debug```
* *HDF5_hdf5_LIBRARY_RELEASE* => ```path/to/hdf5/Release```

**CHECK:**
* **Win32 system**
* *CMAKE_EXE_LINKER_FLAGS* => ```/machine:X86```
* *CMAKE_SHARED_LINKER_FLAGS* => ```/machine:X86```
* *CMAKE_MODULE_LINKER_FLAGS* => ```/machine:X86```
* *CMAKE_STATIC_LINKER_FLAGS* => ```/machine:X86```

* **Win64 system**
* *CMAKE_EXE_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_SHARED_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_MODULE_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_STATIC_LINKER_FLAGS* => ```/machine:X64```

* **Linux system**
```
(TODO)
```

#### 3.5 Click again on Configure and if nothing is red, click on Generate
#### 4. Open the project in VS 2017
#### 4.1 Select both **prismatic** and **prismatic-gui** with *Ctrl* + *Click*
#### 4.2 Right Click on a project and go to Properties/General:
* *Windows SDK Version* => ```10.0.17763.0```
* *Configuration Type* => ```Dynamic library (dll)```
* *Plateform tools* => ```Visual Studio 2017 (v141)```
* *Configurations tools* => ```Application (.exe)```

*All Configurations:*  
* *C/C++/Additionnal Include Directories* => 
```
path\to\FFTW\api;
path\to\HDF5\include;
path\to\BOOST;  
  
path\to\prismatic-master;
path\to\prismatic-master\include;
path\to\prismatic-master\Qt;  
  
path\to\prismatic-target;
path\to\prismatic-target\prismatic-gui_autogen\include_Release;  
...
```  

* **Win32 system**
```
...
path\to\Qt\5.14.2\msvc2017_32; 
path\to\Qt\5.14.2\msvc2017_32\include;
path\to\Qt\5.14.2\msvc2017_32\include\QtWidgets;
path\to\Qt\5.14.2\msvc2017_32\include\QtGui;
path\to\Qt\5.14.2\msvc2017_32\include\QtCore;

```  

* **Win64 system**
```
...
path\to\Qt\5.14.2\msvc2017_64; 
path\to\Qt\5.14.2\msvc2017_64\include;
path\to\Qt\5.14.2\msvc2017_64\include\QtWidgets;
path\to\Qt\5.14.2\msvc2017_64\include\QtGui;
path\to\Qt\5.14.2\msvc2017_64\include\QtCore;

```  

* **Linux system**
```
(TODO)
```


*Release:* 
* *Linker/Input/Additionnal Dependency* => 
```
fftw3f.lib;
libhdf5_hl.lib;
libhdf5.lib;
libhdf5_hl_cpp.lib;
libhdf5_cpp.lib;
Qt5Widgets.lib;
Qt5Gui.lib;
Qt5Core.lib;
qtmain.lib;
shell32.lib;
WindowsApp.lib;
...
```  

* *Linker/General/Additionnal Library Directories* => 
```
path\to\HDF5\Build\lib;
path\to\FFTW\Build\Release;
path\to\BOOST\stage\lib;
...
```  

* **Win32 system**
```  
...
path\to\Qt\5.14.2\msvc2017_32\lib;
``` 

* **Win64 system**
```  
...
path\to\Qt\5.14.2\msvc2017_64\lib;
``` 

* **Linux system**
```
(TODO)
```

* *Builds Events/Post-Build Event* => (You can add these manually or use the automatic post build Event) 
```
copy /y "Path\to\fftw\Build\Release\fftw3f.dll" "$(TargetDir)"

copy /y "Path\to\Qt\5.14.2\msvc2017_64\bin\Qt5Core.dll" "$(TargetDir)"
copy /y Path\to\Qt\5.14.2\msvc2017_64\bin\Qt5Gui.dll" "$(TargetDir)"
copy /y "Path\to\Qt\5.14.2\msvc2017_64\bin\Qt5Widgets.dll" "$(TargetDir)"

mkdir "$(TargetDir)\platforms"
copy /y "Path\to\Tools\QtCreator\bin\libEGL.dll" "$(TargetDir)\platforms"
copy /y "Path\to\5.14.2\msvc2017_64\plugins\platforms\qwindows.dll" "$(TargetDir)\platforms"
``` 
**CHECK:**
* *Linker/System/Sub-System* => Windows (/SUBSYSTEM:WINDOWS)
* *Linker/Advanced/Importation libraries* => D:/Documents/Projets/CEA Grenoble Project/PrismaticGUI/Release/prismatic-gui.lib
* *C/C++/Preprocessor/Preprocessor definition* => ```WIN32;_WINDOWS;NDEBUG;PRISMATIC_BUILDING_GUI=1;PRISMATIC_ENABLE_GUI;PRISMATIC_ENABLE_CLI;QT_WIDGETS_LIB;QT_GUI_LIB;QT_CORE_LIB;QT_NO_DEBUG;CMAKE_INTDIR="Release";```

### Test Prismatic Performances:  
**Win32 and Win64 system**
* Open a Windows PowerShell in the prismatic/Build/Release folder and add the data test file "SI100.XYZ"
```  
Measure-Command {.\prismatic.exe --input-file "SI100.XYZ"}
``` 

**Linux system**
```
(TODO)
```

**Example comparing the Base Build (316ms for this simple file) and the GPU Build (857ms for one file, but should be more effective the more complex and time-consuming the computations are for the CPU)**
``` 
#Base Build  
Measure-Command {.\prismatic.exe --input-file "SI100.XYZ"}  
  
Days              : 0  
Hours             : 0  
Minutes           : 0  
Seconds           : 0  
Milliseconds      : 316  
Ticks             : 3163259  
TotalDays         : 3,66117939814815E-06  
TotalHours        : 8,78683055555556E-05  
TotalMinutes      : 0,00527209833333333  
TotalSeconds      : 0,3163259  
TotalMilliseconds : 316,3259  

#GPU Build  
Measure-Command {.\prismatic.exe --input-file "SI100.XYZ"}  
  
Days              : 0  
Hours             : 0  
Minutes           : 0  
Seconds           : 0  
Milliseconds      : 857  
Ticks             : 8571921  
TotalDays         : 9,92120486111111E-06  
TotalHours        : 0,000238108916666667  
TotalMinutes      : 0,014286535  
TotalSeconds      : 0,8571921  
TotalMilliseconds : 857,1921  
``` 
