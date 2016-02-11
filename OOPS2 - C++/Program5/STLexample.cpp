#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Person
{
public:
	Person( string n, int a ): name(n), age(a){}
	void Print() const { cout << name << " is " << age << " years old." << endl; }
private:
	string name;
	int age;
};

void ToUpper( char& c ) { c-=32; }
template<class T>
bool GreaterThan( T t1, T t2 ) { return t1 > t2; }
bool IsOdd( int i ) { return ( ( i % 2 ) == 1 ); }

class ConvertCase
{
public:
	void operator() ( char& c )
	{
		if ( c >= 'a' && c <= 'z' )
			c -= 32;
		else if ( c >= 'A' && c <= 'Z' )
			c += 32;
	}
};

template <class T>
struct Greater
{
	bool operator() ( T t1, T t2 ) const { return t1 > t2; }
};

void VectorExample()
{
	vector<char> vc;
	for ( int i = 0; i < 10; i++ )
		vc.push_back( 'z' - i );

	int size = vc.size();
	cout << "The size of the vector is " << size << endl;
	
	for ( vector<char>::size_type i = 0; i < vc.size(); i++ )
		vc[i] = vc[i] - 32;
	// or
	//for_each( vc.begin(), vc.end(), ToUpper );

	// sort the vector in ascending order
	sort( vc.begin(), vc.end() );
	// or
	//sort( vc.begin(), vc.begin() + size );

	// sor the vector in decending order
	//sort( vc.begin(), vc.end(), GreaterThan<char> );

	// convert back to upper case
	//ConvertCase convert;
	//for_each( vc.begin(), vc.end(), convert );
	
	vector<char>::iterator vIter;
	for ( vIter = vc.begin(); vIter < vc.end(); vIter++ )
		cout << *vIter << " ";
	cout << endl;

	cout << vIter[-5] << endl;
	vector<char>::iterator vIter2 = vc.begin() + 2;
	vc.insert( vIter - 5, *vc.begin() - 10 );
	//cout << vIter[-5] << endl; // what would happen?
	//cout << vIter2[2] << endl; // what would happen?
	vc.pop_back();
	vc.pop_back();
	
	for ( vIter = vc.begin(); vIter < vc.end(); vIter++ )
		cout << *vIter << " ";
	cout << endl;

	cout << "The first element is " << vc.front() << endl;
	cout << "The last element is  " << vc.back() << endl;

	typedef vector<int*> Nums;
	Nums *values = new Nums;
	values->push_back( new int(10) );
	values->push_back( new int(20) );
	values->push_back( new int(30) );
	for( Nums::iterator iter = values->begin(); iter != values->end(); iter++ )
		cout << **iter << " ";
	cout << endl;

	for( Nums::iterator iter = values->begin(); iter != values->end(); iter++ )
		delete *iter;
	//values->clear(); // is it necessary?
	delete values;

	vector<Person> people;
	Person p1( "Alex", 20 );
	Person p2( "Ben", 21 );
	people.push_back( p1 );
	people.push_back( p2 );	
	vector<Person>::const_iterator iterP = people.begin();
	(*iterP).Print();
	iterP++;
	iterP->Print();

}

void ListExample()
{
	list<int> nums, nums2;
	list<int>::iterator iter, iter2; // iterator
	int value;

	cin >> value;
	while ( value != 9999 )
	{
		nums.push_back( value ); // add to the end of the list
		cin >> value;
	}

	cout << endl << "The original list is: " << endl;
	for ( iter = nums.begin(); iter != nums.end(); iter++ )
		cout << *iter << endl; // use iter the same way as a pointer

	nums2 = nums;
	cout << endl << "The second list is a copy of the original list: " << endl;
	for ( iter = nums2.begin(); iter != nums2.end(); iter++ )
		cout << *iter << endl;

	cout << endl << "Reverse the list: " << endl;
	nums.reverse();
	// or 
	//reverse ( nums.begin(), nums.end() ); 
	for ( iter = nums.begin(); iter != nums.end(); iter++ )
		cout << *iter << endl;

	iter = nums.begin()++;
	iter2 = iter++; // can we do iter2 = iter + 1;?
	cout << "iter is pointing at " << *iter << endl;
	cout << "iter2 is pointing at " << *iter2 << endl;
	nums.erase( iter );
	//cout << "iter is pointing at " << *iter << endl; // What will happen?
	cout << "iter2 is pointing at " << *iter2 << endl; // What will happen?

	cout << endl << "Insert a value as the second last: " << endl;
	iter = nums2.end();
	--iter;
	nums2.insert( iter, *nums2.begin() - 10 );
	for ( iter = nums2.begin(); iter != nums2.end(); iter++ )
		cout << *iter << endl;

	nums.swap( nums2 );
	// or
	// swap ( nums, nums2 );
	cout << endl << "After swapping, the first list is " << endl;
	for ( iter = nums.begin(); iter != nums.end(); iter++ )
		cout << *iter << endl;
	cout << "The second list is " << endl;
	for ( iter = nums2.begin(); iter != nums2.end(); iter++ )
		cout << *iter << endl;
	cout << endl;

}

