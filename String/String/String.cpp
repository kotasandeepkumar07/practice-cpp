// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;
//1. we can find empty spaces in a string just by comparing each character with  ' '
//


//class Solution 
//{
//public:
//	int maxNumberOfBalloons(string text) 
//	{
//		std::vector<char> vect;
//		std::multimap<char, int> mymap;
//		std::vector<char>::iterator it = vect.begin();
//
//		for (int i= 0; i < text.length(); i++)
//		{
//			if (text[i] == 'b' || text[i] == 'a' || text[i] == 'l' ||
//				text[i] == 'o' || text[i] == 'n')
//			{
//				/*it == mymap.find(text[i]);
//				if ( it !=  mymap.end())
//				{*/
//					//mymap.insert(std::make_pair(text[i], i));
//				vect.push_back(text[i]);
//				//}
//					
//			}
//		}
//	
//		//std::multimap<char, int>::iterator it1 = mymap.begin();
//
//		for (auto c : text) 
//		{
//			if (mymap.find(c) == mymap.end())
//				mymap.insert({ c, 1 });
//			else mymap[c]++;
//		}
//
//		for (int i =0; i < vect.size(); i++)
//		{
//			
//		}
//
//		return 1;
//	}
//};

/*******************************Replace . with [.]  in a string *****************************************/

//class Solution 
//{
//public:
//	string defangIPaddr(std::string address)
//	{
//		string res = "";
//		for (auto ch : address)
//		{
//			if (ch == '.')
//				res += "[.]";
//			else
//				res += ch;
//		}
//
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	string str  = s.defangIPaddr("255.512.123");
//	int i = 10;
//}



/*******************************Split a String in Balanced Strings *****************************************/

//class Solution 
//{
//public:
//	int balancedStringSplit(string s)
//	{
//		int nval = 0;
//		int sum = 0;
//		for (auto ch : s)
//		{
//			if (ch == 'L')
//				sum = sum + 1;
//			else
//				sum = sum - 1;
//
//			if (sum == 0)
//				nval++;
//		}
//
//		return nval;
//	}
//};
//
//void main()
//{
//	Solution s;
//	int nval  = s.balancedStringSplit("RLRRLLRLRL");
//}




/*************************************  UpperCase to Lower Case ***********************************/
//class Solution 
//{
//public:
//	string toLowerCase(string str) 
//	{
//		string sTemp = "";
//		for (auto ch : str)
//		{
//			if (ch > 64 && ch < 91)
//				ch = ch + 32;
//			else
//				ch = ch;
//
//			sTemp = sTemp + ch;
//
//		}
//		return sTemp;
//	}
//};
//
//
//void main()
//{
//	Solution s;
//	string str  = s.toLowerCase("HELLO");
//
//
//}



/*********************** Come back to Origin *****************************************************/

//class Solution 
//{
//public:
//	bool judgeCircle(string moves) 
//	{
//		int sum = 0;
//		int count = 0;
//		for (auto ch : moves)
//		{
//			if (ch == 'L')
//			{
//				sum = sum + 1;
//			}
//			else if (ch == 'R')
//			{
//				sum = sum - 1;
//			}
//			else if (ch == 'U')
//			{
//				count = count + 1;
//			}
//			else if (ch == 'D')
//			{
//				count = count - 1;
//			}
//		}
//
//		if (sum == 0 && count == 0)
//			return true;
//		else
//			return false;
//	}
//};
//
//int main()
//{
//	Solution s;
//	s.judgeCircle("LL");
//	return 0;
//}




