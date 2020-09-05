
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

.. code-block:: console

	gcc [options] [source files] [object files] -o output file

If you don't put ``-o output file``, the output file will be ``a.exe`` per default.

:Add libraries: 

.. code-block:: console

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
	
	.. code-block:: console

		-Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wshadow -Weffc++ -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default -Wswitch-enum -Wundef -Wlogical-op -Winline

	For the Debug config, you can put all the flags to detect and display every error or unrecommanded feature of your code.

.. admonition:: Release Flags

	.. code-block:: console

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

+----------+--------------------+----------------+-----------+--------------+-------------------+
| Option   | Optimization Level | Execution Time | Code Size | Memory Usage | Compilation Time  |
+==========+====================+================+===========+==============+===================+
|``-O0``   | compilation time   |        \+      |    \+     |      \-      |        \-         |
+----------+--------------------+----------------+-----------+--------------+-------------------+
|``-O1/-O``| code size/exe time |       \-       |    \-     |      \+      |        \+         |
+----------+--------------------+----------------+-----------+--------------+-------------------+
|``-O2``   | code size/exe time |      \- \-     |    \=     |      \+      |       \+ \+       |
+----------+--------------------+----------------+-----------+--------------+-------------------+
|``-O3``   | code size/exe time |    \- \- \-    |    \=     |      \+      |      \+ \+ \+     |
+----------+--------------------+----------------+-----------+--------------+-------------------+
|``-Os``   | code size          |       \=       |   \- \-   |      \=      |      \+ \+        |
+----------+--------------------+----------------+-----------+--------------+-------------------+
|``-Ofast``| imprecise fast math|    \- \- \-    |    \=     |      \+      |     \+ \+ \+      |
+----------+--------------------+----------------+-----------+--------------+-------------------+

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
- **C++** Treads library: ``#include <thread>`` 

*informations from https://en.cppreference.com/w/cpp/header*

Namespace and utilities
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
When you use multiple libraries, it could be some ``conflicts`` under names between some libraries, that's why we use ``namespaces``.

.. centered:: "Namespaces provide a method for preventing name conflicts in large projects." `source <https://en.cppreference.com/w/cpp/language/namespace>`_

:We can use namespaces like that: ``sf::...``

.. code-block:: cpp

	sf::RectangleShape rectangle(sf::Vector2f(120,50));


:Or like that: ``namespace sf { ... }``

.. code-block:: cpp

	namespace sf {
		RectangleShape rectangle(Vector2f(120,50));
	}

:Or even like that: ``using namespace sf;``

.. code-block:: cpp

	using namespace sf;

	RectangleShape rectangle(Vector2f(120,50));


.. tip:: **I recommand the first two methods**, the problem with the last one is that you ``loose all the purpose`` of the namespace, and it's ``confusing`` when you want to use both functions from libraries that would be in conflict, you will have to mix the third and the first method...

----------------------------------------------------------------------------------



Cheat Sheets
===========================

Usefull Informations
---------------------------

.. _Browse cppreference: https://en.cppreference.com/w/
.. _src: http://pypl.github.io/PYPL.html
+------------------------------------------------------+-------------------------------------------------------+
| **Unofficial Documentation - CppReference**          | **About Cpp**                                         |
+------------------------------------------------------+-------------------------------------------------------+
|                                                      | **Type of Language:** Procedural, Object-Oriented     |
|   .. image:: cppreference.PNG                        +-------------------------------------------------------+
|      :target: `Browse cppreference`_                 | **Born in:** 1985                                     |
|      :align: center                                  +-------------------------------------------------------+
|                                                      | **Caracteristics:** Statically typed, low level, fast |
|                                                      +-------------------------------------------------------+
|   .. image:: ../../../browse_website.png             | **Popularity:** 5.8% (6th) `src`_                     |
|      :target: `Browse cppreference`_                 +-------------------------------------------------------+
|      :width: 200                                     | **Usefull for:** softwares, games, embedded...        |
|      :align: center                                  +-------------------------------------------------------+
|                                                      | **Misc:**  ...                                        |
+------------------------------------------------------+-------------------------------------------------------+

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
| Long Long ``/s/`` | ``long long    | ``64+ bits`` | -9.223e-15        | 9.223e+15         | ``%ll``| ``signed       |
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
| char8_t ``/u/``   | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| char16_t ``/u/``  | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| char32_t ``/u/``  | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| wchar_t ``/u/``   | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+


.. tip:: Chars are just integers linked to an characted by the ascii table.

