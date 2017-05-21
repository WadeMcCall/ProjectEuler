#ifndef BINARY_NODE
#define BINARY_NODE

class node{
	public:
		node* leftNode;
		node* rightNode;
	
		int getValue();
		void setValue(int k);
		node(int v);
		
	private:
		int value;
};

int node::getValue(){
	return value;
}

void node::setValue(int k){
	value = k;
}

node::node(int v){
	value = v;
}

#endif