# 1.1 What's This Book About?
Solving the problem is normally not enough, speed matters. When you work with larger datasets, runtime becomes an
issue and is something you must handle.
# 1.2 Mathematics Review
## Exponents
$X^AX^B = X^{A+B}$  
$\frac{X^A}{X^B}$  
${(X^A)}^B = X^{AB}$  
$X^N + X^N = 2X^N \neq X^{2N}$  
$2^N + 2^N = 2^{N+1}$
## Logarithms
All logarithms are to the base 2 unless specified otherwise when dealing with computer science.
## Series
$\displaystyle\sum_{i=0}^N 2^i=2^{N+1}-1$  
$\displaystyle\sum_{i=0}^N A^i=\frac{A^{N+1}-1}{A-1}$  
If 0 < A < 1,  
$\displaystyle\sum_{i=0}^N A^i \leq \frac{1}{1-A}$  
Arithmetic Series: $\displaystyle\sum_{i=1}^N i = \frac{N(N+1)}{2} \approx \frac{N^2}{2}$  
$\displaystyle\sum_{i=1}^N i^2 = \frac{N(N+1)(2N+1)}{6} \approx \frac{N^3}{3}$  
$\displaystyle\sum_{i=1}^N i^k \approx \frac{N^{k+1}}{|k+1|}$, $k\neq-1$  
$H_N = \sum_{i=1}^N \frac{1}{i} \approx \log_e N$  
$\displaystyle\sum_{i=1}^N f(N)=Nf(N)$  
$\displaystyle\sum_{i=n_0}^N f(i)=\displaystyle\sum_{i=1}^N f(i) - \displaystyle\sum_{i=1}^{n_0-1} f(i)$
## Modular Arithmetic
Modular arithmetic compares numbers based on their remainders when divided by $N$, written as  
$A \equiv B(\mod N)$.  
When $N$ is prime:  
$ab \equiv 0$ implies $a$ or $b$ is $0\mod N$  
every $a$ has a unique inverse $x$ such that $ax \equiv 1$  
$x^2 \equiv a$ either has two or no solutions
## The *P* word
Proof by induction and proof by constradiction are ways to prove statements.
### Proof by Induction
Prove a base case, assume an inductive hypothesis, then use these two premises to prove a statement
### Proof by Contradiction
Prove that some known property of a theorem is false, which proves the entire theorem is false.
# 1.3 A Brief Introduction to Recursion
Recursion is when a function calls itself. There are a few rules to this, but first here is an example using the
fibonacci sequence.  
int fib (int x)  
{  
    if (x <= 1) {return x;}  
    return fib(x-2) + fib(x-1);  
}  
This program calculates the xth term of the Fibonacci sequence using recursion. 
The first line is part of the first rule of recursion, which is called the **base case**. 
The trick to recursion is for a function to call itself until it gets to a value that is known which, in this case, is 0 and 1, which are the first two terms of the fibonacci sequence. 
Until x gets to those values, it will call itself over and over again. This is what the second line does, and is also the second rule of recursion: **making progress**. 
The function, no matter how big x is, will always make it to the base case. Also, every recursive call works for all positive integers greater than or equal to 0, as that's the range for fibonacci. 
However, even if the function were to be called with a negative number, it would not run indefinitely and crash the program. This is part of the **design rule**, the third rule of recursion. 
The last rule of recursion is the **compound interest rule**, which essentially states that you shouldn't duplicate work by solving the same problem in a separate recursive call. 
Clearly, this function does not follow that, and is why it has such a bad run time ($2^n$). 
To understand how this function does not follow that, you can plug in any integer, say 4, 
and instantly you realize that fib(4) will call fib(3) and fib(2), but fib(3) will call fib(2) and fib(1), hence solving fib(2) twice. 
The fibonacci sequence is simply easier to understand, which is why it's often used as an example, 
however, even the book states that it is generally a bad idea to use recursion for simple math functions, such as fibonacci.
# 1.4 C++ Classes
## Basic class Syntax
Classes have members and member functions. Each instance of a class is an object. You can declare members and member functions as
either public or private. Public means anything in the program can access them. Private means only member functions of the class can access
them. Normally, you will see data members set to private and member functions set to public, in order for the class to be usable
by other parts of the program, without needing to know the internal details of that class. Classes also have constructors, which essentially
initializes the data members of that class. A class will always have a default constructor if none is defined and will initialize the data members
using language defaults.
## Extra Constructor Syntax and Accessors
Constructors with no parameters are called default constructors.  
An initializer list can be used to initialize values in the constructor definition. For example, if a data member is a const, only an initializer list
can set its value, not the constructor definition. Initializer lists can also be used in inheritance hierarchies, like if a derived class's base class 
does not have a default constructor, only an overloaded constructor.  
A constructor with parameters is known as an overloaded constructor.  
An initialization list is a way to initialize data members directly, rather than using the constructor's body. It helps save time for when data members consist of other classes. 
Another use case is when a derived class's base class does not have a default constructor.  
Whenever a constructor has one parameter, it is important to make it explicit to avoid implicit type conversions. If you declare a constructor
explicit, the compiler will not do this type conversion and complain about a type mismatch, preventing undefined behavior.  
Member functions have two types, accessors and mutators. Mutators are member functions that change the state of the object, directly 
modifying its data members. Accessors do not change the state of the object, but examine it. For example a member function that retrieves
information from a certain data member of a class is an accessor, and a member function that changes that data member is a mutator. To mark
a member function as an accessor, you use the const keyword, as it does not modify any data members.
## Seperation of Interface and Implementation
In C++, class implementation is normally seperated from the declaration/interface. The interface lists all member functions and data members in a header
file, while the implementation is in a seperate cpp file. For the interface, header guards are included to prevent the implementation
from including a second header file. In the implementation, the header file must be included in order to access the knowledge of the interface.
In the implementation file, the scope resolution operator is included in function definitions in order to specify which class it is a part of. 
The function signatures must also match exactly, including name, parameters, and return type, in order for the member function to be properly implemented.
# 1.5 C++ Details
## Pointers
Pointer variables store the addresses of the objects they point to. To declare a pointer, you use the * symbol. For example, to declare a
pointer to an object, you would do " object* x". This, however, causes x to be uninitialized. To give it a value, you use the *new* keyword, which 
returns a pointer to the newly created object: "object* x = new object;". There are varying syntaxes for the zero parameter constructor, but this is
the most common practice. For every *new* there must be a *delete*. In other programming languages, there is automatic garbage collection for when
an object is no longer referenced, however, in C++, this is not the case. When you dynamically allocate an object using new, you must call delete. 
If you do not, the memory that was allocated for that object will not be freed for other use in the program causing memory leaks. For smaller programs, this is
not normally a problem that is evident, however, as programs get bigger and bigger and take up more memory, these memory leaks cause crashes and other
undefined behavior. When you call assingment or comparison operators on pointers, it applies to the memory address hold, not the values of
the variables they point to. In order to access the value of a pointer, you must *dereference* it using the "*" symbol. To call a function on a pointer,
you use the -> symbol (i.e. object->print_info()). This is the same thing as saying (*object).print_info(), however the -> symbol improves readability
(syntaxic sugar). Another operator that can return a memory location is the & operator, also known as a reference.
## Lvalues, Rvalues, and References
In C++, every value is either an lvalue or an rvalue. An lvalue is basically something you can take the address of. It refers to an actual object in memory. 
For example, if you have a variable with a name like str, x, y, or arr, that’s an lvalue. Even expressions like *ptr or arr[x] are lvalues, because they refer 
to a real location in memory. Rvalues are the opposite they’re temporary values, like literals (2, "foo"), or expressions that return a value but don’t refer 
to anything with a name (x + y, str.substr(0,1)). These temporaries don’t have a real place in memory after the statement is done, and you can’t assign to them or take their address. 
Most of the time, if it’s a named variable, it’s an lvalue. If it’s a throwaway value used during a calculation, it’s an rvalue.
References are just alternative names for values. In regular C++, references use & and can only refer to lvalues, meaning they need to be bound to something that exists. 
So string& r = str; works, but string& r = str + ""; doesn’t, because str + "" is a temporary. If C++ allowed that, you'd end up with a reference to a value that disappears immediately. 
Starting in C++11, there's also &&, which is used for rvalue references. These let you bind to temporaries on purpose. So string&& s = str + ""; is fine. Now you’ve got a reference to a value that 
normally wouldn’t be accessible after the line finishes running. This whole rvalue reference thing mainly exists to help optimize performance by letting you "steal" resources instead of copying them.
There are a few clean uses for lvalue references in everyday code. One is when you want to shorten a long expression. For example, if you’re working with
something like theLists[myhash(x, theLists.size())], writing that over and over is annoying and wasteful. So you just do auto& whichList = theLists[...] 
once and reuse whichList. If you used plain auto instead of auto&, you’d be working with a copy and your changes wouldn’t do anything. Another common use 
is in range-based for loops. If you say for (auto x : arr), you’re just copying each item in the array and modifying the copy, which does nothing. But if you say for (auto& x : arr), 
now x is a real reference to each value in the array and changes will stick. The third big use is avoiding copies from function calls. If you call auto x = findMax(arr);, 
and findMax returns a big object, you’re copying the whole thing. If all you need to do is read from it, you can just say auto& x = findMax(arr); instead and avoid the copy. You do need findMax to 
return a reference for this to work, though. That’s pretty much it for references in this context  it’s all about avoiding unnecessary work and making your code cleaner.
## Parameter Passing
There are different ways to pass parameters in C++. The most common way, and the way a lot of other languages do it is call by value. The variable is directly called into the function
(i.e. f(x)). However, this is not always efficient or right. Call by value is only appropriate for small objects that do not need to be altered by the function, such as finding the 
product of two ints. However, when you get to functions that do alter the variables such as swap() for example, this does not work. This is the case where we call by reference. If you plan
to alter any sort of values that need to be passed to the function, they must be called by reference. Another case of calling by reference is with bigger objects. If I wanted to find the 
minimum value of an int array, I would need to pass that into a function that may look like min(int arr[], size). However, this uses a lot of memory the bigger the array is, as the function will
make a copy of that array. In order to not take up as much memory, you pass in bigger object by call by const reference, so that the program does not need to make a copy of them. In C++11 there 
is a fourth way to pass parameters known as call by rvalue reference, where you pass in an rvalue into the function to do a *move* rather than a *copy*. This lets the caller choose what type of
value will be passed to the function, assuming there is appropriate overload, of course.
## Return Passing
Just like there are different ways to pass parameters, there are also different ways to return values from a function in C++. The first and most common way is return by value, which makes a copy
of the result of a function, then returns it to the caller. For small objects like int or double, this is fine, however, for an object that takes up much more memory, this is not ideal, so in C+11
and later, the compiler applies move semantics, which in short is just transferring the result, instead of copying it, by moving a pointer. There's also another way to return a value, and it is 
known as return by constant reference, where the function a reference to an object that already exists in memory, like an element of a vector. This avoids copying entirely, but you have to be careful: 
the reference must stay valid after the function returns. This only works when you're returning something that still exists, like an element in a parameter that was passed in. The tradeoff is that
the caller also has to bind it to a const& to avoid triggering a copy. So even if the function returns a reference, you’ll still get a copy if you assign it to a regular variable instead of a reference.
In older C++, returning large objects by value usually meant writing weird workarounds like passing pointers or extra arguments just to avoid copies. But now, in C++11 and up, the compiler can automatically
move the return value. So you can return something like a vector directly from a function without worrying about performance. As long as it’s a temporary object, the compiler will optimize the move
behind the scenes. Lastly, there’s return-by-reference (not const), which means the function gives the caller a modifiable reference to something inside the function — usually a private data member in a class. 
This should be used sparingly and carefully, since it exposes the internal state and lets the caller change it directly. That use case shows up more when building custom data structures or container classes, 
like a matrix implementation.
## std::swap and std::move
Alot of the previous sections have talked about moving as a replacement for copying, and another good example of this is with swap(). The basic algorithm for a swap between two values 
is to make a temporary variable, store the first value in that variable, set the first value to the second value, then finally set the second value to the temporary variable. It looks something
like this:  
int swap(double& x, double& y) {
double temp = x;
x = y;
y = temp;
}  
This is alright until you have bigger objects being swapped. Then you have to make a whole copy of that object. If x and y were instead a vector, this copy would be very expensive. So instead of copies
we can do moves. The problem here, however, is that x and y are lvalues. They cannot be moved, only copied. For this, the std::move() can be used which essentially tells the compiler to treat a
certain value like an rvalue. So instead of copying temp into x and then back again, you would write  
int swap(double& x, double& y) {
double temp = std::move(x);
x = std::move(y);
y = std::move(temp);
}  
Under the hood, swap() is just a type cast that converts an lvalue to an rvalue. This allows for more efficient swaps with objects that might take up more memory.
## The Big-Five: Destructor, Copy Constructor, Move Constructor, Copy Assignment operator=, Move Assignment operator=
### Destructor
The destructor is called whenever an object goes out of scope. It frees up any memory that were taken up by the use of the object. The default constructor applies this 
to every data member.
### Copy and Move Constructors
To create a new object initialized to the same state as another object, the copy and move constructors are called. As any other object, copy is for lhand and move is for
rhand values. A copy or move constructor can be called when another object is being initialized (Object B = C; <- NOT THE SAME AS B = C), when an object is passed into a function
using call-by-value, and if an object is returned by value. Copy constructors, by default, are implemented by applying copy constructors to each data member of the object being copied.
### Copy *Assignment* and Move *Assignment* (operator=)
This is similar, but not the same as the constructors, as now the operator is being applied to objects that have already been previously constructed. Like the 
traditional assignment operator, it is simply *lhs*=*rhs*. If rhs is an lvalue, then the copy assignment operator is applied, and if rhs is an rvalue, then the
move assignment operator is applied. Similar to the constructors, this is done by applying these operators on the data members themselves.
### Defaults
The defaults of the big five are not always acceptable. If a pointer data member is declared with the *new* keyword, it must also be deleted. The default destructor does
not do this, and in turn, this causes a memory leak. Also, if the copy constructor or copy assignment operator copies the value of that data member, it will not 
make a clone or a *deep copy*, but will instead create a shallow copy, which makes two instances of a class that point to the same object. To solve this problem,
the big 5 will be implemented manually. This removes the defaults, making the programmer implement all five. If you do not want a certain one, say the copy assignment
operator, you can use *Object& operator=(Object && rhs) = delete* to explicitly disallow this.
### C-style Arrays and Strings
C++ includes built-in support for C-style arrays, but they’re pretty low-level and come with a lot of issues. When you write int arr1[10];, 
you're creating an array of 10 integers, but what you're really getting is a constant pointer to a block of memory. It's not a real object like a vector.
You can’t assign arrays with arr1 = otherArray; because you're trying to assign to a pointer that can't change. Also, when you pass arr1 into a function, 
you're only passing the pointer, not the whole array. That means the function has no idea how big the array is, so you always have to pass the size separately. 
On top of that, there's no index checking, so if you go out of bounds, it's on you to catch it. Another issue is that the size must be known at compile time. 
You can’t write int arr[n]; if n is a variable. If you want a dynamic array, you have to manually allocate memory like this: int* arr2 = new int[n];. This works,
but since you used new, you also have to call delete[] arr2; when you're done. If you forget, you leak memory, and the leak can be huge if the array is large. 
C-style strings are just arrays of characters. To tell where the string ends, they use a special character called the null terminator ('\0'). Functions like strlen, 
strcpy, and strcmp are used to deal with these strings. But again, they have no safety built in. If you try to copy a string into an array that’s too small, or you 
forget space for the null terminator, your program might crash or behave unpredictably. Modern C++ gives you std::vector and std::string so you don’t have to deal
with all this directly. These classes wrap around dynamic memory and handle everything for you. They're safer, cleaner, and way easier to work with. Unless you're 
dealing with C libraries or extremely performance-sensitive code, you should always use vector and string instead of the C-style versions.
# 1.6 Templates
It's preferred to write algorithms that are type independent, as to avoid writing redundant code for each data type.
## Function Templates
Function templates are not actual functions, but patterns for what could be a function. You declare a function as a function template by writing template<typename something>, 
where something is your template argument. In this case, something can be replaced by any type to generate a function. For example if I had a function  
template<typename T>  
const T & foo(const vector<T> & x) {}  
then I am able to call foo on a vector<int>, vector<string>, vector<user_defined_object>, etc. However, every time you use a new type on the template, the compiler will generate
a whole new version of the function for that type. If the function is called on many different types, this leads to code bloat. For template functions, it is common to include 
comments about the assumptions about what type of constructors, destructors, or operators the type must have to avoid compile-time errors from trying to use a type that is not 
supported by the template function. Also, most if not all template functions will assume that the types are not primitive data-types, meaning that a constant reference is to be 
used to avoid expensive copies. Templates can get tricky when the compiler tries to figure out which version of a function to call. If a non-template version and a template both
match, the non-template wins. If two templates are both "close enough," but neither is a perfect match, the compiler just gives up and throws an ambiguity error. So while 
templates are powerful, they come with a lot of compiler rules that can get pretty weird if you're not careful.
## Class Templates
Class templates work like function templates. Instead of writing a separate class for each data type, you can write one template that works for any type. In the example, 
MemoryCell is a class template that acts like a simple container. It stores a value and lets you read or write it. Instead of being limited to just int like IntCell was, it 
can store any type, like MemoryCell<int> or MemoryCell<string>. The template uses Object as a placeholder for the type. When you create a MemoryCell<int>, the compiler 
replaces Object with int everywhere inside the class. The constructor takes a const Object& as a parameter and sets the stored value. If you don’t pass anything in, it 
defaults to Object{}, meaning it calls the default constructor for that type. This is safer than using 0, since 0 might not make sense for something like a string or custom class.
Inside the MemoryCell, the stored value is kept private, and you interact with it using the read and write functions. Read returns a constant reference so you don't accidentally 
modify the value, and write takes a constant reference to avoid unnecessary copies. Also, class templates are usually implemented entirely in header files. This is because 
many compilers don’t handle separating the implementation into a .cpp file very well. So instead of splitting the class into a header and source file, most template classes 
just keep everything in one .h file. That’s how the STL is written too. You can separate them if you really want to, but it adds extra syntax and tends to be annoying, 
which is why most people don’t bother unless they have to.
## Object, Comparable, and an Example
Example of how to make templates work with generic code.
## Function Objects
a generic function template like findMax typically works only if the type being compared defines operator<, but this can be limiting when working with custom types or when 
the desired comparison is different from the default. For example, comparing rectangles by area or strings in a case-insensitive way cannot rely on operator< alone. To make 
findMax more flexible, you can pass a separate comparison function that specifies how to compare two objects. Instead of using a plain function pointer, which is less efficient 
and cannot carry state, C++ commonly uses a function object, also called a functor, which is simply a class or struct with a operator() defined. This allows the compiler to inline calls, 
supports stateful comparisons, integrates with templates more easily, and aligns with STL conventions.
## Seperate Compilation of Class Templates
Compiler support for seperate compilation of template classes has been weak, which is why it is common practice to put the implementation along with the interface in one file, to avoid this.
# 1.7 Using Matrices