void DequeExample()
{
	deque<int> d;
	deque<int>::iterator iter;

	iter = d.begin();
	d.push_back( 100 );
	//cout << *iter << endl; // can we do that?
	iter = d.end();
	d.pop_back( );
	//cout << *iter << endl; // can we do that?

	for ( int i = 0; i < 10; i ++ )
		d.push_front( i * i );

	const int& num1 = d.at( 1 );
	int& num2 = d.at( 2 );
	int num3 = d.at( 3 );
	cout << num1 << " " << num2 << " " << num3 << endl;

	cout << endl << "original: " << endl;
	iter = d.begin();
	for ( int i = 0; i < (int)d.size(); i++ )
		cout << " " << iter[i];
	cout << endl;
	
	iter += 2; // where is iter pointing at?
	d.pop_front();
	d.pop_front();
	cout << "After poping two element from the front: " << endl;
	for ( int i = 0; i < (int)d.size(); i++ )
		cout << " " << iter[i];
	cout << endl;

	cout << "iter is pointing at " << *iter << endl; // can we do that?
	d.insert( iter + 2, 1000 );
	cout << "After inserting 1000: " << endl;
	for ( iter = d.begin(); iter < d.end(); iter++ )
		cout << " " << *iter;
	cout << endl;

	iter -= 2;
	cout << "The second last element is " << *iter << endl;
	d.push_front( 2000 );
	// cout << "The second last element is " << *iter << endl; Can we:?

	// remove all odd numbers from the deque:
	// erase is used here to remove a range of elements
	d.erase( remove_if( d.begin(), d.end(), IsOdd ), d.end() );
	// what if we only do remove_if?
	//iter = remove_if( d.begin(), d.end(), IsOdd );
	//cout << *iter << endl;
	cout << "after removing odd numbers: " << endl;
	for ( iter = d.begin(); iter < d.end(); iter++ )
		cout << " " << *iter;
	cout << endl;
}

void StackExample()
{
	stack<int> s1, s2;
	s1.push( 10 );
	s1.push( 20 );
	s1.push( 30 );

	s2.push( 10 );
	s2.push( 20 );
	s2.push( 30 );
	if ( s1 == s2 )
		cout << "same" << endl;
	s2.pop();
	if ( s1 > s2 )
		cout << "s1 is larger" << endl;
	s2.push( 40 );
	if ( s1 < s2 )
		cout << "s2 is larger" << endl;
	s2.pop();
	s2.push( 20 );
	s2.push ( 50 );
	if ( s1 > s2 )
		cout << "s1 is larger" << endl;
}

void PQueueExample()
{
	priority_queue<int> pq;
	pq.push( 10 );
	pq.push( 20 );
	pq.push( 30 );
	
	cout << "The top of the priority queue is " << pq.top() << endl;
	while ( pq.size() != 0 )
	{
		cout << " " << pq.top();
		pq.pop();
	}
	cout << endl;
}

