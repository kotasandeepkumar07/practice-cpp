// Vector.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream> 
#include <string>




using namespace std;

/***************************  Custom Vector class ***********************************/

//class myVector
//{
//private:
//	
//	int	m_nSize;
//	int	m_nCapacity;
//
//public:
//	int*	m_nArray;
//	myVector()
//	{
//		m_nArray = new int[1];
//		m_nSize = 0;
//		m_nCapacity = 1;
//	}
//
//	~myVector()
//	{
//		delete[] m_nArray;
//	}
//
//	void Push_back(int data)
//	{
//		if (m_nSize == m_nCapacity)
//		{
//			int *temp = new int[2 * m_nCapacity];
//
//			for (int i = 0; i < m_nCapacity; i++)
//			{
//				temp[i] = m_nArray[i];
//			}
//
//			delete[] m_nArray;
//			m_nCapacity = m_nCapacity * 2;
//			m_nArray = temp;
//		}
//
//		m_nArray[m_nSize] = data;
//		m_nSize++;
//	}
//
//	//overload subscript operator
//	int operator[]( int index) 
//	{
//		return m_nArray[index];
//	}
//
//	//get size
//	int getSize() const
//	{
//		return m_nSize;
//	}
//
//	//get capacity
//	int getCapacity() const
//	{
//		return m_nCapacity;
//	}
//
//	//copy constructor
//	myVector(myVector& newobj)
//	{
//		m_nSize = newobj.getSize();
//		m_nCapacity = newobj.getCapacity();
//		m_nArray = new int[m_nCapacity];
//
//		for (int i = 0; i < m_nCapacity; i++)
//		{
//			m_nArray[i] = newobj.m_nArray[i];
//		}
//	}
//
//	bool operator==(const myVector& rhs)
//	{
//		if (getSize() != rhs.getSize()) return false;
//
//		for (int i = 0; i < getSize(); i++)
//		{
//			if (m_nArray[i] != rhs.m_nArray[i])
//				return false;
//		}
//		return true;
//	}
//
//	friend std::ostream operator<<(const ostream& stream, const myVector& vec);
//};
//
//std::ostream& operator<<(ostream& stream, const myVector& vec)
//{
//	for (int i = 0; i < vec.getSize(); i++)
//	{
//		stream << vec.m_nArray[i] << " ";
//	}	
//
//	return stream;
//}

//void main()
//{
//	myVector obj;
//	obj.Push_back(10);
//	obj.Push_back(20);
//	obj.Push_back(30);
//
//	//this works because ofoverloading copy constructor
//	myVector V2 = obj;
//
//	//this prints all values because we overloaded  << operaor for vector
//	cout << V2 << endl; 
//
//
//	myVector newobject;
//	newobject.Push_back(10);
//	newobject.Push_back(20);
//	newobject.Push_back(30);
//
//	//overloading ==  operator to check if two vectors are equal
//	bool bval  = ( obj == newobject );
//
//	int i = 10;
//}


//void main()
//{
//
//	//list <int> gqlist1, gqlist2;
//	//gqlist1.push_back(10);
//	//gqlist1.push_back(10);
//
//	//auto it = gqlist1.begin();
//
//	//while (it != gqlist1.end())
//	//{
//	//	cout<< *it << endl;
//	//	it++;
//	//}
//
//
//	/*std::vector<int> vect = { 10, 20, 40, 30, 40, 50 };
//
//	vect.insert(vect.begin(), 2);
//
//	auto it = vect.cbegin();
//	*it = 10;*/
//
//	//vector<int> arr1 = { 1, 4, 6, 3, 2 };
//
//	//// initializing 2nd container 
//	//vector<int> arr2 = { 6, 2, 5, 7, 1 };
//
//	//// declaring resultant container 
//	//vector<int> arr3(10);
//
//	//// sorting initial containers 
//	//sort(arr1.begin(), arr1.end());
//	//sort(arr2.begin(), arr2.end());
//
//	//// using merge() to merge the initial containers 
//	//merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());
//
//	//vector<int> vect(3, 0);
//
//	//vector<int> v(3, 0);
//	//v.assign(vect.begin(), vect.end());
//
//	//cout << v.size() << endl;
//
//	//std::remove(vect.begin(), vect.end(), 40);
//	//////vect.erase(std::find(vect.begin(), vect.end(), 4));
//	//for (int test : arr3)
//	//	cout << test << endl;
//	//std::vector<int> vect = { 10, 20, 30, 30, 20, 10, 10, 20 };
//
//	//std::remove(vect.begin(), vect.end(), 20);
//
//	///*for (int test : vect)
//	//	cout << test << endl;*/
//
//	////std::vector<int>::iterator pend;
//
//	//std::cout << "Range contains:";
//	//for (std::vector<int>::iterator p = vect.begin(); p != vect.end(); ++p)
//	//	std::cout << ' ' << *p; std::cout << '\n';
//
//	//int i;
//	//cin >> i;
//
//
//	std::vector<int> v = { 15, 2, 33, 65, 9, 12,  };
//	std::sort(v.begin(), v.end());
//	/*auto it = v.begin();
//
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}*/
//
//	for (auto i : v)
//	{
//		cout << i << endl;
//	}
//
//}

//class Solution
//{
//public:
//
//	int reverse(int x)
//	{
//		if (x < -2^(31) || x  > 2^(31) - 1)
//			return -1;
//
//		int nNums = 0;
//		int res = 0;
//		int a = x;
//		while (a > 0)
//		{
//			a = a / 10;
//			nNums++;
//		}
//
//		for (int i = 0; i < nNums; i++)
//		{
//			int reminder = x % 10;
//			res = (res * 10) + reminder;
//			x = x / 10;
//		}
//
//		return res;
//	}
//};
//
//void main()
//{
//	Solution test;
//	test.reverse(123);
//
//}


//
//bool Ispallindrome(int x)
//{
//	if (x < 0)
//		return false;
//
//	int ntemp = x;
//	int nRev = 0;
//	int number = 0;
//
//	while (x > 0)
//	{
//		nRev  = x % 10;
//		number = (number * 10) + nRev;
//		x = x / 10;
//	}	
//
//	if (ntemp == number)
//		return true;
//	else
//		return false;
//}
//
//void main()
//{
//	Ispallindrome(-123);
//	Ispallindrome(123);
//}

//class Solution 
//{
//public:
//	int lengthOfLastWord(string s)
//	{
//		int n =0;
//		bool b = false;
//		if (s.length() <= 0)
//			return 0;
//
//		for (int i = 0; i < s.length(); i++)
//		{
//			if (s[i] == ' ')
//			{
//				n = i;
//				b = true;
//			}
//		}
//
//		int len = 0;
//		string strTemp(s, n);
//
//		if ( b )
//			len = strTemp.length() - 1;
//		else
//			len = strTemp.length();
//		return len;
//	}
//};
//
//
//
//void main()
//{
//	Solution str;
//	str.lengthOfLastWord("a ");
//}
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>


//class Solution {
//public:
//	int maximumProduct(vector<int>& nums)
//	{
//		int nProduct = 1;
//		std::sort(nums.begin(), nums.end());
//		for (int i = 0; i < 3; i++)
//		{
//			vector<int>::iterator it = std::max_element(nums.begin(), nums.end() - i);
//			int n = *it;
//			nProduct = nProduct * n;
//
//		}
//
//		return nProduct;
//	}
//};




//class Solution {
//public:
//	int firstBadVersion(int nNumbers, int nbadversion) 
//	{
//		int nleft = 1;
//		int nRight = nNumbers;
//
//		int nMid = nleft + (nRight - nleft) / 2;
//
//		while (nleft < nRight)
//		{
//
//			if (isbadversion(nNumbers, nMid))
//			{
//				nRight = nMid;
//			}
//			else
//			{
//				nleft = nMid + 1;
//			}
//		}
//		return nleft;
//	}
//
//	bool isbadversion(int nNumbers, int nBadversion)
//	{
//		bool breturn = false;
//		for (int i = 0; i < nNumbers; i++)
//		{
//			if (i == nBadversion)
//			{
//				breturn = true;
//			}
//		}
//		return breturn;
//	}
//};

//class Solution {
//public:
//	int numJewelsInStones(string J, string S) 
//	{
//		int nCount = 0;
//		for (auto i : J)
//		{
//			nCount += std::count(S.begin(), S.end(), i);
//		}
//
//		return nCount;
//	}
//};


//class Solution 
//{
//public:
//	bool canConstruct(string ransomNote, string magazine) 
//	{
//		bool bRturn = false;
//
//		std::size_t found = magazine.find(ransomNote);
//		if (found != std::string::npos)
//			bRturn = true;
//
//		return bRturn;
//	}
//};


//class Solution 
//{
//public:
//
//	int findComplement(int N)
//	{
//		int sum = 0;
//		long pow = 1;
//		do		
//		{
//			if (N % 2 == 0)
//			{
//				sum = sum +  pow;
//			}
//
//			N = (N >> 1);
//
//			pow = pow * 2;
//
//		} while (N);
//
//		return sum;
//	}
//};


