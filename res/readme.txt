DAVID TOOMER
SMILES PARSING AND RETROSYNTHESIS PREDICTION
DECEMBER 2019
--------------------------------------------
The code relies on one library, Armadillo, for fast linear algebra calculations. In order to install Armadillo and run it in Qt Creator, follow the instructions below.

---------------------
1. DOWNLOAD ARMADILLO
Go to SourceForge and download Armadillo from this link:
	http://arma.sourceforge.net/
Click on the "download lates version" option towards the bottom of the page and the download should begin.

-------------------------------
2. MOVE ARMADILLO TO QT PROJECT
In order to avoid linker errors during compile time, move the armadillo directory into the  directory containing the project. It may help to rename the directory "armadillo" instead of the longer "armadillo-9.800.3".

-------------------------
3. CHANGING THE .PRO FILE
In order to access the armadillo library, you will need to open the .pro file for the project and add two lines (for consistency with the code, write this around line 260, but it should not matter where the code snippets are written)

	INCLUDEPATH *= $$PWD/armadillo/include/
	LIBS += -llapack -lblas

The second command makes sure that Qt Creator has access to some of Armadillo's dependencies, such as LAPack for eigendecomposition.

---------------
4. RUN THE CODE
You're all set! All of the dependencies are downloaded and the program should run as normal.