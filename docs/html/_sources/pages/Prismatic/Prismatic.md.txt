<script>
    var currentpath = "D:/Libraries"
    var newpath = "D:/Libraries"

    var label
    var textbox
    var button
    var content

    const isPath = /^([a-zA-Z]:)((\/|\\)[a-zA-Z0-9_-]+)*/gmi

    window.addEventListener("DOMContentLoaded", (event) => {

        console.log("DOMContentLoaded")
        
        UpdateElements()

        function UpdateElements() {
            label = document.getElementById("path_label")
            textbox = document.getElementById("path_textbox")
            button = document.getElementById("path_button")
            content = document.getElementsByClassName("rst-content")[0]

            button.addEventListener('click', function(){
                
                UpdatePath()
                
            }, false)
        }

        function UpdatePath() {
            UpdateElements()
            newpath = textbox.value
            if (isPath.test(newpath)) {
                let currentRegular = new RegExp(currentpath, "gi");
                content.innerHTML = content.innerHTML.replace(currentRegular, newpath);
            
                currentpath = newpath
                UpdateElements()

                label.innerHTML = "You can edit the path to the root directory: (current: " + currentpath + ")"
            } else {
                //label.innerHTML = "You can edit the path to the root directory: (current: " + currentpath + ")</br>" + newpath + " is not a regular expression for a windows Path"
            }

            textbox.value = currentpath
        }
    })
</script>

# Prismatic

