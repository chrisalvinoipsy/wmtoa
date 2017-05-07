#ifndef __EXHAUSTIVE_H__
#define __EXHAUSTIVE_H__

#include <vector>
#include "ManyNode.h"
#include "SingularNode.h"
#include "Edge.h"

class Exhaustive {
public:
	static float computeMinFlowExhaustive(
		const std::vector<ManyNode> & manyNodes, 
		const std::vector<SingularNode> & singularNodes, 
		const std::vector<std::vector<Edge> > & edges);

private:
	static std::vector<std::vector<int>> generatePermutations(int n);
};

#endif // __EXHAUSTIVE_H__