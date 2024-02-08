## USACO Bronze


<!-- MarkdownTOC levels="1,2" autolink="true" autoanchor="true"-->

- [Complete Search:](#complete-search)
   - [2020 Daisy Chains](#2020-daisy-chains)
   - [2016 Milk Pails](#2016-milk-pails)

<!-- /MarkdownTOC -->



# Complete Search: 


## [2020 Daisy Chains](http://www.usaco.org/index.php?page=viewproblem2&cpid=1060)


### Problem Summary
Bessie the cow, during her farm walk, takes photos of flowers in a row. Each flower has a specific number of petals. For every pair of flowers, she captures all flowers between them. Bessie wonders how many photos have an "average flower," defined as a flower with the exact average number of petals among all flowers in the photo.

### Input
- The first line contains an integer N (1≤N≤100) representing the number of flowers.
- The second line contains N space-separated integers p1…pN (1≤pi≤1000) representing the number of petals for each flower.

### Output
- Print the number of photos that have an average flower.

### Example
**Input:**
4
1 1 2 3

**Output:**
6

**Explanation:**
Every photo with a single flower contributes to the count (4 in total). Additionally, the ranges (1,2) and (2,4) correspond to photos with an average flower.

### Solution
It systematically explores all possible combinations of flowers to determine whether the current set of flowers forms a photo with an average flower.
```cpp
int photos = 0;
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        int totalPetals = 0;
        for (int k = i; k <= j; k++) {
            totalPetals += petals[k];
        }

        bool present = false;
        for (int k = i; k <= j; k++) {
            if (petals[k] * (j - i + 1) == totalPetals) {
                present = true;
            }
        }

        if (present) {
            photos++;
        }
    }
}

```


## [2016 Milk Pails](http://www.usaco.org/index.php?page=viewproblem2&cpid=615)

### Problem Summary
Farmer John needs to fill an order of M units of milk using three pails with sizes X, Y, and M (where 1 ≤ X < Y < M). The milking machine is broken, and he can perform two types of operations: filling the smallest pail (of size X) or the medium-sized pail (of size Y) and pouring it into the size-M pail without causing overflow. Determine the maximum amount of milk Farmer John can add to the size-M pail.


**Input:**
- Three integers X, Y, and M separated by spaces.

**Output:**
- Output the maximum amount of milk Farmer John can add to the size-M pail.

**Example:**
**Input:**
17 25 77

**Output:**
76


In this example, Farmer John fills the pail of size 17 three times and the pail of size 25 once, accumulating a total of 76 units of milk.

**Explanation:**
Farmer John fills the smallest pail three times (17 + 17 + 17 = 51) and the medium-sized pail once (25). The total amount of milk added to the size-M pail is 76.
```cpp
// Loop over how many times we can pour the X-size bucket
for (int xPour = 0; xPour * x <= m; xPour++) {
    // Loop over how many times we can then pour over the Y-size bucket
    for (int yPour = 0; xPour * x + yPour * y <= m; yPour++) {
        // Determine if we have filled the bucket more than any previous time
        if (xPour * x + yPour * y > ans) {
            ans = xPour * x + yPour * y;
        }
    }
}
```
