/**
 * File: molgraph.h
 * ----------------
 * This file contains the interface for the MolGraph class.
 * The MolGraph is an adjacency matrix representation of a
 * Molecule object. It uses the spectral properties of the
 * weighted Laplacian matrix in order to predict a single
 * retrosynthetic step.
 *
 * Linear algebra calculations done via Armadillo package.
 */

#include <armadillo>
#include "molecule.h"

class MolGraph {
public:
    /**
     * Constructor: MolGraph
     * Usage: MolGraph molgraph;
     * -------------------------
     * Initializes a new MolGraph object.
     */
    MolGraph();

    /**
     * Function: MolGraph
     * Parameters: mol
     * Usage: Molgraph molgraph(mol);
     * ------------------------------
     * Initializes a new MolGraph object based on the molecule given.
     */
    MolGraph(Molecule& mol);

    /**
     * Destructor: ~MolGraph
     * Usage: delete molgraph
     * ----------------------
     * Deletes any dynamically allocated memory from the MolGraph object.
     */
    ~MolGraph();

    /**
     * Function: moleculeToGraph
     * Parameters: mol
     * Usage: molgraph.moleculeToGraph(mol);
     * --------------------------------
     * Converts the properties of the molecule into the current MolGraph object.
     */
    void moleculeToGraph(Molecule& mol);

    /**
     * Function: retrosynthesize
     * Usage: molgraph.retrosynthesize()
     * ---------------------------------
     * Predicts which clusters each atom (enumerated) will fall into.
     */
    void retrosynthesize();

    /**
     * Function: printGraphs
     * Usage: molgraph.printGraphs();
     * ------------------------------
     * Prints the degree, adjacency, and Laplacian matrices of the graph
     */
    void printGraphs();

private:
    // stores the matrices needed for spectral clustering
    arma::Mat<double> degree, wAdjacency, laplacian;

    // the Fiedler eigenvector: used to assign clusters
    Vector<double> fiedler;

};
