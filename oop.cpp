// padding and greedy alignment





// memory leak

// Memory leakage occurs in C++ when programmers allocates memory by using new keyword and forgets to deallocate the memory by using delete() function or delete[] operator. One of the most memory leakage occurs in C++ by using wrong delete operator. 
// The delete operator should be used to free a single allocated memory space, whereas the delete [] operator should be used to free an array of data values. 
// Disadvantage with memory leakage: 
// If a program has memory leaks, then its memory usage is satirically increasing since all systems have limited amount of memory and memory is costly. Hence it will create problems.
// Example of memory leakage in C++ 
 


// // Program with memory leak
// #include <bits/stdc++.h>
// using namespace std;
 
// // function with memory leak
// void func_to_show_mem_leak()
// {
//     int* ptr = new int(5);
 
//     // body
 
//     // return without deallocating ptr
//     return;
// }
 
// // driver code
// int main()
// {
 
//     // Call the function
//     // to get the memory leak
//     func_to_show_mem_leak();
 
//     return 0;
// }
// How to avoid Memory Leak?

// Instead of managing memory manually, try to use smart pointers where applicable.
// use std::string instead of char *. The std::string class handles all memory management internally, and it’s fast and well-optimized.
// Never use a raw pointer unless it’s to interface with an older lib.
// The best way to avoid memory leaks in C++ is to have as few new/delete calls at the program level as possible – ideally NONE. Anything that requires dynamic memory should be buried inside an RAII object that releases the memory when it goes out of scope. RAII allocate memory in constructor and release it in destructor, so that memory is guaranteed to be deallocated when the variable leave the current scope.
// Allocate memory by new keyword and deallocate memory by delete keyword and write all code between them.





// const keyword in c++



// In C++, the const keyword is used to specify that a variable or function parameter should not be modified. In object-oriented programming, it can be used to indicate that a member function will not modify the state of the object on which it is called.

// When used with a variable, const makes that variable read-only, meaning that its value cannot be changed once it has been initialized. Here's an example:

//const int x = 10; // x is a constant integer with value 10
//x = 20; // error: cannot modify a const variable


// When used with a member function, const indicates that the function does not modify the object's state, and therefore can be called on a const object. Here's an example:

// class MyClass {
// public:
//     int getValue() const; // const member function declaration

// private:
//     int value;
// };

// int MyClass::getValue() const { // const member function definition
//     return value; // can read but not modify member variable 'value'
// }

// int main() {
//     const MyClass obj; // obj is a const object of MyClass
//     obj.getValue(); // OK: calling a const member function on a const object
//     obj.value = 10; // error: cannot modify a const object
//     return 0;
// }
// In this example, the getValue() member function is declared as const, indicating that it does not modify the state of the MyClass object. This allows the function to be called on a const object like obj. The attempt to modify the member variable value of obj results in a compilation error, since obj is declared as const.



// initialization list 



// In C++, an initialization list is used to initialize member variables of a class in the constructor of that class. It provides a way to set the initial values of the class's member variables before the body of the constructor is executed.

// Here's an example of how to use an initialization list in C++:


// class MyClass {
// public:
//     MyClass(int x, int y) : var1(x), var2(y) {
//         // constructor body
//     }

// private:
//     int var1;
//     int var2;
// };

// int main() {
//     MyClass obj(10, 20);
//     return 0;
// }
// In this example, the MyClass constructor takes two integer arguments x and y, which are used to initialize the var1 and var2 member variables, respectively. The initialization list is specified after the constructor argument list, and is enclosed in parentheses and separated by commas. The body of the constructor is empty in this example.

// When an object of MyClass is created with the MyClass obj(10, 20) statement, the constructor is called with the arguments 10 and 20. The var1 member variable is initialized to 10, and the var2 member variable is initialized to 20, using the initialization list syntax.

// Using initialization lists can be more efficient than assigning member variables in the constructor body, especially for complex objects or objects with large arrays or vectors as member variables. It can also help avoid errors caused by uninitialized member variables.



// operator overloading



// #include <iostream>
// using namespace std;

// class MyClass {
// public:
//     int x;
//     int y;

//     ostream& operator<<(ostream& os) const {
//         os << x << ", " << y;
//         return os;
//     }

//     istream &operator>>(istream &is)
//     {
//         is >> x >> y;
//     }
// };

// int main() {
//     MyClass obj;
//     obj.x = 10;
//     obj.y = 20;
//     // cout << obj << endl; // will not work
//     // obj << cout << endl; // will work
//     obj>>cin;
//     return 0;
// }


// In the example above, we define a class MyClass with two integer members x and y. We then define an overloaded operator<< function as a member function of the class. The function takes an output stream os as its argument, and returns a reference to the same output stream.

// Inside the function, we write the contents of the MyClass object to the output stream os in a format of our choice. In this case, we write "MyClass(" followed by the values of x and y, separated by a comma and space, followed by ")".

// In the main function, we create a MyClass object and set its x and y members. However, we cannot output the object to cout using the << operator directly, since it is not a friend function. Instead, we use the overloaded << operator on the object itself, passing cout as an argument. This will call our member function operator<<, which will write the contents of the object to the output stream cout.

// Note that when overloading the "<<" operator as a member function, it takes the left operand implicitly as this pointer. Therefore, the function should return a reference to the output stream os rather than void. Also, since we cannot use the << operator on the object itself, we need to use the << operator on some other object, such as cout, passing the object as an argument to the overloaded operator.