//class Solution
//{
//public:
//	int firstUniqChar(string s)
//	{
//
//		if (s.length() == 1) { return 1; }
//
//
//		std::map<char, int> myMap;
//
//		for (auto i : s)
//		{
//			myMap[i]++;
//		}
//
//		string str = "";
//		for (auto k : myMap)
//		{
//			if (k.second == 1)
//			{
//				str = str + k.first;
//			}
//		}
//
//		if (str.length() == 0) { return -1; }
//
//		int nIndex = 9999;
//		for (int i = 0; i < str.length(); i++)
//		{
//			int nVal = s.find(str[i]);
//			nIndex =std::min(nIndex, nVal);
//		}
//
//
//		return nIndex;
//	}
//};


//class Solution {
//public:
//	int firstUniqChar(string s)
//	{
//		unordered_map<char, int> m;
//		for (auto &c : s) 
//		{
//			m[c]++;
//		}
//
//		for (int i = 0; i < s.size(); i++) 
//		{
//			if (m[s[i]] == 1) return i;
//		}
//		return -1;
//	}
//};


//.rotate array by k units
//class Solution {
//public:
//	void rotate(vector<int>& nums, int k)
//	{
//		int nSize = nums.size();
//		nums.resize(nums.size() + k );
//		for (int i = 0; i < nums.size() - k; i++)
//		{
//			nums[nSize - 1 - i + k] = nums[nSize -1 - i] ;
//		}
//
//		int nIndex = 0;
//		for (int i = k; i > 0; i--)
//		{
//			
//			nums[i -1] = nums[nSize - 1 + k - nIndex];
//			nIndex++;
//		}
//
//		nums.resize(nSize);
//	}
//};


//return unique number 
//class Solution {
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		int x = nums[0];
//		vector<int> vect;
//
//		for (int i =1; i < nums.size(); i++)
//		{
//
//			x = x ^ nums[i];
//
//			vect.push_back(x);
//		}
//
//		return x;
//	}
//};


//Add one to the last elemnet of an array and return new array
//class Solution {
//public:
//	vector<int> plusOne(vector<int>& digits)
//	{
//		for (int i = digits.size() - 1; i >= 0; i--) 
//		{
//			if (digits[i] != 9) 
//			{
//				digits[i]++;
//				return digits;
//			}
//			else
//				digits[i] = 0;
//		}
//
//		digits.insert(digits.begin(), 1);
//		return digits;
//	}
//};


//check if all points lie on the same line
//class Solution 
//{
//public:
//
//	float findSlope(int x1, int x0, int y1, int y0)
//	{
//		if (x1 - x0 == 0 || y1 - y0 == 0)
//			return 0;
//		else
//			return (y1 - y0 / x1 - x0);
//	}
//
//
//	bool checkStraightLine(vector<vector<int>>& coordinates) 	
//	{
//		
//		if (coordinates.size() == 1) return true;
//
//		int nY1 = coordinates[1][1];
//		int nY0 = coordinates[0][1];
//
//		int nX1 = coordinates[1][0];
//		int nX0 = coordinates[0][0];
//
//		float dSlope = findSlope(nX1, nX0, nY1, nY0);
//
//		for (int i = 1; i < coordinates.size() - 1; i++)
//		{
//	
//			int nNextPointX = coordinates[i][0];
//			int nNextPointY = coordinates[i][1];
//			int nCurrentrPointY = coordinates[i - 1][1];			
//			int nCurrentrPointX = coordinates[i - 1][0];
//
//			int nDiffY = nNextPointY - nCurrentrPointY;
//			int nDiffX = nNextPointX - nCurrentrPointX;
//
//			float dNextSlope = findSlope(nNextPointX, nCurrentrPointX, nNextPointY, nCurrentrPointY);
//
//			if (dNextSlope != dSlope)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//};


////find if a number is perfect square 
//class Solution 
//{
//public:
//	bool isPerfectSquare(unsigned int num)
//	{
//
//		//using sqrt function
//		//long double sr = sqrt(num);
//		//long double test = floor(sr);
//		//// If square root is an integer 
//		//return ((sr - floor(sr)) == 0);
//
//
//
//	/*	int nLessthanVal;
//		if (num < 9)
//			nLessthanVal = num;
//		else
//			nLessthanVal = num / 2;
//
//		for (int i = 1; i < (int64_t)nLessthanVal; i++)
//		{
//			if (i * i == num)
//				return true;
//		}
//		return false;*/
//
//		/*int nSum = 0;
//		for (int i = 1; nSum < num; i = i + 2)
//		{
//			nSum = i + nSum;
//
//			if (nSum == num)
//				return true;
//		}
//
//		return false;
//	}*/
//
//
//		
//		/*for (int i = 1; i < num; i++)
//		{
//			if (i == num)
//				return true;
//
//			return false;
//		}*/
//
//		long x = 1;
//		long y = 1;
//		while (y < num)
//		{
//			x++;
//			y = x * x;
//		}
//
//		if (y == num)
//			return true;
//
//		return false;
//	}
//};


// House Robber
//class Solution 
//{
//public:
//	int rob(vector<int>& nums)
//	{
//		int ans =  getsum(nums, nums.size() - 1);
//
//		return ans;
//	}
//
//
//	int getsum(vector<int>& nums, int index)
//	{
//		if (index < 0) return 0;
//		return max(getsum(nums, index - 2) + nums[index], getsum(nums, index - 1));
//	}
//};


//class Solution
//{
//public:
//	int rob(vector<int>& nums)
//	{
//		int even_sum = 0;
//		int odd_sum = 0;
//
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			if (i % 2 == 0)
//			{
//				even_sum = max(even_sum + nums[i], odd_sum);
//			}
//			else
//			{
//				odd_sum = max(odd_sum + nums[i], even_sum);
//			}
//		}
//	
//		return max(even_sum, odd_sum);
//	}
//};

#include <stack>

//valid paranthesis
//class Solution 
//{
//public:
//	bool isValid(string s)
//	{
//		stack<char> st;
//		for (auto i : s)
//		{
//			if (i == '(' || i == '[' || i =='{')
//			{
//				st.push(i);
//			}
//			else
//			{
//				if (st.empty()) return false;
//				if (i == ')' && st.top() != '(') return false;
//				if (i == '}' && st.top() != '{') return false;
//				if (i == ']' && st.top() != '[') return false;
//				st.pop();
//			}
//		}
//
//		return st.empty();
//	}
//};



//Happy Number 
//class Solution
//{
//public:
//
//	std::vector<int> arr;
//
//	bool isHappy(int n)
//	{
//		int nSum = n;
//		do
//		{
//			nSum  = GetSumofsquares(nSum);
//			if (nSum == 1 || nSum == 7) return true;
//
//		} while (nSum > 9);
//		
//		return false;
//	}
//
//	int GetSumofsquares(int n)
//	{
//		int sum = 0;
//		while (n > 0)
//		{
//			int nreminder = n % 10;
//			sum = sum + (nreminder * nreminder);
//			n = n / 10;
//		}
//		return sum;
//	}	
//};


// Maximum Sum Circular Subarray //kadane's algorithm
//class Solution {
//public:
//	int maxSubarraySumCircular(vector<int>& A)
//	{
//
//		int nSize = A.size();
//		for (int i = 0; i < nSize - 2; i++)
//		{
//			A.push_back(A[i]);
//		}
//
//		int nMaxSumTillNow = 0;
//		int nSum = 0;
//		for (int i = 0; i < A.size(); i++)
//		{
//			if (nSum < 0)
//				nSum = 0;
//			nSum = nSum + A[i];
//			nMaxSumTillNow = max(nSum, nMaxSumTillNow);
//		}
//
//		return nMaxSumTillNow;
//	}
//};


//class Solution
//{
//public:
//
//	bool Compare(string str1, string str2)
//	{
//		return str1 < str2;
//	}
//
//
//	void Sort(vector<string>& A)
//	{
//		std::sort(A.begin(), A.end(), Compare);
//	}
//};


//Array Pair Sum
//class Solution
//{
//public:
//
//	vector<vector<int>> FindPair(vector<int> vec, int sum)
//	{
//
//		
//	}
//};



//Twin Scheduling problem:
/*
Here first we should find the difference between the array elements and then sort them according to decreasing order
so first n People will go to city A and then rest will go to city B 

For Explanation: https://www.youtube.com/watch?v=2U5KkOy9pRE
*/

//class Solution 
//{
//public:
//	int twoCitySchedCost(vector<vector<int>>& costs) 
//	{
//		int sum = 0; 
//		std::sort(costs.begin(), costs.end(), [](vector<int> &v1, vector<int> &v2) { return v1[0] - v1[1] < v2[0] - v2[1]; });
//
//		for (int i = 0; i < costs.size(); i++)
//		{
//			if ( i < costs.size() / 2 )
//				sum = sum + costs[i][0];
//			else
//				sum = sum + costs[i][1];
//		}	
//
//		return sum;
//	}
//};


