#ifndef yolosir
#define yolosir

#define _SCL_SECURE_NO_WARNINGS  
#include<memory>
#include<algorithm>
#include<iostream>
#include<cstdlib>




template <class T> class vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T value_type;

	vec() { create(); }
		
	//version 2. somehow def outside of class doenst work
	template<class id> vec(id begin, id end) {
		data = alloc.allocate(end - begin);
		//data = operator new vec<T>(sizeof(T) *(end - begin));
		limit = fakelimit = std::uninitialized_copy(begin, end, data);

	}

	explicit vec(const size_t& t, const T& val = T()) { create(t, val); }
vec(const vec& v) { create(v.begin(), v.end()); }
	~vec() { uncreate(); }

	void assign(T*arr, size_t s) {
		//size_t size = sizeof(arr) / sizeof(*arr);
		fakelimit = data = new T[s];
		limit = data + s;
		std::copy(arr, (arr + s ), std::back_inserter(*this));
	}

	

	void push_back(const T& t);
	iterator erase(iterator );
	iterator destroy(iterator);


	T& operator[] (size_t i) { return data[i]; }
	const T& operator[] (size_t i) const { return data[i]; }
	vec& operator=(const vec& );

	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return fakelimit; }
	const_iterator end() const { return fakelimit; }

	size_t size() { return fakelimit - data; }

	friend vec& operator+ (const vec&, const vec&);
private:
	iterator data;
	iterator fakelimit;
	iterator limit;
	
	
	std::allocator<T> alloc;
	void create();
	void create(const size_t& , const T& );
	void create(const_iterator , const_iterator );
	void uncreate();
	void grow();
	void append(const T&);
	
	
};

template<class T> vec<T>& vec<T>::operator=(const vec& v) {
	if (&v != this) {
		uncreate();
		create(v.begin(), v.end());
	}
	return *this;
}
template<class T>
//problem here?!
void vec<T>::push_back(const T& t) {
	if (fakelimit == limit)
		grow();
	append(t);
}
template<class T> void vec<T>::create() {
	data = limit = fakelimit = 0;
}

template<class T> void vec<T>::create(const_iterator begin, const_iterator end) {
	     data = alloc.allocate(end - begin);
//data = operator new vec<T>(sizeof(T) *(end - begin));
	limit = fakelimit = std::uninitialized_copy(begin, end, data);

}



template<class T> void vec<T>::create(const size_t& t, const T& val) {
	data = alloc.allocate(t);
	fakelimit = limit = data + t;
	std::uninitialized_fill(data, fakelimit, val);
}

template<class T> void vec<T>::uncreate() {
	if (data) {
		iterator i = fakelimit;
		while (i != data) 
			alloc.destroy(--i);
			//std::cout << *(i + 1) << std::endl;
		
		alloc.deallocate(data, limit - data);
	}
	data = limit = fakelimit = 0;

}

/*
template<class T> void vec<T>::grow() {
pointer1 = data;
pointer2 = fakelimit;
if (pointer2 - pointer1 != 0) {
size_t size= (fakelimit - data) * 2
data = alloc.allocate(size);
fakelimit = data + size/2;
limit = fakelimit + (fakelimit - data);
alloc.destroy(pointer1);
alloc.deallocate(pointer1, pointer2 - pointer1);

}
else {
alloc.deallocate(pointer1,1);
data = alloc.allocate(2);
fakelimit = data + 1;
limit = fakelimit + (fakelimit - data);
}

} */

template<class T> void vec<T>::grow() {
	size_t size = std::max(2 * (limit - data), ptrdiff_t(1));
	// data = operator new vec<T>(sizeof(T) *(end - begin));

	 iterator newdata = alloc.allocate(size);
	iterator newfake = std::uninitialized_copy(data, fakelimit, newdata);

	uncreate();
	data = newdata;
	fakelimit = newfake;
	limit = data + size;

}

template<class T> void vec<T>::append(const T& val) {
	alloc.construct(fakelimit++, val);
}

template<class T> typename vec<T>::iterator vec<T>::erase(iterator i) {


	if (data && i != limit) {
		//so apparently destroy doesnt destroy objects. i can also overwrite values using construct
		//so there is basically no point in destroy.
		//lmao

		//alloc.destroy(i);
		iterator point = i + 1;
		while (point != limit) {
			alloc.construct(i++, *point++);
			//alloc.destroy(i);
		}
		limit = i;
		std::realloc(data, sizeof(iterator) *((limit) - data));
	}
		return limit;

	
}
/*
template<class T>
typename vec<T>::iterator vec<T>::destroy(iterator pos)
{
	if (data && pos != limit)
	{
		alloc.destroy(pos);
		iterator it = pos + 1;
		//std::cout << *pos << std::endl;
		while (it != limit)
		{
			alloc.construct(pos++, *it++);
			alloc.destroy(pos);
		}
		limit = pos;
	}
	return limit;
}
*/
template<class T>
typename vec<T>::iterator vec<T>::destroy(iterator pos)
{
	if (data && pos != fakelimit)
	{
		alloc.destroy(pos);
		iterator it = pos + 1;

		while (it != fakelimit)
		{
			alloc.construct(pos++, *it++);
			alloc.destroy(pos);
		}
		fakelimit = pos;
	}
	return fakelimit;
}

template<class T> vec<T> operator+ (const vec<T>& v1, const vec<T>& v2) {
	// friend function requires <T>

	//iterator temp =  new T[v1.size()+v2.size()];
	//std::copy(v1.begin(), v1.end(), std::back_inserter(*temp));
	//std::copy(v2.begin(), v2.end(), std::back_inserter(*temp));
	
	// not sure if returnign ref will cause probs
	vec<T> temp = v1;
	std::copy(v2.begin(), v2.end(), std::back_inserter(temp));
	return temp;
}





#endif