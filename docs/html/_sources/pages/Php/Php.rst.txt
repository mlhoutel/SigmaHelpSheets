============================
PHP
============================

.. contents:: Table of Contents
	:local: 

Introduction
============================

History of the PHP language
----------------------------

.. todo::

	Language

Programming in PHP
----------------------------

A Backend language
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. todo::

	Explanation

Setup Apache server
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. todo::

	Apache server

Cheat Sheets
===========================

Usefull Informations
---------------------------

.. _Browse phpnet: https://www.php.net/docs.php
.. _src: http://pypl.github.io/PYPL.html

+------------------------------------------------------+-------------------------------------------------------+
| **Official Documentation - Phpnet**                  | **About PHP**                                         |
+------------------------------------------------------+-------------------------------------------------------+
|                                                      | **Type of Language:** Imperative, Object-Oriented     |
|   .. image:: phpnet.PNG                              +-------------------------------------------------------+
|      :target: `Browse phpnet`_                       | **Born in:** 1994                                     |
|      :align: center                                  +-------------------------------------------------------+
|                                                      | **Caracteristics:** Simple, permissive, html inbedded |
|                                                      +-------------------------------------------------------+
|   .. image:: ../../../browse_website.png             | **Popularity:** 5.85% (5th) `src`_                    |
|      :target: `Browse phpnet`_                       +-------------------------------------------------------+
|      :width: 200                                     | **Usefull for:** website backend, database linking    |
|      :align: center                                  +-------------------------------------------------------+
|                                                      | **Misc:**  ...                                        |
+------------------------------------------------------+-------------------------------------------------------+

Types and Variables
---------------------------

.. Note:: ``variable typing`` is **automatic** in PHP

+-------------------+-----------------+--------------+-------------------+---------------------+
| Name              | Expression      | Size         | Min               | Max                 |
+===================+=================+==============+===================+=====================+
| Boolean           | ``$foo = true;``| ``1 bits``   | 0 (false)         | 1 (true)            |
+-------------------+-----------------+--------------+-------------------+---------------------+
| Int               | ``$foo = 1234;``| ``32+ bits`` | -9.223e+15        | 9.223e+15           |
+-------------------+-----------------+--------------+-------------------+---------------------+
| Float/Double      | ``$foo = 1.24;``| ``32+ bits`` | accuracy 1.11e-16                       |
+-------------------+-----------------+--------------+-------------------+---------------------+
| String            |``echo 'test';`` | ``32+ bits`` | 64-bits => no restriction, else 1.6e+10 |
+-------------------+-----------------+--------------+-------------------+---------------------+

.. tip:: It's also possible do define the type like ``$foo = (double)4;`` or like ``settype($foo,'double');`` 

Input Output
---------------------------

.. code-block:: php
	
	<?php
		$age = 18;
		var_dump($age); // => int(18)
		echo gettype($age); // => integer

		define("MAX",10);
		echo('he is '.$age.'years old');
		$input = trim(fgets(STDIN));


Variables, Tests and Loops
---------------------------

	
:TESTS IF:

.. code-block:: php
	:linenos:

	<?php
		if (Condition) {
			// Action
		}

		if (Condition) {
			// Action
		} elseif (Condition) {
			// Action
		} else {
			// Action
		}

		if(Condition)
			// Action

		($a == $b); // test equality of value
		($a === $b); // test equality of value AND type

:SWITCH:

.. code-block:: php
	:linenos:

	<?php
		switch (variable) {
			case 1: // Action
				break;
			case 2: // Action
				break;
			case 3: // Action
				break;
	}

:LOOPS:

.. code-block:: php
	:linenos:

	<?php
		for ($i=0; $i<10; $i++) {
			// Action
		}

		do {
			// Action
		} while($i > 0);

		while ($i > 0) {
			// Action
		}

		foreach ($items as $item) {
			// Action
		}

.. tip:: You can use ``break;`` to stop a loop.

Random numbers
---------------------------

:RANDOMS:

.. code-block:: php
	:linenos:

	<?php
		define("MIN", 0);
		define("MAX", 100);

		$alea = rand(MIN,MAX); // alias of mt_rand(MIN,MAX) since PHP 7.1.0

Arrays
---------------------------

:ARRAYS:

.. code-block:: php
	:linenos:

	<?php
		$table = array("E1"=>0, "E2"=>6, "E3"=>5);
		$table['E1'] = 10;
		$table['E2'] = 13;
		$table['V1'] = 5;

		echo($table['E1']); // 10

		foreach ($table as $key => $value) {
			echo ("$key : $value \n");
		}

		for($i=0; $i<count($table);$i++) {
			echo $test[$i;]
		}

		print_r($table);
		
		/*
		Array
		(
		    [E1] => 10
		    [E2] => 13
		    [E3] => 5
		    [V1] => 5
		)
		*/

		$test = array(10, 15, 20);
		count($test); // 3

:ARRAYS OPERATORS:

.. code-block:: php
	:linenos:

	<?php
		$array_a = array(...);
		$array_b = array(...);

		$array_a + $array_b // union of a and b
		array_merge($array_a, $array_) // addition of items
		array_intersect($array_a, $array_) // intersection of items

		min($array_a); // return the min elem
		max($array_a); // return the max elem
		array_sum($array_a, $array_b); // return the sum of elem
		in_array("test", $array_a); // search and return true/false
		array_search("test", $array_a); // search and return the position
		array_shift($array_a); // extract the first value
		array_pop($array_a); // extract the last value

		echo(round(6.1234, 2)); // 6.12
		echo(pow(5,2)); // 25

		array_slice($array,2,1);

