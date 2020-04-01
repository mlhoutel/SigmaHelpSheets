## Compile Prismatic-master from source
You will have to install some tools and libraries in order to build prismatic form source:
 
 **Tools needed :**
 * *Visual Studio 15 2017* (https://visualstudio.microsoft.com/fr/vs/older-downloads/)
 * *CMake* (https://cmake.org/download/)
 * *7zip* (https://www.7-zip.org/)

 **Libraries :**
 * *BOOST*
 * *FFTW3*
 * *HDF5*

### BOOST
**Ressources:**
* https://boostorg.github.io/build/manual/develop/index.html#bbv2.overview.configuration  
* https://github.com/boostorg/wiki/wiki/Getting-Started%3A-Overview  
* https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html  

**Compile:**  
#### 1. Download [boost_1_72_0.zip](https://sourceforge.net/projects/boost/files/boost/1.72.0/)  
#### 2. Unzip the file
#### 3. Open a cmd in the directory  
```
bootstrap
./b2 --build-dir="D:\Documents\Projets\CEA Grenoble Project\prismatic\required\boost-1.72.0-simple" --build-type=complete msvc stage
```

**Test:**  
#### 4. Create a new VS 2017 project
##### 4.1 Add test code https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html
##### 4.2 Edit the project properties
**All Configurations:**  
	* *Windows SDK Version* => ```10.0.17763.0```    
	* *Tools* => ```Visual Studio 2019 (v142)```  
	* *C/C++/Additionnal Include Directories* => ```D:\Documents\Projets\CEA Grenoble Project\prismatic\required\boost_1_72_0```   
	* *Linker/General/Additionnal Library Directories* => ```D:\Documents\Projets\CEA Grenoble Project\prismatic\required\boost_1_72_0\stage\lib```  

### FFTW3
**Ressources:**
* https://www.youtube.com/watch?v=0qQm5AGB_18
* http://www.fftw.org/download.html

**Compile:**  
#### 1. Download [fftw-3.3.8.tar.gz](http://www.fftw.org/download.html)  
#### 2. Unzip and Untar the file
```
tar xvf fftw-3.3.8.tar
```
#### 3. Open the GUI of Cmake  
#### 3.1 Complete the links with the code source directory and the build directory  
#### 3.2 Click on Configure and select Visual Studio 15 2017  
#### 3.3 Check **BUILD_SHARED_LIBS**, **ENABLE_FLOAT** and **ENABLE_THREADS**  
#### 3.4 Cick again on Configure and if nothing is still red, click on Generate

#### 4. Open the project in VS 2017
#### 4.1 Right Click on the fftw3_threads and go to Properties/General:  
* *Windows SDK Version* => ```10.0.17763.0```
* *Configuration Type* => ```Dynamic library (dll)```

#### 4.2 In the up bar, go to *Build/Batch Build* and check all the **fftw3_threads** options

**Test:**  
#### 4. Create a new VS 2017 project
##### 4.1 Add test code https://gist.github.com/damian-dz/a5d7d61993597253747b6dfe400805d9
##### 4.2 Edit the project properties
	*All Configurations:*  
	- *C/C++/Additionnal Include Directories* => ```D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8\api```  
	- *Linker/Input/Additionnal Dependency* => ```fftw3.lib;...```  
	
  *Debug:*  
	- *Linker/General/Additionnal Library Directories* => ```D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8-simple\Debug```  
	- *Builds Events/Post-Build Event* => ```xcopy /d /y "D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8-simple\Debug\*.dll" "$(TargetDir)"```  
	
  *Release:*  
	- *Linker/General/Additionnal Library Directories* => ```D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8-simple\Release```  
	- *Builds Events/Post-Build Event* => ```xcopy /d /y "D:\Documents\Projets\CEA Grenoble Project\prismatic\required\fftw-3.3.8-simple\Release\*.dll" "$(TargetDir)"``` 

## HDF5
**Ressources:**
* https://support.hdfgroup.org/ftp/HDF5/current/src/unpacked/release_docs/INSTALL_CMake.txt  
* https://support.hdfgroup.org/HDF5/release/cmakebuild.html  

**Compile:**  
#### 1. Download [hdf5-1.12.0.zip](https://hdf-wordpress-1.s3.amazonaws.com/wp-content/uploads/manual/HDF5/HDF5_1_12_0/source/hdf5-1.12.0.zip)  
#### 2. Unzip the file
##### 2.1 create a new folder where the library will be compiled
##### 2.2 To use the make script from hdf5, open a cmd in this directory

**On Windows 32 bit**  
```
cmake -G "Visual Studio 12 2013" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON ..\hdf5-1.10."X"

cmake --build . --config Release
```

**On Windows 64 bit**
```  
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON -DHDF5_ENABLE_THREADSAFE -DALLOW_UNSUPPORTED -DBUILD_TESTING:BOOL=ON ..\hdf5-1.12.0

cmake --build . --config Release
```

**On Linux and Mac**
```
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON ../hdf5-1.10."X"

cmake --build . --config Release
```

##### 2.2* You can also use CMake, open the GUI of Cmake  
##### 2.2.1* Complete the links with the code source directory and the build directory  
##### 2.2.2* Click on Configure and select Visual Studio 15 2017  
##### 2.2.3* **HDF5_ENABLE_THREADSAFE**, **ALLOW_UNSUPPORTED**, Click on the Add entry button and paste this
```
ENABLE_CXX
set(ADD_BUILD_OPTIONS "${ADD_BUILD_OPTIONS} -DHDF5_BUILD_CPP_LIB:BOOL=ON")
```  
##### 2.2.4* Click again on Configure and if nothing is still red, click on Generate

##### 2.2.5* Open the project in VS 2017
##### 2.2.6* Right Click on the fftw3_threads and go to Properties/General:  
* *Windows SDK Version* => ```10.0.17763.0```
* *Configuration Type* => ```Dynamic library (dll)```


**Test:** 
##### 3. Open a cmd in the compiled directory
```ctest . -C Release``` 
##### 3.1 Check that 2027/2027 Tests are *Passed* 


test : 


 

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



PRISMATIC
In the MakeFile replace 
FIND_PACKAGE(Boost) 
by
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

Dependancies...