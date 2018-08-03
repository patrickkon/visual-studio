#include<iterator>

template<class T> class bidi : public std::iterator<std::bidirectional_iterator_tag, T,ptrdiff_t,T*,T&> {
private:
	T * point;
	//typedef const point const_iterator;
	
public:
	//set  "pointer to any number i want " constructor?
	// as well as "default initialized" kind of constuctor, i.e no parameters?
	bidi(T* ptr = nullptr) { point = ptr; }
	//copy constructor?
	//THINK ABOUT WHY DEFAULT CAN BE USED HERE.....BECAUSE the intended behaviour is obvious
	bidi(const bidi<T>& ) = default;
	//I DID NOT include destructor

	bidi<T>& operator= (T* swag) { point = swag; return *this; }
	bidi<T>&   operator= (const bidi<T>&) = default;
	
	bool operator== (const bidi<T>& swag) { return point == swag.getpoint(); }
	bool operator!= (const bidi<T>& swag) { return point != swag.getpoint(); }

	bidi<T> operator++ () { ++point; return *this; }
	bidi<T>& operator-- () { --point; return *this; }

	//this allows ++....why?

	bidi<T>  operator++(ptrdiff_t) { auto temp(*this); ++point; return temp; }
	bidi<T>& operator+ (const ptrdiff_t& num) { auto temp = point + num; point = temp; return *this; }
	bidi<T>& operator- (const ptrdiff_t& num) { auto temp = point - num; point = temp; return *this; }
	ptrdiff_t  operator-(const bidi<T>& rawIterator) { return std::distance(rawIterator.getpoint(), *(this).getpoint()); }

	//get current iterator position
	T* getpoint() { return point; }
	const T* getpoint() const { return point; }
	
	//dereference
	T& operator*() { return *point; }
	const T& operator*() const{ return *point; }
	
	//operator bidi<T const>() const;
};