/*******************************************Unique Emails ************************************/
//class Solution 
//{
//public:
//	int numUniqueEmails(vector<string>& emails)
//	{
//		string strBefore;
//		string strAfterEmail;
//		std::set<string> set;
//		for (auto str : emails)
//		{
//			int pos = str.find('@');
//			strAfterEmail = str.substr(pos,str.length() -1);
//			int npos = str.find('+');
//
//			if (npos > -1)
//			{
//				strBefore = str.substr(0, str.find('+'));
//				strBefore.erase(std::remove(strBefore.begin(), strBefore.end(), '+'), strBefore.end());
//			}
//			else
//			{
//				strBefore = str.substr(0, pos);
//			}
//
//			strBefore.erase(std::remove(strBefore.begin(), strBefore.end(), '.'), strBefore.end());
//			set.insert(strBefore + strAfterEmail);
//		} 
//
//		return set.size();
//	}
//};
//
//
//int main()
//{
//	vector<string> emails;
//	emails.push_back("test.email@leetcode.com");
//	emails.push_back("test.email1@leetcode.com");
//	emails.push_back("testemail+david@lee.tcode.com");
//
//	Solution s;
//	s.numUniqueEmails(emails);
//
//	return 0;
//}




/******************************************revserse string *************************************/
//class Solution 
//{
//public:
//	string reverseWords(string str) 
//	{
//		string strFinal;
//		int pos = str.find(' ');
//		while (pos > -1)
//		{
//			string s1 = str.substr(0, pos);
//			std::reverse(s1.begin(), s1.end());
//			if (strFinal.length() == 0)
//				strFinal = s1;
//			else
//				strFinal = strFinal + ' '+ s1;
//			str = str.substr(pos + 1, str.length());
//			pos = str.find(' ');
//		}	
//
//		std::reverse(str.begin(), str.end());
//		if (strFinal.length() == 0)
//			strFinal = str;
//		else
//			strFinal = strFinal + ' ' + str;
//		return strFinal;
//	}
//};
//
//int main()
//{
//	Solution s;
//	s.reverseWords("hehhhhhhe");
//	return 0;
//}


//class Solution 
//{
//public:
//	string toGoatLatin(string str) 
//	{
//		static int i = 1;
//		int nPos = str.find(' ');
//
//
//		string strFinal;
//		string strTemp = str;
//		string stra = "a";
//		while (nPos > -1)
//		{
//			strTemp = str.substr(0, nPos);
//			str = str.substr(nPos + 1, str.length());
//
//			char ch = strTemp[0];
//			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
//				ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
//			{
//				strTemp = strTemp + "ma";
//			}
//			else
//			{
//				char ch1 = strTemp[0];
//				strTemp = strTemp.substr(1, strTemp.length());
//				strTemp = strTemp + ch1 + "ma";
//			}
//
//			
//			strTemp = strTemp + stra;
//			stra += "a";
//			i++;
//
//			if (strFinal.length() >0)
//				strFinal = strFinal + ' ' +strTemp;
//			else
//				strFinal =  strTemp;
//
//			nPos = str.find(' ');
//		}
//
//
//		strTemp = str;
//		char ch = strTemp[0];
//		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
//			ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
//		{
//			strTemp = strTemp + "ma";
//		}
//		else
//		{
//			char ch1 = strTemp[0];
//			strTemp = strTemp.substr(1, strTemp.length());
//			strTemp = strTemp + ch1 + "ma";
//		}
//
//
//		strTemp = strTemp + stra;
//		stra += "a";
//		i++;
//
//		if (strFinal.length() > 0)
//			strFinal = strFinal + ' ' + strTemp;
//		else
//			strFinal = strTemp;
//
//
//		return strFinal;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	s.toGoatLatin("yDumm");
//	return 1;
//}


//
//class Solution
//{
//public:
//	int lengthOfLastWord(string str)
//	{
//
//		int nLength;
//		int pos = str.find(' ');
//		if (pos > -1)
//		{
//			string strTemp = str.substr(pos + 1, str.length());
//			nLength = strTemp.length();
//		}
//		else
//			nLength = 0;
//
//		return nLength;
//	}
//};
//
//void main()
//{
//	Solution s;
//	s.lengthOfLastWord(" a");
//}
//


