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
 * [Prismatic](#prismatic_gui)
 * [Pyprismatic]()

## BOOST
### Ressources:
* https://boostorg.github.io/build/manual/develop/index.html#bbv2.overview.configuration  
* https://github.com/boostorg/wiki/wiki/Getting-Started%3A-Overview  
* https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html  


https://stackoverflow.com/questions/43946538/how-to-build-boost-1-64-in-64-bits/43950508
### Compile: 
#### 1. Download [boost_1_72_0.zip](https://sourceforge.net/projects/boost/files/boost/1.72.0/)  
#### 2. Unzip the file
#### 3. Create a new folder where the library will be compiled
#### 3.1 Open a cmd in the directory  
```
bootstrap

./b2 --build-dir="Path\to\the\build\directory" --build-type=complete msvc stage
```

b2 -j8 toolset=msvc-14.1 address-model=64 architecture=x86 link=static threading=multi runtime-link=shared --build-type=complete stage --build-dir="BUILD" 

### Test: 
#### 4. Create a new VS 2017 project
#### 4.1 Add the test code from [here](https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html)  
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
#### 3. Create a new folder where the library will be compiled
#### 3.1 Open a cmd in this folder
```
cmake -G "Visual Studio 15 2017 Win64" -DBUILD_SHARED_LIBS:BOOL=ON -DENABLE_FLOAT:BOOL=ON -DENABLE_THREADS:BOOL=ON ../
cmake --build . --config Release
cmake --build . --config Debug
```

#### LINUX
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

### Test (for the default fftw compiled without --enable-float and --enable-threads):   
#### 4. Create a new VS 2017 project
#### 4.1 Add the test code from [here](https://gist.github.com/damian-dz/a5d7d61993597253747b6dfe400805d9) 
#### 4.2 Edit the project properties
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

*Not necessary*: [zlib](http://gnuwin32.sourceforge.net/packages/zlib.htm)

### Compile:    
#### 1. Download [hdf5-1.12.0.zip](https://hdf-wordpress-1.s3.amazonaws.com/wp-content/uploads/manual/HDF5/HDF5_1_12_0/source/hdf5-1.12.0.zip)  
#### 2. Unzip the file
#### 2.1 Create a new folder where the library will be compiled
#### 2.2 Open a cmd in the created directory
```  
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON -DHDF5_ENABLE_THREADSAFE:BOOL=ON -DALLOW_UNSUPPORTED:BOOL=ON -DBUILD_TESTING:BOOL=ON path\to\hdf5

cmake --build . --config Release
cmake --build . --config Debug

cpack -C Release CPackConfig.cmake
cpack -C Debug CPackConfig.cmake
```

### Test:  
#### 3. Open a cmd in the compiled directory
```ctest . -C Release``` 
#### 3.1 Check that 2027/2027 Tests are *Passed* 

#### 5. Create a new VS 2017 project
#### 5.1 Add the test code from [here](https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/c++/examples/h5tutr_crtdat.cpp)
#### 5.2 Edit the project properties
*All Configurations:*  
* *C/C++/Additionnal Include Directories* => ```Path\to\hdf5\include```  
* *Linker/Genral/Additionnal Libraries repertory* => ```Path\to\hdf5\lib```
* *Linker/Input/Additionnal Dependency* => ```libhdf5.lib;libhdf5_cpp.lib;...```  


#### TEMPORARY
* https://sourceforge.net/projects/nsis/files/NSIS%203/3.05/nsis-3.05-setup.exe/download?use_mirror=netix&download=
* https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/release_docs/USING_HDF5_VS.txt  
* https://www.youtube.com/watch?v=BAjsCldRMMc  

## PRISMATIC
### Ressources:
* https://prism-em.com/docs-compiling/
* https://www.it-swarm.dev/fr/visual-c%2B%2B/erreur-fatale-lnk1112-le-type-de-machine-du-module-x64-est-en-conflit-avec-le-type-de-machine-cible-x86/969200768/

*You can add the libraries directory to the PATH if you want, otherwise you will have to complete the links manually later...*
* <kbd>Windows</kbd> PATH > Edit environment variables > Environment variables > Select Path > Edit > New



#### 1. Download [prismatic](https://github.com/prism-em/prismatic)
```
git clone https://github.com/prism-em/prismatic.git 
```
#### 2. Create a new folder where the library will be compiled
#### 3. Open the Cmake GUI  
#### 3.1 Complete the links with the code source directory and the build directory  
#### 3.2 Click on Configure and select Visual Studio 15 2017 x64
#### 3.3 Complete the missing links to the compiled libraries:
* *FFTW_INCLUDE_DIR* => ```path/to/fftw/api```
* *FFTW_LIBRARY* => ```path/to/fftw```

* *HDF5_hdf5_LIBRARY_DEBUG* => ```path/to/hdf5/Debug```
* *HDF5_hdf5_LIBRARY_RELEASE* => ```path/to/hdf5/Release```

* *CMAKE_EXE_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_SHARED_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_MODULE_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_STATIC_LINKER_FLAGS* => ```/machine:X64```

#### 3.4 Click again on Configure and if nothing is red, click on Generate
#### 4. Open the project in VS 2017
#### 4.1 Right Click on the **prismatic** project and go to Properties/General:

* *Windows SDK Version* => ```10.0.17763.0```
* *Configuration Type* => ```Dynamic library (dll)```
* *Plateform tools* => ```Visual Studio 2017 (v141)```
* *Configurations tools* => ```Application (.exe)```

*All Configurations:*  
* *C/C++/Additionnal Include Directories* => ```Path\to\prismatic\include; Path\to\fftw\api; Path\to\hdf5\include; Path\to\boost\```  
* *Linker/Input/Additionnal Dependency* => ```fftw3f.lib; libhdf5.lib; libhdf5_cpp.lib; libhdf5_hl_cpp.lib; libhdf5_hl.lib;...```  
* *Linker/Input/Advanced/Target computer* => ```MachineX64 (/MACHINE:X64)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X86```

*Debug:*  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\compiled\Debug```  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\hdf5(Debug)\lib```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "Path\to\fftw\compiled\Debug\*.dll" "$(TargetDir)"```  
  
*Release:*  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\compiled\Release```  
* *Linker/General/Additionnal Library Directories* => ```Path\to\fftw\hdf5(Release)\lib```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "Path\to\fftw\compiled\Release\*.dll" "$(TargetDir)"``` 


#### 5. In the top bar, select ```Release x64``` then Run
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
#### 8.2 If you have python with the hdf5, cv2 and numpy installed, you can use this to visualise the image
```
import cv2
import numpy as np
import h5py
f = h5py.File('Path/to/the/folder/output.h5', 'r')
dset = f['key']
data = np.array(dset[:,:,:])
file = 'output.jpg'
cv2.imwrite(file, data)
```

### TEMP
git clone https://code.qt.io/qt/qt5.git
https://www.qt.io/download-qt-installer
https://wiki.qt.io/Building_Qt_5_from_Git


## PRISMATIC GUI
### Ressources:
* https://www.qt.io/
* https://stackoverflow.com/questions/6626397/error-lnk2019-unresolved-external-symbol-winmain16-referenced-in-function

#### 1. Download [Qt](http://ftp.fau.de/qtproject/archive/online_installers/3.2/qt-unified-windows-x86-3.2.2-online.exe)
#### 1.1 Create an Qt account here[https://login.qt.io/register]
#### 1.2 Select **Qt 5.14 mscv2017 x64** in the installer

#### 2. Create a new folder where the library will be compiled
#### 2.1 Open Path/to/prismatic/Qt/prismatic-master.pro in a text editor and add ```CONFIG += console```
#### 2.2 (Optional) Open CMakeLists.txt in the prismatic-master source code and check that the paths to the icons are good (if not replace ../Qt by Qt).

#### 3. Open the Cmake GUI  
#### 3.1 Complete the links with the code source directory and the build directory  
#### 3.2 Click on Configure and select Visual Studio 15 2017 x64
#### 3.3 Check **PRISMATIC_ENABLE_CLI** and **PRISMATIC_ENABLE_GUI**
#### 3.4 Complete the missing links to the compiled libraries:
* *QT5Widgets_DIR* => ```path/to/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5Widgets```

* *FFTW_INCLUDE_DIR* => ```path/to/fftw/api```
* *FFTW_LIBRARY* => ```path/to/fftw```

* *HDF5_hdf5_LIBRARY_DEBUG* => ```path/to/hdf5/Debug```
* *HDF5_hdf5_LIBRARY_RELEASE* => ```path/to/hdf5/Release```

* *CMAKE_EXE_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_SHARED_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_MODULE_LINKER_FLAGS* => ```/machine:X64```
* *CMAKE_STATIC_LINKER_FLAGS* => ```/machine:X64```

#### 3.5 Click again on Configure and if nothing is red, click on Generate

#### 4. Open the project in VS 2017
#### 4.1 Select both **prismatic** and **prismatic-gui** with <kbd>Ctrl</kbd> + </kbd>Click</kbd>
#### 4.2 Right Click on a project and go to Properties/General:
* *Windows SDK Version* => ```10.0.17763.0```
* *Configuration Type* => ```Dynamic library (dll)```
* *Plateform tools* => ```Visual Studio 2017 (v141)```
* *Configurations tools* => ```Application (.exe)```

*All Configurations:*  
* *C/C++/Additionnal Include Directories* => 
```
D:\Documents\Projets\CEA Grenoble Project\PrismaticGUI\prismatic-gui_autogen\include_Release;
D:\Programmes\Qt\5.14.2\msvc2017_64\include;D:\Documents\Projets\CEA Grenoble Project\libs\fftw\fftw-3.3.8\api;
D:\Documents\Projets\CEA Grenoble Project\libs\hdf5\hdf5-1.12.0-WIN64\include;
D:\Documents\Projets\CEA Grenoble Project\prismGUI\prismatic-master;
D:\Documents\Projets\CEA Grenoble Project\PrismaticGUI;D:\Documents\Projets\CEA Grenoble Project\libs\prismatic-master\include;
D:\Documents\Projets\CEA Grenoble Project\libs\boost\boost-1.66.0-WIN64;
D:\Documents\Projets\CEA Grenoble Project\libs\prismatic-master\Qt;
D:\Programmes\Qt\5.14.2\msvc2017_64;D:\Programmes\Qt\5.14.2\msvc2017_64\include\QtWidgets;D:\Programmes\Qt\5.14.2\msvc2017_64\include\QtGui;
D:\Programmes\Qt\5.14.2\msvc2017_64\include\QtCore;D:\Documents\Projets\CEA Grenoble Project\prismGUI\prismatic-master\Qt
```  

*Release:* 
* *Linker/Input/Additionnal Dependency* => ```fftw3f.lib;libhdf5_hl.lib;libhdf5.lib;libhdf5_hl_cpp.lib;libhdf5_cpp.lib;Qt5Widgets.lib;Qt5Gui.lib;Qt5Core.lib;qtmain.lib;shell32.lib;WindowsApp.lib;...```  

* *Linker/General/Additionnal Library Directories* => 
```
D:\Documents\Projets\CEA Grenoble Project\libs\hdf5\hdf5-1.12.0-WIN64\lib;
D:\Documents\Projets\CEA Grenoble Project\libs\fftw\fftw-3.3.8\BUILD\Release;
D:\Programmes\Qt\5.14.2\msvc2017_64\lib;
D:\Documents\Projets\CEA Grenoble Project\libs\boost\boost-1.66.0-WIN64\stage\lib
```  


* *Builds Events/Post-Build Event* => (You can add these manually or use the automatic post build Event) 
```
xcopy /d /y "Path\to\fftw\compiled\Release\*.dll" "$(TargetDir)";

xcopy /d /y "Path\to\Qt\5.14.2\msvc2017_64\bin\Qt5Core.dll" "$(TargetDir)";
xcopy /d /y "Path\to\Qt\5.14.2\msvc2017_64\bin\Qt5Gui.dll" "$(TargetDir)";
xcopy /d /y "Path\to\Qt\5.14.2\msvc2017_64\bin\Qt5Widgets.dll" "$(TargetDir)";

if not exist $(TargetDir)\platforms mkdir $(TargetDir)\platforms

xcopy /d /y "Path\to\Qt\Tools\QtCreator\bin\libEGL.dll" "$(TargetDir)\platforms";
xcopy /d /y "Path\to\Qt\Tools\QtCreator\bin\qwindows.dll" "$(TargetDir)\platforms";
``` 

* ??? *Linker/System/Sub-System* => Windows (/SUBSYSTEM:WINDOWS)
* ??? *Linker/Advanced/Importation libraries* => D:/Documents/Projets/CEA Grenoble Project/PrismaticGUI/Release/prismatic-gui.lib

* *C/C++/Preprocessor/Preprocessor definition* => ```WIN32;_WINDOWS;NDEBUG;PRISMATIC_BUILDING_GUI=1;PRISMATIC_ENABLE_GUI;PRISMATIC_ENABLE_CLI;QT_WIDGETS_LIB;QT_GUI_LIB;QT_CORE_LIB;QT_NO_DEBUG;CMAKE_INTDIR="Release";```




LIBS
D:\Documents\Projets\CEA Grenoble Project\libs\hdf5\hdf5-1.12.0-WIN64\lib;
D:\Documents\Projets\CEA Grenoble Project\libs\fftw\fftw-3.3.8\BUILD\Release;
D:\Programmes\Qt\5.14.2\msvc2017_64\lib;
D:\Documents\Projets\CEA Grenoble Project\libs\boost\boost-1.66.0-WIN64\stage\lib;


import library D:/Documents/Projets/CEA Grenoble Project/GUI/Build/Release/prismatic.lib


QT       += core gui
 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 
TARGET = sans_titre
TEMPLATE = app


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


Measure-Command {.\prismatic.exe --input-file "../test/SI100.XYZ"}

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