#pragma once
template<typename T>
class MovieContainer
{
private:
	int cap;
	int len;
	Relation r;
	T* list = new T[cap];

	void reallocate();
	

public:
	/* constructor */
	MovieContainer(T* list); 

	/*find position of an element in the list*/
	int find(T elem)

	/*add a new element to the list*/
	void add(T elem);

	/*delete an element from the list*/
	void del(T elem);

	/*update an element in the list*/
	void update(T elem);
};