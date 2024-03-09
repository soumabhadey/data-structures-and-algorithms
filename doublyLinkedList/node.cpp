#include <iostream>
using namespace std;
struct node {
	private:
		node *prev;
		int data;
		node *next;
	public:
		node();
		void setprev(node *);
		void setdata(int);
		void setnext(node *);
		node * getprev();
		int getdata();
		node * getnext();
};
node::node() {
	this->prev=NULL;
	this->data=0;
	this->next=NULL;
}
void node::setprev(node *prev) {
	this->prev=prev;
}
void node::setdata(int data) {
	this->data=data;
}
void node::setnext(node *next) {
	this->next=next;
}
node * node::getprev() {
	return prev;
}
int node::getdata() {
	return data;
}
node * node::getnext() {
	return next;
}




