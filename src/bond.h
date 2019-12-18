/**
 * File: bond.h
 * ------------
 * This file contains the interface for the Bond class.
 * A Bond object stores a relation between two Atoms, similar
 * to a weighted arc/edge on a directed graph.
 */

#include <string>
#include "atom.h"

class Bond {
public:
    /**
     * Constructor: Bond
     * Usage: Bond bond;
     * -----------------
     * Initializes a new Bond object.
     */
    Bond();

    /**
     * Constructor: Bond
     * Parameters: one, two
     * Usage: Bond bond(one, two);
     * ---------------------------
     * Initializes a new Bond object connecting the two atoms.
     */
    Bond(Atom * one, Atom * two);

    /**
     * Destructor: ~Bond
     * Usage: delete bond;
     * -------------------
     * Deletes all dynamically allocated atoms in the bond.
     */
    ~Bond();

    /**
     * Function: setFirstAtom
     * Parameters: atom
     * Usage: bond.setFirstAtom(atom);
     * -------------------------------
     * Sets the first atom in the bond to the atom passed in.
     */
    void setFirstAtom(Atom * atom);

    /**
     * Function: getFirstAtom
     * Usage: Atom * atom = bond.getFirstAtom();
     * -----------------------------------------
     * Returns the "first" atom in the bond.
     */
    Atom * getFirstAtom();

    /**
     * Function: setSecondAtom
     * Parameters: atom
     * Usage: bond.setSecondAtom(atom);
     * --------------------------------
     * Sets the second atom in the bond to the atom passed in.
     */
    void setSecondAtom(Atom * atom);

    /**
     * Function: getSecondAtom
     * Usage: Atom * atom = bond.getSecondAtom();
     * ------------------------------------------
     * Returns the second atom in the bond.
     */
    Atom * getSecondAtom();

    /**
     * Function: setOrder
     * Parameters: c
     * Usage: bond.setOrder(c);
     * ------------------------
     * Sets the type (order) of bond based on the character passed in.
     * '-' = single bond
     * '=' = double bond
     * '#' = triple bond
     */
    void setOrder(const char& c);

    /**
     * Function: setOrder
     * Parameters: order
     * Usage: bond.setOrder(order);
     * ----------------------------
     * Sets the type (order) of the bond based on the number passed in.
     * 1 = single bond
     * 2 = double bond
     * 3 = triple bond
     * 4 = aromatic bond
     */
    void setOrder(int order);

    /**
     * Function: getOrder
     * Usage: int order = bond.getOrder();
     * -----------------------------------
     * Returns the order of the bond object.
     */
    int getOrder();

private:
    Atom * atom1, * atom2; // atoms the bond connects
    int order; // strength/type of the bond
    int stereo; // stereochemical information
};
