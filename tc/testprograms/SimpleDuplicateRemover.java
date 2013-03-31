// BEGIN CUT HERE
// PROBLEM STATEMENT
// We have a sequence of integers. We want to remove duplicate elements from it.
You will be given a int[] sequence. For each element that occurs more than once leave only its rightmost occurrence. All unique elements must be copied without changes.


DEFINITION
Class:SimpleDuplicateRemover
Method:process
Parameters:int[]
Returns:int[]
Method signature:int[] process(int[] sequence)


CONSTRAINTS
-sequence will have between 1 and 50 elements, inclusive. 
-Each element of sequence will be between 1 and 1000, inclusive. 


EXAMPLES

0)
{1,5,5,1,6,1}

Returns: {5, 6, 1 }

We left the third 1, the second 2 and the only 6.

1)
{2,4,2,4,4}

Returns: {2, 4 }

2)
{6,6,6,6,6,6}

Returns: {6 }

3)
{1,2,3,4,2,2,3}

Returns: {1, 4, 2, 3 }

4)
{100,100,100,99,99,99,100,100,100}

Returns: {99, 100 }

// END CUT HERE
import java.util.*;
public class SimpleDuplicateRemover {
	public int[] process(int[] sequence) {
		
	}
	public static void main(String[] args) {
		SimpleDuplicateRemover temp = new SimpleDuplicateRemover();
		System.out.println(temp.process(int[] sequence));
	}
}
