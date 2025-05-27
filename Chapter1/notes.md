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
$H_N = \displaystyle\sum_{i=1}^N \frac{1}{i} \approx$ log$_eN$  
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
# 1.4 C++ Classes
# 1.5 C++ Details
# 1.6 Templates
# 1.7 Using Matrices