:STRINGS:

.. code-block:: php
	:linenos:

	<?php
		$string = 'my String';
		echo('length: ' . strlen($string)); // length: 9

		echo('substr 0 7: ' . substr($string, 0, 7)); // substr 0 7: my Stri
	 	echo('substr 1 1: ' . substr($string, 2, 2)); // substr 1 1: y
	 	echo('substr 1: ' . substr($string, 1)); // substr 1: y String

	 	echo('strpos S: ' . strpos($string, "S")); // strpos S: 3 (First occurence)
	 	echo('strpos s: ' . strpos($string, "s")); // strpos s: false (Case sensitive)
	 	echo('stripos s: ' . stripos($string, "s")); // stripos s: 3 (Not case sensitive)
	 	echo('strrpos s: ' . strrpos($string, "s")); // strrpos s: 3 (Last occurence)

		echo('lower: ' . strtolower($string)); // lower: my string
		echo('upper: ' . strtoupper($string)); // upper: MY STRING

		echo('first maj: ' . ucfirst($string)); // first maj: My String
		echo('first min: ' . lcfirst($string)); // first min: my string

		explode(" ", $chain);

:FILTER:

.. code-block:: php
	:linenos:

	<?php
		filter_var($mail, FILTER_VALIDATE_EMAIL);
		$verification = preg_match($pattern, $string);

+-----------+---------------+
| ``$``     | end chain     |
+-----------+---------------+
| ``^``     | begin chain   |
+-----------+---------------+
| ``.``     | anything      |
+-----------+---------------+
| ``{1}``   | exact number  |
+-----------+---------------+
| ``[a-z]`` | chars         |
+-----------+---------------+
| ``[^b]``  | not char      |
+-----------+---------------+

:FOLDERS:

.. code-block:: php
	:linenos:

	<?php
		$handle = fopen("file.txt","r"); // pointer or false
		if ($handle) {
			while ($buffer = fgets($handle,2) != false) { // return the line of a defined size
				echo $buffer;
			}
		}
		fwrite($handle, $string);
		fclose($handle);

		file($filename [, FILE_IGNORE_NEW_LINES / FILE_SKIP_EMPTY_LINES]); // return file in array

+-------+-------------------------+
| ``r`` | read from beggining     |
+-------+-------------------------+
| ``r+``| writing from end        |
+-------+-------------------------+
| ``w`` | reset and write         |
+-------+-------------------------+
| ``a`` | reate or write from end |
+-------+-------------------------+

:DATE:

.. code-block:: php
	:linenos:

	<?php
		date_default_timezone_set('Europe/Paris');
		date('Y')/date('m')/date('d');

Functions
---------------------------

.. code-block:: php
	:linenos:

	<?php
		function say($text[, $language="EN"]) {
			echo($text);
			return $language;
		}

Embedded PHP
===========================

Post/Get
---------------------------

:FORM:

.. code-block:: html
	:linenos:

	<form id="inscription" method="post" action="form.php">
		<p>
			<label for="name">Name:</label>
			<input type="text" name="name" id="name">
		</p>
		<input type="submit" name="validate" id="validate" value="Send"/>
	</form>

TODO

:Text Input:

* **value:** displayed value
* **size:** handler size
* **name:** datas in php
* **placeholder:** information
* **maxlength:** max enabled
* **title:** hovering info
* **required:** needed to validate
* **pattern** ="^[A-Za-z]+$"

:TextArea Input:

.. code-block:: html
	:linenos:

	<textarea name="area" id="area" rows="10" cols="10">
		default text
	</textarea>

:Radio Input:

* **value:** 0 or 1
* **checked:** default

:Checkbox Input:

* name="array[]"

:Select Input:

.. code-block:: html
	:linenos:

	<select name="departement" id="departement">
		<option value="choice A">Choice A</option>
		<option value="choice B">Choice B</option>
		<option value="choice C">Choice C</option>
	</select>

:Special Inputs:

* **url**
* **email**
* **number**
* **tel**
* **date**
* **time**
* **search**
* **color**
* **range**

:FieldSet:

.. code-block:: html
	:linenos:

	<fieldset>
		<legend> Legend </legend>

		<!-- FORM -->

	</fieldset>

:Datas:

.. code-block:: php
	:linenos:

	<?php

		print_r($_POST);
		echo ("Hello ".$_POST["name"]);

		if (isset($_POST["sports"] as $sport)) {
			echo "<ul>";
			foreach ($_POST["sports"] as $sport) {
				echo "<li> $sport </li>";
			}
			echo "</ul>";
		}

:Include in same page:

.. code-block:: php
	:linenos:

	<?php

		if (!empty($_POST[])) {
			include_once("file.php");
		}

:Dynamic variable:

.. code-block:: php
	:linenos:

	<?php
		$names = array('name','surname');

		foreach ($names as $name) {
			$$name = $_POST[$name];
		}

		echo $name; // instead of echo $_POST["name"];
		echo $surname;

MVC
============================

.. todo::

	Mvc

Laravel
============================

.. todo::

	Laravel