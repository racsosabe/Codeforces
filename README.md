# Codeforces
Codeforces problems that I could solve :,'v


## 633A: Ebony and Ivory

This problem is stated [here]("https://codeforces.com/contest/633/problem/A").
<br>
### Solution
The solution consists basically in verifying wheter the equation *`ak+bt=c`* has at least a non-negative solution for(k,t). As this is a diophantine equations, it has infinite integer solutions if and only if *`gcd(a,b)|c`* (*`c mod gcd(a,b) = 0`*). Therefore, we should start checking this condition before moving to the actual answer.
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
      <em>End</em>
  Print "No"
Else
  Print "No"
End
</pre>
