/*
	Input file format: ASCII
	<Number of many nodes>
	<Number of singular nodes>
	<Quantities for each many node> 
	<Edge costs>
*/

#include <vector>
#include <iostream>
#include <fstream>
#include "Edge.h"
#include "ManyNode.h"
#include "SingularNode.h"
#include "exhaustive.h"
#include "optimize.h"

int main(int argc, char *argv[]) {

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	int numManyNodes;
	int numSingularNodes;

	inputFile >> numManyNodes;
	std::cout << "numManyNodes: " << numManyNodes << std::endl;
	inputFile >> numSingularNodes;
	std::cout << "numSingularNodes: " << numSingularNodes << std::endl;

	std::vector<ManyNode> manyNodes(numManyNodes);
	for (int i=0;i<numManyNodes;++i) {
		int quantity;
		inputFile >> quantity;
		manyNodes[i].set_quantity(quantity);
	}

	std::vector<SingularNode> singularNodes(numSingularNodes);

	std::vector<std::vector<Edge> > edges(numManyNodes);
	for (int i=0;i<numManyNodes;++i) {
		edges[i].resize(numSingularNodes);
		for (int ei=0;ei<numSingularNodes;ei++) {
			float cost;
			inputFile >> cost;
			edges[i][ei].set_cost(cost);
		}
	}

	char command = argv[2][0];
	if (command=='e' || command=='b') {
		float minFlow = Exhaustive::computeMinFlowExhaustive(manyNodes,singularNodes,edges);
		std::cout << "Mininum flow (exhaustive): " << minFlow << std::endl;
	} 

	if (command=='o' || command == 'b') {
		float minFlow = Optimize::computeScalingPushRelabel(manyNodes,singularNodes,edges);
		std::cout << "Computed minimize flow: " << minFlow << std::endl;
	}

	exit(0);
}