//reverse a string
//class Solution {
//public:
//	void reverseString(vector<char>& s)
//	{
//		std::reverse(s.begin(), s.end());
//	}
//};


////Coin Change 2
////https://www.youtube.com/watch?v=L27_JpN6Z1Q
//class Solution 
//{
//public:
//
//	int change(int amount, vector<int>& coins)
//	{
//		vector<int> dp(amount + 1, 0);
//		dp[0] = 1;
//		for (int c : coins)
//		{
//			for (int i = c; i <= amount; i++)
//				dp[i] = dp[i] + dp[i - c];
//		}
//		return dp[amount];
//	}
//};


//isPowerOfTwo
//class Solution 
//{
//public:
//	bool isPowerOfTwo(int n)
//	{
//		for (int i = 0; i < 999999; i++)
//		{
//			/*if (pow(2, i) == n)
//				return true;
//
//			if (pow(2, i) > n)
//				return false;*/
//
//			if (log2(n) == (float)log2(n))
//				return  true;
//			else
//				return false;
//		}
//		return false;
//	}
//};



//isSubsequence
//class Solution 
//{
//public:
//	bool isSubsequence(string s, string t) 
//	{
//		int j = 0;
//		for (int i = 0; i < t.size() && j < s.size(); i++) 
//		{
//			if (t[i] == s[j])
//				j++;
//		}
//		return j == s.size();
//	}
//};

//class Solution 
//{
//public:
//	vector<int> twoSum(vector<int>& nums, int target) 
//	{
//		std::stack<int> st;
//		for (auto i : nums)
//		{
//			if (st.size() > 0)
//			{
//			
//			}
//		}
//	}
//};


//subtractProductAndSum
//class Solution 
//{
//public:
//	int subtractProductAndSum(int n) 
//	{
//		int k = 0;
//		int nSum = 0;
//		int nProduct = 1;
//		while (n != 0)
//		{
//			k = n % 10;
//			n = n / 10;
//
//			nSum = nSum + k;
//			nProduct = nProduct * k;
//		}
//
//		return nProduct - nSum;
//	}
//};


//class Solution {
//public:
//	double myPow(double x, int n)
//	{	
//		double res = 1.0;
//		for (int i = n; i >= 1; i /= 2) 
//		{
//			if (i & 1)
//				res *= x;
//
//			x *= x;
//		}
//
//		return n >= 0 ? res : 1 / res;
//		
//	}
//};


//class Solution 
//{
//public:
//	bool uniqueOccurrences(vector<int>& arr)
//	{
//		std::unordered_map<int, int> myMap;
//
//		for (auto i : arr)
//		{
//			myMap[i]++;
//		}
//
//		std::vector<int> res;
//		std::unordered_map<int, int>::iterator it = myMap.begin();
//		while (it != myMap.end())
//		{
//			res.push_back(it->second);
//			it++;
//		}
//
//		std::sort(res.begin(), res.end());
//
//		if ( std::adjacent_find(res.begin(), res.end()) != res.end() )
//			return false;
//
//		return true;
//		
//	}
//};

////Letter Combinations of a Phone Number
//class Solution 
//{
//public:
//	vector<string> letterCombinations(string digits) 
//	{
//		std::vector<char> arrAlphabets;
//		std::vector<string> arrResult;
//		for (auto i : digits)
//		{
//
//			if (i == '2')
//			{
//				arrAlphabets.push_back('a');
//				arrAlphabets.push_back('b');
//				arrAlphabets.push_back('c');
//			}
//			else if (i == '3')
//			{
//				arrAlphabets.push_back('d');
//				arrAlphabets.push_back('e');
//				arrAlphabets.push_back('f');
//			}
//			else if (i == '4')
//			{
//				arrAlphabets.push_back('g');
//				arrAlphabets.push_back('h');
//				arrAlphabets.push_back('i');
//			}
//			else if (i == '5')
//			{
//				arrAlphabets.push_back('j');
//				arrAlphabets.push_back('k');
//				arrAlphabets.push_back('l');
//			}
//			else if (i == '5')
//			{
//				arrAlphabets.push_back('j');
//				arrAlphabets.push_back('k');
//				arrAlphabets.push_back('l');
//			}
//			else if (i == '6')
//			{
//				arrAlphabets.push_back('m');
//				arrAlphabets.push_back('n');
//				arrAlphabets.push_back('o');
//			}
//			else if (i == '7')
//			{
//				arrAlphabets.push_back('p');
//				arrAlphabets.push_back('q');
//				arrAlphabets.push_back('r');
//				arrAlphabets.push_back('s');
//			}
//			else if (i == '8')
//			{
//				arrAlphabets.push_back('t');
//				arrAlphabets.push_back('u');
//				arrAlphabets.push_back('v');
//			}
//			else if (i == '9')
//			{
//				arrAlphabets.push_back('w');
//				arrAlphabets.push_back('x');
//				arrAlphabets.push_back('y');
//				arrAlphabets.push_back('z');
//			}
//
//		}
//
//			for (int i =0; i < arrAlphabets.size(); i++)
//			{
//				for (int j = i + 1; j < arrAlphabets.size(); j++)
//				{
//					char ch1 = arrAlphabets[i];
//					char ch2 = arrAlphabets[j];
//
//					std::string s = "";
//					s = s + ch1;
//					s = s + ch2;
//
//					arrResult.push_back(s);
//				}
//			}
//
//
//		return arrResult;
//	}
//};


//class RandomizedSet
//{
//private:
//	vector<int>m_nArray;
//
//public:
//	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//	bool insert(int val)
//	{
//		bool bReturn = false;
//		if (std::find(m_nArray.begin(), m_nArray.end(), val) != m_nArray.end())
//			bReturn = false;
//		else
//		{
//			m_nArray.push_back(val);
//			bReturn = true;
//		}
//
//		return bReturn;
//	}
//
//	/** Removes a value from the set. Returns true if the set contained the specified element. */
//	bool remove(int val)
//	{
//		bool bReturn = false;
//		if (std::find(m_nArray.begin(), m_nArray.end(), val) == m_nArray.end())
//			bReturn = false;
//		else
//		{
//			bReturn = true;
//			m_nArray.erase(std::find(m_nArray.begin(), m_nArray.end(), val));
//		}
//
//		return bReturn;
//	}
//
//	/** Get a random element from the set. */
//	int getRandom()
//	{
//		//srand(time(NULL));
//		int nRand = rand();
//		int random_index = nRand % m_nArray.size();
//
//		// Return element at randomly picked index 
//		return m_nArray.at(random_index);
//	}
//};


//return median of two separate lists 
//class Solution
//{
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//	{
//		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
//		std::sort(nums1.begin(), nums1.end());
//
//
//		if (nums1.size() % 2 == 0)
//		{
//			int k1 = nums1[nums1.size() / 2 - 1];
//			int k2 = nums1[nums1.size() / 2];
//
//			double k3 = (k1 + k2) / 2.0;
//
//			return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2.0;
//		}
//		else
//		{
//			return nums1[nums1.size() / 2];
//		}
//
//	}
//};

//
//class Solution
//{
//public:
//	int peakIndexInMountainArray(vector<int> A)
//	{
//		int l = 0, r = A.size() - 1, mid;
//		while (l < r) 
//		{
//			mid = (l + r) / 2;
//
//			if (A[mid] < A[mid + 1])
//				l = mid + 1;
//			else
//				r = mid;
//		}
//
//		return l;
//	}
//};


//class Solution
//{
//public:
//	char nextGreatestLetter(vector<char>& letters, char target)
//	{
//		int i = target;
//		for (auto ch : letters)
//		{
//			int ichar = ch;
//
//			if (ichar > i)
//				return ch;
//
//		}
//
//		return 'a';
//	}
//};


////Move Zeros to end
//class Solution {
//public:
//	void moveZeroes(vector<int>& nums)
//	{
//		std::vector<int>::iterator it = nums.begin();
//		int nCount = std::count(nums.begin(), nums.end(), 0);
//		for (it = nums.begin(); it != nums.end(); it++)
//		{
//			if (*it == 0)
//			{
//				nums.erase(it);
//				it--;
//			}
//				
//		}
//		for (int i = 0; i < nCount; i++)
//		{
//			nums.push_back(0);
//		}
//	}
//};

