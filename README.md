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
