/**
 * File: molgraph.cpp
 * ------------------
 * This file contains the implementation for the MolGraph interface.
 * Documentation for each method can be found in the molgraph.h file.
 */

#include "molgraph.h"

MolGraph::MolGraph() {}

MolGraph::MolGraph(Molecule& mol) {
    moleculeToGraph(mol);
}

MolGraph::~MolGraph() {}

void MolGraph::moleculeToGraph(Molecule& mol) {
    Vector<Atom*> atoms = mol.getAtoms();
    Vector<Bond*> bonds = mol.getBonds();
    // make the adjacency matrix
    wAdjacency = arma::zeros(atoms.size(), atoms.size());
    for (int i = 0; i < bonds.size(); ++i) {
        int row = atoms.indexOf(bonds[i]->getFirstAtom());
        int col = atoms.indexOf(bonds[i]->getSecondAtom());
        wAdjacency(row, col) = wAdjacency(col, row) = bonds[i]->getOrder();
    }

    // make the degree matrix
    degree = arma::zeros(atoms.size(), atoms.size());
    for (int i = 0; i < atoms.size(); ++i) {
        int sum = 0;
        for (int j = 0; j < atoms.size(); ++j) {
            sum += wAdjacency(i, j);
        }
        degree(i, i) = sum;
    }

    // make the laplacian matrix
    laplacian = degree - wAdjacency;

    // calculate the fiedler vector
    arma::Col<double> eigenvalues;
    arma::Mat<double> eigenvectors;
    arma::eig_sym(eigenvalues, eigenvectors, laplacian);
    for (int i = 0; i < atoms.size(); ++i) {
        fiedler.add(eigenvectors(1, i));
    }
}

void MolGraph::retrosynthesize() {
    Vector<int> one, two;
    for (int i = 0; i < fiedler.size(); ++i) {
        if (fiedler[i] > 0) {
            one.add(i);
        } else {
            two.add(i);
        }
    }
    std::cout << "First cluster: " << one << std::endl;
    std::cout << "Second cluster: " << two << std::endl;
}

void MolGraph::printGraphs() {
    std::cout << "DEGREE MATRIX:" << std::endl <<
                 degree << std::endl;
    std::cout << "WEIGHTED ADJACENCY MATRIX:" << std::endl <<
                 wAdjacency << std::endl;
    std::cout << "LAPLACIAN MATRIX:" << std::endl <<
                 laplacian << std::endl;
    std::cout << "FIEDLER VECTOR: " << std::endl <<
                 fiedler << std::endl;
}