////Move Zeros to end - fast approach
//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) 
//	{
//		int j = 0;
//		// move all the nonzero elements advance
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] != 0) {
//				nums[j++] = nums[i];
//			}
//		}
//
//		for (; j < nums.size(); j++) 
//		{
//			nums[j] = 0;
//		}
//	}
//};


//Anagram
//class Solution 
//{
//public:
//	bool isAnagram(string s, string t)
//	{
//
//		std::multiset<char> set1;
//		for (auto i : s)
//		{
//			set1.insert(i);
//		}
//
//		std::multiset<char> set2;
//		for (auto i : t)
//		{
//			set2.insert(i);
//		}
//
//		return (set1 == set2);
//		
//	}
//};


//sum of squares //https://leetcode.com/problems/perfect-squares/
//class Solution {
//public:
//	int numSquares(int n)
//	{
//		while ((n & 3) == 0) 
//		{
//			n >>= 2;
//		}
//
//		if ((n & 7) == 7)  return 4;
//
//		if (n < 4) return n;
//
//		int end = sqrt(n);
//		if (end * end == n) return 1;
//
//		for (int i = 1; i <= end; ++i)
//		{
//			int remain = n - i * i;
//			int possible = sqrt(remain);
//			if (possible* possible == remain) 
//				return 2;
//		}
//
//		return 3;
//	}
//};

#include <unordered_map>

//171. Excel Sheet Column Number
//class Solution 
//{
//public:
//	int titleToNumber(string s) 
//	{
//		int res = 0;
//		for (auto ch : s)
//			res = 26 * res + (ch - 'A' + 1);
//		return res;
//	}
//};

//4,3,2,7,8,2,3,1
//class Solution {
//public:
//	vector<int> findDisappearedNumbers(vector<int>& nums)
//	{
//		std::vector<int> res;
//		for (int i = 0; i < nums.size(); i++)
//		{
//
//			int nIndex = abs(nums[i]) - 1;
//
//			if (nums[nIndex]> 0)
//				nums[nIndex] = -nums[nIndex];
//		}	
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] > 0)
//				res.push_back(i+1);
//		}
//
//
//
//		return res;
//	}
//};

//class Solution 
//{
//public:
//	int missingNumber(vector<int>& nums) 
//	{
//		int result = nums.size();
//		int i = 0;
//
//		for (int num : nums) 
//		{
//			result = result  ^ num;
//			result = result ^ i;
//			i++;
//		}
//
//		return result;
//	}
//};


// Kids With the Greatest Number of Candies
//class Solution {
//public:
//	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
//	{
//		std::vector<bool> res;
//		//std::vector<int>::iterator it = std::max(candies.begin(), candies.end());
//
//		for (int i = 0; i < candies.size(); i++)
//		{
//			if (candies[i] + extraCandies >= *max_element(candies.begin(), candies.end()))
//				res.push_back(true);
//			else
//				res.push_back(false);
//		}
//
//		return res;
//	}
//};



//Arrange Coins
//class Solution 
//{
//public:
//	int arrangeCoins(int n)
//	{
//		int i = 0;
//		while (n >= 0)
//		{
//			i++;
//			n = n - i;
//		}
//
//		return i - 1;
//	}
//};

//Arrange Coins using Binary Search
//class Solution {
//public:
//	int arrangeCoins(int n) {
//		int left = 0;
//		int right = n;
//		int ans = 0;
//
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//
//			long long curr = ((long long)(mid)*(mid + 1)) / 2;
//
//			if (curr <= n)
//			{
//				ans = mid;
//				left = mid + 1;
//			}
//			else
//				right = mid - 1;
//		}
//		return ans;
//	}
//};


////add one to the number represented by array and return new array
//class Solution {
//public:
//	vector<int> plusOne(vector<int>& digits)
//	{
//		vector<int> res(digits.begin(), digits.end());
//		for (int i = digits.size() - 1; i > -1; i--)
//		{
//			int lastelement = digits[i];
//
//			if (lastelement < 9)
//			{
//				res[i] = lastelement + 1;
//				return res;
//			}
//			else
//			{
//				res[i] = 0;
//				if (i == 0)
//					res.insert(res.begin(), 1);
//			}
//		}
//		return res;
//	}
//};

//class Solution
//{
//public:
//	int hammingDistance(int n1, int n2)
//	{
//		int x = n1 ^ n2;
//		int setBits = 0;
//
//		while (x > 0)
//		{
//			setBits += x & 1;
//			x  = x >> 1;
//		}
//		return setBits;
//	}
//};
//


//class Solution 
//{
//public:
//	int search(vector<int>& nums, int target)
//	{
//		int n = BinarySearch(nums, target, 0, nums.size() - 1);
//
//		return n;
//	}
//
//	int BinarySearch(vector<int>& nums, int target, int low, int high)
//	{
//		int mid;
//
//		if (high > low)
//		{
//			mid = low + (high - low) / 2;
//
//			if (nums[mid] == target)
//				return mid;
//
//			if (nums[mid] < target)
//				return BinarySearch(nums, target, mid + 1, high);
//
//			if (nums[mid] > target)
//				return BinarySearch(nums, target, 0, mid - 1);
//		}
//		return -1;
//	}
//};


//class Solution
//{
//public:
//	int mySqrt(int x)
//	{
//
//		if (x == 0 || x == 1)
//			return x;
//
//		return GetRoot(2, x / 2, x);
//	}
//
//	int GetRoot(int low, int high, int x)
//	{
//		int ans;
//		int mid;
//		while (low <= high)
//		{
//			mid = low + (high - low) / 2;
//
//			if (mid*mid == x)
//				return mid;
//
//			else if (mid *mid < x)
//			{
//				low = mid + 1;
//				ans = mid;
//			}
//			else
//				high = mid - 1;
//		}
//
//		return mid;
//	}
//};


////Number of Subarrays whose Sum Equals K
////https://www.youtube.com/watch?v=HbbYPQc-Oo4
//class Solution
//{
//public:
//	int subarraySum(vector<int>& nums, int k)
//	{
//		unordered_map<int, int> map;
//		int sum = 0;
//		int count = 0;
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			sum += nums[i]; // Find the Continuos sum or cumulative sum of each element in array
//			map[sum]++; //Store the sum in the map
//
//			if (sum == k || map.find(sum -k) != map.end()) //If the sum is present in map or the Currentsum-k is present in map then increase the count
//				count++;	
//		}
//		return count;
//	}
//};

//Shuffle String
//class Solution 
//{
//public:
//	string restoreString(string s, vector<int>& indices)
//	{
//		
//		map<int, char> MyMap;
//		for (auto i : indices)
//		{
//			MyMap.insert (std::make_pair(indices[i], s[i]));
//		}
//
//		string res;
//		map<int, char>::iterator it = MyMap.begin();
//		for (auto i : MyMap)
//		{
//			res = res + it->second;
//			it++;
//		}
//
//		return res;
//	}
//};

// Best Time to Buy and Sell Stock
//class Solution 
//{
//public:
//	int maxProfit(vector<int>& prices)
//	{
//		if (prices.size() == 0) return 0;
//
//		int minVal = INT_MAX;
//		int Profit = 0;
//
//		for (int i = 0; i < prices.size(); i++)
//		{
//			minVal = min(minVal, prices[i]);
//			Profit = max(Profit, prices[i] - minVal);
//		}
//
//		return Profit;
//	}
//};


//class Solution
//{
//public:
//	int thirdMax(vector<int>& nums)
//	{
//		if (nums.size() == 0) return 0;
//		set<int> myset;
//		for (auto i : nums)
//		{
//			myset.insert(i);
//		}
//
//		auto it = myset.begin();
//
//		if (myset.size() == 1)
//		{
//			return *it;
//		}
//		if (myset.size() == 2)
//		{
//			return *it;
//		}
//		if (myset.size() >= 3)
//		{
//			it++;
//			it++;
//			return *it;
//		}
//
//		return 0;
//	}
//};


//class Solution 
//{
//public:
//	bool detectCapitalUse(string word)
//	{
//		if (word.length() == 0) return 0;
//		int otherLetters = 0;
//		int firstLetter = word[0];
//		int count = 0;
//		for (int i = 0; i < word.length(); i++)
//		{
//			if (word[i] >= 65 && word[i] <= 96)
//			{
//				if (i > 1)
//				{
//					otherLetters++;
//				}
//				count++;
//			}
//		}
//
//		if (count == word.length()) return true;
//		if (count == 0) return true;
//		if (count >= 1 && otherLetters > 0)
//			return false;
//		else
//			return true;
//
//		return false;
//	}
//};

//class Solution
//{
//public:
//	vector<int> intersect(vector<int>& a, vector<int>& b)
//	{
//		unordered_map<int, int> ctr;
//		for (int i : a)
//		{
//			ctr[i]++;
//		}
//
//		vector<int> out;
//		for (int i : b)
//		{
//			if (ctr[i]-- > 0)
//				out.push_back(i);
//		}
//		return out;
//	}
//};

//class Solution
//{
//public:
//	bool isPalindrome(string str)
//	{
//		if (str.empty()) return true;
//
//		int i = 0;
//		int j = str.length() - 1;
//
//		while (i < j)
//		{
//			if (!isalnum(str[i]))
//			{
//				i++;
//				continue;
//			}
//			if (!isalnum(str[j]))
//			{
//				j--;
//				continue;
//			}
//
//			if (tolower(str[i++]) != tolower(str[j--])) 
//				return false;
//		}
//
//		return true;
//	}
//};

