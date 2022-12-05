/* C++ program to print a fraction in Egyptian Form using Greedy Algorithm*/
/*Efficient Approach */

/*
Every positive fraction can be represented as sum of unique unit fractions. 
A fraction is unit fraction if numerator is 1 and denominator is a positive integer, 
for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction as it was used by ancient Egyptians. 

Following are a few examples: 

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156
We can generate Egyptian Fractions using Greedy Algorithm. For a given number of the form ‘nr/dr’ where dr > nr, 
first find the greatest possible unit fraction, then recur for the remaining part. For example, consider 6/14, we first find ceiling of 14/6, i.e., 3. 
So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42. 

*/
#include <bits/stdc++.h>
using namespace std;
void egyptianFraction(int n, int d)
{
//When Both Numerator and denominator becomes zero then we simply return;
	if (d == 0 || n == 0)
		return;
	if (d % n == 0) {
		cout << "1/" << d / n;
		return;
	}
	if (n % d == 0) {
		cout << n / d;
		return;
	}
	if (n > d) {
		cout << n / d << " + ";
		egyptianFraction(n % d, d);
		return;
	}
	int x = d / n + 1;
	cout << "1/" << x << " + ";
	egyptianFraction(n * x - d, d * x);
}
int main()
{
	int numerator = 6, denominator = 14;
	cout << "Egyptian Fraction representation of "
		<< numerator << "/" << denominator << " is"
		<< endl;
	egyptianFraction(numerator, denominator);
	return 0;
}
