#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

//function declaration 
void add(vector <int> &);
int firstUniqueNumber();
void addNumber(int );



//data struucture
unordered_map <int,int> st;
//list has two function, push front and pop back 
// we have further auto it = l.begin() and advance(it, 2), and l.insert(it,4);
// insert the element at the given position
//accessing element, l.front() and l.back()
// how to access the third element from the fromt 
//finding element 
// auto it = find(l.begin(), l.end(), 4);
// pop_back and pop_front
// l.erase(it)
//insertion at the beginning and at end can be done using push_back and push_front
list <int> uniqueElementList;
unordered_map <int, list<int>::iterator> listIteratorEntry;

//main function 
int main()
{
	vector <int> store {1,2,3,4};
	add(store);
	cout <<" First Unique element in the list is"<<endl;
	cout << firstUniqueNumber() <<endl;

	addNumber(1);
	cout <<" First Unique element in the list is"<<endl;
	cout << firstUniqueNumber() <<endl;
	return 0;
}

void add(vector <int> & store)
{
	for(auto i: store)
	{
		st[i]++;
	}


	for(auto i: store)
	{
		if(st[i] == 1)
		{
			uniqueElementList.push_back(i);
			//list.end points to the last element
			cout <<"Putting the element i  in the list "<<i<<endl;
			auto it= uniqueElementList.end();
			it--;
			listIteratorEntry[i] = it; 
		}
	}
	//delete the original hashmap here, for the cleannnup function
	st.clear();
}

int firstUniqueNumber()
{
	//simple function always return the head of the list 
	//check if thhe list is not emepty 
	if(uniqueElementList.empty())
	{
		return -1; //no entry found in the list
	}
	else
	{ 
		//return the front element from the list
	return uniqueElementList.front(); //return the front element of the list
	}
}

void addNumber(int x)
{
	if(listIteratorEntry.find(x) != listIteratorEntry.end())
	{
		//duplicate element found 
		uniqueElementList.erase(listIteratorEntry[x]); //remove the element from the list
		//erase the entry from the list iterator entry 
		listIteratorEntry.erase(x);
	}
	else
	{
		uniqueElementList.push_back(x);
		auto it= uniqueElementList.end();
		it--;
		listIteratorEntry[x] = it;
	}
}
