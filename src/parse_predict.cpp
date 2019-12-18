/**
 * File: parse_predict.cpp
 * -----------------------
 * This file contains the main program for RetroChem.
 * RetroChem is a command-line interface for graph-based, single step
 * retrosynthetic reaction prediction. It offers a variety of options,
 * including SMILES tutorials, SMILES parsing, conversion to MDL Molfile
 * and graph formats, and predicting decomposition reactions.
 */

#include <iostream>
#include <fstream>

#include "console.h"
#include "simpio.h"
#include "strlib.h"

#include "vector.h"
#include "set.h"
#include "queue.h"

#include "molgraph.h"
using namespace std;

/**
 * Function: printRules
 * --------------------
 * Prints the general rules of SMILES for those who do not know.
 */
void printRules() {
    cout << endl;
    cout << "The Simplified Molecular-Input Line-Entry System (S.M.I.L.E.S) is a method of writing chemicals"
            "and molecules as strings. The string contains various information about the atoms, their bonds"
            "with other atoms, and even more complex features like chirality stereochemistry, and isotope mass." << endl;
    cout << "For example, an atom would be represented with its abbreviation in the periodic table (see res/periodicTable.csv"
            "for more information)." << endl;
    cout << "A bond is always assumed to be a single bond, but characters like '=' and '#' add more complexity." << endl;
    cout << "Branches are places where a molecule diverges into two different \"paths\". "
            "They are represented with brackets around the branch." << endl;
    cout << endl;
}

/**
 * Function: giveExamples
 * ----------------------
 * Gives three examples of valid SMILES.
 */
void giveExamples() {
    cout << "Acetic Acid: \t CC(=O)O" << endl;
    cout << "Cyclohexane: \t C1CCCCC1" << endl;
    cout << "Decalin: \t\t C1CC2CCCCC2CC1" << endl << endl;
}

/**
 * Function: smilesToMolecule
 * --------------------------
 * Converts a SMILES to MDL MolFile and prints it.
 */
void smilesToMolecule() {
    string smiles;
    getLine("Enter a SMILES string: ", smiles);
    Molecule mol(smiles);
    mol.printMolecule();
    cout << endl;
}

/**
 * Function smilesToGraph
 * ----------------------
 * Prints the graph versions of the SMILES string.
 */
void smilesToGraph() {
    string smiles;
    getLine("Enter a SMILES string: ", smiles);
    Molecule mol(smiles);
    MolGraph graph(mol);
    graph.printGraphs();
}

/**
 * Function: retrosynthesize
 * -------------------------
 * Returns the two clusters each atom falls into.
 */
void retrosynthesize() {
    string smiles;
    getLine("Enter a SMILES string: ", smiles);
    Molecule mol(smiles);
    MolGraph graph(mol);
    graph.retrosynthesize();
    cout << endl;
}

/**
 * Function: welcome
 * -----------------
 * Open the program on a lighthearted note.
 */
void welcome() {
    cout << "Welcome to RetroChem! "
            "This program is designed to show you some of the interesting "
            "ways you can represent chemistry with computer science." << endl;
    cout << "Press ENTER to continue...";
    getLine();
    cout << endl;
    cout << "There are several options you can choose from, and each requires a SMILES "
            "string as input." << endl;
    cout << "Don't know what a SMILES string is? Press 1!" << endl;
    cout << "Can't think of one off the top of your head? Press 2!" << endl << endl;
}

enum ChemOption {
    MinOption,
    SmilesRules,
    ExampleSmiles,
    SmilesToMolecule,
    SmilesToGraph,
    Retrosynthesis,
    Quit,
    NumOptions
};

// UI
void displayOptions() {
    cout << "Please pick from the following: " << endl;
    cout << "  " << SmilesRules         << "\t Explain how the SMILES format works." << endl;
    cout << "  " << ExampleSmiles       << "\t Give me some example SMILES!" << endl;
    cout << "  " << SmilesToMolecule    << "\t Convert SMILES to MDL MolFile Format." << endl;
    cout << "  " << SmilesToGraph       << "\t Convert SMILES to a molecular graph." << endl;
    cout << "  " << Retrosynthesis      << "\t Predict a single retrosynthetic step." << endl;
    cout << "  " << Quit                << "\t Quit." << endl;
}

bool processInput(ChemOption option) {
    switch(option) {
    case SmilesRules:
        printRules();
        break;
    case ExampleSmiles:
        giveExamples();
        break;
    case SmilesToMolecule:
        smilesToMolecule();
        break;
    case SmilesToGraph:
        smilesToGraph();
        break;
    case Retrosynthesis:
        retrosynthesize();
        break;
    case Quit:
        return false;
    default:
        error("Unknown menu option.");
    }
    return true;
}

ChemOption getUserInput() {
    while (true) {
        ChemOption option = ChemOption(getInteger("Enter your choice: "));
        if (option > MinOption && option < NumOptions) {
            return option;
        }
        cerr << "Sorry, that choice was invalid." << endl;
    }
}

int main() {
    welcome();
    do {
        displayOptions();
    } while(processInput(getUserInput()));
    cout << "Hope you're in your ELEMENT today! Goodbye!" << endl;
    return 0;
}
