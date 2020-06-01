
============================
C++
============================

.. contents:: Table of Contents
	:local: 
	
Introduction
============================

History of the C language
----------------------------

C is an ``imperative procedural language``. It was designed to be  ``compiled`` to provide  ``low-level access to memory``.

It was developed between 1972 and 1973 by  ``Dennis Ritchie``, initially to construct utilities running on the  ``Unix`` operating system.
During the 1980s, C gradually gained popularity and became one of the most widely used programming languages.

Today, the C is not as popular as it used to be, but it's still a very good language to begin with and understand the rules of programmation.
Moreover, it is realy  ``fast and light`` and permit to manage the low level datas with the  ``pointers``, one thing that most of the high level languages can't.

Evolution toward C++
----------------------------

C++ was developped in 1979 by  ``Bjarne Stroustrup``. It was firstly named  ``C with Classes`` by it's creator, then renamed in 1983.
It is an evolution toward an more  ``Object Oriented programming language``, that it implements with Classes, Inheritance and many others functionnalities.

The current version of it is  ``C++17`` (2017). A new one is standardized by the ISO every 3 years since 2011, the next versions is  ``C++20``, already released but not every functionnality are supported yet on the compilators. 

Programming in C 
============================

First Program : helloworld.c
----------------------------
.. literalinclude:: helloworld.c
          :language: cpp
          :linenos:
          :lines: 1-6

This file is a simple ``.txt file``, I just edited the **extension**. Like you can see, it is ``.c`` for the base language, and ``.cpp`` for C++, but these are not the only ones that exist, there are many others, like ``.h`` and ``.hpp`` for the **header files**, ``.cuh`` and ``.cu`` for CUDA...

To have your program working, you'll have to **build the file**:
To put it simply, we get the ``source code`` (*helloworld.c*) and put it into a ``compiler`` with the right settings and dependancies, and this compiler output and ``executable`` (*helloworld.exe*) that you can run from your machine. We will use the ``command line`` to build and run this file, it's realy easy.

Compiling
---------
But first of all, you will need a compiler. That's a piece of software that transform your file from ``readable instructions`` (in english) into a language that your machine can understand: ``binaries`` (0 and 1), that's what an ``.exe`` file is (if you open it with and text editor, you will see some stranges charaters).

Many C compiler exists, (`See all <https://en.wikipedia.org/wiki/List_of_compilers#C_compilers>`_), I recommand these ones:

.. _Download GCC from GNU: https://gcc.gnu.org/
.. _Download Visual Studio: https://visualstudio.microsoft.com/fr/downloads/

+-------------------------------------+------------------------------------+
| GCC (from GNU, Open sources)        | `Download GCC from GNU`_           |
+-------------------------------------+------------------------------------+
| MSVC (from Microsoft Visual Studio) | `Download Visual Studio`_          |
+-------------------------------------+------------------------------------+

For this example, I'm using `GCC 10.0.1 <ftp://ftp.lip6.fr/pub/gcc/releases/gcc-10.1.0/>`_, the base ``command line`` from **Windows 10** and the text editor `Sublime Text 3 <https://www.sublimetext.com/3>`_

.. note::
	
	I recommand to install GCC by MinGW instead of compiling it yourself, you will find explanations on how to proceed `HERE <http://mingw.org/wiki/Getting_Started>`_

Setup GCC and compiling a basic program
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. If you are on windows, you can press ``Windows`` + ``Q`` then type ``cmd`` to open the command line.

	1.1 Open it and try to type ``gcc`` and press ``Enter``

	1.2 If you have a message that look like that, make sure that you downloaded GCC and go to the next step: We will add GCC to the environment variables so the system can find it::

		'gcc' n’est pas reconnu en tant que commande interne

	1.3 The system need to know where the compiler is to understand that you call it from the command line. 

		1.3.1 Press ``Windows`` + ``Q`` then type ``env`` and open ``Edit the system environment variables`` 

		1.3.2 Click on the ``Environment variables`` button

		1.3.3 Select ``Path`` and click on ``Edit``

		1.3.4 Finally, click on ``New`` and paste the link to GCC (ex: ``C:\MinGW\bin``)

	1.4 Open a new command and type ``gcc``, now it should work and diplay that message::

		gcc: fatal error: no input files
		compilation terminated.