//class Solution
//{
//	public:
//	bool increasingTriplet(vector<int>& nums)
//	{
//		int c1 = INT_MAX, c2 = INT_MAX;
//		for (int x : nums)
//		{
//			if (x <= c1)
//			{
//				c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
//			}
//			else if (x <= c2)
//			{							 // here when x > c1, i.e. x might be either c2 or c3
//				c2 = x;           // x is better than the current c2, store it
//			}
//			else 
//			{							// here when we have/had c1 < c2 already and x > c2
//				return true;      // the increasing subsequence of 3 elements exists
//			}
//		}
//		return false;
//	}
//};


//class WordDictionary
//{
//public:
//	vector<string> arr;
//	/** Initialize your data structure here. */
//	WordDictionary()
//	{
//
//	}
//
//	/** Adds a word into the data structure. */
//	void addWord(string word)
//	{
//		arr.push_back(word);
//	}
//
//	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//	bool search(string word)
//	{
//		bool bval = false;
//		if (std::find(word.begin(), word.end(), '.') != word.end())
//			bval = true;
//
//		for (auto storedword : arr)
//		{
//			if (bval && storedword == word)
//				return true;
//			else if (!bval && storedword != word)
//				continue;
//			else
//			{
//				for (int i = 0; i < word.length(); i++)
//				{
//					if (word[i] == '.') continue;
//					if (word[i] != storedword[i]) return false;
//				}
//			}
//		}
//
//		return false;
//	}
//};

//class Solution 
//{
//public:
//	int findKthPositive(vector<int>& arr, int k)
//	{
//		vector<int> res;
//
//		for (int i = 1; i < INT_MAX; i++)
//		{
//			if (std::find(arr.begin(), arr.end(), i) == arr.end())
//				res.push_back(i);
//
//			if (k <= res.size())
//				return res[k -1];
//		}
//
//		return 1;
//	}
//};
 

//H-Index
//class Solution 
//{
//public:
//	std::set<int> myset;
//	int hIndex(vector<int>& citations)
//	{
//		if (citations.size() == 0) return 0;
//
//		sort(citations.begin(), citations.end());
//
//		int nsize = citations.size();
//		for (int i = 0; i < nsize; i++)
//		{
//			if (citations[i] >=  nsize - i )
//				return nsize - i;
//		}
//
//		return 0;
//	}
//};
//
//class Solution
//{
//public:
//	int longestPalindrome(string s)
//	{
//		transform(s.begin(), s.end(), s.begin(), ::tolower);
//
//		int length = 0;
//		std::map<char, int> mymap;
//		for (auto i : s)
//		{
//			mymap[i]++;
//		}
//
//		bool bvalue = false;
//		for (auto i : mymap)
//		{
//			if (i.second  == 1)
//			{
//				bvalue = true;
//			}
//			else if(i.second > 1)
//			{
//				if(i.second % 2 == 0) 
//					length = length + i.second;
//				else 
//					length = length + i.second -1;
//
//			}
//		}
//
//		return bvalue ? length + 1 : length;
//	}
//};

//#include <unordered_set>
//class Solution
//{
//public:
//	int eraseOverlapIntervals(vector<vector<int>>& intervals)
//	{
//		unordered_set<int> myset;
//		bool bfirst = false;
//		bool bsecond = false;
//		int count = 0;
//
//		if (intervals.size() == 0) return 0;
//
//		//sort(intervals.begin(), intervals.end());
//		myset.insert(intervals[0][0]);
//		myset.insert(intervals[0][1]);
//
//		for (int i = 1; i < intervals.size(); i++)
//		{
//			vector<int> vect = intervals[i];
//
//			if (std::find(myset.begin(), myset.end(), vect[0]) != myset.end()) //element found
//			{
//				bfirst = true;
//			}
//			if (std::find(myset.begin(), myset.end(), vect[1]) != myset.end()) //element found
//			{
//				bsecond = true;
//			}
//
//			if (bfirst && bsecond)
//			{
//				count++;
//			}
//			else
//			{
//				myset.insert(vect[0]);
//				myset.insert(vect[1]);
//			}
//
//			bfirst = false;
//			bsecond = false;
//
//		}
//
//		return count;
//	}
//};

//class Solution
//{
//public:
//	bool threeConsecutiveOdds(vector<int>& arr)
//	{
//		int n = arr.size();
//		if (n < 3) return false;
//
//		int count = 0;
//		for (int i = n - 1; i > -1; i--)
//		{
//			if (arr[i] % 2 != 0)
//			{
//				count++;
//				if (count == 3) return true;
//			}
//			else
//			{
//				count = 0;
//			}
//		}
//
//		return false;
//	}
//};


//class Solution
//{
//public:
//	int minOperations(int n)
//	{
//		if (n == 0) return 0;
//		int sum = 0;
//		for (int i = 1; i < n; i++)
//		{
//			if (i % 2 == 1)
//			{
//				sum = sum + (n - i);
//			}
//		}
//		return sum;
//	}
//};


//class Solution {
//public:
//	int minDays(int n)
//	{
//		int count = 0;
//		if (n == 0) return 0;
//		if (n == 1) return 1;
//
//		while (n != 0)
//		{
//			
//			if (n % 3 == 0)
//			{
//				n = (n - 2 * (n / 3));
//				count++;
//			}
//			else if (n % 2 == 0)
//			{
//				n = n - n / 2;
//				count++;
//			}
//			else if (n - 1 == 0 || n % 3 == 1 || n % 2 == 1)
//			{
//				n = n - 1;
//				count++;
//			}
//		}
//
//		if (n == 0) 
//			return count;
//	}
//};

//Best Time to Buy and Sell Stock III
//class Solution {
//public:
//	int maxProfit(vector<int>& prices)
//	{
//		if (prices.size() == 0) return 0;
//		if (prices.size() == 1) return 0;
//
//		int minvalue = INT_MAX;
//		int profit = 0;
//		int finalprofit = 0;
//		int m = 0;
//
//		for (int i = 0; i < prices.size(); i++)
//		{
//			minvalue = min(minvalue, prices[i]);
//			profit = max(profit, prices[i] - minvalue);
//			if (profit > 0)
//			{
//				finalprofit = finalprofit + profit;
//				m = i + 1;
//				break;
//			}
//		}
//
//		minvalue = INT_MAX;
//		profit = 0;
//		for (int i = m; i < prices.size(); i++)
//		{
//			minvalue = min(minvalue, prices[i]);
//			profit = max(profit, prices[i] - minvalue);
//		}
//
//		finalprofit = finalprofit + profit;
//
//		return finalprofit;
//	}
//};


//Pascal's Triangle
//class Solution
//{
//public:
//	vector<int> getRow(int rowIndex)
//	{
//		vector<vector<int>> res;
//		for (int i = 0; i < rowIndex + 1; i++)
//		{
//
//			res.push_back(vector<int>(i + 1, 1));
//			for (int j = 1; j < i; j++)
//			{
//				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
//			}
//		}
//
//		return res[rowIndex];
//	}
//};

//Top K Frequent Elements
//class Solution {
//public:
//	vector<int> topKFrequent(vector<int>& nums, int k)
//	{
//		unordered_map<int, int> mymap;
//		for (auto i : nums)
//		{
//			mymap[i]++;
//		}
//
//		vector<std::pair<int, int>> res(mymap.begin(), mymap.end());
//		sort(res.begin(), res.end(), [](std::pair<int, int> &a, std::pair<int, int>&b) { return a.second > b.second; });
//
//		std::vector<int> finalres;
//		for (int i = 0; i < k; i++)
//		{
//			finalres.push_back(res[i].first);
//		}
//
//		return finalres;
//	}
//};


//Product of Array Except Self
//class Solution
//{
//public:
//	vector<int> productExceptSelf(vector<int>& nums)
//	{
//		vector<int> res(nums);
//		vector<int> resLeft(nums);
//
//		resLeft[0] = 1;
//		int product = 1;
//		for (int i = 1; i < nums.size(); i++)
//		{
//			resLeft[i] = resLeft[i - 1] * nums[i - 1];
//		}
//
//		vector<int> resRight(nums.size(), 1);
//		resRight[nums.size() - 1] = 1;
//		for (int i = nums.size() - 2; i > -1;  i--)
//		{
//			resRight[i] = resRight[i + 1] * nums[i + 1];
//		}
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			res[i] = resLeft[i] * resRight[i];
//		}
//
//		return res;
//	}
//};