:ASCII TABLE:

+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| DEC | HEX | BIN         | CHAR                     |   | DEC | HEX | BIN         | CHAR                     |   | DEC | HEX | BIN         | CHAR                     | DEC | HEX | BIN         | CHAR                     |
+=====+=====+=============+==========================+===+=====+=====+=============+==========================+===+=====+=====+=============+==========================+=====+=====+=============+==========================+
| 0   | 00  |``0000 0000``| NUL (null)               |   | 32  | 20  |``0010 0000``| ``(space)``              |   | 64  | 40  |``0100 0000``| ``@``                    | 96  | 60  |``0110 0000``|  `                       |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 1   | 01  |``0000 0001``| SOH (start of header)    |   | 33  | 21  |``0010 0001``| ``!``                    |   | 65  | 41  |``0100 0001``| ``A``                    | 97  | 61  |``0110 0001``| ``a``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 2   | 02  |``0000 0010``| STX (start of text)      |   | 34  | 22  |``0010 0010``| ``"``                    |   | 66  | 42  |``0100 0010``| ``B``                    | 98  | 62  |``0110 0010``| ``b``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 3   | 03  |``0000 0011``| ETX (end of text)        |   | 35  | 23  |``0010 0011``| ``#``                    |   | 67  | 43  |``0100 0011``| ``C``                    | 99  | 63  |``0110 0011``| ``c``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 4   | 04  |``0000 0100``| EOT (end of transmission)|   | 36  | 24  |``0010 0100``| ``$``                    |   | 68  | 44  |``0100 0100``| ``D``                    | 100 | 64  |``0110 0100``| ``d``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 5   | 05  |``0000 0101``| ENQ (enquiry)            |   | 37  | 25  |``0010 0101``| ``%``                    |   | 69  | 45  |``0100 0101``| ``E``                    | 101 | 65  |``0110 0101``| ``e``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 6   | 06  |``0000 0110``| ACK (acknowledge)        |   | 38  | 26  |``0010 0110``| ``&``                    |   | 70  | 46  |``0100 0110``| ``F``                    | 102 | 66  |``0110 0110``| ``f``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 7   | 07  |``0000 0111``| EL (bell)                |   | 39  | 27  |``0010 0111``| ``'``                    |   | 71  | 47  |``0100 0111``| ``G``                    | 103 | 67  |``0110 0111``| ``g``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 8   | 08  |``0000 1000``| BS (backspace)           |   | 40  | 28  |``0010 1000``| ``(``                    |   | 72  | 48  |``0100 1000``| ``H``                    | 104 | 68  |``0110 1000``| ``h``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 9   | 09  |``0000 1001``| HT (horizontal tab)      |   | 41  | 29  |``0010 1001``| ``)``                    |   | 73  | 49  |``0100 1001``| ``I``                    | 105 | 69  |``0110 1001``| ``i``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 10  | 0A  |``0000 1010``| LF (line feed - new line)|   | 42  | 2A  |``0010 1010``| ``*``                    |   | 74  | 4A  |``0100 1010``| ``J``                    | 106 | 6A  |``0110 1010``| ``j``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 11  | 0B  |``0000 1011``| VT (vertical tab)        |   | 43  | 2B  |``0010 1011``| ``+``                    |   | 75  | 4B  |``0100 1011``| ``K``                    | 107 | 6B  |``0110 1011``| ``k``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 12  | 0C  |``0000 1100``| FF (form feed - new page)|   | 44  | 2C  |``0010 1100``| ``,``                    |   | 76  | 4C  |``0100 1100``| ``L``                    | 108 | 6C  |``0110 1100``| ``l``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 13  | 0D  |``0000 1101``| CR (carriage return)     |   | 45  | 2D  |``0010 1101``| ``-``                    |   | 77  | 4D  |``0100 1101``| ``M``                    | 109 | 6D  |``0110 1101``| ``m``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 14  | 0E  |``0000 1110``| SO (shift out)           |   | 46  | 2E  |``0010 1110``| ``.``                    |   | 78  | 4E  |``0100 1110``| ``N``                    | 110 | 6E  |``0110 1110``| ``n``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 15  | 0F  |``0000 1111``| SI (shift in)            |   | 47  | 2F  |``0010 1111``| ``/``                    |   | 79  | 4F  |``0100 1111``| ``O``                    | 111 | 6F  |``0110 1111``| ``o``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 16  | 10  |``0001 0000``| DLE (data link escape)   |   | 48  | 30  |``0011 0000``| ``0``                    |   | 80  | 50  |``0101 0000``| ``P``                    | 112 | 70  |``0111 0000``| ``p``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 17  | 11  |``0001 0001``| DC1 (device control 1)   |   | 49  | 31  |``0011 0001``| ``1``                    |   | 81  | 51  |``0101 0001``| ``Q``                    | 113 | 71  |``0111 0001``| ``q``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 18  | 12  |``0001 0010``| DC2 (device control 2)   |   | 50  | 32  |``0011 0010``| ``2``                    |   | 82  | 52  |``0101 0010``| ``R``                    | 114 | 72  |``0111 0010``| ``r``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 19  | 13  |``0001 0011``| DC3 (device control 3)   |   | 51  | 33  |``0011 0011``| ``3``                    |   | 83  | 53  |``0101 0011``| ``S``                    | 115 | 73  |``0111 0011``| ``s``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 20  | 14  |``0001 0100``| DC4 (device control 4)   |   | 52  | 34  |``0011 0100``| ``4``                    |   | 84  | 54  |``0101 0100``| ``T``                    | 116 | 74  |``0111 0100``| ``t``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 21  | 15  |``0001 0101``|NAK (negative acknowledge)|   | 53  | 35  |``0011 0101``| ``5``                    |   | 85  | 55  |``0101 0101``| ``U``                    | 117 | 75  |``0111 0101``| ``u``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 22  | 16  |``0001 0110``| SYN (synchronous idle)   |   | 54  | 36  |``0011 0110``| ``6``                    |   | 86  | 56  |``0101 0110``| ``V``                    | 118 | 76  |``0111 0110``| ``v``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 23  | 17  |``0001 0111``|ETB (EOF transmitionblock)|   | 55  | 37  |``0011 0111``| ``7``                    |   | 87  | 57  |``0101 0111``| ``W``                    | 119 | 77  |``0111 0111``| ``w``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 24  | 18  |``0001 1000``| CAN (cancel)             |   | 56  | 38  |``0011 1000``| ``8``                    |   | 88  | 58  |``0101 1000``| ``X``                    | 120 | 78  |``0111 1000``| ``x``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 25  | 19  |``0001 1001``| EM (end of medium)       |   | 57  | 39  |``0011 1001``| ``9``                    |   | 89  | 59  |``0101 1001``| ``Y``                    | 121 | 79  |``0111 1001``| ``y``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 26  | 1A  |``0001 1010``| SUB (substitute)         |   | 58  | 3A  |``0011 1010``| ``:``                    |   | 90  | 5A  |``0101 1010``| ``Z``                    | 122 | 7A  |``0111 1010``| ``z``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 27  | 1B  |``0001 1011``| ESC (escape)             |   | 59  | 3B  |``0011 1011``| ``;``                    |   | 91  | 5B  |``0101 1011``| ``[``                    | 123 | 7B  |``0111 1011``| ``{``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 28  | 1C  |``0001 1100``| FS (file separator)      |   | 60  | 3C  |``0011 1100``| ``<``                    |   | 92  | 5C  |``0101 1100``| ``\``                    | 124 | 7C  |``0111 1100``| ``|``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 29  | 1D  |``0001 1101``| GS (group separator)     |   | 61  | 3D  |``0011 1101``| ``=``                    |   | 93  | 5D  |``0101 1101``| ``]``                    | 125 | 7D  |``0111 1101``| ``}``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 30  | 1E  |``0001 1110``| RS (record separator)    |   | 62  | 3E  |``0011 1110``| ``>``                    |   | 94  | 5E  |``0101 1110``| ``^``                    | 126 | 7E  |``0111 1110``| ``~``                    |
+-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+   +-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
| 31  | 1F  |``0001 1111``| US (unit separator)      |   | 63  | 3F  |``0011 1111``| ``?``                    |   | 95  | 5F  |``0101 1111``| ``_``                    | 127 | 7F  |``0111 1111``| DEL (delete)             |
+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+---+-----+-----+-------------+--------------------------+-----+-----+-------------+--------------------------+
*informations from https://fr.cppreference.com/w/cpp/language/ascii*

