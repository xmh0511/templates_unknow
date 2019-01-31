#include <iostream>
#include <string>

template<typename T,typename...Args>
struct unknow_context
{
	using type = T;
};

///第一组
//template<class _Alloc,class _Elem,  //0
//	class _Traits> inline
//	std::basic_ostream<_Elem, _Traits>& print(
//		std::basic_ostream<_Elem, _Traits>& _Ostr,
//		const typename unknow_context<std::basic_string<_Elem, _Traits, _Alloc>>::type& _Str)
//{	// insert a string
//	printf("0\n");
//	return _Ostr;
//}
//
//
//template<class _Alloc> inline
//	std::basic_ostream<char, std::char_traits<char>>& print(  //1
//		std::basic_ostream<char, std::char_traits<char>>& _Ostr,
//		const std::basic_string<char, std::char_traits<char>, _Alloc>& _Str)
//{	// insert a string
//	printf("1\n");
//	return _Ostr;
//}

/////第二组
//template<class _Alloc, class _Elem,
//	class _Traits> inline
//	std::basic_ostream<_Elem, _Traits>& print( //2
//		std::basic_ostream<_Elem, _Traits>& _Ostr,
//		const std::basic_string<typename unknow_context<_Elem>::type, typename unknow_context<_Traits>::type, _Alloc>& _Str)
//{	// insert a string
//	printf("0\n");
//	return _Ostr;
//}
//
//
//template<class _Alloc,class _Elem,
//	class _Traits> inline
//	std::basic_ostream<_Elem, _Traits>& print(  //3
//		std::basic_ostream<_Elem, _Traits>& _Ostr,
//		const std::basic_string<char, std::char_traits<char>, _Alloc>& _Str)
//{	// insert a string
//	printf("1\n");
//	return _Ostr;
//}

///第一组
//template<typename U,typename T>
//void show(T, typename unknow_context<T,U>::type)  //0
//{
//	std::cout << "0" << std::endl;
//}
//
//template<typename U,typename T>//1
//void show(T, U)
//{
//	std::cout << "1" << std::endl;
//}


///第二组
//template<typename T>
//void show(T, typename unknow_context<T>::type)  //2
//{
//	std::cout << "0" << std::endl;
//}
//
//template<typename U, typename T>//3
//void show(T, U)
//{
//	std::cout << "1" << std::endl;
//}


///第三组
//template<typename U,typename T>
//void show(T, typename unknow_context<T,U>::type)  //4
//{
//	std::cout << "0" << std::endl;
//}
//
//template<typename T>//5
//void show(T, T)
//{
//	std::cout << "1" << std::endl;
//}


///第四组
//template<typename T>
//void show(T, typename unknow_context<T, T>::type)  //6
//{
//	std::cout << "0" << std::endl;
//}
//
//template<typename T>
//void show(T, T)  //7
//{
//	std::cout << "1" << std::endl;
//}


///第五组
template<typename T,typename U = T>
void show(T, typename unknow_context<T, U>::type)  //8
{
	std::cout << "0" << std::endl;
}

template<typename T>
void show(T, T)  //9
{
	std::cout << "1" << std::endl;
}


int main()
{
	std::string ab;
	//第一组
	//print<std::allocator<char>>(std::cout, ab); //二义性 

	//第二组
	//print(std::cout, ab);  //use 3


	///第一组
	//show<int>(0, 0); //use 0

	///第二组
	//show(0, 0);  //二义性 

	///第三组
	//show<int>(0, 0);//二义性 

	//第四组
	//show(0, 0);  //use 7


	//第五组
	//show(0, 0);//二义性 

	std::cin.get();
	return 0;
}
