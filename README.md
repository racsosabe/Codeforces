# Codeforces
Codeforces problems that I could solve :,'v


## 628A: Tennis Tournament

This problem is stated <a href="http://codeforces.com/contest/628/problem/A">here</a>.
<br>
### Solution
The solution consists basically in the simulation of the events and counting. First of all, each match would require to spend *2b+1* bottles, because there are *b* bottles for each of the players and one for the judge. Also, the number of matches that will be played in a determined round is 2<sup>(&lfloor;logn&rfloor;-1)</sup>, and the rest of the competitors pass directly to the next round. Finally, the number of towels used are just *np*, because each player receives *p* towels for the whole tournament.
<br>
Since we want 2<sup>(&lfloor;logn&rfloor;-1)</sup> for each *n*, that is the **Most Significant Bit** of *n*, which is easy to compute for numbers that fix into a 32-bit integer. The simulation should stop when the number of players is 1 and we should set a counter for the matches. The answers will be *counter.match* and *np*. The function msb(n) computes the value of highest the power of 2 that is not greater that n.

<pre>Algorithm</pre>
<br>
<pre>
match = 2*b+1
towels = np
counter = 0
while(<em>n != 1</em>)
  counter += msb(n)/2
  n = (msb(n))/2 + n - msb(n)
Print counter*match," ",towels
End
</pre>

## 630A: Again Twenty Five!
This problem is stated <a href="http://codeforces.com/contest/630/problem/A">here</a>.
<br>
### Solution
The solution consists basically in printing the last 2 numbers of 5<sup>n</sup> with n&gt;2. We should proove by induction that the answer is always 25.
<ol>
<li> 5<sup>2</sup> = 25. Nothing to proof.</li>
<li> Assume that 5<sup>n</sup> mod 100 = 25. Inductive Hypothesis.</li>
<li> We know that 5<sup>n</sup> = 100k + 25, then 5.5<sup>n</sup> = 5(100k+25) = 500k+125 = 100(5k+1) + 25, so 5<sup>(n+1)</sup> mod 100 = 25.</li>
</ol>
<br>
<pre>Algorithm</pre>
<br>
<pre>
Print 25
End
</pre>

## 630B: Moore's Law
This problem is stated <a href="http://codeforces.com/contest/630/problem/B">here</a>.
<br>
### Solution
The solution consists basically in computing the value of f(t), with 
<ul>
<li>f(0) = n.</li>
<li>f(t) = 1.000000011.f(t-1), t&gt;0. </li>
</ul>

It's simple to verify that f(t) = 1.000000011<sup>t</sup>.n, so we need to compute this value in less than *O(t)*, because *t* is at most 2.10<sup>9</sup>. Fortunately, there exists the fast exponentiation algorithm, which computes the value of a<sup>b</sup> in *O(log(b))*. Besides that, there's nothing else to explain.
<br>
<pre>Fast Exponentiation Algorithm</pre>
<br>
<pre>
expfast(x,n)
  ans = 1
  while(<em>n</em>)
    if(<em>&amp;1</em>)
      ans = ans*x
      n = n-1
    else
      a = a*a
      n = n/2 // We could use n = n>>1
  return ans
</pre>
<br>
<pre>Algorithm</pre>
<br>
<pre>
Print expfast(1.000000011,t)*n with at least 6 decimals
End
</pre>

## 630C: Lucky Numbers
This problem is stated <a href="http://codeforces.com/contest/630/problem/C">here</a>.
<br>
### Solution
This solution consists basically in counting the quantity of posible numbers exist with no more than *n* digits and formed by only 7's and 8's. Considering that we only have 2 posibilities per digit, then the quantity of numbers with *l* digits woudl be 2<sup>l</sup>. Since we want **all** the quantities from numbers with digits from *1* to *n*, then we should compute &sum;q(i) with i &in; [1,n].
<br>
Therefore, the answer for each *n* is: 2<sup>1</sup> + 2<sup>2</sup>+...+2<sup>n</sup>. We should know that the sum from 2<sup>0</sup> to 2<sup>n</sup> is 2<sup>(n+1)</sup> - 1, then 2<sup>1</sup> + 2<sup>2</sup>+...+2<sup>n</sup> = 2<sup>(n+1)</sup> - 1 - 2<sup>0</sup> = 2<sup>(n+1)</sup> - 2.
<br>
A fast way to compute this (it's not really necessary for this problem, though) is **bit shifting**, so we will shift a number *1* *n+1* times and then substract 2. Remember that the maximum number of direct shifts in C++ is 31 because is suported for 32-bit integers. In order to prevent overflow, we should store the answer into a **long long**.
<br>
<pre>Algorithm</pre>
<br>
<pre>
q = 1
If <em>n&lt;32</em>
  Print 1&lt;&lt;(n+1) - 2
Else
  q = q&lt;&lt;31
  n = n - 31
  Print 1&lt;&lt;(n+1) - 2
End
</pre>

## 630J: Divisibility
This problem is stated <a href="http://codeforces.com/contest/630/problem/J">here</a>.
<br>
### Solution
The solution consists basically in counting the quantity of numbers that are between *1* and *n* that are divisible by 2,3,4,5,6,7,8,9,10. It's very simple to show that the answer is just *n/mcm(2,3,4,5,6,7,8,9,10)*. We can compute previously that mcm(2,3,4,5,6,7,8,9,10) = 2520, so we just return n/2520.
<br>
<pre>Algorithm</pre>
<br>
<pre>
Print n/2520
End
</pre>


## 633A: Ebony and Ivory

This problem is stated <a href="https://codeforces.com/contest/633/problem/A">here</a>.
<br>
### Solution
The solution consists basically in verifying wheter the equation *`ak+bt=c`* has at least a non-negative solution for *`(k,t)`*. As this is a diophantine equations, it has infinite integer solutions if and only if *gcd(a,b)|c* (*c mod gcd(a,b) = 0*). Therefore, we should start checking this condition before moving to the actual answer.
<br>
If the *gcd(a,b)* does divide *c*, considering that *`c < 10001`* and that *`a > 0`*, then the value of *`-1 < c-ak < 10001`*, so we can iterate through *k* and it will do at most *c/a+1* operations (10001 operations max). For each iteration we should check if the remaining from the substraction is a multiple of *b*.
<br>
<pre>Algorithm</pre>
<br>
<pre>
If <em>c mod gcd(a,b) = 0</em>
  For <em>k=0</em> to <em>k=c/a</em>
    If <em>(c-ak) mod b = 0</em>
      Print <em>"Yes"</em>
      End
  Print "No"
Else
  Print "No"
End
</pre>
