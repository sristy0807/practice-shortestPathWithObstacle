# Shortest Path with K Obstacles

## 📝 Problem Overview
You're given an **m × n** grid where:

- `0` represents an **empty cell** you can walk through  
- `1` represents an **obstacle**

You start at the **top-left corner** `(0, 0)` and must reach the **bottom-right corner** `(m-1, n-1)`.

You are allowed to **eliminate up to K obstacles** while finding the path.

Your goal is to determine the **shortest possible path length** under these rules.  
If no such path exists, return **-1**.

---

## 🧠 Key Idea
You cannot treat each `(x, y)` cell as a single state because the number of remaining obstacle removals (`k`) affects whether future paths are possible.

So the real BFS state is:

(x, y, remaining_k)


We track a 3D `visited[x][y][remaining_k]` array.

---

## 📌 Example

### Grid (3 × 3), K = 1
0 0 0
1 1 0
0 0 0


**Output: `4`**

You can remove one obstacle and take the shortest valid path of length 4.

---