//class Solution 
//{
//public:
//	string strTemp1= "";
//	string strTemp2 = "";
//	bool isPalindrome(string str) 
//	{
//		string strOriginal = str;
//		for (auto ch : str)
//		{
//			if (ch > 64 && ch < 91 || ch > 96 && ch < 123 || ch > 47 && ch < 58)
//			{
//				strTemp1 = strTemp1 + ch;
//			}
//		}
//
//		std::reverse(strOriginal.begin(), strOriginal.end());
//		for (auto ch : strOriginal)
//		{
//			if (ch > 64 && ch < 91 || ch > 96 && ch < 123 || ch > 47 && ch < 58)
//			{
//				strTemp2 = strTemp2 + ch;
//			}
//		}
//
//		transform(strTemp1.begin(), strTemp1.end(), strTemp1.begin(), ::toupper);
//		transform(strTemp2.begin(), strTemp2.end(), strTemp2.begin(), ::toupper);
//
//		if (strTemp1 == strTemp2)
//			return true;
//		else
//			return false;
//	}
//};



//class Solution 
//{
//public:
//	int strStr(string haystack, string needle)
//	{
//		int needlelength = needle.length();
//		if (needlelength == 0) return 0;
//		int index = 0;
//		int firstindex = -1;
//		for (int i = 0; i < haystack.length(); i++)
//		{
//			while (needlelength != 0)
//			{
//				if (haystack[i] != needle[index])
//				{
//					break;
//				}
//				else
//				{
//					firstindex = index;
//					index++;
//					needlelength--;
//				}
//			}
//		}
//		return index;
//	}
//};


//class Solution
//{
//public:
//	string thousandSeparator(int n)
//	{
//		string str = to_string(n);
//
//		if (str.length() < 4) return str;
//		std::reverse(str.begin(), str.end());
//
//		string strres = "";
//		int index = 0;
//		for (int i = 0; i < str.length(); i++)
//		{
//
//			if ( i !=0  && i % 3 == 0)
//				strres = strres + "." + str[i];
//			else
//				strres = strres + str[i];
//		}
//
//		std::reverse(strres.begin(), strres.end());
//
//		return strres;
//	}
//};

//class Solution {
//public:
//	string reorderSpaces(string text)
//	{
//		if (text.length() == 0) return "";
//
//		int space = 0;
//		for (int i = 0; i < text.length(); i++)
//		{
//			if (text[i] == ' ')
//			{
//				space++;
//			}
//		}
//
//		istringstream s(text);
//		string word;
//		int wordcount = 0;
//
//		while (s >> word)
//		{
//			wordcount++;
//		}
//
//		int nSpaceforeachword = space / (wordcount - 1);
//
//		istringstream sNew(text);
//		string strFinal;
//		string strSpace = "";
//		while (sNew >> word)
//		{
//			strFinal = strFinal + word;
//
//			if (space >= nSpaceforeachword)
//			{
//
//				for (int i = 0; i < nSpaceforeachword; i++)
//				{
//					strSpace = strSpace + " ";
//					space--;
//				}
//			}
//
//			strFinal = strFinal + strSpace;
//			strSpace = ""; 
//			
//		}
//
//		for (int i = 0; i < space; i++)
//		{
//			strSpace = strSpace + " ";
//		}
//		strFinal = strFinal + strSpace;
//
//		return strFinal;
//	}
//};


class Solution {
public:
	string reverseWords(string s)
	{
		istringstream is(s);
		string tmp;
		is >> s;
		while (is >> tmp)
		{
			s = tmp + " " + s;
		}

		if (s[0] == ' ') 
			s = "";

		return s;
	}
};


int main()
{
	
	/*Solution s;
	s.strStr("hello", "ll");*/

	/*Solution s;
	s.thousandSeparator(123);*/

	/*Solution s;
	s.reorderSpaces(" practice   makes   perfect");*/

	Solution s;
	s.reverseWords("the sky is blue");
	
	return 0;
}
