.. toctree::
	:caption: Table of Contents:
	:maxdepth: 2

============================
Python
============================

Language
============================

.. todo::

	Language

Packages Manager
============================

Pip
----------------------------

Anaconda
----------------------------

Manage Environments
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code:: bash

	conda create -n env_name python=3.7 pandas=0.16

	source activate env_name
	conda activate env_name

	source desactivate

	conda list (enviroment)

	conda install name_packages
	conda update name_packages
	conda remove name_packages

	anaconda search tensoflow (cloud)
	anaconda show jjhelmus/tensorflow

Install Packages
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

pip
conda

...

.. code:: bash

	conda create -n prismatic python=3.7
	conda activate prismatic
	conda install -c ericpre pyprismatic

	conda install constructor



Create Packages
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CONDA FORGE
https://conda-forge.org/docs/user/introduction.html#what-is-conda-forge

STRUCTURE
https://conda-forge.org/docs/user/ci-skeleton.html

AZURE PIPELINES
https://www.youtube.com/watch?v=7pzBwuMjpP0


Create structure: yaml
then build (locally or from remote like azure pipelines)?


https://www.youtube.com/watch?v=HSK-6dCnYVQ

3 files min:
	meta.yaml (description, version, source code, requirements)
	bld.bat (Windows build package)
	build.sh (Unix build package)

Conda constructor (env bootstrapper)

conda install constructor
installer settings in construct.yaml
cross plateform, create installer for linux, os, windows

Jupyter Notebook
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Numpy
============================

Cv2
============================

pyFFTW
============================

pyHdf
============================

Tensorflow
============================


Package Conda-Forge
============================

Conda-Forge docs: 
https://conda-forge.org/docs/maintainer/infrastructure.html

Smithy:
https://github.com/conda-forge/conda-smithy

.. code-block:: 

	conda install -n root -c conda-forge conda-smithy

Generating the Package skeletton:

.. code-block:: 
	
	conda skeleton pypi your_package_name

Source code must be availlable ``as one file`` (as an archive [.tar.gz, .zip, .tar.bz2, .tar.xz] or tagged on GitHub)

Package Structure
----------------------------

Base Template:
https://github.com/conda-forge/staged-recipes

.. code-block:: 

	git clone https://github.com/conda-forge/staged-recipes.git

- meta.yaml (description, version, source code, requirements)
https://conda-forge.org/docs/maintainer/adding_pkgs.html#meta-yaml

selecteur ``# [linux] [win]``

- bld.bat (Windows build package)
- build.sh (Unix build package)

Conda constructor (env bootstrapper)

conda install constructor
installer settings in construct.yaml
cross plateform, create installer for linux, os, windows

Install a Precompiled Package
------------------------------

1. Search package on the Anaconda Cloud: https://anaconda.org/conda-forge
2. Install the package: ``conda install -c conda-forge prismatic_gui``
3. It will Download and Extract all the packages that the program need to run (in ``Anaconda3\envs\env_name\Library``)
4. You can find the binaries in ``Anaconda3\envs\env_name\Library\bin``

Build Locally a Package
------------------------------