//class Solution
//{
//public:
//	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
//	{
//		vector<int>res;
//		vector<int> secondelem;
//		for (int i = 0; i < n; i++)
//		{
//			secondelem.push_back(edges[i][1]);
//		}
//
//		set<int> myset;
//		for (int i = 0; i < n; i++)
//		{
//			myset.insert(edges[i][0]);
//			myset.insert(edges[i][1]);
//		}
//
//		auto it = myset.begin();
//		while (it != myset.end())
//		{
//			if (std::find(secondelem.begin(), secondelem.end(), *it) == secondelem.end())
//				res.push_back(*it);
//
//			it++;
//		}
//
//		return res;
//	}
//};


//class Solution
//{
//public:
//	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
//	{
//
//		vector<vector<int>> matrix(n, vector<int>(n, -1));
//
//		for (auto data : edges)
//		{
//			int i = data[0];
//			int j = data[1];
//			matrix[j][i] = 1;
//		}
//
//		vector<int>res;
//		for (int i = 0; i < matrix.size(); i++)
//		{	
//			vector<int>data = matrix[i];
//			if(std::find(data.begin(), data.end(), 1) == data.end())
//				res.push_back(i);
//		}
//		return res;
//	}
//};


//class Solution
//{
//public:
//	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
//	{
//
//		vector<int> temp(edges.size(), -1);
//		for (auto data : edges)
//		{
//			temp[data[1]] = 1;
//		}
//
//		vector<int>res;	
//		for (int i = 0; i != n; i++)
//		{
//			if (temp[i] != 1) res.push_back(i);
//		}
//
//		return res;
//
//	}
//};

//
//class Solution {
//public:
//	
//	int sum = 0;
//	int stoneGameV(vector<int>& stoneValue)
//	{
//		vector<int> vec1;
//		vector<int> vec2;
//		if (stoneValue.size() == 0) return 0;
//		if (stoneValue.size() == 1) return 0;
//
//		int firstsum = 0;
//		int secondsum = 0;
//		int elements = stoneValue.size() / 2;
//
//		for (int i = 0; i < stoneValue.size(); i++)
//		{
//			if (i < elements)
//			{
//				firstsum = firstsum + stoneValue[i];
//				vec1.push_back(stoneValue[i]);
//			}
//			else
//			{
//				secondsum = secondsum + stoneValue[i];
//				vec2.push_back(stoneValue[i]);
//			}
//		}
//
//		if (secondsum > firstsum)
//		{
//			sum = sum + firstsum;
//			stoneGameV(vec1);
//		}
//		else
//		{
//			sum = sum + secondsum;
//			stoneGameV(vec2);
//		}
//
//		return sum;
//	}
//};


//class Solution 
//{
//public:
//	using VI = vector<int>;
//
//	int maxCoins(VI& A, int ans = 0) 
//	{
//		sort(A.begin(), A.end());
//
//		int N = A.size();
//		int K = N / 3,
//		i = N - 2;
//
//		while (K--)
//		{
//			ans = ans + A[i];
//			i =  i - 2;
//		}
//			
//		return ans;
//	}
//};


//class Solution
//{
//public:
//	int longestPalindromeSubseq(string s)
//	{
//		if (s.length() == 0) return 0;
//
//		std::map<char, int> mymap;
//		for (int i = 0; i < s.length(); i++)
//		{
//			mymap[s[i]]++;
//		}
//
//		int count = 0;
//		for (auto i : mymap)
//		{
//			if (i.second % 2 == 0)
//			{
//				count = count + i.second;
//			}
//		}
//
//		return count;
//	}
//};


//class Solution
//{
//public:
//	int longestConsecutive(vector<int>& nums)
//	{
//		if (nums.size() == 0) return 0;
//
//		int count = 1;
//		int longstreak = 1;
//		sort(nums.begin(), nums.end());
//
//		for (int i = 1; i < nums.size(); i++)
//		{
//			if (nums[i] != nums[i - 1])
//			{
//				if (nums[i] == nums[i - 1] + 1)
//				{
//					count++;
//				}
//				else
//				{
//					longstreak = max(count, longstreak);
//					count = 1;
//				}
//			}
//		}
//
//		return max(longstreak, count);
//	}
//};

//class Solution
//{
//public:
//	int alternatingCharacters(string s)
//	{
//		int count = 0;
//		if (s.length() == 0) return 0;
//		for (int i = 0; i < s.length() - 1; i++)
//		{
//			if (s[i] == s[i + 1])
//			{
//				count++;
//			}
//		}
//		return count;
//	}
//};

// Fibonacci Number
//class Solution
//{
//public:
//	//recursive approach
//	//int FibonacciNumber(int n)
//	//{
//	//	if(n < 2 ) return n;
//	//	return FibonacciNumber(n - 1) + FibonacciNumber(n - 2);
//	//}
//
//
//	//memorization
//	int FibonacciNumber(int n)
//	{
//		if (n < 2 ) return n;
//
//		int i = n;
//		std::vector<int> arr(n + 1, 0);
//		arr[0] = 0;
//		arr[1] = 1;
//
//		for (int i = 2; i <= n; i++)
//			arr[n] =  arr[n - 1] + arr[n - 2];
//
//		return arr[n];
//	}
//};


////factorial of a number
//class Solution
//{
//public:
//	//Recursive way
//	/*int Factorial(int n)
//	{
//		if (n == 0) return 1;
//		return n * Factorial(n - 1);
//	}*/
//
//	//iterative
//	int Factorial(int n)
//	{
//		int res = 1;
//		for (int i = 1; i <= n; i++)
//			res = res * i;
//		
//		return res;
//	}
//};

//check if number is prime number
//class Solution
//{
//public:
//	bool isPrime(int n)
//	{
//		if (n <= 1) return false;  //as 0 and 1 are not prime numbers
//		for (int i = 2; i < n / 2; i++)
//		{
//			if (n % i == 0) return false;
//
//		}
//
//		return true;
//	}
//};


//Palindrome
//class Solution
//{
//public:
//	bool isPallindrome(int n)
//	{
//		int temp = n;
//		int reminder = 0;
//		int res;
//		do
//		{
//			reminder = n % 10;
//			res = (res * 10) + reminder;
//			n = n / 10;
//		} while (n != 0);
//
//		return temp == res ? true : false;
//	}
//};


//Most Active Customers from HackerRank
//class Solution
//{
//public:
//	vector<string> mostActive(vector<string> customers)
//	{
//		vector<string> res;
//		int size = customers.size();
//		if (size == 0) return res;
//
//		double nmincount = (0.05 * size);
//		std::sort(customers.begin(), customers.end());
//
//		std::map<string, int> mymap;
//		for (auto cust : customers)
//		{
//			mymap[cust]++;
//		}
//
//		for (auto custcount : mymap)
//		{
//			if (custcount.second >= nmincount)
//			{
//				res.push_back(custcount.first);
//			}
//		}
//
//		if (res.size() > 3)
//			res.erase(res.begin() + 3, res.end());
//
//		return res;
//	}
//};


//Remove Odd Indexed elements
//class Solution
//{
//public:
//	vector<int> RemoveOddIndexElemnents(std::vector<int>& vec)
//	{
//		auto it = vec.begin();
//
//		int i = 0;
//		while (it!= vec.end())
//		{
//			if (i % 2 != 0)
//			{
//				it = vec.erase(it);
//			}
//			else
//			{
//				it++;
//			}
//
//			i++;
//		}
//
//		return vec;
//	}
//};


//
//class Solution 
//{
//public:
//	vector<string> topKFrequent(vector<string>& words, int k)
//	{
//		std::vector<string>res;
//		int nsize = words.size();
//		if (nsize == 0) return res;
//
//		std::map<string, int> mymap;
//		for (auto i : words)
//		{
//			mymap[i]++;
//		}
//
//
//		std::priority_queue<
//	
//		return res;
//	}
//};
//


//// Complete the sockMerchant function below.
//class Solution
//{
//public:
//	int sockMerchant(int n, vector<int> ar)
//	{
//		std::map<int, int> mymap;
//		for (auto val : ar)
//		{
//			mymap[val]++;
//		}
//
//		int npairs = 0;
//		auto it = mymap.begin();
//		while (it != mymap.end())
//		{
//			if (it->second % 2 == 0)
//				npairs = npairs + it->second / 2;
//			else if ((it->second % 2) - 1 == 0)
//			{
//				npairs = npairs + (it->second - 1) / 2;
//			}
//			it++;
//		}
//		return npairs;
//	}
//};

//class Solution {
//public:
//	int maxDistance(vector<vector<int>>& arrays)
//	{
//		if (arrays.size() == 0) return 0;
//
//		int maxDiff1 = 0;
//		int maxDiff2 = 0;
//		for (int i = 0; i < arrays.size() - 1; i++)
//		{
//			vector<int> v1 = arrays[i];
//			vector<int> v2 = arrays[i + 1];
//
//			maxDiff1 = abs(v1[0] - v2[v2.size() - 1]) > maxDiff1 ?
//				abs(v1[0] - v2[v2.size() - 1]) : maxDiff1;
//		}
//
//		for (int i = 0; i < arrays.size() - 1; i++)
//		{
//			vector<int> v1 = arrays[i];
//			vector<int> v2 = arrays[i + 1];
//
//
//			maxDiff2 = abs(v2[0] - v1[v1.size() - 1]) > maxDiff2 ?
//				abs(v2[0] - v1[v1.size() - 1]) : maxDiff2;
//
//		}
//
//		return  max(maxDiff1, maxDiff2);
//
//	}
//};

