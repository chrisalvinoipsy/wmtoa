#ifndef __EDGE_H__
#define __EDGE_H__

class Edge {

public:
	Edge();

	~Edge();

	void setCost(float cost) { m_cost = cost; }

	float getCost(void) const { return m_cost; }
	
	void setFlow(float flow) { m_flow = flow; }

private:
	float m_cost;
	float m_flow;
};

#endif // __EDGE_H__