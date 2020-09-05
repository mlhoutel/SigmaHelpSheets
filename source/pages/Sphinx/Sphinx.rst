============================
Sphinx
============================

.. contents:: Table of Contents
	:local: 

Introduction
============================

.. todo::

	Intro

Setup
============================

Installation with Anaconda
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. Note::

	**Install Anaconda:** https://docs.anaconda.com/anaconda/install/windows/

.. code:: bash
	
	$ conda create -n sphinx python=3.7 # Create the env we will use for sphinx
	$ conda activate sphinx 			# Activate the env (reopen a new command if error)
	(sphinx) $ conda install sphinx 	# Install Sphinx from the package repository

	# Extentions (themes, converter, highligting etc)
	(sphinx) $ conda install -c anaconda recommonmark 		# If you want to use the .md language in addition to the .rst base one
	(sphinx) $ conda install -c anaconda sphinx_rtd_theme 	# Read The Doc theme is a cool theme to begin, see example at https://sphinx-rtd-theme.readthedocs.io/en/stable/
	(sphinx) $ conda install -c conda-forge nbsphinx		# If you want to have embedded notebooks into the documentation 
	(sphinx) $ conda install -c conda-forge sphinx-copybutton # Add a copy button on the code blocks

	(sphinx) $ mkdir website_folder		# Create the website folder
	(sphinx) $ cd website_folder		# Go into the folder
	(sphinx) $ sphinx-quickstart		# Initialize the website

	(sphinx) $ make html
	(sphinx) $ start chrome _build/html/index.html

Website Setup
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:Source Folder:

.. code-block::

    source                                          *Root*  
    ├─── _static                                    *Ressource*
    │     ├─── main.js  
    │     ├─── style.css  
    │     ├─── image.png  
    │     ├─── favicon.ico  
    │     └─── logo.svg   
    ├─── _templates                                 *Templates*
    │     └─── layout.html   
    ├─── pages                                      *Pages*
    ├─── conf.py                                    *Config*
    └─── index.rst                                  *Main Page*

:Conf File:

.. code-block::
	
	# Configuration file for the Sphinx documentation builder.

	/* ... */

	# -- Project information -----------------------------------------------------

	project = 'Project-Name'
	copyright = 'Copyright text'
	author = 'Author Name'
	release = '1.0.0'

	/* ... */

	# -- General configuration ---------------------------------------------------

	extensions = ['recommonmark','sphinx_rtd_theme','nbsphinx','sphinx_copybutton']
	templates_path = ['_templates']
	exclude_patterns = []
	html_theme = 'sphinx_rtd_theme'
	pygments_style = 'monokai'

	html_static_path = ['_static']
	html_css_files = ['style.css']
	html_js_files = ['main.js']

	html_title = "Website Title"
	html_short_title = "Title"
	html_logo = "_static/logo.svg"
	html_favicon = "_static/favicon.ico"

	html_show_sourcelink = False
	html_theme_options = {
	    'logo_only': True,
	    'prev_next_buttons_location': 'both'
	}

Cheat Sheets
============================

ReStructuredText (.rst)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: rst
	
	============================
	Main Title
	============================

	Sub Title
	============================

	Sub Sub Title
	----------------------------

	Sub Sub Sub Title
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	:Title note:

.. code-block:: rst

	.. contents:: Table of Contents
		:local:

	.. toctree::
		:maxdepth: 2
		:caption: Maths Tree
		
		File.rst

.. code-block:: rst
	
	``inline code``

	Code example::

		if (a == b) { /* code */ }

	.. code-block::

		if (a == b) { /* code */ }

	.. code-block:: c
		:linenos:
		:lines: 1, 3-5
	    :start-after: 3
	    :end-before: 5

		if (a == b) { /* code */ }

	.. literalinclude:: file.c
		:language: c
		:linenos:

.. code-block:: rst
	
	+---------------------+---------+---+
	| 1                   | 2       | 3 |
	+---------------------+---------+---+

	+---------+---------+-----------+
	| 1       | 2       | 3         |
	+=========+=========+===========+
	| 4                 | 5         |
	+---------+---------+-----------+
	| 6       | 7       | 10        |
	+---------+---------+           |
	| 8       | 9       |           |
	+---------+---------+-----------+

	.. csv-table:: a title
	   :header: "1", "2", "3"
	   :widths: 20, 20, 20

	   "4", "5", "6"
	   "7", "8", "9"

.. topic:: Topic title

	Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 196


.. code-block:: rst
	
	.. image:: image.jpg
	    :width: 200px
	    :align: center
	    :height: 100px
	    :alt: alternate text

	.. figure:: image.jpg
	    :width: 200px
	    :align: center
	    :height: 100px
	    :alt: alternate text
	    :figclass: align-center

	    Caption text

.. code-block:: rst

	.. todo::
	.. seealso:: Note
	.. note:: Note
	.. warning:: Note
	.. Attention:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
	.. Caution:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
	.. DANGER:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
	.. WARNING:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
	.. Error:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
	.. Hint:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
	.. Important:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
	.. Note:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
	.. Tip:: Lorem ipsum dolor sit amet, consectetur adipiscing elit.

	.. admonition:: Custom Title

	    Lorem ipsum dolor sit amet, consectetur adipiscing elit.

	.. topic:: Title

		Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. 
		Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. 
		uis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. 
		Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

	.. sidebar:: Sidebar Title
		:subtitle: Sidebar Subtitle

		Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. 
		Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. 
		uis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. 
		Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.


.. code-block:: rst

	:download:`download samplet.py <sample.py>`
	:math:`\alpha > \beta`
	.. math::

    	n_{\mathrm{offset}} = \sum_{k=0}^{N-1} s_k n_k



MarkDown (.md)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Installation



Themes
============================

Install Theme
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Edit Style
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Code Syntax Highlighting
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



sphinx-quickstart

pip install pypandoc

import pypandoc
output = pypandoc.convert_file('PRISMATIC.md', 'rst')

with open("prismatic.rst", "w", encoding="utf-8") as f:
    f.write(output)


https://stackoverflow.com/questions/11315504/sphinx-list-of-supported-languages-for-highlighting

pygmentize -L lexers

https://docs.typo3.org/m/typo3/docs-how-to-document/master/en-us/WritingReST/Codeblocks.html

https://pygments.org/docs/lexers/

https://stylishthemes.github.io/Syntax-Themes/pygments/

.. tip:: 

	https://nbsphinx.readthedocs.io/en/0.7.0/installation.html