:FLOATS:

+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Name              | Syntax         | Size         | Min               | Max               | Letter | Aliases        |
+===================+================+==============+===================+===================+========+================+
| Char ``/s/``      | ``char``       | ``8+ bits``  | -128              | 127               | ``%hh``|``signed char`` |
|                   |                |              | :math:`(-2^{7})`  | :math:`(2^{7}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| Char ``/u/``      | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| char8_t ``/u/``   | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| char16_t ``/u/``  | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| char32_t ``/u/``  | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+
| wchar_t ``/u/``   | ``unsigned     | ``8+ bits``  | 0                 | 255               | ``%hh``|                |
|                   | char``         |              | :math:`(0)`       | :math:`(2^{8}-1)` |        |                |
+-------------------+----------------+--------------+-------------------+-------------------+--------+----------------+

Input Output
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: inputoutput.c
          :language: c
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


Variables, Tests and Loops
~~~~~~~~~~~~~~~~~~~~~~~~~~~

:VARIABLES DECLARATIONS:

.. literalinclude:: variables.c
          :language: c
          :linenos:

:TESTS IF:

.. code-block:: c
	:linenos:

	if (Condition) {
		// Action
	}

	if (Condition) {
		// Action
	} else if (Condition) {
		// Action
	} else {
		// Action
	}

	if(Condition)
		// Action

:SWITCH:

.. code-block:: c
	:linenos:

	switch (variable) {
		case 1: // Action
			break;
		case 2: // Action
			break;
		default: // Action
	}

:LOOPS:

.. code-block:: c
	:linenos:

	do {
		// Action
	} while(conditions);

	while (conditions) {
		// Action
	}

	for (int i=0; i<10; i++) {
		// Action
	}

.. tip:: You can use ``break;`` to stop a loop.

Random numbers
~~~~~~~~~~~~~~~~~~~~~~~~~~~

:RANDOMS:

.. literalinclude:: randoms.c
          :language: c
          :linenos:

.. tip:: You can see the max of ``rand()`` with ``RAND_MAX`` (32767+). For betters randoms number you can use the BOOST library.

Arrays
~~~~~~~~~~~~~~~~~~~~~~~~~~~

:ARRAYS:

.. literalinclude:: arrays.c
          :language: c
          :linenos:


:STRINGS:

.. literalinclude:: strings.c
          :language: c
          :linenos:

.. code-block:: c
	:linenos:

	string entry;
	int test;
	do {
		// Test if the input string is composed of chars bewteen 'a' and 'z'
		test = scanf("%1[a-z]c", &entry);
	} while(test != 1)
	

Functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: c
	:linenos:

	int random(int min, int max) {
		return (rand()%(max-min)) + min;
	}

	void nothing() {
		//return nothing ...
	}

Structures
~~~~~~~~~~~~~~~~~~~~~~~~~~~

:RECTANGLE STRUCTURE EXAMPLE:

.. literalinclude:: structure.c
          :language: c
          :linenos:

.. code-block:: 

	structure: Rectangle
	 + Position: [10.000000, 2.000000]
	 + Size: [3.700000, 6.500000]
	 + Area: 24.050000

Pointers and Smart pointers
~~~~~~~~~~~~~~~~~~~~~~~~~~~

https://www.youtube.com/watch?v=IzoFn3dfsPA
https://www.youtube.com/watch?v=DTxHyVn0ODg
https://www.youtube.com/watch?v=UOB7-B2MfwA

HEAP vs STACK
Passing by reference ...


:POINTERS:

.. literalinclude:: pointer.c
          :language: c
          :linenos:


Basic C++ Cheat Sheet
---------------------------

Input Output
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: inputoutput.cpp
          :language: cpp
          :linenos:

Arrays
~~~~~~~~~~~~~~~~~~~~~~~~~~~

:ARRAYS:

.. literalinclude:: arrays.cpp
          :language: c
          :linenos:

Classes and Properties
~~~~~~~~~~~~~~~~~~~~~~~~~~~

https://www.youtube.com/watch?v=V-BFlMrBtqQ

Inheritances
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Virtual classes
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Vectors
~~~~~~~~~~~~~~~~~~~~~~~~~~~

https://www.youtube.com/watch?v=PocJ5jXv8No
https://www.youtube.com/watch?v=HcESuwmlHEY

Threads
~~~~~~~~~~~~~~~~~~~~~~~~~~~

https://www.youtube.com/watch?v=wXBcwHwIt_I

.. literalinclude:: threads.cpp
          :language: cpp
          :linenos:


SFML
============================

.. literalinclude:: sfml.cpp
          :language: cpp
          :linenos:

Qt
============================

.. todo::

	Qt

CUDA
============================

https://matehickey.github.io/Projet-CUDA-M2/site/cuda/

.. todo::

	Cuda

CMake and Builds
============================

.. todo::

	CMake