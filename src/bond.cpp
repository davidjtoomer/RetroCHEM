/**
 * File: bond.cpp
 * --------------
 * This file contains the implementation for the Bond interface.
 * Documentation for each method can be found in the bond.h file.
 */

#include "bond.h"

Bond::Bond() {}

Bond::Bond(Atom * one, Atom * two) {
    atom1 = one;
    atom2 = two;
    order = 1;
}

Bond::~Bond() {} // atoms 1 and 2 are deleted during Molecule's delete call

void Bond::setFirstAtom(Atom * atom) {
    atom1 = atom;
}

Atom * Bond::getFirstAtom() {
    return atom1;
}

void Bond::setSecondAtom(Atom * atom) {
    atom2 = atom;
}

Atom * Bond::getSecondAtom() {
    return atom2;
}

void Bond::setOrder(const char& c) {
    switch(c) {
    case '-':
        order = 1;
        break;
    case '=':
        order = 2;
        break;
    case '#':
        order = 3;
        break;
    }
}

void Bond::setOrder(int ord) {
    order = ord;
}

int Bond::getOrder(){
    return order;
}
