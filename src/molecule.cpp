/**
 * File: molecule.cpp
 * ------------------
 * This file contains the implementation for the Molecule interface.
 * Documentation for each method can be found in the molecule.h file.
 */

#include "stack.h"
#include "map.h"
#include "molecule.h"

bool isDigit(const char& c){
   return c >= '0' && c <= '9';
}

Molecule::Molecule() {}

Molecule::Molecule(const std::string& smiles) {
    smilesToMolecule(smiles); // sets all properties in the molecule
}

Molecule::~Molecule() {
    // deletes any dynamically allocated atoms and bonds
    for (const Atom * atom : atoms) delete atom;
    for (const Bond * bond : bonds) delete bond;
}

void Molecule::addAtom(Atom * atom) {
    atoms.add(atom);
}
Vector<Atom*> Molecule::getAtoms() const {
    return atoms;
}

void Molecule::addBond(Bond * bond) {
    bonds.add(bond);
}
Vector<Bond*> Molecule::getBonds() const {
    return bonds;
}

void Molecule::smilesToMolecule(const std::string& smiles) {
    size_t strpos = 0;
    Map<int, Atom*> ringClosures; // maps a ring closure to its original atom
    Stack<Atom*> branches; // top element contains the atom right before the most recent branch
    while (strpos < smiles.size()) {
        Atom * prevAtom = nullptr;
        if (!atoms.isEmpty()) {
            prevAtom = atoms.back();
        }
        while (smiles[strpos] == ')') { // CHECK FOR CLOSING BRANCHES FIRST
            prevAtom = branches.pop();
            strpos++;
            if (strpos == smiles.size()) break; // if a branch close is the end of the molecule
        }
        if (isalpha(smiles[strpos]) || smiles[strpos] == '[') { // ATOMS
            Atom * curr = new Atom();
            size_t copyStrpos = strpos; // useful if the atom's information is longer than one character
            if (isalpha(smiles[strpos])) { // normal atom
                if (strpos + 1 < smiles.size() && isalpha(smiles[strpos + 1]) &&
                        periodicTable.containsKey(smiles.substr(strpos, 2))) { // two-letter element
                    curr->setToken(smiles.substr(strpos, 2));
                } else { // one-letter element
                    curr->setToken(charToString(smiles[strpos]));
                }
            } else { // SPECIAL ATOM (isotope, chiral, stereo...)
                size_t temp = smiles.find(']', strpos);
                std::string token = smiles.substr(strpos + 1, temp - strpos - 1);
                curr->setToken(token);
                strpos = temp;
            }
            curr->setAllSpecials();
            atoms.add(curr);
            if (prevAtom != nullptr) { // if not the first atom
                Bond * bond = new Bond(prevAtom, curr);
                if (smiles[copyStrpos - 1] == '-' ||
                        smiles[copyStrpos - 1] == '=' ||
                        smiles[copyStrpos - 1] == '#') {
                    bond->setOrder(smiles[copyStrpos - 1]);
                }
                bonds.add(bond);
            }
        } else if (isDigit(smiles[strpos]) || smiles[strpos] == '%') { // RING CLOSURES
            int ringClosure;
            if (smiles[strpos] == '%') {
                std::string temp;
                while (isDigit(smiles[strpos + 1])) {
                    temp += smiles[strpos + 1];
                    strpos++;
                }
                ringClosure = stringToInteger(temp);
            } else {
                ringClosure = charToInteger(smiles[strpos]);
            }
            // if the ringClosure already exists --> finish the closure
            if (ringClosures.containsKey(ringClosure)) {
                Bond * bond = new Bond(ringClosures[ringClosure], atoms.back());
                if (smiles[strpos - 1] == '-' ||
                        smiles[strpos - 1] == '=' ||
                        smiles[strpos - 1] == '#') {
                    bond->setOrder(smiles[strpos - 1]);
                }
                bonds.add(bond);
            } else {
               ringClosures.add(ringClosure, atoms.back());
            }
        } else if (smiles[strpos] == '(') {
            branches.push(atoms.back());
        }
        strpos++;
    }
}

void Molecule::printMolecule() {
    std::cout << "MOLECULE OVERVIEW" << std::endl;
    std::cout << "Number of atoms: " << atoms.size() << std::endl;
    std::cout << "Number of bonds: " << bonds.size() << std::endl;

    std::cout << "ATOM BLOCK" << std::endl;
    for (int i = 0; i < atoms.size(); ++i) {
        std::cout << "Atom " << i << ": " << atoms[i]->getAbbreviation() << std::endl;
    }
    std::cout << "BOND BLOCK" << std::endl;
    for (int i = 0; i < bonds.size(); ++i) {
        std::cout << "Bond " << i << ": " << atoms.indexOf(bonds[i]->getFirstAtom()) <<
                     "\t" << atoms.indexOf(bonds[i]->getSecondAtom()) << std::endl;
    }
}
