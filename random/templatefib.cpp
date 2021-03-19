#include <iostream>
using std::cout;
using std::endl;

template <unsigned int i> 
struct Fibo{
    static const unsigned result = Fibo<i-1>::result + Fibo<i-2>::result;
};
/*Or:
template <unsigned int T>
struct Fibo {
    enum {value = Fibo<T-1>::value + Fibo<T-2>::value};
    };
}
*/
template <>
struct Fibo<0>{
    static const unsigned result = 1;
};

template <>
struct Fibo<1>{
    static const unsigned result = 1;
};

int main () {
    cout << Fibo<5>::result << endl;
   
    return 0;
}
/*
I see that the other answers cover the alternative approaches well, but no one's explained why the enum (or static const int) is required.

First, consider the following non-template equivalent:

#include <iostream>

int Factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * Factorial(n-1);
}

int main()
{
    std::cout << Factorial(5) << std::endl;
    std::cout << Factorial(10) << std::endl;
}
You should be able to understand it easily. However, it's disadvantage is that the value of the factorial will be computed at run-time, i.e. after running your program the compiler will execute the recursive function calls and calculations.

The idea of template approach is to perform the same calculations at compile-time, and place the result in the resulting executable. In other words, the example you presented resolves to something alike:

int main()
{
    std::cout << 120 << std::endl;
    std::cout << 3628800 << std::endl;
}
But in order to achieve that, you have to 'trick' the compiler into performing the computations. And in order to do that, you need to let it store the result somewhere.

The enum is there exactly in order to do that. I will try to explain that by pointing out what would not work there.

If you tried to use a regular int, it would not work because a non-static member like int is meaningful only in a instantiated object. And you can't assign a value to it like this but instead do that in a constructor. A plain int won't work.

You need something that would be accessible on an uninstantiated class instead. You could try static int but it still doesn't work. clang would give you a pretty straightforward description of the problem:

c.cxx:6:14: error: non-const static data member must be initialized out of line
                static int value=n*Factorial<n-1>::value ;
                           ^     ~~~~~~~~~~~~~~~~~~~~~~~
If you actually put those definitions out-of-line, the code will compile but it will result in two 0s. That is because this form delays the computation of values to the initialization of program, and it does not guarantee the correct order. It is likely that a Factorial<n-1>::values was obtained before being computed, and thus 0 was returned. Additionally, it is still not what we actually want.

Finally, if you put static const int there, it will work as expected. That's because static const has to be computed at the compile time, and that's exactly what we want. Let's type the code again:

#include <iostream>

template <unsigned n>
struct Factorial
{
    static const int value=n*Factorial<n-1>::value ;
};

template <>
struct Factorial<0>
{
    static const int value=1;
};

int main()
{
    std::cout << Factorial<5>::value << std::endl;
    std::cout << Factorial<10>::value << std::endl;
}
First you instantiate Factorial<5>; static const int forces the compiler has to compute its value at compiler time. Effectively, it instantiates the type Factorial<4> when it has to compute another value. And this goes one until it hit Factorial<0> where the value can be computed without further instantiations.

So, that was the alternate way and the explanation. I hope it was at least a bit helpful in understanding the code.

You can think of that kind of templates as a replacement of the recursive function I posted at the beginning. You just replace:

return x; with static const int value = ...,
f(x-1) with t<x-1>::value,
and if (n == 0) with the specialization struct Factorial<0>.
And for the enum itself, as it was already pointed out, it was used in the example to enforce the same behavior as static const int. It is like that because all the enum values need to be known at compile-time, so effectively every requested value has to be computed at compile-time.


*/