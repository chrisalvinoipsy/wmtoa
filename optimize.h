#ifndef __OPTIMIZE_H__
#define __OPTIMIZE_H__

#include <vector>
#include "ManyNode.h"
#include "SingularNode.h"
#include "Edge.h"

class Optimize {
public:
	static float computeScalingPushRelabel(
		std::vector<ManyNode> & manyNodes, 
		std::vector<SingularNode> & singularNodes, 
		std::vector<std::vector<Edge> > & edges);

	static float setPricesToZero(
		std::vector<ManyNode> & manyNodes, 
		std::vector<SingularNode> & singularNodes);
};

#endif // __OPTIMIZE_H__