//class Solution {
//public:
//	std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) 
//	{
//		std::sort(candidates.begin(), candidates.end());
//		std::vector<std::vector<int> > res;
//		std::vector<int> combination;
//		combinationSum(candidates, target, res, combination, 0);
//		return res;
//	}
//
//private:
//	void combinationSum(std::vector<int> &candidates, int target, 
//		std::vector<std::vector<int> > &res, std::vector<int> &combination, 
//		int begin) 
//	{
//		if (!target) 
//		{
//			res.push_back(combination);
//			return;
//		}
//
//		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) 
//		{
//			combination.push_back(candidates[i]);
//			combinationSum(candidates, target - candidates[i], res, combination, i);
//			combination.pop_back();
//		}
//	}
//};


//class Solution
//{
//public:
//	int findPairs(vector<int>& nums, int k) 
//	{
//		set<pair<int, int>> unq;
//		unordered_map<int, int> m;
//
//		sort(nums.begin(), nums.end());
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			int temp = nums[i] - k;
//			if (m.find(temp) != m.end())
//			{
//				unq.insert(make_pair(nums[i], temp));
//
//			}
//			m[nums[i]] = 0; // so we can use temp=nums[i]-k again but from next time nums[i] shouldn't be same so we decreament its count  or make it equal to 0 
//		}
//
//		return unq.size();
//	}
//};

//class Solution {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums)
//	{
//		vector<vector<int>> res;
//
//		if (nums.size() <= 2)
//			return res;
//
//
//		vector<int> twosum;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			twosum = FindtwosumArray(nums, -nums[i], i);
//			if ((twosum.size() > 0))
//			{
//				twosum.push_back(nums[i]);
//				res.push_back(twosum);
//			}
//		}
//			
//
//		return res;
//	}
//
//	vector<int> FindtwosumArray(vector<int> vec, int sum, int ignoreindex)
//	{
//		vector<int> res;
//		vector<int> temp;
//		for (int i = 0; i < vec.size(); i++)
//		{
//			if (i != ignoreindex)
//				temp.push_back(vec[i]);
//		}
//
//		set<int> myset;
//		for (int i = 0; i < temp.size(); i++)
//		{
//			if (std::find(temp.begin(), temp.end(), sum - temp[i]) != temp.end())
//			{
//				res.push_back(sum - temp[i]);
//				res.push_back(temp[i]);
//				return res;
//			}
//			else
//			{
//				myset.insert(temp[i]);
//			}
//		}
//		return res;
//	}
//};

//Remove Covered Intervals
//class Solution {
//public:
//	int removeCoveredIntervals(vector<vector<int>>& intervals)
//	{
//		int nSize = intervals.size();
//		if (nSize == 0) return 0;
//
//		int count = nSize;
//		for (int i = 0; i < nSize; i++)
//		{
//			for (int j = 0; j < nSize; j++)
//			{
//				if (intervals[i][0] >= intervals[j][0] 
//					&& intervals[i][1] <= intervals[j][1] 
//					&&  i !=j)
//				{
//					count--;
//					break;
//				}
//
//			}
//		}
//
//
//
//		return count;
//	}
//};

//class Solution
//{
//public:
//	int bitwiseComplement(int N)
//	{
//		vector<int> vec;
//		while (N >= 1)
//		{
//			int reminder = N % 2;
//			N = N / 2;
//
//			if (reminder == 0)
//				vec.push_back(1);
//			else
//				vec.push_back(0);
//		}
//
//		int res = 0;
//		for (int i = 0; i < vec.size(); i++)
//		{
//			res = res + pow(2, i) * vec[i]
//		}
//
//		return res;
//	}
//};

//Minimum Number of Arrows to Burst Balloons
//class Solution {
//public:
//
//	static bool comp(const vector<int>& vec1, const vector<int>& vec2)
//	{
//		return vec1[1] < vec2[1];
//	}
//
//	int findMinArrowShots(vector<vector<int>>& points)
//	{
//		if (points.size() <= 1)
//			return points.size();
//
//		sort(points.begin(), points.end(), comp);
//
//		int minNumArrow = 0;
//		int tmp = points[0][1];
//
//		for (int i = 1; i < points.size(); i++)
//		{
//			if (points[i][0] > tmp)
//			{
//				minNumArrow++;
//				tmp = points[i][1];
//			}
//		}
//
//		return minNumArrow + 1;
//	}
//};