## Introduction
Welcome for this intruction manual. I wrote it to help people compiling prismatic from the source code ([here](https://github.com/prism-em/prismatic)). 
I tried to make it as easy as possible to reproduce, even for peoples that are not familiar with the compilation of c++ libraries.

I tried to make the compilation trivial by :
* putting the process in the same order as I did, so I recommand to repeat the compilations in the same order as describled here to understand the process (CMD > GUI > GPU)
* organizing a setup so you can take example on it, you can adapt the root directory of the folder organisation, or even make one that correspond better to what you need, but you will have to manually adapt the links and maybe meet some errors.
* creating a *Ressources* section for each major step, where I put some of the ressources (webpages, forums...) where I found responses at some problems I had.

### Tools
You will have to install some tools and libraries in order to build prismatic from source:

 Tools needed:
 * [Visual Studio 15 2017](https://visualstudio.microsoft.com/fr/vs/older-downloads/) (You can also use Visual Studio 2019, but I only did the process with the SDK 14.1)
 * [CMake](https://cmake.org/download/) (Prismatic build whas made with its and it realy help to compile the dependency libraries)
 * [7zip](https://www.7-zip.org/) (We will need to dectompress and Untar some file so it's a good choice)
 
  Others Tools (Python library, GUI and GPU):
  * [Anaconda 3.7](https://www.anaconda.com/products/individual) (Make sur to have python in version 3.7, I met some problems in v3.8)
  * [CUDA](https://developer.nvidia.com/cuda-downloads) (Cuda is developped by Nvidia, it provide a compiler for the GPU c++ code)
  * [Qt](http://ftp.fau.de/qtproject/archive/online_installers/3.2/) (Qt is a great library to build GUI, it is used in prismatic)

 Libraries:
 * [BOOST](#boost) (Utility library and )
 * [FFTW3](#fftw3) (Fast library for Fast Fourier Transform)
 * [HDF5](#hdf5) (Library for the hdf file compression, permit to save and read big datasets)

 Compilation:
 * [Prismatic](#prismatic)
 * [Prismatic GUI](#prismatic-gui)
 * [Prismatic GPU](#prismatic-gpu)  
 
### Folder organisation
For a clarity matter, and to help the user to do the process without having errors from the links, I will put my personal config for this configuration with the links like that: ```D:/Libraries/fftw-3.3.8/Build64/```
> You can edit the first part (```D:/Libraries/```) and you can put your folders wherever you want if you don't want the same folder configuration as me, but you will have to edit every links for the Build of prismatic and make sure that it match your configuration. 

<label id="path_label" for="path">You can edit the path to the root directory: (current: D:/Libraries)</label>
<input id="path_textbox" type="text" name="path" minlength="2" maxlength="60" size="70" value="D:/Libraries">
<input id="path_button" type="button" value="Update">

The global organisation of my folders look like that: 
```text
D:/Libraries
├─── Downloads
│    ├─── boost_1_72_0.zip
│    ├─── cuda_10.2.89_win10_network.exe
│    ├─── fftw-3.3.8.tar.gz
│    ├─── hdf5-1.12.0.zip
│    ├─── qt-unified-windows-x86-3.2.2-online.exe
│    └─── vs_Community.exe
│
├─── boost_1_72_0
│    ├─── boost 						//Header files
│    ├─── stage/lib 						//Library files
│    ├─── Build64						//Build
│    └─── BuildTest						//VS Test project
├─── fftw-3.3.8
│    ├─── api							//Header files
│    ├─── Build64						//Build Float
│    │    └─── Release						//Library files
│    ├─── Build64Default					//Build Default (Tests)
│    │    └─── Release	
│    └─── BuildTest						//VS Test project
├─── hdf5-1.12.0
│    ├─── Build64						//Build
│    │    └─── _CPack_Packages/win64/ZIP/HDF5-1.12.0-win64	//Package
│    │         └─── include					//Header files
│    │         └─── lib						//Library files
│    └─── BuildTest						//VS Test project
├─── Qt/5.14.2/msvc2017_64
│    ├─── include						//Header files
│    └─── lib							//Library files
│ 
└─── prismatic
     ├─── Build64
     ├─── Build64GUI
     ├─── Build64GPU
     ├─── include						//Header files
     ├─── src							//Library files
     └─── Qt							//GUI files

C:/
├─── Program Files/NVIDIA GPU Computing Toolkit
│    └─── CUDA/v10.2
└─── Program Files (x86)/Microsoft Visual Studio    
     ├─── 2017/Community
     └─── 2019/Community
```   

## Boost
### Ressources
* [Boost b2 tool](https://boostorg.github.io/build/manual/develop/index.html#bbv2.overview.configuration)  
* [Boostorg wiki](https://github.com/boostorg/wiki/wiki/Getting-Started%3A-Overview)  
* [Boost Windows](https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html)  
* [Build Boost x64](https://stackoverflow.com/questions/43946538/how-to-build-boost-1-64-in-64-bits/43950508)

### Compiling BOOST 
#### 1. Download [boost_1_72_0.zip](https://sourceforge.net/projects/boost/files/boost/1.72.0/)  
#### 2. Unzip the file and put it in ```D:/Libraries/```

#### 3. Open a cmd in the *Boost* directory  
```bash
cd D:/Libraries/boost_1_72_0
bootstrap
```

**Win32bit system:**
```bash
mkdir D:/Libraries/boost_1_72_0/Build32

b2 -j8 --build-dir="Build32" toolset=msvc-14.1 threading=multi runtime-link=shared --build-type=complete stage 
```  
**Win64bit system**
```bash
mkdir D:/Libraries/boost_1_72_0/Build64

b2 -j8 --build-dir="Build64" toolset=msvc-14.1 address-model=64 architecture=x86 link=static threading=multi runtime-link=shared --build-type=complete stage 
```
   
> ```-j8``` indicate the number of threads availlable to compile this library to faster the build (boost is a raltively big library so the process take some time to compile, but don't put more threas than availlable because it can result in errors.   
> ```build-dir``` is the directory for the temporaryy files and the build settings.  
> ```toolset``` is the compilator, mscv-14.1 (to 15) for the Visual Studio 2017 compilator.   
> ```address-model``` and architecture permit to have the library in x64 while building on a x86 machine.  
> ```link``` is for building the library into static mode (I also want to build fftw in static instead of dynamic but I don't know if it is possible).   
> ```theading``` is for using the threads (compilation of library use?)   
> ```stage``` at the end is the folder where the library will be built. I though I could change it to put my own name for the compilation folder but then the library didn't worked well... (to test?)   


### Testing BOOST 
#### 4. Open Visual Studio 2017 and create a new C++ console application project into a new directory
```bash
mkdir D:/Libraries/boost_1_72_0/BuildTest
```
#### 4.1 Add the test code from [here](https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html) at the point 6 (Link Your Program to a Boost Library)   
```cpp
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
* *C/C++/Additionnal Include Directories* => ```D:/Libraries/boost_1_72_0```   
* *Linker/General/Additionnal Library Directories* => ```D:/Libraries/boost_1_72_0/stage/lib```  

Select the right plateform at the left of the Run button and then run the code. You can write your mail as a string and it will extract the subject with the regex library from boost.  
*Try with this:*
```text
This is some test text, only for test purposes. This shouldn't be re-printed by the regex program.
```
*Then test with this:*
```text
Subject: This is the subject of the mail that should be printed.
``` 

## Fftw3
### Ressources
* https://www.youtube.com/watch?v=0qQm5AGB_18
* http://www.fftw.org/download.html

### Compiling FFTW  
#### 1. Download [fftw-3.3.8.tar.gz](http://www.fftw.org/download.html)  
#### 2. Open a cmd in the downloaded file directory
#### 2.1 Use this command to Extract the file then Untar it in ```D:/Libraries```:
```bash
tar xvf fftw-3.3.8.tar.gz -C D:/Libraries/
```
#### 3. Open a cmd in this folder
> We use the cmake tool to build the fftw library. 
> If cmake is not found in the command, add it to the PATH environment variable the link to 'path/to/CMake/bin'. 
> All the parameters of the compilation must begin with -D.     

**Win32bit system:**
```bash
mkdir D:/Libraries/fftw-3.3.8/Build32 & cd D:/Libraries/fftw-3.3.8/Build32

cmake -G "Visual Studio 15 2017 Win32" -DBUILD_SHARED_LIBS:BOOL=ON -DENABLE_FLOAT:BOOL=ON -DENABLE_THREADS:BOOL=ON D:/Libraries/fftw-3.3.8"

cmake --build . --config Release & cmake --build . --config Debug
```
**Win64bit system:**
```bash
mkdir D:/Libraries/fftw-3.3.8/Build64 & cd D:/Libraries/fftw-3.3.8/Build64

cmake -G "Visual Studio 15 2017 Win64" -DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_TESTS:BOOL=ON -DDISABLE_ALLOCA:BOOL=ON -DDISABLE_STATIC:BOOL=ON -DENABLE_FLOAT:BOOL=ON -DENABLE_SHARED:BOOL=ON -DENABLE_THREADS:BOOL=ON -DWITH_COMBINED_THREADS:BOOL=ON -DWITH_OUR_MALLOC16:BOOL=ON "D:/Libraries/fftw-3.3.8"

cmake --build . --config Release & cmake --build . --config Debug
```

**Linux system**
```bash
--disable-alloca: as of this writing (14 July 2009), the alloca function seems to be broken under the 64-bit MinGW compilers, so when compiling for Win64 you should pass --disable-alloca to tell FFTW not to use that function  
--with-our-malloc16: this is required in order to allocate properly aligned memory (for SSE) with gcc  
--with-windows-f77-mangling: this will include Fortran wrappers for some common Windows Fortran compilers (GNU, Intel, and Digital).  
--enable-shared --disable-static: this will create DLLs instead of static libraries (since MinGW s static-library format seems to be different from Microsoft s).  
--enable-threads --with-combined-threads: this will include multi-threading support. The second option puts the multi-threading functions into the main FFTW DLL rather than into a separate DLL (the default under Unix); this is required because MinGW can t create DLLs that depend on one another.  
--enable-portable-binary: required if you want to create DLLs that will work on any Intel processor.  
--with-incoming-stack-boundary=2: compile FFTW assuming a 4-byte alignment. On win32, some versions of gcc assume that the stack is 16-byte aligned, but code compiled with other compilers may only guarantee a 4-byte alignment, resulting in mysterious segfaults.  

-----------------------------------------------------------------------------
./configure --disable-alloca --with-our-malloc16 --enable-shared --disable-static --enable-float --enable-threads --with-combined-threads
make
make install
```

### Testing FFTW   
> To build the default version of this library in x32, use 
```bash
mkdir D:/Libraries/fftw-3.3.8/Build32Default & cd D:/Libraries/fftw-3.3.8/Build32Default

cmake -DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_TESTS:BOOL=ON -DDISABLE_ALLOCA:BOOL=ON -DDISABLE_STATIC:BOOL=ON -DENABLE_SHARED:BOOL=ON -DENABLE_THREADS:BOOL=ON -DWITH_COMBINED_THREADS:BOOL=ON -DWITH_OUR_MALLOC16:BOOL=ON "D:/Libraries/fftw-3.3.8"

cmake --build . --config Release & cmake --build . --config Debug
```  
> You can't test the float version of fftw <-DENABLE_FLOAT> with the test code I give, so build a default version for test is a good idea   

#### 4. Open Visual Studio 2017 and create a new C++ console application project into a new directory
```bash
mkdir D:/Libraries/fftw-3.3.8/BuildTest
```
#### 4.1 Add the test code from [here](https://gist.github.com/damian-dz/a5d7d61993597253747b6dfe400805d9) 
#### 4.2 Edit the project properties
Select **All Configurations:** in the top menu and also select the right **Plateform**
* *C/C++/Additionnal Include Directories* => ```D:/Libraries/fftw-3.3.8/api```  
* *Linker/Input/Additionnal Dependency* => ```fftw3.lib;(default system libraries)```  
	
Select **Debug:** in the top menu
* *Linker/General/Additionnal Library Directories* => ```D:/Libraries/fftw-3.3.8/Build32Default/Debug```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "D:/Libraries/fftw-3.3.8/Build32Default/Debug/*.dll" "$(TargetDir)"```  
	
Select **Release:** in the top menu 
* *Linker/General/Additionnal Library Directories* => ```D:/Libraries/fftw-3.3.8/Build32Default/Release```  
* *Builds Events/Post-Build Event* => ```xcopy /d /y "D:/Libraries/fftw-3.3.8/Build32Default/Release/*.dll" "$(TargetDir)"``` 

> Make sure that the compilation is done on the right plateform (x64 or x84) on the top bar or you will have an conflict error message. Also, make sure that the rights .dll are linked at the right compilation version (Debug and Release).   
> FFTW is only compilable in the dynamic version, so the program .exe need the fftw3.dll (or fftw3d.dll for the float version) on the same folder in order to work.   
> the post build event with ```xcopy``` copy the .dll in the .exe folder, but if it don't work, you will have an error when launching the .exe that say that the fftw3.dll is missing. You will have to search for this dll in the compiled fftw folder and manually copy it to the .exe program folder.   

## Hdf5
### Ressources
* [Build HDF5](https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/release_docs/INSTALL_CMake.txt) 
* [CMake HDF5](https://support.hdfgroup.org/HDF5/release/cmakebuild.html)    
* [HDF5 VS error](https://stackoverflow.com/questions/24325508/getting-stared-with-hdf5-on-visual-studio-2013-with-visual-c-2013)
* [HDF5 Linking](https://stackoverflow.com/questions/7397296/linking-hdf5-library-into-visual-c-dll-project-unresolved-external-symbol-i)
* [HDF5 ressources](https://svn.oss.deltares.nl/repos/openearthtools/trunk/fortran/io/netcdf/win32/visual_fortran_6/lib/win32/all/)

*Not necessary*: [zlib](http://gnuwin32.sourceforge.net/packages/zlib.htm)

### Compiling HDF5    
#### 1. Download [hdf5-1.12.0.zip](https://hdf-wordpress-1.s3.amazonaws.com/wp-content/uploads/manual/HDF5/HDF5_1_12_0/source/hdf5-1.12.0.zip)  
#### 2. Unzip the file and put it in ```D:/Libraries/```
#### 2.1 Open a cmd in this directory
> Once again we use the cmake tool, this time it's to build hdf5.   
> All the parameters of the compilation must begin with -D.   
> We only build the Release version for prismatic, if you want both versions, edit ```-DCMAKE_BUILD_TYPE:STRING```  

**Win32bit system:**
```bash 
mkdir D:/Libraries/hdf5-1.12.0/Build32 & cd D:/Libraries/hdf5-1.12.0/Build32

cmake -G "Visual Studio 15 2017 Win32" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON -DHDF5_ENABLE_THREADSAFE:BOOL=ON -DALLOW_UNSUPPORTED:BOOL=ON -DBUILD_TESTING:BOOL=ON "D:/Libraries/hdf5-1.12.0"

cmake --build . --config Release
```  
**Win64bit system:**
```bash  
mkdir D:/Libraries/hdf5-1.12.0/Build64 & D:/Libraries/hdf5-1.12.0/Build64

cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON -DHDF5_ENABLE_THREADSAFE:BOOL=ON -DALLOW_UNSUPPORTED:BOOL=ON -DBUILD_TESTING:BOOL=ON "D:/Libraries/hdf5-1.12.0"

cmake --build . --config Release 
```

> This will take some time... If you want to build the Debug library, replace in the commands the ```Release``` by ```Debug```*

#### 2.2 Now, we will use the cpack tool to build a Package with the compiled library:
```bash
cpack -C Release CPackConfig.cmake 
```
> A package with the compiled library has been created (ex: *hdf5-1.12.0/Build64/HDF5-1.12.0-win64.zip*).   
> Extract it to the same directory: ```D:/Libraries/hdf5-1.12.0/Build64/HDF5-1.12.0-win64```

### Testing HDF5  
#### 3. Open a cmd in the compiled directory
```bash
cd D:/Libraries/hdf5-1.12.0/Build64
ctest . -C Release 
``` 
#### 3.1 Check that all Tests are *Passed* 
#### 4. Open Visual Studio 2017 and create a new C++ console application project into a new directory
```bash
mkdir D:/Libraries/hdf5-1.12.0/BuildTest
```
#### 4.1 Add the test code from [here](https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/c++/examples/h5tutr_crtdat.cpp)
#### 4.2 Edit the project properties
Select **All Configurations:** in the top menu and also select the right **Plateform**
* *C/C++/Additionnal Include Directories* => ```D:/Libraries/hdf5-1.12.0/Build64/HDF5-1.12.0-win64/include```  
* *Linker/Genral/Additionnal Libraries repertory* => ```D:/Libraries/hdf5-1.12.0/Build64/HDF5-1.12.0-win64/lib```
* *Linker/Input/Additionnal Dependency* => ```libhdf5.lib;libhdf5_cpp.lib;(default system libraries)```  

## Prismatic CMD
### Ressources
* [Prismatic Compilation info](https://prism-em.com/docs-compiling/)
* [Error module type](https://www.it-swarm.dev/fr/visual-c%2B%2B/erreur-fatale-lnk1112-le-type-de-machine-du-module-x64-est-en-conflit-avec-le-type-de-machine-cible-x86/969200768/)
* [HDF5 Linking](https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/release_docs/USING_HDF5_VS.txt)  
* [HDF Presentation](https://www.youtube.com/watch?v=BAjsCldRMMc) 

*You can add the libraries directory to the PATH if you want, otherwise you will have to complete the links manually later...*
> <kbd>Windows</kbd> + <kbd>"Path"</kbd> => Edit environment variables/Environment variables/Path/Edit/New
> Add these links to the PATH
```bash
D:/Libraries/boost_1_72_0
D:/Libraries/fftw-3.3.8
D:/Libraries/hdf5-1.12.0
```

#### 1. Download [prismatic](https://github.com/prism-em/prismatic)
```bash
cd D:/Libraries

git clone https://github.com/prism-em/prismatic.git 
```
#### 2. Create a new folder (ex: *prismatic-master/Build64*) where the library will be compiled
```bash
mkdir D:/Libraries/prismatic/Build64
```   
#### 3. Open the CMake GUI  
#### 3.1 Complete the links with the code source directory and the build directory  
* Where is the source code: ```D:/Libraries/prismatic```   
* Where to build the binaries: ```D:/Libraries/prismatic/Build64```   

#### 3.2 Click on *Configure* and select *Visual Studio 15 2017*
**Win32 system**
* Select ```Win32``` in the Optional Plateform Generator

**Win64 system**
* Select ```x64``` in the Optional Plateform Generator

#### 3.3 Check Grouped and Advanced then complete the missing links to the compiled libraries:
**BOOST**
* *Boost_INCLUDE_DIR* => ```D:/Libraries/boost_1_72_0```

**Click on Configure**

**FFTW:**  
* *FFTW_INCLUDE_DIR* => ```D:/Libraries/fftw-3.3.8/api```
* *FFTW_LIBRARY* => ```D:/Libraries/fftw-3.3.8```

**HDF5:**  
* *HDF5_CXX_INCLUDE_DIR* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include```
* *HDF5_hdf5_LIBRARY_DEBUG* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64```
* *HDF5_hdf5_LIBRARY_RELEASE* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64```

#### 3.4 Click again on *Configure* and if nothing is red, click on *Generate*
> You may have an error message, but it's ok if you have *Generating done* at the end of the process, it's only warning about the DIR-NOTFOUND but we will edit every links maually in the project.

#### 4. Open the project in Visual Studio 2017 
> You can click on the *Open Project* button in CMake  

#### 4.1 Right Click on the **prismatic** project and go to Properties/General:
Make sure to select **Select All Configurations** and the right **Plateform**   

* *Configuration Property/General/Windows SDK Version* => ```10.0.17763.0```
* *Configuration Property/General/Plateform tools* => ```Visual Studio 2017 (v141)```

* *C C++/General/Additionnal Include Directories* => 
```text
D:/Libraries/prismatic/include;
D:/Libraries/fftw-3.3.8/api;
D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include;
D:/Libraries/boost_1_72_0;
%(AdditionalIncludeDirectories)
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
D:/Libraries/prismatic/include;D:/Libraries/fftw-3.3.8/api;D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include;D:/Libraries/boost_1_72_0;%(AdditionalIncludeDirectories)
```

* *Linker/Input/Additionnal Dependency* => 
```text
fftw3f.lib;
libhdf5.lib;
libhdf5_cpp.lib;
libhdf5_hl_cpp.lib;
libhdf5_hl.lib;
%(AdditionalDependencies)
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
fftw3f.lib;libhdf5.lib;libhdf5_cpp.lib;libhdf5_hl_cpp.lib;libhdf5_hl.lib;%(AdditionalDependencies)
```

> The order in wich the libraries are linked is realy important, that's even more true when you have like here a program with many links to others libraries, and that these libraries use the base functions of others libraries.   

* **Win32 system**
* *Linker/Input/Advanced/Target computer* => ```MachineX86 (/MACHINE:X86)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X64```

* **Win64 system**
* *Linker/Input/Advanced/Target computer* => ```MachineX64 (/MACHINE:X64)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X86```

Click on **Apply** and select **Release:** in Configuration   
* *Linker/General/Additionnal Library Directories* => 
```text
D:/Libraries/fftw-3.3.8/Build64/Release;
D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/lib
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
D:/Libraries/fftw-3.3.8/Build64/Release;D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/lib;%(AdditionalLibraryDirectories)
```

* *Builds Events/Post-Build Event/Command line* => ```xcopy /d /y "D:/Libraries/fftw-3.3.8/Build64/Release/*.dll" "$(TargetDir)"``` 

#### 5. In the top bar, make sure to select Release and the right Plateform, then Click on Run
> You may have an error popup when the project try to run the ALL BUILD version, just run manually the build file with ```D:/Libraries/prismatic/Build64/Release/prismatic.exe```   
#### 6. You can get the **prismatic.exe** and **fftwf.dll** files at D:\Libraries\prismatic\Build64\Release and move them to another directory, if at least these files are in the same folder the program will work

### Test:  
#### 7. Copy the **prismatic.exe** and **fftwf.dll** files in a new directory
#### 7.1 Create a new file "SI100.XYZ" in this directory
#### 7.1 Open it and paste these datas:
```text
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
```bash
prismatic.exe --input-file "Path/to/the/directory/SI100.XYZ"
```

#### 8.1 Wait for the *PRISM Calculation complete* message to be displayed
#### 8.2 If you have python with the hdf5 library, you can use this to explore the HDF file
```python
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

f = h5py.File('path/to/output.h5', 'r')
recursiveHDF(f)
```

## Prismatic GUI
### Ressources:
* [Qt website](https://www.qt.io/)
* [Qt Visual Studio](https://stackoverflow.com/questions/6626397/error-lnk2019-unresolved-external-symbol-winmain16-referenced-in-function)

#### 1. Download [Qt](http://ftp.fau.de/qtproject/archive/online_installers/3.2/qt-unified-windows-x86-3.2.2-online.exe)
#### 1.1 Create an Qt account [here](https://login.qt.io/register)
#### 1.2 Select in the installer the Qt path at ```D:/Libraries/Qt``` and select the right version for the compilation:
**Win32 system**
* **Qt 5.14.2 MSCV 2017 32-Bits**

**Win64 system**
* **Qt 5.14.2 MSCV 2017 64-Bits**

#### 2. Create a new folder (ex: *prismatic-master/Build64GUI*) where the library will be compiled
```bash
mkdir D:/Libraries/prismatic/Build64GUI
```
#### 2.1 Open **prismatic-master.pro** (D:/Libraries/prismatic/Qt/prismatic-master.pro) in a text editor:
```bash
notepad D:/Libraries/prismatic/Qt/prismatic-gui.pro
```
Then add at the end
```text
CONFIG += console
```

#### 2.2 (Optional) Open CMakeLists.txt in the prismatic-master source code and check that the paths to the icons are good (if not replace ../Qt by Qt).
#### 2.3 You can also add the link to Qt to the PATH: ```D:/Libraries/Qt```   

#### 3. Open the CMake GUI  
#### 3.1 Complete the links with the code source directory and the build directory  
* Where is the source code: ```D:/Libraries/prismatic```   
* Where to build the binaries: ```D:/Libraries/prismatic/Build64GUI```    

#### 3.2 Click on *Configure* and select *Visual Studio 15 2017*
**Win32 system**
* Select ```Win32``` in the Optional Plateform Generator

**Win64 system**
* Select ```x64``` in the Optional Plateform Generator

#### 3.3 Check **Grouped** and **Advanced**, then check **PRISMATIC_ENABLE_GUI** and **PRISMATIC_ENABLE_CLI**
#### 3.4 Complete the missing links to the compiled libraries:

**BOOST**
* *Boost_INCLUDE_DIR* => ```D:/Libraries/boost_1_72_0```

**Click on Configure**

**FFTW:**  
* *FFTW_INCLUDE_DIR* => ```D:/Libraries/fftw-3.3.8/api```
* *FFTW_LIBRARY* => ```D:/Libraries/fftw-3.3.8```

**HDF5:**  
* *HDF5_CXX_INCLUDE_DIR* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include```
* *HDF5_hdf5_LIBRARY_DEBUG* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64```
* *HDF5_hdf5_LIBRARY_RELEASE* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64```

**Click on Configure**

**Ungouped Entries (QT5):**
* *QT5Widgets_DIR* => ```D:/Libraries/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5Widgets```

**Click on Configure**

#### 3.5 Click again on Configure and if nothing is still red, click on Generate
> You may again have an error message, but it's ok if you have *Generating done* at the end of the process, it's only warning about the DIR-NOTFOUND but we will edit every links maually in the project.

#### 4. Open the project in Visual Studio 2017 
> You can click on the *Open Project* button in CMake  

#### 4.1 Select both **prismatic** and **prismatic-gui** with *Ctrl* + *Click*
#### 4.2 Right Click on a project and go to Properties/General:
Make sure to select **Select All Configurations** and the right **Plateform**   

* *Configuration Property/General/Windows SDK Version* => ```10.0.17763.0```
* *Configuration Property/General/Plateform tools* => ```Visual Studio 2017 (v141)```
* *C C++/General/Additionnal Include Directories* => 
```text
D:/Libraries/prismatic/include;
D:/Libraries/fftw-3.3.8/api;
D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include;
D:/Libraries/boost_1_72_0;

D:/Libraries/prismatic;
D:/Libraries/prismatic/include;
D:/Libraries/prismatic/Qt;

D:/Libraries/Qt/5.14.2/msvc2017_64;
D:/Libraries/Qt/5.14.2/msvc2017_64/lib;
D:/Libraries/Qt/5.14.2/msvc2017_64/include;
D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtWidgets;
D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtGui;
D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtCore;

D:/Libraries/prismatic/Build64GUI;
D:/Libraries/prismatic/Build64GUI/prismatic-gui_autogen/include_Release;
%(AdditionalIncludeDirectories)
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
D:/Libraries/prismatic/include;D:/Libraries/fftw-3.3.8/api;D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include;D:/Libraries/boost_1_72_0;D:/Libraries/prismatic;D:/Libraries/prismatic/include;D:/Libraries/prismatic/Qt;D:/Libraries/Qt/5.14.2/msvc2017_64;D:/Libraries/Qt/5.14.2/msvc2017_64/lib;D:/Libraries/Qt/5.14.2/msvc2017_64/include;D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtWidgets;D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtGui;D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtCore;D:/Libraries/prismatic/Build64GUI;D:/Libraries/prismatic/Build64GUI/prismatic-gui_autogen/include_Release;%(AdditionalIncludeDirectories)
```

* *Linker/Input/Additionnal Dependency* => 
```text
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
%(AdditionalDependencies)
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
fftw3f.lib;libhdf5_hl.lib;libhdf5.lib;libhdf5_hl_cpp.lib;libhdf5_cpp.lib;Qt5Widgets.lib;Qt5Gui.lib;Qt5Core.lib;qtmain.lib;shell32.lib;WindowsApp.lib;%(AdditionalDependencies)
```

> The order in wich the libraries are linked is realy important, that's even more true when you have like here a program with many links to others libraries, and that these libraries use the base functions of others libraries.     

* **Win32 system**
* *Linker/Input/Advanced/Target computer* => ```MachineX86 (/MACHINE:X86)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X64```

* **Win64 system**
* *Linker/Input/Advanced/Target computer* => ```MachineX64 (/MACHINE:X64)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X86```

Click on **Apply** and select **Release:** in Configuration   

* *Linker/General/Additionnal Library Directories* => 
```  text
D:/Libraries/boost_1_72_0/stage/lib;
D:/Libraries/fftw-3.3.8/Build64/Release;
D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/lib;
D:/Libraries/Qt/5.14.2/msvc2017_64/lib;

%(AdditionalLibraryDirectories)
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
D:/Libraries/boost_1_72_0/stage/lib;D:/Libraries/fftw-3.3.8/Build64/Release;D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/lib;D:/Libraries/Qt/5.14.2/msvc2017_64/lib;%(AdditionalLibraryDirectories)
```

* *Builds Events/Post-Build Event/Command line* => 
```bash
xcopy /d /y "D:/Libraries/fftw-3.3.8/Build64/Debug/*.dll" "$(TargetDir)"

xcopy /d /y "D:/Libraries/Qt/5.14.2/msvc2017_64/bin/Qt5Core.dll" "$(TargetDir)"
xcopy /d /y "D:/Libraries/Qt/5.14.2/msvc2017_64/bin/Qt5Gui.dll" "$(TargetDir)"
xcopy /d /y "D:/Libraries/Qt/5.14.2/msvc2017_64/bin/Qt5Widgets.dll" "$(TargetDir)"

mkdir "$(TargetDir)/platforms"
xcopy /d /y "D:/Libraries/Qt/Tools/QtCreator/bin/libEGL.dll" "$(TargetDir)/platforms"
xcopy /d /y "D:/Libraries/Qt/5.14.2/msvc2017_64/plugins/platforms/qwindows.dll" "$(TargetDir)/platforms"
``` 
Click on **Apply**

**Select only the properties for prismatic-gui and check that these parameters are good:**
* *Linker/System/Sub-System* => Windows (/SUBSYSTEM:WINDOWS)
* *Linker/Advanced/Importation libraries* => D:/Libraries/prismatic/Build64GUI/Release/prismatic-gui.lib
* *C/C++/Preprocessor/Preprocessor definition* => 
```
WIN32;_WINDOWS;NDEBUG;PRISMATIC_BUILDING_GUI=1;PRISMATIC_ENABLE_GUI;PRISMATIC_ENABLE_CLI;QT_WIDGETS_LIB;QT_GUI_LIB;QT_CORE_LIB;QT_NO_DEBUG;CMAKE_INTDIR="Release";
```

#### 5. In the top bar, make sure to select Release and the right Plateform, then Click on Run
> You may have an error popup when the project try to run the ALL BUILD version, just run manually the build file with 
```D:/Libraries/prismatic/Build64/Release/prismatic.exe```  

### Test Prismatic Performances:  
**Win32 and Win64 system**
* Open a Windows PowerShell in the prismatic/Build/Release folder and add the data test file "SI100.XYZ"
```bash
Measure-Command {./prismatic.exe --input-file "SI100.XYZ"}
``` 

**Example comparing the Base Build (316ms for this simple file) and the GPU Build (857ms for one file, but should be more effective the more complex and time-consuming the computations are for the CPU)**
``` bash
#Base Build  
Measure-Command {./prismatic.exe --input-file "SI100.XYZ"}  
  
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
Measure-Command {./prismatic.exe --input-file "SI100.XYZ"}  
  
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

## Prismatic GPU
### Ressources:
* [CUDA Installation](https://docs.nvidia.com/cuda/cuda-installation-guide-microsoft-windows/index.html)
* [CUDA Linker error](https://stackoverflow.com/questions/6626397/error-lnk2019-unresolved-external-symbol-winmain16-referenced-in-function)

#### 1. Download the [CUDA](https://developer.nvidia.com/cuda-downloads) Toolkit 10.2 for Windows (v10)
#### 1.1 Make sure that you have a Graphical card compatible with CUDA
#### 1.2 Cuda will be installed at ```C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.2```
> You can test the installation by running ```nvcc -V``` to check the Version on the instalation. If the call to nvcc don't work, make sure to add this link to the PATH: ```C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.2/bin```
> You can even compile some of the tests codes at ```C:/ProgramData/NVIDIA Corporation/CUDA Samples/v10.2```
> the .exe will be built at ```C:/ProgramData/NVIDIA Corporation/CUDA Samples/v10.2/bin/win64```

#### 2. Create a new folder (ex: *prismatic-master/Build64GPU*) where the library will be compiled
```bash
mkdir D:/Libraries/prismatic/Build64GPU
```
#### 2.1 Open **prismatic-master.pro** (D:/Libraries/prismatic/Qt/prismatic-master.pro) in a text editor:
```bash
notepad D:/Libraries/prismatic/Qt/prismatic-gui.pro
```
Then add at the end
```bash
CONFIG += console
```
#### 3. Open the CMake GUI  
#### 3.1 Complete the links with the code source directory and the build directory  
* Where is the source code: ```D:/Libraries/prismatic```   
* Where to build the binaries: ```D:/Libraries/prismatic/Build64GPU```    

#### 3.2 Click on *Configure* and select *Visual Studio 15 2017*
#### 3.3 Check **Grouped** and **Advanced**, then check **PRISMATIC_ENABLE_GPU**, **PRISMATIC_ENABLE_GUI** and **PRISMATIC_ENABLE_CLI**

#### 3.4 **Click on Configure** Then complete the missing links to the compiled libraries:

**BOOST**
* *Boost_INCLUDE_DIR* => ```D:/Libraries/boost_1_72_0```

**Click on Configure**

**FFTW:**  
* *FFTW_INCLUDE_DIR* => ```D:/Libraries/fftw-3.3.8/api```
* *FFTW_LIBRARY* => ```D:/Libraries/fftw-3.3.8```

**HDF5:**  
* *HDF5_CXX_INCLUDE_DIR* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include```
* *HDF5_hdf5_LIBRARY_DEBUG* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64```
* *HDF5_hdf5_LIBRARY_RELEASE* => ```D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64```

**Click on Configure**

**Ungouped Entries (QT5):**
* *QT5Widgets_DIR* => ```D:/Libraries/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5Widgets```

**Click on Configure**

**CUDA:**
* *CUDA_64_BITS_DEVICE_CODE* => make sure that it's checked if you build in x64

**Click on Configure**

#### 3.5 Click again on Configure and if nothing is still red, click on Generate
> You may again have an error message, but it's ok if you have *Generating done* at the end of the process, it's only warning about the DIR-NOTFOUND but we will edit every links maually in the project.

#### 4. Open the project in Visual Studio 2017 
> You can click on the *Open Project* button in CMake  

#### 4.1 Select both **prismatic** and **prismatic-gui** with *Ctrl* + *Click*
#### 4.2 Right Click on a project and go to Properties/General:
Make sure to select **Select All Configurations** and the right **Plateform**   

* *Configuration Property/General/Windows SDK Version* => ```10.0.17763.0```
* *Configuration Property/General/Plateform tools* => ```Visual Studio 2017 (v141)```

* *C C++/General/Additionnal Include Directories* => 
```text
C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.2/include;

D:/Libraries/prismatic/include;
D:/Libraries/fftw-3.3.8/api;
D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include;
D:/Libraries/boost_1_72_0;

D:/Libraries/prismatic;
D:/Libraries/prismatic/include;
D:/Libraries/prismatic/Qt;

D:/Libraries/Qt/5.14.2/msvc2017_64;
D:/Libraries/Qt/5.14.2/msvc2017_64/lib;
D:/Libraries/Qt/5.14.2/msvc2017_64/include;
D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtWidgets;
D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtGui;
D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtCore;

D:/Libraries/prismatic/Build64GPU;
D:/Libraries/prismatic/Build64GPU/prismatic-gui_autogen/include_Release;
%(AdditionalIncludeDirectories)
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.2/include; D:/Libraries/prismatic/include; D:/Libraries/fftw-3.3.8/api; D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/include; D:/Libraries/boost_1_72_0; D:/Libraries/prismatic; D:/Libraries/prismatic/include; D:/Libraries/prismatic/Qt; D:/Libraries/Qt/5.14.2/msvc2017_64; D:/Libraries/Qt/5.14.2/msvc2017_64/lib; D:/Libraries/Qt/5.14.2/msvc2017_64/include; D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtWidgets; D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtGui; D:/Libraries/Qt/5.14.2/msvc2017_64/include/QtCore; D:/Libraries/prismatic/Build64GPU; D:/Libraries/prismatic/Build64GPU/prismatic-gui_autogen/include_Release; %(AdditionalIncludeDirectories)
```

* *Linker/Input/Additionnal Dependency* => 
```text
cudart_static.lib;
cufft.lib;
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
%(AdditionalDependencies)
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
cudart_static.lib;cufft.lib;fftw3f.lib;libhdf5_hl.lib;libhdf5.lib;libhdf5_hl_cpp.lib;libhdf5_cpp.lib;Qt5Widgets.lib;Qt5Gui.lib;Qt5Core.lib;qtmain.lib;shell32.lib;WindowsApp.lib;%(AdditionalDependencies)
```

> The order in wich the libraries are linked is realy important, that's even more true when you have like here a program with many links to others libraries, and that these libraries use the base functions of others libraries.   

* **Win32 system**
* *Linker/Input/Advanced/Target computer* => ```MachineX86 (/MACHINE:X86)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X64```

* **Win64 system**
* *Linker/Input/Advanced/Target computer* => ```MachineX64 (/MACHINE:X64)```
* *Link editor/Command line/Additional options* => Remove ```/machine:X86```

Click on **Apply** and select **Release:** in Configuration   

* *Linker/General/Additionnal Library Directories* => 
```text
C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.2/lib/x64;
D:/Libraries/boost_1_72_0/stage/lib;
D:/Libraries/fftw-3.3.8/Build64/Release;
D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/lib;
D:/Libraries/Qt/5.14.2/msvc2017_64/lib;

%(AdditionalLibraryDirectories)
```  
*For fast copy: <kbd>CTRL+C</kbd> this line then click in the VS textbox, <kbd>CTRL+A</kbd> and <kbd>CTRL+V</kbd>*
```text
C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.2/lib/x64; D:/Libraries/boost_1_72_0/stage/lib; D:/Libraries/fftw-3.3.8/Build64/Release; D:/Libraries/hdf5-1.12.0/Build64/_CPack_Packages/win64/ZIP/HDF5-1.12.0-win64/lib; D:/Libraries/Qt/5.14.2/msvc2017_64/lib; %(AdditionalLibraryDirectories)
```

* *Builds Events/Post-Build Event/Command line* => 
```bash
xcopy /d /y "D:/Libraries/fftw-3.3.8/Build64/Debug/*.dll" "$(TargetDir)"

xcopy /d /y "D:/Libraries/Qt/5.14.2/msvc2017_64/bin/Qt5Core.dll" "$(TargetDir)"
xcopy /d /y "D:/Libraries/Qt/5.14.2/msvc2017_64/bin/Qt5Gui.dll" "$(TargetDir)"
xcopy /d /y "D:/Libraries/Qt/5.14.2/msvc2017_64/bin/Qt5Widgets.dll" "$(TargetDir)"

mkdir "$(TargetDir)/platforms"
xcopy /d /y "D:/Libraries/Qt/Tools/QtCreator/bin/libEGL.dll" "$(TargetDir)/platforms"
xcopy /d /y "D:/Libraries/Qt/5.14.2/msvc2017_64/plugins/platforms/qwindows.dll" "$(TargetDir)/platforms"
``` 
Click on **Apply**

**Select only the properties for prismatic-gui and check that these parameters are good:**
* *Linker/System/Sub-System* => Windows (/SUBSYSTEM:WINDOWS)
* *Linker/Advanced/Importation libraries* => D:/Libraries/prismatic/Build64GUI/Release/prismatic-gui.lib
* *C/C++/Preprocessor/Preprocessor definition* => 
```
WIN32;_WINDOWS;NDEBUG;PRISMATIC_BUILDING_GUI=1;PRISMATIC_ENABLE_GUI;PRISMATIC_ENABLE_CLI;QT_WIDGETS_LIB;QT_GUI_LIB;QT_CORE_LIB;QT_NO_DEBUG;CMAKE_INTDIR="Release";
```

#### 5. Make sure to desactivate the antivirus because it can block some files and corrupt the process

#### 5.1 If you use CUDA 10.0, you may have an error with mutex.h, go in this file and replace the line 133:
```cpp
constexpr QMutex() = default;
```
with
```cpp
const QMutex() = default;
```

#### 5.2 In the top bar, make sure to select Release and the right Plateform, then Click on Run
> You may have an error popup when the project try to run the ALL BUILD version, just run manually the build file with 
```D:/Libraries/prismatic/Build64/Release/prismatic.exe```  
