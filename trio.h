#ifndef TRIO_H
#define TRIO_H


template <typename A, typename B, typename C> 
struct trio{
	
	A first;
	B second;
	C third;
	trio(A a,B b,C c):  first(a), second(b), third(c){};
	

};

template <typename A, typename B, typename C> 
trio<A,B,C> make_trio(A a, B b, C c){

	trio<A,B,C> foo(a,b,c);
	return foo;
}


#endif