1. Install conda-build: ``conda install conda-build [--use-local]``
2. Make your package, or get a package source code (ex: https://github.com/ericpre/prismatic_split-feedstock)
3. Lanch the build conda build recipe -c conda-forge
4. You can find the build in ``Anaconda3\conda-bld``

.. code-block:: 

	conda build recipe -c conda-forge --variants "{'cuda_compiler_version':'10.2'}“

Build for Remote
------------------------------

Todo (Azure pipeline)

TEMP
============================

cd D:\Libraries\cuda_toolkit\cudatoolkit-dev-feedstock
conda build recipe -c conda-forge>output.txt
conda install cudatoolkit-dev --use-local

1. Disable the windows skip:
	skip: True  # [win]
2. Error with wget x64:
	conda_build.exceptions.DependencyNeedsBuildingError: Unsatisfiable dependencies for platform win-64: {'wget'}
	=> switch to python-wget (win only, I don't want to edit linux  create errors)


https://github.com/ericpre/prismatic


CONDA FORGE
https://conda-forge.org/docs/
https://conda-forge.org/docs/user/introduction.html#what-is-conda-forge

STRUCTURE
https://conda-forge.org/docs/user/ci-skeleton.html

AZURE PIPELINES
https://www.youtube.com/watch?v=7pzBwuMjpP0

Build package: conda-build
https://docs.conda.io/projects/conda-build/

Receipe: conda-smithy
https://conda-forge.org/docs


Create structure: yaml
configd: https://github.com/conda-forge/conda-forge-pinning-feedstock/blob/master/recipe/conda_build_config.yaml

then build (locally or from remote with azure pipelines)

https://www.youtube.com/watch?v=HSK-6dCnYVQ

3 files min:
	meta.yaml (description, version, source code, requirements)
	bld.bat (Windows build package)
	build.sh (Unix build package)

Conda constructor (env bootstrapper)

conda install constructor
installer settings in construct.yaml
cross plateform, create installer for linux, os, windows


Build locally:

Source code

Processus assez long (30 minutes)


Then upload on the Anaconda Cloud...

Installation:
conda install prismatic=*=gpu* -c ericpre

NVIDIA: /!\ Pas sur windows
conda install cudatoolkit-dev -c conda-forge
https://github.com/conda-forge/cudatoolkit-dev-feedstock

Two options:
	- Converge conda-forge/cudatoolkit-dev-feedstock with AnacondaRecipes/cudatoolkit-feedstock
	- Tweak the recipe scripts
Option 1 will be more future proof but may a bigger and better change

Questions:

Compilation: conda build recipe -c conda-forge...

Récuperation des dépendance (ressources de bases puis compilateur et librairies)
=> librairies dépendances pré compilées? 
Ou récuperation des ressources sur l'ordinateur (ex VS, CUDA etc)

Seulement le code source compilé et lié aux dépendances

Prismatic cli OK/ GUI OK/ 
Tests prismatic simple/double OK
Erreur 

cudatoolkit-dev Non fonctionnel Windows (tous les scripts en .sh)
AnacondaRecipes/cudatoolkit-feedstock






/ ------------------------------------------------------------------------- /

Recupere librairies/ressources dans caches
Definies (déjà packages conda faites pour conda, tout est compatible)

Pour windows
Compiler cuda-toolkit (restriction, pas open source)
Anaconda arrangement avec Nvidia (pour pouvoir distribuer le toolkit 1 packages)
Docker base conda toolkit/ jsute détails, regler paths etc

Conda-build gere version (dans conda forge, package qui existe mais problèmes actuellement avec CUDA10.2 
et ne supporte pas windows) => Il faut l'adapter pour Windows 
cudatoolkit-dev package feedtock:
Chaque recette = repository
Les pakcages sont fait a partir des repository (code source)
Fichiers configuration (parametres par toucher)

doc conda forge https://conda-forge.org/docs/user/ci-skeleton.html


Seulement modifier meta (recette) Puis build: sript: voir le script executé

Compilation => anaconda cloud => téléchargement (fichier python et binaries compilés)

cudatoolkit spécial: Coquille vide, quand installe télécharge cuda toolkit et installe localement (pas habituel)
Utile pour compiler du code (pas pour utiliser cuda toolkit indépendemment)

channel défault (Anaconda) et conda-forge (communauté conda-forge, open source/gratuit)

cudatoolkit-feedstock (Anaconda): https://github.com/AnacondaRecipes/cudatoolkit-feedstock
=> Utilisatuer final(build.py, recette du package Windows et Linux)

cuda_toolkit-dev (copie a l'installation)
=> Ancinne version du script (maintenant divergence => QUE POUR LINUX)
script cuda toolkit dev ne marche pas avec la dernière ? (10.2 a verifier)



(historique en commun)

But:
Principalement modifier build.py:
=> télécharger la distribution cuda depuis le site officiel

Fork puis pull request...

post_install car pas le dorit de distribuer (vraiment similaire nbuild conda toolkit)
post-link après installation après copié packages

conda build recipe -c conda-forge 2&1> output.txt
recipe = folder

packages dans dossier distribution miniconda3 conda-build en .tarball
conda install cudatoolkit-dev --use-local



build: comopiler cuda
Ajoute automatiquement cudatioolkit
automatisé

host:
Librairies necessaire a l'instalation

run: librairies necessaires lors du focntionnement






/ ----------------------------------------------------------------------------------------- /
Ressources:

Aide creation package: https://docs.conda.io/projects/conda-build/en/latest/user-guide/tutorials/build-pkgs.html
Build dans: D:\Programmes\Anaconda3\conda-bld

cd D:\Libraries\cuda_toolkit\cudatoolkit-dev-feedstock
conda build recipe -c conda-forge>output.txt
conda install cudatoolkit-dev --use-local

1. Disable the windows skip:
	skip: True  # [win]
1.1 Error with wget x64:
	conda_build.exceptions.DependencyNeedsBuildingError: Unsatisfiable dependencies for platform win-64: {'wget'}
	=> switch to python-wget (win only, I don't want to edit linux  create errors)