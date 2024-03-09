#include "node.cpp"
struct dlinklist {
	private:
		node *start;
	public:
		dlinklist();
		void insertbegin();
		void insertend();
		void insertpos();
		void delbegin();
		void delend();
		void delpos();
		int count();
		int count(node *);
		void show();
		void show(node *);
		void reverse();
		void reverse(node *,node *,node *);
		void sort();
		void search();
		void search(node *,int,int);
		~dlinklist();
};
dlinklist::dlinklist() {
	start=NULL;
}
void dlinklist::insertbegin() {
	node *nptr=new node;
	cout<<"enter item"<<endl;
	int item;
	cin>>item;
	nptr->setdata(item);
	nptr->setnext(start);
	if(start!=NULL)
		start->setprev(nptr);
	start=nptr;
	show();
}
void dlinklist::insertend() {
	if(start==NULL)
		insertbegin();
	else {
		node *nptr=new node;
		cout<<"enter item"<<endl;
		int item;
		cin>>item;
		nptr->setdata(item);
		node *ptr=start;
		while(ptr->getnext()!=NULL)
			ptr=ptr->getnext();
		ptr->setnext(nptr);
		nptr->setprev(ptr);
		show();
	}
}
void dlinklist::insertpos() {
	cout<<"enter position"<<endl;
	int pos;
	cin>>pos;
	if(pos<1||pos>count()+1)
		cout<<"invalid position";
	else if(pos==1)
		insertbegin();
	else if(pos==count()+1)
		insertend();
	else {
		int i=1;
		node *ptr=start;
		while(i!=pos-1) {
			i++;
			ptr=ptr->getnext();
		}
		node *nptr=new node;
		cout<<"enter item"<<endl;
		int item;
		cin>>item;
		nptr->setdata(item);
		nptr->setprev(ptr);
		nptr->setnext(ptr->getnext());
		ptr->getnext()->setprev(nptr);
		ptr->setnext(nptr);
		show();
	}
}
void dlinklist::delbegin() {
	if(start==NULL)
		cout<<"empty"<<endl;
	else {
		node *temp=start;
		if(start->getnext()!=NULL)
			start->getnext()->setprev(NULL);
		start=start->getnext();
		cout<<temp->getdata()<<endl;
		delete temp;
		temp=NULL;
		show();
	}
}
void dlinklist::delend() {
	if(start==NULL)
		cout<<"empty"<<endl;
	else if(start->getnext()==NULL)
		delbegin();
	else {
		node *ptr=start;
		while(ptr->getnext()!=NULL)
			ptr=ptr->getnext();
		ptr->getprev()->setnext(NULL);
		cout<<ptr->getdata()<<endl;
		delete ptr;
		ptr=NULL;
		show();
	}
}
void dlinklist::delpos() {
	cout<<"enter  position"<<endl;
	int pos;
	cin>>pos;
	if(pos<1||pos>count())
		cout<<"invalid position"<<endl;
	else if(pos==1)
		delbegin();
	else if(pos==count())
		delend();
	else {
		int i=1;
		node *ptr=start;
		while(i!=pos) {
			i++;
			ptr=ptr->getnext();
		}
		ptr->getprev()->setnext(ptr->getnext());
		ptr->getnext()->setprev(ptr->getprev());
		cout<<ptr->getdata()<<endl;
		delete ptr;
		ptr=NULL;
		show();
	}
}
int dlinklist::count() {
	return count(start);
}
int dlinklist::count(node *ptr) {
	if(ptr==NULL)
		return 0;
	return 1+count(ptr->getnext());
}
void dlinklist::show() {
	show(start);
}
void dlinklist::show(node *ptr) {
	if(ptr!=NULL) {
		cout<<ptr->getdata()<<endl;
		show(ptr->getnext());
	}
}
void dlinklist::reverse() {
	reverse(NULL,NULL,start);
	show();
}
void dlinklist::reverse(node *a,node *b,node *c) {
	if(c!=NULL) {
		a=b;
		b=c;
		c=c->getnext();
		b->setprev(c);
		b->setnext(a);
		if(c==NULL)
			start=b;
		reverse(a,b,c);
	}
}
void dlinklist::sort() {
	for(node *i=start;i!=NULL;i=i->getnext())
		for(node *j=i->getnext();j!=NULL;j=j->getnext())
			if(i->getdata()>j->getdata()) {
				int temp=i->getdata();
				i->setdata(j->getdata());
				j->setdata(temp);
			}
	show();
}
void dlinklist::search() {
	cout<<"enter search item"<<endl;
	int item;
	cin>>item;
	search(start,item,1);
}
void dlinklist::search(node *ptr,int item,int pos) {
	if(ptr==NULL)
		cout<<"not found"<<endl;
	else if(ptr->getdata()==item)
		cout<<"found"<<endl<<"position "<<pos<<endl;
	else
		search(ptr->getnext(),item,pos+1);
}
dlinklist::~dlinklist() {
	while(start!=NULL) {
		node *temp=start;
		start=start->getnext();
		delete temp;
		temp=NULL;
	}
}