void SetExample()
{
	set<int> s1;
	set<int, less<int>> s2;
	set<int, Greater<int>> s3;
	set<int>::iterator iter, iter2;

	s1.insert( 80 );
	s1.insert( 70 );
	s1.insert( 0 );
	s1.insert( 30 );
	s1.insert( 20 );
	s1.insert( 60 );
	s1.insert( 30 );
	s1.insert( 40 );
	s1.insert( 10 );

	iter2 = --s1.end();
	cout << "iter2 is pointing at " << *iter2 << endl;
	iter = s1.find( 40 );
	s1.insert( iter, 50 ); // what does the first parameter mean?
	cout << "s1 is: " << endl;
	for ( iter = s1.begin(); iter != s1.end(); iter++ )
		cout << *iter << " ";
	cout << endl;
	cout << "iter2 is pointing at " << *iter2 << endl;
	
	cout << endl;
	s2.insert( 20 );
	s2.insert( 40 );
	pair< set<int>::iterator, bool > pr;
	pr = s2.insert( 60 );
	if ( pr.second == true )
		cout << "Element 60 was successfuly inserted in s1." << endl;
	cout << "s2 is: " << endl;
	for ( iter = s2.begin(); iter != s2.end(); iter++ )
		cout << *iter << " ";
	cout << endl;

	cout << endl;
	s3.insert( ++s1.begin(), --s1.end() );
	cout << "s3 is: " << endl;
	for ( iter = s3.begin(); iter != s3.end(); iter++ )
		cout << *iter << " ";
	cout << endl;

	cout << endl;
	iter = s1.begin();
	iter2 = --s1.end();
	cout << "iter is pointing at " << *iter << endl;
	cout << "iter2 is pointing at " << *iter2 << endl;
	s1.erase( iter2 );
	cout << "iter is pointing at " << *iter << endl;
	// cout << "iter2 is pointing at " << *iter2 << endl; // can we do that?
	cout << "After erasing one element, s1 is: " << endl;
	for ( iter = s1.begin(); iter != s1.end(); iter++ )
		cout << *iter << " ";
	cout << endl;
	
	cout << endl;
	s1.erase( s1.lower_bound( 30 ), s1.upper_bound( 50 ) );
	cout << "After erasing a rang of elements, s1 is: " << endl;
	for ( iter = s1.begin(); iter != s1.end(); iter++ )
		cout << *iter << " ";
	cout << endl;

	// note the intersting observation here:
	cout << endl;
	iter = s3.upper_bound( 10 );
	if ( iter == s3.end() )
		cout << "All elements in s3 are smaller than or equal to 10!" << endl;
	else
		cout << "The first element that is greater than 10 in s3 is " 
		     << *iter << endl;

	cout << endl;
	multiset<int> s4;
	s4.insert( s3.begin(), --s3.end() );
	cout << "s4 is: " << endl;
	for ( iter = s4.begin(); iter != s4.end(); iter++ )
		cout << *iter << " ";
	cout << endl;

	s4.insert( 50 );
	s4.insert( 50 );
	s4.insert( 30 );
	cout << "After inserting several elements, s4 is: " << endl;
	for ( iter = s4.begin(); iter != s4.end(); iter++ )
		cout << *iter << " ";
	cout << endl;

	int n = s4.erase( 50 );
	cout << "After erasing " << n << " occurances of 50, s4 is:" << endl;
	for ( iter = s4.begin(); iter != s4.end(); iter++ )
		cout << *iter << " ";
	cout << endl;
}

void MapExample()
{
	typedef pair<int, string> Student;
	map<int, string> m1;
	map<int, string, Greater<int>> m2;
	map<int, string>::iterator iter;

	m1.insert( Student( 5, "John" ) );
	m1.insert( Student( 3, "Betty" ) );
	m1.insert( Student( 6, "Phil" ) );
	m1.insert( Student( 1, "Ada" ) );
	m1.insert( Student( 4, "Kyle" ) );
	m1.insert( Student( 3, "Brian" ) );
	pair< int, string > pr(2, "Sam");
	m1.insert( pr );
	m1.insert( pair<int, string>( 5, "Larry" ) );

	cout << "m1 is " << endl;
	for ( iter = m1.begin(); iter != m1.end(); iter++ )
		cout << iter->first << " " << iter->second << endl;
	cout << endl << endl;

	m2.insert( m1.find( 2 ), m1.find( 6 ) );
	cout << "m2 is " << endl;
	for ( iter = m2.begin(); iter != m2.end(); iter++ )
		cout << iter->first << " " << iter->second << endl;
	cout << endl << endl;

	cout << "The student whose id is 3 is " << m1.at( 3 ) << endl << endl;

	multimap<int, string> m3;
	m3.insert( m1.begin(), m1.end() );
	m3.insert( Student( 3, "David" ) );
	m3.insert( Student( 3, "Zack" ) );
	m3.insert( Student( 5, "Marshall" ) );
	cout << "m3 is " << endl;
	for ( iter = m3.begin(); iter != m3.end(); iter++ )
		cout << iter->first << " " << iter->second << endl;
	cout << endl << endl;

	cout << "The number of students with id 3 is " << m3.count( 3 ) << endl;
	typedef multimap<int, string>::iterator MMIter;
	pair<MMIter, MMIter> pr2;
	pr2 = m3.equal_range( 3 );
	cout << "These students are: " << endl;
	for ( iter = pr2.first; iter != pr2.second; iter++ )
		cout << iter->second << " ";
	cout << endl << endl;

	m3.erase( 3 );
	cout << "After removing these students, m2 is " << endl;
	for ( iter = m3.begin(); iter != m3.end(); iter++ )
		cout << iter->first << " " << iter->second << endl;
	cout << endl << endl;
}

void main()
{
	//VectorExample();
	//ListExample();
	//DequeExample();
	StackExample();
	//PQueueExample();
	//SetExample();
	//MapExample();
}