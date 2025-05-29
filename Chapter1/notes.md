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
# 1.6 Templates
# 1.7 Using Matrices