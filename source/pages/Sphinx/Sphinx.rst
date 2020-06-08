.. toctree::
	:caption: Table of Contents:
	:maxdepth: 2

============================
Sphinx
============================
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


.. code-block:: objective-c

.. centered:: "Namespaces provide a method for preventing name conflicts in large projects." `source <https://en.cppreference.com/w/cpp/language/namespace>`_

.. tip:: 