/*
 * teexGraph --- by Frank Takes --- https://github.com/franktakes/teexgraph
 *
 * Example main-file showing how to use teexGraph
 */

#include <teexgraph/Graph.h>
#include <teexgraph/Timer.h>

using namespace std;
using namespace teexgraph;

// if compiled with "make listener", start the listener and ignore this file
#if runlistener == 1
#include "listener.h"
int main(const int argc, const char* argv[]) { Graph G; return listener(G); }

#else

// if compiled with reguler "make" command, run this main function
#include "examples.h"
int main(const int argc, const char* argv[]) {

    // catch no input graph given in command line parameter
    if(argc < 2) {
        cerr << "Error: first argument should be the network filename." << endl;
        return 1;
    }

    // timer object to measure loading and computation time
    Timer T;
    T.click();

    // create and load graph from file. pass an int >= nodecount
    // to optimize memory usage or if you want to have a nodecount > 10M nodes
    Graph G;
    if(!G.loadUndirected(argv[1]))
        return 1;

    // detect weakly connected components
    G.computeWCC();

    // show some statistics of the network
    stats(G); // from examples.cpp
	//computeIntensiveStats(G); // from examples.cpp; 
    T.click();

    // compute the diameter of the largest WCC of this network
	boundingDiameters(G); // from examples.cpp
    T.click();

    // list the network's distance distribution
    //distanceDistribution(G); // from examples.cpp; compute-heavy
    //T.click();

    // list the network's degree distribution
    //degreeDistribution(G); // from examples.cpp
    //T.click();

	// list some statistics related to clustering coefficients
	//clusteringStats(G); // from examples.cpp
	//T.click();
	
    return 0;
}

#endif
