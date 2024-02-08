## USACO Bronze

Complete Search: 

2020 [Daisy Chains](http://www.usaco.org/index.php?page=viewproblem2&cpid=1060)


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
