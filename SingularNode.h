#ifndef __SINGULARNODE_H__
#define __SINGULARNODE_H__

class SingularNode {

public:
	SingularNode();

	~SingularNode();

	void set_price(float price) { m_price = price; }

private:
	float m_price;
};

#endif // __SINGULARNODE_H__