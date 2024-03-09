#include "dlinklist.cpp"
void display();
void showmenu();
void perform(dlinklist &,int);
int main(void) {
	display();
	return 0;
}
void display() {
	dlinklist l1;
	do {
		showmenu();
		cout<<"enter choice"<<endl;
		int choice;
		cin>>choice;
		if(!choice)
			break;
		perform(l1,choice);
	} while(true);
	cout<<"end"<<endl;
}
void showmenu() {
	cout<<"1. insert at beginning"<<endl;
	cout<<"2. insert at end"<<endl;
	cout<<"3. insert at specified position"<<endl;
	cout<<"4. delete from beginning"<<endl;
	cout<<"5. delete from end"<<endl;
	cout<<"6. delete from specified position"<<endl;
	cout<<"7. show number of items"<<endl;
	cout<<"8. show list"<<endl;
	cout<<"9. reverse list"<<endl;
	cout<<"10. sort"<<endl;
	cout<<"11. search"<<endl;
	cout<<"0. exit"<<endl;
}
void perform(dlinklist &l,int choice) {
	switch(choice) {
		case 1:
			l.insertbegin();
			break;
		case 2:
			l.insertend();
			break;
		case 3:
			l.insertpos();
			break;
		case 4:
			l.delbegin();
			break;
		case 5:
			l.delend();
			break;
		case 6:
			l.delpos();
			break;
		case 7:
			cout<<l.count()<<endl;
			break;
		case 8:
			l.show();
			break;
		case 9:
			l.reverse();
			break;
		case 10:
			l.sort();
			break;
		case 11:
			l.search();
			break;
	}
}






