/**
 * File: atom.cpp
 * --------------
 * This file contains the implementation for the Atom interface.
 * Documentation for each method can be found in the atom.h file.
 */

#include "atom.h"

// helper function declaration
bool isDigit(const char& c);

Atom::Atom() {}

Atom::Atom(const std::string &tok) {
    token = tok;
    setAllSpecials();
}

Atom::~Atom() {}

void Atom::setToken(const std::string& tok) {
    token = tok;
    setAllSpecials();
}

void Atom::setAbbreviation(const std::string& abbrev) {
    abbr = abbrev;
}

std::string Atom::getAbbreviation() {
    return abbr;
}

void Atom::setIsotope(int mass) {
    isotope = mass;
}

int Atom::getIsotope() {
    return isotope;
}

void Atom::setChirality(const std::string& chirality) {
    chiralClass = chirality;
}
std::string Atom::getChirality() {
    return chiralClass;
}

void Atom::setHCount(int count) {
    hcount = count;
}
int Atom::getHCount() {
    return hcount;
}

void Atom::setCharge(int chrg) {
    charge = chrg;
}
int Atom::getCharge() {
    return charge;
}

/**
 ******************************************************************
 ******************************************************************
 ****************************SPECIALS******************************
 ******************************************************************
 ******************************************************************
 */
void Atom::setAllSpecials() {
    if (isIsotope()) setIsotope();
    if (isChiral()) setChirality();
    if (isCharged()) setCharge();
    if (hasHydrogen()) setHydrogens();
}

bool Atom::isIsotope() {
    return isDigit(token[0]);
}

void Atom::setIsotope() {
    size_t strpos = 0;
    std::string mass;
    while (strpos < token.size() && isDigit(token[strpos])) {
        mass += token[strpos];
        strpos++;
    }
    if (abbr.empty()) {
        abbr = token[strpos];
    }
    isotope = stringToInteger(mass);
}

bool Atom::isChiral() {
    return token.find('@') != std::string::npos;
}

void Atom::setChirality() {
    size_t chiralLoc = token.find('@');
    chiralClass = token.substr(chiralLoc);
}

bool Atom::hasHydrogen() {
    size_t hLoc = token.find('H');
    if (hLoc == std::string::npos) {
        return false;
    } else {
        if (isalpha(token[hLoc + 1])) return false; // ignore atoms like Helium
        return true;
    }
}

void Atom::setHydrogens() {
    hcount = 1;
    size_t hLoc = token.find('H');
    if (hLoc + 1 < token.size() && isDigit(token[hLoc + 1])) {
        hcount = charToInteger(token[hLoc + 1]);
    }
}

bool Atom::isCharged() {
    return token.find('+') != std::string::npos ||
           token.find('-') != std::string::npos;
}

void Atom::setCharge() {
    int chrg = 1; // assume positive charge
    size_t signLoc = token.find('+');
    if (signLoc == std::string::npos) {
        signLoc = token.find('-');
        chrg = -1;
    }
    if (isDigit(token[signLoc + 1])) {
        charge = chrg * charToInteger(token[signLoc + 1]);
    } else {
        size_t i = 1;
        int increment = chrg; // toggles positive or negative
        while (token[signLoc + i] == token[signLoc]) { // if there are multiple signs (++, --)
            chrg += increment;
            i++;
        }
    }
}

bool Atom::isAromatic() {
    return islower(abbr[0]);
}

bool isDigit(const char& c){
   return c >= '0' && c <= '9';
}
