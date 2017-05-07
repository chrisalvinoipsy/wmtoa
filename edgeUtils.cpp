
#include "edgeUtils.h"

void EdgeUtils::clearFlow(std::vector<std::vector<Edge> > & edges) {
	for (auto ite=edges.begin();ite != edges.end();++ite) {
		ite->setFlow(0.0f);
	}
}