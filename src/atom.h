/**
 * File: atom.h
 * ------------
 * This file contains the interface for the Atom class.
 * The Atom class contains information about each Atom object,
 * such as its name and various chemical properties.
 */

#include <string>
#include "strlib.h"

class Atom {
public:
    /**
     * Constructor: Atom
     * Usage: Atom atom;
     * -----------------
     * Initializes a blank Atom object.
     */
    Atom();

    /**
     * Constructor: Atom
     * Parameters: token
     * Usage: Atom atom(token);
     * ------------------------
     * Creates an Atom object with all of the features of the
     * atom included (the whole token).
     */
    Atom(const std::string& token);

    /**
     * Destructor: ~Atom
     * Usage: delete atom;
     * -------------------
     * Deletes any dynamically allocated memory for the Atom object.
     */
    ~Atom();

    /**
     * Function: setToken
     * Parameters: token
     * Usage: atom.setToken(token);
     * ----------------------------
     * Sets the token value to the string passed in.
     */
    void setToken(const std::string& token);

    /**
     * Function: setAbbreviation
     * Parameters: abbrev
     * Usage: atom.setAbbreviation(abbrev);
     * ------------------------------------
     * Sets the abbreviation of the molecule to the string passed in.
     */
    void setAbbreviation(const std::string& abbrev);

    /**
     * Function: getAbbreviation
     * Usage: std::string abbr = atom.getAbbreviation();
     * -------------------------------------------------
     * Returns the abbreviation of the molecule.
     */
    std::string getAbbreviation();

    /**
     * Function: setIsotope
     * Parameters: mass
     * Usage: atom.setIsotope(mass);
     * -----------------------------
     * Sets the isotope to have the mass of the value passed in.
     */
    void setIsotope(int mass);

    /**
     * Function: getIsotope
     * Usage: int mass = atom.getIsotope();
     * ------------------------------------
     * Returns the mass of the atom.
     */
    int getIsotope();

    /**
     * Function: setChirality
     * Parameters: chirality
     * Usage: atom.setChirality(chirality);
     * ------------------------------------
     * Sets the chiral class of the atom.
     */
    void setChirality(const std::string& chirality);

    /**
     * Function: getChirality
     * Usage: string chirality = atom.getChirality();
     * ----------------------------------------------
     * Returns the chiral class of the atom.
     */
    std::string getChirality();

    /**
     * Function: setHCount
     * Usage: atom.setHCount(count);
     * -----------------------------
     * Sets the number of hydrogens to count.
     */
    void setHCount(int count);

    /**
     * Function: getHCount
     * Usage: int count = atom.getHCount();
     * ------------------------------------
     * Sets the number of hydrogens to count.
     */
    int getHCount();

    /**
     * Function: setCharge
     * Parameters: chrg
     * Usage: atom.setCharge(chrg);
     * ----------------------------
     * Sets the charge to the given charge.
     */
    void setCharge(int chrg);

    /**
     * Function: getCharge
     * Usage:  int chrg = atom.getCharge();
     * ------------------------------------
     * Returns the charge on the atom.
     */
    int getCharge();

    /**
     * Function: isAromatic
     * Usage: if (isAromatic) {...}
     * ----------------------------
     * Determines if the atom is aromatic or not.
     */
    bool isAromatic();

    /**
     * Function: setAllSpecials
     * Usage: atom.setAllSpecials();
     * -----------------------------
     * Sets all of the chemical properties and names from the token alone.
     */
    void setAllSpecials();

private:
    // naming
    std::string token, abbr, name;

    // chemical properties
    int isotope; 
    std::string chiralClass;
    int hcount = 0;
    int charge = 0;

    /* METHODS FOR SETTING SPECIAL PROPERTIES:
     * 1. checks to see if the token has certain qualities
     * 2. if so, take those qualities and put them into private data members
     */
    bool isIsotope();
    void setIsotope();

    bool isChiral();
    void setChirality();

    bool hasHydrogen();
    void setHydrogens();

    bool isCharged();
    void setCharge();
};
