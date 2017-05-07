
#include <vector>
#include <iostream>
#include <limits>
#include "exhaustive.h"
#include "edgeUtils.h"

float Exhaustive::computeMinFlowExhaustive(
	const std::vector<ManyNode> & manyNodes, 
	const std::vector<SingularNode> & singularNodes, 
	const std::vector<std::vector<Edge> > & edges) {

	// generate all index permutations
	std::vector<std::vector<int>> index_permutations = generatePermutations(singularNodes.size());
	
	// now go through all index permutations and find the minimum cost
	double min_cost = std::numeric_limits<double>::max();
	int optimalIterationIndex = -1;
	int iterationIndex = 0;
	for (auto ite=index_permutations.begin();ite != index_permutations.end();ite++,iterationIndex++) {
		int currentManyNodeIndex = 0;
		int countWithinManyNode = 0;
		double cost = 0.0f;
		for (auto itee=ite->begin();itee != ite->end();itee++) {
			cost += edges[currentManyNodeIndex][*itee].get_cost();
			countWithinManyNode++;
			if (countWithinManyNode >= manyNodes[currentManyNodeIndex].get_quantity()) {
				currentManyNodeIndex++;
				countWithinManyNode = 0;
			}
		}

		if (cost < min_cost) {
			min_cost = cost;
			optimalIterationIndex = iterationIndex;
		}
	}

	// clear flow
	EdgeUtils::clearFlow(edges);

	// assign optimal flow
	
	
	return min_cost;
}

std::vector<std::vector<int>> Exhaustive::generatePermutations(int n) {

	std::vector<std::vector<int>> result;

	// start with 0
	// will then create 0 1 and 1 0 from it
	// will then create 0 1 2 and 0 2 1 and 2 0 1 from the 0 1
	// as well as 1 0 2 and 1 2 0 and 2 1 0 from the 1 0
	// etc.

	if (n > 0) {
		std::vector<int> zeroOnly; 
		zeroOnly.push_back(0);
		result.push_back(zeroOnly);

		for (int i=1;i<n;i++) {
			std::vector<std::vector<int>> temp_result;          // for example temp_result is 0 1 and 1 0
			for (int ri=0;ri<result.size();ri++) {              // for first iteration result[ri] will be 0 1
				for (int cii=0;cii<=result[ri].size();cii++) {  // cii will range from 0 to 2
					std::vector<int> current_indices = result[ri];          // copy 0 1 to current_indices
					current_indices.insert(current_indices.begin()+cii,i);  // insert 2 into each slot e.g. 2 0 1
					temp_result.push_back(current_indices);     // and push_back 2 0 1 into temp_result
				}
			}
			result = temp_result;  // now copy full temp_result into result
		}
	}

	std::cout << "total number of permutations: " << result.size() << std::endl;

	return result;
}