2. Now we will compile the file ``helloworld.c``
	
	2.1 Open a command in the same directory as the C file

	2.2 type these commands::

		gcc helloworld.c -o helloworld.exe
		helloworld.exe

	2.3 The program will output this string::

		Hello, World!

3. Great, you have now a ``working basis`` to begin your learning of the ``C`` and ``C++`` languages. 

.. centered:: Good luck!
		
Compilator settings and flags
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. note::
	
	You can call the compiler by ``gcc`` for the **C compiler** and ``g++`` for the **C++ compiler**. I explain here the flags that I use and find the **most important**, but you can find all the gcc flags `HERE <https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html>`_. If you want, you can even create a ``.bat`` file to automate the command and launch the compilations.

:Command Syntax:

.. parsed-literal::

	gcc [options] [source files] [object files] -o output file

If you don't put ``-o output file``, the output file will be ``a.exe`` per default.

:Add libraries: 

.. parsed-literal::

	 -I %libpath%\include -L %libpath%\lib -l libfileA -l libfileB

- ``-I`` define the include folder, generally where the headers files ``.h`` are
- ``-L`` define the folder where to look at the source files 
- ``-l`` define the name/link for the library to include ``.dll`` if the lib is dynamically compiled, and ``.lib`` if it is staticaly compiled

:Warnings and Errors:

The **Errors Flags** begin with a ``-W`` (for Warning):

- ``-w`` disable all warnings messages, the program will keep compiling
- ``-Wall`` enables all the warnings for minors errors
- ``-Wextra`` enables some extra warning flags that -Wall don't activate
- ``-Werror`` make all warnings into errors. 
- ``-Wfatal-errors`` abort compilation on the first error

.. admonition:: Debug Flags
	
	.. parsed-literal::

		-Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wshadow -Weffc++ -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default -Wswitch-enum -Wundef -Wlogical-op -Winline

	For the Debug config, you can put all the flags to detect and display every error or unrecommanded feature of your code.

.. admonition:: Release Flags

	.. parsed-literal::

		-Werror -Wfatal-errors

	For the Release config, the process abort at the first error

The **Debug Flags** begin with a ``-g`` (for Generate debug informations)

- ``-g0`` no debug informations
- ``-g1`` minimal debug informations
- ``-g`` default debug informations
- ``-g3`` maximal debug informations

.. tip:: I recommand to stay with the default value ``-g`` and switch to higher level ``-g3`` if you have no clue on the error.

:Optimisation:

The **Optimisation Flags** begin with a ``-O`` (for Optimisation)

+--------+--------------------+----------------+-----------+--------------+-------------------+
| Option | Optimization Level | Execution Time | Code Size | Memory Usage | Compilation Time  |
+========+====================+================+===========+==============+===================+
| -O0    | compilation time   |	       \+      |    \+     |      \-      |        \-         |
+--------+--------------------+----------------+-----------+--------------+-------------------+
| -O1/-O | code size/exe time |	      \-       |    \-     |      \+      |        \+         |
+--------+--------------------+----------------+-----------+--------------+-------------------+
| -O2    | code size/exe time |	     \- \-     |    \=     |      \+      |       \+ \+       |
+--------+--------------------+----------------+-----------+--------------+-------------------+
| -O3    | code size/exe time |	   \- \- \-    |    \=     |      \+      |      \+ \+ \+     |
+--------+--------------------+----------------+-----------+--------------+-------------------+
| -Os    | code size          |	      \=       |   \- \-   |      \=      |      \+ \+        |
+--------+--------------------+----------------+-----------+--------------+-------------------+
| -Ofast | imprecise fast math|	   \- \- \-    |    \=     |      \+      |     \+ \+ \+      |
+--------+--------------------+----------------+-----------+--------------+-------------------+

