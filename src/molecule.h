/**
 * File: molecule.h
 * ----------------
 * This file contains the interface for the Molecule class.
 * A Molecule object stores most of the molecular information
 * from a MDL MolFile. It contains atoms, bonds, and their
 * relation to one another.
 */

#include <string>
#include "vector.h"
#include "map.h"
#include "bond.h"


class Molecule {
public:
    /**
     * Constructor: Molecule
     * Usage: Molecule mol;
     * --------------------
     * Initializes a new Molecule object.
     */
    Molecule();

    /**
     * Constructor: Molecule
     * Parameters: smiles
     * Usage: Molecule mol(smiles);
     * ----------------------------
     * Initializes a new Molecule object and sets the features of the
     * molecule based on the SMILES string.
     */
    Molecule(const std::string& smiles);

    /**
     * Destructor: ~Molecule
     * Usage: delete mol;
     * ---------------------
     * Deletes any dynamically allocated atoms and bonds in the molecule object.
     */
    ~Molecule();

    /**
     * Function: addAtom
     * Parameters: atom
     * Usage: mol.addAtom(atom);
     * -------------------------
     * Adds a new atom to the molecule object.
     */
    void addAtom(Atom* atom);

    /**
     * Function: getAtoms
     * Usage: Vector<Atom*> atoms = mol.getAtoms();
     * --------------------------------------------
     * Returns the atoms in the molecule.
     */
    Vector<Atom*> getAtoms() const;

    /**
     * Function: addBond
     * Parameters: bond
     * Usage: mol.addBond(bond);
     * -------------------------
     * Adds a new bond to the molecule object.
     */
    void addBond(Bond* bond);

    /**
     * Function: getBonds
     * Usage: Vector<Bond*> bonds = mol.getBonds();
     * --------------------------------------------
     * Returns the bonds in the molecule.
     */
    Vector<Bond*> getBonds() const;

    /**
     * Function: smilesToMolecule
     * Parameters: smiles
     * Usage: mol.smilestoMolecule(smiles);
     * ------------------------------------
     * Parses a SMILES string and adds all of the features of the SMILES into the molecule object.
     */
    void smilesToMolecule(const std::string& smiles);

    /**
     * Function: printMolecule
     * Usage: mol.printMolecule()
     * --------------------------
     * Prints out the molecule information in MOLFILE format.
     */
    void printMolecule();

private:
    // holds all of the atoms in the molecule
    Vector<Atom*> atoms;

    // holds all of the bonds in the molecule
    Vector<Bond*> bonds;

    // holds all of the elements and their features
    Map<std::string, Vector<std::string>> periodicTable;
};
