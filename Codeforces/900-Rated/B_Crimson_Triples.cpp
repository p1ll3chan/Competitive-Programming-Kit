#include <bits/stdc++.h>
using namespace std;

/*
gcd∗(lcm†(a,b),lcm(b,c))=gcd(a,c)

To satistfy the expression relation of the problem is altered into, that is
to co-relate the term b being divisble to both a and c.

* and †,are just notation to direct us to the expression.

gcd(gcd(a,b),gcd(b,c))=gcd(a,c)

---
The right side become => gcd(a,b,c)

let gcd(a,c) -> g
1) How many b we need?
    So b which is 1<=b<=n should be divisible to g.
    So number of possible b's are [n/g].


2) How many pair of a,c be need? <any-order-plz>
    here, 1<=x,y<=n/g

    We know can make like this,
    if gcd(a,c) -> g;
    Then -> a=gx & c=gy

    So gcd(gx,gy) => g * gcd(x,y);

    Which states that gcd(x,y) = 1;

    Theorthically it means x and y pair must be co-prime.

3) How many pair of co-prime (x,y), must be choose for each g, where gx<n & gy<n ?

INSERTING <Euler's totient function>
    -> E(n) -> Number of prime number less than and relative to n;
    -> Eg : E(5) -> [1,2,3,4];      => So ans= 4
             gcd(1,5)=1
             gcd(2,5)=1
             gcd(3,5)=1
             gcd(4,5)=1
            E(8) -> [1,2,3,4,5,6,7] => So ands= 4
             gcd(1,8)=1
             gcd(2,8)=2
             gcd(3,8)=1
             gcd(4,8)=4
             gcd(5,8)=1
             gcd(6,8)=2
             gcd(7,8)=1
4) 

The key result
Euler's totient function (phi(k)) is:
phi(k)=Number of integers 1<=> x <= k, such that gcd(x,k)=1

So for a fixed (y=k), the number of (x<k) satisfying
    gcd(x,k)=1
is exactly: phi(k)

---

Solution : Summation of N/g till n from g=1 * (2*[Summation of phi function till N/g from k=1]+1)

But since b is divislbe to both a and c here,

the equality holds.
Therefore, for each (b), there are exactly  n/b choices for (a) and the same number for (c).
The answer is simply!!
*/

int EulorTolFun(int n){
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(__gcd(i,n)==1)  cnt++;
    }
    return cnt;
}

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        long long ans=0;
        for (int i = 1; i <= N; i++)
        {
            long long cnt=N/i;
            ans+=1ll*cnt*cnt;
        }   
        
        cout<<ans<<endl;
    }
    return 0;
}