*informations from https://www.rapidtables.com/code/linux/gcc/gcc-o.html#optimization*

Import and use Libraries 
------------------------------

Includes and Dependancies
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

To **include a library** we use the ``#include`` command.

- ``#include <library.h>`` when the headers folder is already linked in the compiler
- ``#include "folder/library.h"`` to search in a specific folder with the path

:List of the most common and used system libraries:

- **C** Input/Output library: ``#include <stdio.h>`` 
- **C** General library: ``#include <stdlib.h>``
- **C** Numerics library : ``#include <cmath.h>`` 
- **C** Strings library: ``#include <string.h>`` 
- **C** Time library: ``#include <time.h>`` 
- **C++** Time library: ``#include <chrono>`` 

*informations from https://en.cppreference.com/w/cpp/header*

Namespace and utilities
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
When you use multiple libraries, it could be some ``conflicts`` under names between some libraries, that's why we use ``namespaces``.

.. centered:: "Namespaces provide a method for preventing name conflicts in large projects." `source <https://en.cppreference.com/w/cpp/language/namespace>`_

:We can use namespaces like that: ``sf::...``

.. code-block:: objective-c

	sf::RectangleShape rectangle(sf::Vector2f(120,50));

:Or like that: ``namespace sf { ... }``

.. code-block:: objective-c

	namespace sf {
		Rectangle Shape rectangle(Vector2f(120,50));
	}

:Or even like that: ``using namespace sf;``

.. code-block:: objective-c

	using namespace sf;

	Rectangle Shape rectangle(Vector2f(120,50));


.. tip:: **I recommand the first two methods**, the problem with the last one is that you ``loose all the purpose`` of the namespace, and it's ``confusing`` when you want to use both functions from libraries that would be in conflict, you will have to mix the third and the first method...

----------------------------------------------------------------------------------

Cheat Sheets
===========================

Basic C Cheat Sheet
---------------------------

Types and Variables
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. Note:: ``/s/`` stand for **Signed** and ``/u/`` for **Unsigned**

:INTEGERS:

+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Name              | Syntax         | Size         | Min               | Max               | Letter | Aliases        |
+===================+================+==============+===================+===================+========+================+
| Short ``/s/``     | ``short int``  | ``16+ bits`` | -32 768           | 32 767            | ``%h`` |``short``       |
| Integer           |                |              | :math:`(-2^{15})` | :math:`(2^{15}-1)`|        |``signed short``|
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Short ``/u/``     | ``unsigned     | ``16+ bits`` | 0                 | 65 535            | ``%h`` |``unsigned``    |
| Integer           | short int``    |              | :math:`(0)`       | :math:`(2^{16}-1)`|        |``short``       |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Integer ``/s/``   | ``int``        | ``16+ bits`` | -32 768           | 32 767            | ``%i`` | ``signed``     |
|                   |                |              | :math:`(-2^{15})` | :math:`(2^{15}-1)`|        | ``signed int`` |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Integer ``/u/``   |``unsigned int``| ``16+ bits`` | 0                 | 65 535            | ``%i`` |``unsigned``    |
|                   |                |              | :math:`(0)`       | :math:`(2^{16}-1)`|        |``unsigned int``|
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Long ``/s/``      | ``long int``   | ``32+ bits`` | -2 147 483 648    | 2 147 483 647     | ``%l`` | ``signed       |
| Integer           |                |              | :math:`(-2^{31})` | :math:`(2^{31}-1)`|        | long int``     |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Long ``/u/``      | ``unsigned     | ``32+ bits`` | 0                 | 4 294 967 295     | ``%l`` | ``unsigned     |
| Integer           | long int``     |              | :math:`(0)`       | :math:`(2^{32}-1)`|        | long``         |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Long Long ``/s/`` | ``long long    | ``64+ bits`` | -9.223e-15        | -9.223e+15        | ``%ll``| ``signed       |
| Integer           | int``          |              | :math:`(-2^{63})` | :math:`(2^{63}-1)`|        | long long``    |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Long Long ``/u/`` | ``unsigned long| ``64+ bits`` | 0                 | 18.446e+15        | ``%ll``| ``unsigned     |
| Integer           | long int``     |              | :math:`(0)`       | :math:`(2^{64}-1)`|        | long long``    |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+

