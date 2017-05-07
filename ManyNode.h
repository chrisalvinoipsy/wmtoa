#ifndef __MANYNODE_H__
#define __MANYNODE_H__

class ManyNode {

public:
	ManyNode();

	~ManyNode();

	void setQuantity(int quantity) { m_quantity = quantity; }

	int getQuantity(void) const { return m_quantity; }

	void setPrice(float price) { m_price = price; }

private:
	float m_price;
	int m_quantity;
};

#endif // __MANYNODE_H__