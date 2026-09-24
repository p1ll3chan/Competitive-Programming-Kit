[1. Two Sum](https://leetcode.com/problems/two-sum/)

You are given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`_.

You may assume that each input would have **_exactly_ one solution**, and you may not use the _same_ element twice.

You can return the answer in any order.

---
# Brute Force Solution

Since the goal is the find the arr[i] and arr[j] that sum up to give the target value, obviously we case use nested forloop search of O(n^2)

---

# Hashing Map Approach O(n)

We need to maintaince the search by one as the complement value instead of two values, and store the visited value to a container that will find the two value are we process by saving for later check along the way of the next coming complement value.

Store in a <unordered_map>  // Since the order isn't nesssary to be sorted, that's headache.

What are we storing? Value : Key :: Index: Value

We don't initally store the index of the map here, that's useless;
we do it while visiting each value in the array.

```
for each value in the arr
	 complement value = target - arr[i]
	 check if the complement value is already visited in the map,if YES 
		 output {complement,arr[i]}
	 insert the	map[arr[i]] = i
 if nothing found;
	 return "There isn't a single one or two!!"

```


---


