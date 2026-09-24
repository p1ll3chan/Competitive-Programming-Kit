Given an unsorted array of integers `nums`, return _the length of the longest consecutive elements sequence._

You must write an algorithm that runs in `O(n)` time.

---

# Gready Approach [BF]

Have a Max_val counter and a index wise counter

Throgh the given array;

	Checking if the next vakue in the right is equal to the present value + 1 ->       If Yes count that
	
	else reset the count;
	
	{Special case} => If Next Value is equal to the present value -> "Don't count      and move on.

	 Update the Max_val with prev_max_val with the cnt in each turn.


Since we are not looking the till the n-1 index, where n is the size of the array

Answer is Max_val + 1;

---

