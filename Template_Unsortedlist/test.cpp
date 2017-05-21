#include "unSortedList.h"

int main(){
	unSortedList<int> unsorted;

	for(int i=0; i<10; i++){
		unsorted.insertItem(i);
	}

	unsorted.printAll();
	cout<<endl;

	unsorted.removeItem(2);
	unsorted.printAll();
	cout<<endl;

	cout<<unsorted.getItem(1, false)<<endl;
	return 0;
}
