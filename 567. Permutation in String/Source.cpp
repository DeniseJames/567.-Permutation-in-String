/*
	Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

	In other words, return true if one of s1's permutations is the substring of s2.

*/

#include <vld.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string my_generate(int k, string s, vector<string>& vs);
bool checkInclusion(string s1, string s2)
{
	// determine string size
	int s1_size = s1.length();
	// determine vector size !vec_size
	int vec_size = 1;
	for (int  i = s1_size; i > 0 ; i--)
	{
		vec_size = vec_size * i;
	}

	vector<string> vs;
	
	my_generate(s1_size, s1, vs);

	// Iterate through vector of strings to see if s2 contains
	// the permutation
	for (int j = 0; j < vec_size; j++)
	{
		if (s2.find(vs[j])!=-1)
		{
			return true;
		}
	}
	return false;
}

/*
	Get permutations of a string using Heap's Algorithm
	https://en.wikipedia.org/wiki/Heap%27s_algorithm
	https://www.youtube.com/watch?v=AUmI9Kx9Qag

*/

string my_generate(int k, string s, vector<string> &vs)
{

	if (k == 1)
	{
		cout << s << endl;
		vs.push_back(s);
		return s;

	}
	else
	{
		// Generate permutations with k-th unaltered
		// Initially k = length(s)
		my_generate(k - 1, s, vs);
		// Generate permutations for k-th swapped with each k-1 initial
		for (int i = 0; i < k-1; i++)
		{
			
			// Swap choice dependent on parity of k (even or odd)
			if (k % 2 == 0)
			{
				swap(s[i], s[k - 1]); // zero-indexed, the k-th is at k-1
			}
			else
			{
				swap(s[0], s[k - 1]);

			} // end if/else
			

			my_generate(k - 1, s, vs);
		} // end for
		
	} // end if/else
	
	return s;
}

int main()
{


	string s1 = "ABCD", s2 = "eidboaoo", s3 = "abc";
	// string s1 = "ab", s2 = "eidbaooo";
	 cout << " Is a permutation of s1 included in s2 " << boolalpha << checkInclusion(s1, s2) << endl;
	
}
/*
Console Output:

Visual Leak Detector read settings from: C:\Program Files (x86)\Visual Leak Detector\vld.ini
Visual Leak Detector Version 2.5.1 installed.
ABCD
BACD
CBAD
BCAD
ABCD
BACD
DBCA
BDCA
CBDA
BCDA
DBCA
BDCA
DACB
ADCB
CADB
ACDB
DACB
ADCB
DABC
ADBC
BADC
ABDC
DABC
ADBC
 Is a permutation of s1 included in s2 false
No memory leaks detected.
Visual Leak Detector is now exiting.


*/