//void main()
//{
//	/*vector<string> strings = { "zabc" , "xdef", "yghi"};
//	Solution s;
//	s.Sort(strings);*/
//
//
//	/*vector<int> nums = { 5, -3, 5};
//	Solution s;
//	s.maxSubarraySumCircular(nums);*/
//
//
//	/*Solution s;
//	s.isHappy(1111111);*/
//
//
//	/*vector<int> nums = { -4,-3,-2,-1,60 };
//	Solution s;
//	s.maximumProduct(nums);*/
//
//	//Day 1
//	/*Solution s1;
//	s1.detectCapitalUse("USA");*/
//
//
//	//Day 2
//	//Solution s;
//	//s.numJewelsInStones("z", "ZZ");
//
//	//Day 3
//	/*Solution s;
//	bool bval = s.canConstruct("a", "b");
//	bool bval1 = s.canConstruct("aa", "ab");
//	bool bval2 = s.canConstruct("aa", "aab");*/
//
//
//	//Solution s;
//	//s.findComplement(9);
//
//	//Solution s;
//	//s.firstUniqChar("pafkjoaadadaad");
//
//
//	//vector<int> nums = { 1,2,3,4,5,6,7 };
//	//Solution s;
//	//s.rotate(nums, 3);
//
//	/*vector<int> nums = {3, 4, 4, 6, 6};
//	Solution s;
//	s.singleNumber(nums);*/
//
//
//	////Add one to the last elemnet of an array and return new array
//	/*vector<int> nums = { 9,9,9 };
//	Solution s;
//	s.plusOne(nums);*/
//
//
//	//check if all points lie on the same line
//	/*vector<vector<int>> nums = { {-3, -2}, {-1, -2}, {2, -2}, {-2, -2}, {0, -2} };
//	Solution s;
//	s.checkStraightLine(nums);*/
//
//
//	/*Solution s;
//	s.isPerfectSquare(10);*/
//
///*
//	Solution s;
//	s.isValid("([{}])");
//*/
//
//
//	/*vector<int> vec = { 1, 5, 7, -1, 5 };
//	Solution s;
//	s.FindPair(vec, 6);*/
//
//
//
//	//Twin Scheduling problem:
//	//vector<vector<int>> nums = { {10, 20}, {30, 200}, {400, 50}, {30, 20}};
//	//Solution s;
//	//s.twoCitySchedCost(nums);
//
//
//	// Reverse a string
//	//std::vector<char>arr  = { 'h', 'e', 'l', 'l', 'o' };
//	//Solution s;
//	//s.reverseString(arr);
//
//
//	////Coin Change 2
//	//std::vector<int>arr  = { 1, 2, 5 };
//	//Solution s;
//	//s.change(5, arr);
//
//	//Power of Two
//	/*Solution s;
//	s.isPowerOfTwo(17);*/
//
//
//	//isSubsequence
//	/*Solution s;
//	s.isSubsequence("leeeeetcode", "yyyyyleyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyeyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyeyyyyyyeyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyeyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyeyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyytyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyycyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyoyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyydyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyeyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy");*/
//	
//
//	/*vector<int> nums = { 2, 7, 11, 15 };
//	Solution s;
//	s.twoSum(nums, 9);*/
//
//	/*Solution s;
//	s.subtractProductAndSum(234);*/
//
//
//	/*int npower = 6;
//	Solution s;
//	s.myPow(2.00000, npower);*/
//
//
//	//vector<int> nums = { 1,2 };
//	//Solution s;
//	//s.uniqueOccurrences(nums);
//
//
//	//Solution s;
//	//s.letterCombinations("23");
//
//
//
// // Your RandomizedSet object will be instantiated and called as such:
//  //RandomizedSet* obj = new RandomizedSet();
//  //bool remove1 = obj->remove(0);
//  //bool remove2 = obj->remove(0);
//  //bool param_1 = obj->insert(0);
//  //int param_3 = obj->getRandom();
//  //bool remove3 = obj->remove(0);
//  //bool param_10 = obj->insert(0);
//
//
//	//std::vector<int>arr1{ 1, 2 };
//	//std::vector<int>arr2{ 3, 4 };
//	//Solution s;
//	//s.findMedianSortedArrays(arr1, arr2);
//
//
//	/*std::vector<int>arr1{ 0, 2, 1, 0 };
//	Solution s;
//	s.peakIndexInMountainArray(arr1);*/
//
//	//std::vector<char>arr{ 'c', 'f', 'j'};
//	//Solution s;
//	//s.nextGreatestLetter(arr, 'c');
//
//
////Move Zeros to End
//	/*std::vector<int>arr1{ 4, 1, 0, 0, 5 };
//	Solution s;
//	s.moveZeroes(arr1);*/
//
//
////Anagram
//	/*Solution s;
//	s.isAnagram("anagram", "nagaram");*/
//
//
////Sum of Squares
//	//Solution s;
//	//s.numSquares(13);
//
//
//	/*Solution s;
//	s.titleToNumber("BD");*/
//
//
////findDisappearedNumbers
//	//std::vector<int>arr1{ 4,3,2,7,8,2,3,1};
//	//Solution s;
//	//s.findDisappearedNumbers(arr1);
//
//
//// Kids With the Greatest Number of Candies
//	/*std::vector<int>arr1{ 2,3,5,1,3 };
//	Solution s;
//	s.kidsWithCandies(arr1, 3);*/
//
//
//	/*Solution s;
//	s.arrangeCoins(6);*/
//
//
////plus one
//	/*std::vector<int>arr1{ 9,9};
//	Solution s;
//	s.plusOne(arr1);*/
//
////Hamming Distance
//	/*Solution s;
//	s.hammingDistance(4, 2);*/
//
//
//	/*std::vector<int>arr1{ -1, 0, 3, 5, 9, 12 };
//	Solution s;
//	s.search(arr1, 2);*/
//
//	//Solution s;
//	//s.mySqrt(10);
//
//
//	/*std::vector<int>arr1{ 3, 4, 7, 2, -3, 1, 4, 2 };
//	Solution s;
//	s.subarraySum(arr1, 7);*/
//
//
//	/*std::vector<int>arr1{ 4,5,6,7,0,2,1,3 };
//	Solution s;
//	s.restoreString("codeleet", arr1);*/
//
//	/*std::vector<int>arr1{ 2,4,1};
//	Solution s;
//	s.maxProfit(arr1);*/
//
//	/*std::vector<int>arr1{ 1,2};
//	Solution s;
//	s.thirdMax(arr1);*/
//
//	/*Solution s;
//	s.detectCapitalUse("LeetcodE");*/
//
//	/*std::vector<int>arr1{ 4, 9, 5 };
//	std::vector<int>arr2{ 9,4,9,8,4 };
//	Solution s;
//	s.intersect(arr1, arr2);*/
//
//	/*Solution s;
//	s.isPalindrome("A man, a plan, a canal: Panama");*/
//
//	/*std::vector<int>arr1{ 4, 5, 0, 2, 1 };
//	Solution s;
//	s.increasingTriplet(arr1);*/
//
//
//	/*WordDictionary* obj = new WordDictionary();
//
//	obj->addWord("bad");
//	obj->addWord("dad");
//	obj->addWord("mad");
//
//	bool param_2 = obj->search("pad");
//	bool param_3 = obj->search("bad");
//	bool param_4 = obj->search(".ad");
//	bool param_5 = obj->search("b..");
//*/
//
//	/*std::vector<int>arr1{ 2,3,4,7,11 };
//	Solution s;
//	s.findKthPositive(arr1, 5);*/
//
//	/*std::vector<int>arr1{ 1,2,2 };
//	Solution s;
//	s.hIndex(arr1);*/
//
//
//	/*Solution s;
//	s.longestPalindrome("abccccdd");*/
//
//
//	//std::vector<int>arr1{ 1, 2 };
//	//std::vector<int>arr2{ 2, 3 };
//	//std::vector<int>arr3{ 1, 3 };
//
//	//std::vector<vector<int>> findlarray{ arr1 , arr2, arr3 };
//	//Solution s;
//	//s.eraseOverlapIntervals(findlarray);
//
//
//	/*std::vector<int>arr1{ 1,1, 1};
//	Solution s;
//	bool bval = s.threeConsecutiveOdds(arr1);*/
//
//	/*Solution s;
//	s.minOperations(6);*/
//
//	/*Solution s;
//	int val = s.minDays(10);*/
//
//
//	/*std::vector<int>arr1{ 1,2,3,4,5 };
//	Solution s;
//	s.maxProfit(arr1);*/
//
//
//	/*std::vector<int>arr1;
//	Solution s;
//	arr1 = s.getRow(3);*/
//
//	/*std::vector<int>arr1{ 1};
//	Solution s;
//	s.topKFrequent(arr1, 1);*/
//
//	/*std::vector<int>arr1{ 1, 2, 3, 4 };
//	Solution s;
//	s.productExceptSelf(arr1);*/
//
//	//House Robber
//	/*std::vector<int>arr1{ 1, 2, 3, 1, 7, 9 };
//	Solution s;
//	s.rob(arr1);*/
//
//
//	/*std::vector<int>arr1{ 0, 1 };
//	std::vector<int>arr2{ 2, 1 };
//	std::vector<int>arr3{ 3, 1 };
//	std::vector<int>arr4{ 1, 4 };
//	std::vector<int>arr5{ 2, 4 };
//
//	std::vector<vector<int>> findlarray{ arr1 , arr2, arr3, arr4, arr5};
//	Solution s;
//	s.findSmallestSetOfVertices(5,findlarray);*/
//
//
//	/*std::vector<int>arr1{ 7,7,7,7,7,7,7 };
//	Solution s;
//	int ans = s.stoneGameV(arr1);*/
//
//
//	/*std::vector<int>arr1{ 9,8,7,6,5,1,2,3,4 };
//	Solution s;
//	s.maxCoins(arr1);*/
//
//
//	/*Solution s;
//	s.longestPalindromeSubseq("bbbab");*/
//
//	//std::vector<int>arr1{ 9,1,4,7,3,-1,0,5,8,-1,6 };
//	//Solution s;
//	//s.longestConsecutive(arr1);
//
//	//Solution s;
//	//s.alternatingCharacters("AAABBB");
//
//
//	//std::vector<string>arr1{ "Alpha",
//	//"Beta", "Zeta", "Beta", "Zeta", "Zeta", "Epsilon", "Beta", "Zeta", "Beta", "Zeta",
//	//"Beta", "Delta", "Zeta", "Beta", "Zeta", "Beta", "Zeta", "Beta", "Zeta", "Beta" };
//	//Solution s;
//	//s.mostActive(arr1);
//
//
//	/*std::vector<int> arr1{ 1, 2, 3, 4, 5, 6 };
//	Solution s;
//	s.RemoveOddIndexElemnents(arr1);*/
//
//	/*vector<string> vec{ "i", "love", "leetcode", "i", "love", "coding" };
//	Solution s;
//	s.topKFrequent(vec, 2);*/
//
//
//	/*std::vector<int> arr1{ 10, 20, 20, 10, 10, 30, 50, 10, 20 };
//	Solution s;
//	s.sockMerchant(9, arr1);*/
//
//	/*std::vector<vector<int>> m_nArray{ {1,2,3}, {4,5}, {1,2,3} };
//	Solution s;
//	s.maxDistance(m_nArray);*/
//
//	/*std::vector<int> arr1{ 2, 3, 6, 7 };
//	Solution s;
//	s.combinationSum(arr1, 7);*/
//
//	/*std::vector<int> arr1{ 3,1,4,1,5 };
//	Solution s;
//	s.findPairs(arr1, 2);*/
//
//	//3 SUM
//	/*std::vector<int> arr1{ -1,0,1,2,-1,-4 };
//	Solution s;
//	s.threeSum(arr1);*/
//
//	//Remove Covered Intervals
//	/*std::vector<vector<int>> m_nArray{ {3, 10}, {4, 10}, {5, 11} };
//	Solution s;
//	s.removeCoveredIntervals(m_nArray);*/
//
//	//Minimum Number of Arrows to Burst Balloons
//	std::vector<vector<int>> m_nArray{ {10, 16}, {2, 8}, {1, 6}, {7, 12} };
//	Solution s;
//	s.findMinArrowShots(m_nArray);
//}



//int main()
//{
//	int val;
//	int carry = 0;
//	cin >> val;
//
//	vector <int> arr(200, 0 );
//	arr[0] = 1; //Initial product = 1
//
//	int k = 0; //Current size of the number stored in arr
//
//	for (int i = 1; i <= val; i++)
//	{
//		for (int j = 0; j <= k; j++)
//		{
//			arr[j] = arr[j] * i + carry;
//			carry = arr[j] / 10;
//			arr[j] = arr[j] % 10;
//		}
//
//		while (carry) ///Propogate the remaining carry to higher order digits
//		{
//			k++;
//			arr[k] = carry % 10;
//			carry /= 10;
//		}
//	}
//
//	for (int i = k; i >= 0; i--)
//	{
//		cout << arr[i];
//	}
//
//	cout << endl;
//	return 0;
//}


