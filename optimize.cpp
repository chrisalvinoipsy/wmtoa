
#include "optimize.h"
#include <limits>
#include <iostream>

float Optimize::computeScalingPushRelabel(
	std::vector<ManyNode> & manyNodes, 
	std::vector<SingularNode> & singularNodes, 
	std::vector<std::vector<Edge> > & edges) {

	float C = -std::numeric_limits<float>::max();
	for (auto ite=edges.begin();ite != edges.end();ite++) {
		for (auto itee=ite->begin();itee != ite->end();itee++) {
			float cost = itee->get_cost();
			if (cost > C) {
				C = cost;
			}
		}
	}

	std::cout << "Maximum cost C: " << C << std::endl;

	float epsilon = C;

	setPricesToZero(manyNodes,singularNodes);

	return 0.0;
}

float Optimize::setPricesToZero(
	std::vector<ManyNode> & manyNodes, 
	std::vector<SingularNode> & singularNodes) {
	for (auto ite=manyNodes.begin();ite != manyNodes.end();ite++) {
		ite->setPrice(0.0f);
	}
	for (auto ite=singularNodes.begin();ite != singularNodes.end();ite++) {
		ite->setPrice(0.0f);
	}	
}