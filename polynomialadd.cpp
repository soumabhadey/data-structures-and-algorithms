#include <iostream>
using namespace std;
struct term
{
	int coef;
	int exp;
	term *next;
	term()
	{
		next=NULL;
	}
};
struct expression
{
	term *head;
	expression()
	{
		head=NULL;
	}
	term * create();
	void addexpr(expression *,expression *);
	void display();
	
};
term * expression::create()
{
	int c,e;
	term *nptr;
	cin>>c>>e;
	if(c==0&&e==0)
		return NULL;
	nptr=new term;
	nptr->coef=c;
	nptr->exp=e;
	nptr->next=create();
	return nptr;
}
void expression::addexpr(expression *e1,expression *e2)
{
	term *ptr1, *ptr2, *ptr3;
	ptr1=e1->head;
	ptr2=e2->head;
	ptr3=head;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->exp==ptr2->exp)
		{
			if(ptr1->coef+ptr2->coef!=0)
			{
				if(head==NULL)
				{
					head=new term();
					ptr3=head;
				}
				else
				{
					ptr3->next=new term();
					ptr3=ptr3->next;
				}
				ptr3->coef=ptr1->coef+ptr2->coef;
				ptr3->exp=ptr1->exp;
			}
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->exp>ptr2->exp)
		{
			if(head==NULL)
			{
				head=new term();
				ptr3=head;
			}
			else
			{
				ptr3->next=new term();
				ptr3=ptr3->next;
			}
			ptr3->coef=ptr1->coef;
			ptr3->exp=ptr1->exp;
			ptr1=ptr1->next;
		}
		else if(ptr1->exp<ptr2->exp)
		{
			if(head==NULL)
			{
				head=new term;
				ptr3=head;
			}
			else
			{
				ptr3->next=new term;
				ptr3=ptr3->next;
			}
			ptr3->coef=ptr1->coef;
			ptr3->exp=ptr2->exp;
			ptr2=ptr2->next;
		}
	}
}
void expression::display()
{
	term *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr!=head&&ptr->coef>0)
			cout<<"+";
		cout<<ptr->coef<<"x^"<<ptr->exp<<" ";
		ptr=ptr->next;
	}
}
int main(void)
{
	expression e1,e2,e3;
	cout<<"Enter coefficient and exponent of polynomial 1"<<endl;
	e1.head=e1.create();	
	cout<<"Enter coefficient and exponent of polynomial 2"<<endl;
	e2.head=e2.create();
	e3.addexpr(&e1,&e2);
	e1.display();
	cout<<endl;
	e2.display();
	cout<<endl;
	e3.display();
	cout<<endl;
	return 0;
}




