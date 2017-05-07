#ifndef __EDGEUTILS_H__
#define __EDGEUTILS_H__

#include <vector>
#include "ManyNode.h"
#include "SingularNode.h"
#include "Edge.h"

class EdgeUtils {
public:
	static void clearFlow(std::vector<std::vector<Edge> > & edges);
};

#endif // __EDGEUTILS_H__