.. tip:: Integers are not rounded they are truncated toward 0. I recommand to not use short appart if you know what you do.

:CHARS:

+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Name              | Syntax         | Size         | Min               | Max               | Letter | Aliases        |
+===================+================+==============+===================+===================+========+================+
| Char ``/s/``      | ``char``       | ``8+ bits``  | -128              | 127               | ``%hh``|``signed char`` |
|                   |                |              | :math:`(-2^{7})`  | :math:`(2^{7}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Char ``/u/``      | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+

char8_t
char16_t
char32_t
wchar_t


.. tip:: Chars are just integers linked to an characted by the ascii table.

:ASCII TABLE:

+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+
| DEC | HEX | BIN         | CHAR                     |   | DEC | HEX | BIN         | CHAR                     |   | DEC | HEX | BIN         | CHAR                     |
+=====+=====+=============+==========================+===+=====+=====+=============+==========================+===+=====+=====+=============+==========================+
| 0   | 00  |``0000 0000``| NUL (null)               |   | 32  | 20  |``0010 0000``|                          |   | 64  | 40  |``0100 0000``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 1   | 01  |``0000 0001``| SOH (start of header)    |   | 33  | 21  |``0010 0001``|                          |   | 65  | 41  |``0100 0001``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 2   | 02  |``0000 0010``| STX (start of text)      |   | 34  | 22  |``0010 0010``|                          |   | 66  | 42  |``0100 0010``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 3   | 03  |``0000 0011``| ETX (end of text)        |   | 35  | 23  |``0010 0011``|                          |   | 67  | 43  |``0100 0011``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 4   | 04  |``0000 0100``|EOT (end of transmission) |   | 36  | 24  |``0010 0100``|                          |   | 68  | 44  |``0100 0100``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 5   | 05  |``0000 0101``|                          |   | 37  | 25  |``0010 0101``|                          |   | 69  | 45  |``0100 0101``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 6   | 06  |``0000 0110``|                          |   | 38  | 26  |``0010 0110``|                          |   | 70  | 46  |``0100 0110``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 7   | 07  |``0000 0111``|                          |   | 39  | 27  |``0010 0111``|                          |   | 71  | 47  |``0100 0111``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 8   | 08  |``0000 1000``|                          |   | 40  | 28  |``0010 1000``|                          |   | 72  | 48  |``0100 1000``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 9   | 09  |``0000 1001``|                          |   | 41  | 29  |``0010 1001``|                          |   | 73  | 49  |``0100 1001``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 10  | 0A  |``0000 1010``|                          |   | 42  | 2A  |``0010 1010``|                          |   | 74  | 4A  |``0100 1010``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 11  | 0B  |``0000 1011``|                          |   | 43  | 2B  |``0010 1011``|                          |   | 75  | 4B  |``0100 1011``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 12  | 0C  |``0000 1100``|                          |   | 44  | 2C  |``0010 1100``|                          |   | 76  | 4C  |``0100 1100``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 13  | 0D  |``0000 1101``|                          |   | 45  | 2D  |``0010 1101``|                          |   | 77  | 4D  |``0100 1101``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 14  | 0E  |``0000 1110``|                          |   | 46  | 2E  |``0010 1110``|                          |   | 78  | 4E  |``0100 1110``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 15  | 0F  |``0000 1111``|                          |   | 47  | 2F  |``0010 1111``|                          |   | 79  | 4F  |``0100 1111``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 16  | 10  |``0001 0000``|                          |   | 48  | 30  |``0011 0000``|                          |   | 80  | 50  |``0101 0000``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 17  | 11  |``0001 0001``|                          |   | 49  | 31  |``0011 0001``|                          |   | 81  | 51  |``0101 0001``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 18  | 12  |``0001 0010``|                          |   | 50  | 32  |``0011 0010``|                          |   | 82  | 52  |``0101 0010``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 19  | 13  |``0001 0011``|                          |   | 51  | 33  |``0011 0011``|                          |   | 83  | 53  |``0101 0011``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 20  | 14  |``0001 0100``|                          |   | 52  | 34  |``0011 0100``|                          |   | 84  | 54  |``0101 0100``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 21  | 15  |``0001 0101``|                          |   | 53  | 35  |``0011 0101``|                          |   | 85  | 55  |``0101 0101``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 22  | 16  |``0001 0110``|                          |   | 54  | 36  |``0011 0110``|                          |   | 86  | 56  |``0101 0110``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 23  | 17  |``0001 0111``|                          |   | 55  | 37  |``0011 0111``|                          |   | 87  | 57  |``0101 0111``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 24  | 18  |``0001 1000``|                          |   | 56  | 38  |``0011 1000``|                          |   | 88  | 58  |``0101 1000``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 25  | 19  |``0001 1001``|                          |   | 57  | 39  |``0011 1001``|                          |   | 89  | 59  |``0101 1001``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 26  | 1A  |``0001 1010``|                          |   | 58  | 3A  |``0011 1010``|                          |   | 90  | 5A  |``0101 1010``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 27  | 1B  |``0001 1011``|                          |   | 59  | 3B  |``0011 1011``|                          |   | 91  | 5B  |``0101 1011``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 28  | 1C  |``0001 1100``|                          |   | 60  | 3C  |``0011 1100``|                          |   | 92  | 5C  |``0101 1100``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 29  | 1D  |``0001 1101``|                          |   | 61  | 3D  |``0011 1101``|                          |   | 93  | 5D  |``0101 1101``|                          |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+
| 30  | 1E  |``0001 1110``|                          |   | 62  | 3E  |``0011 1110``|                          |   | 94  | 5E  |``0101 1110``|                          |
+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+
| 31  | 1F  |``0001 1111``|                          |   | 63  | 3F  |``0011 1111``|                          |   | 95  | 5F  |``0101 1111``|                          |
+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+

*informations from https://fr.cppreference.com/w/cpp/language/ascii*

:FLOATS:


Input Output
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: inputoutput.c
          :language: cpp
          :linenos:

.. code-block:: 

	Enter an integer for your age: 19
	You are 19 years old.
	Great!

.. Note:: 
	
	If you input ``a`` you will have an output of ``4194432``. That's because scanf don't convert the string to an int. 
	When the value is not in the right format, it will get the ``memory location``.

	For the boundaries, an input of ``2147483647`` will output ``2147483647``, but if you try to enter a 
	value of ``2147483648`` you will have an output of ``-2147483648``. Thats because the signed value is greater than 
	:math:`2^{31}-1`. The default int boundaries are ``32bits`` on my ``x64 processor`` 


Tests and Loops
~~~~~~~~~~~~~~~~~~~~~~~~~~~


Structures
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: structure.c
          :language: cpp
          :linenos:

.. code-block:: 

	structure: Rectangle
	 + Position: [10.000000, 2.000000]
	 + Size: [3.700000, 6.500000]
	 + Area: 24.050000

Pointers and Smart pointers
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: pointer.c
          :language: cpp
          :linenos:

Basic C++ Cheat Sheet
---------------------------

Classes and Properties
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Inheritances
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Virtual classes
~~~~~~~~~~~~~~~~~~~~~~~~~~~

SFML
============================

+---------------------+---------------------------+
| Instruction         | Command                   |
+=====================+===========================+
| **Namespace**       | ``using namespace sf;``   |
+---------------------+---------------------------+
| **main function**   | ``int main() { }``        |
+---------------------+---------------------------+

Qt
============================


CMake and Builds
============================