/* 这是一个 C/C++ 扩展头文件。
 * 可在编译器 MinGW GCC 16.1.0 64-bit ，编译参数 -std=c++98，c++03，c++11，c++14，c++17，c++20，c++23，c++26，
 * c89，c90，c99，c11，c17，c18，c23
 * -Werror 的环境下运行。
 * 版本 1.0
 * 作者 刘禅玉米（网名） 享有版权。 */

/* This is a C/C++ extension header file.
 * Compatible with MinGW GCC 16.1.0 64-bit, compiled with flags -std=c++98, c++03, c++11, c++14, c++17, c++20, c++23, c++26,
 * c89, c90, c99, c11, c17, c18, c23
 * -Werror.
 * Version 1.0
 * Copyright Liu shan Yu mi (handle). */
#ifndef __STD_EXTENSION__
#define __STD_EXTENSION__

/* -------------------------       int128 的定义与实现      ------------------------- */
/* ------------------------- Define and implement of int128 ------------------------- */

typedef __int128 i128;

typedef unsigned __int128 ui128;

#ifdef __cplusplus

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>

namespace std
{
	inline i128 stoi(const std::string s)
	{
		i128 r = 0, v = 1;
	    
	    size_t i = 0;
	
	    if (s[0] == '-')
	    {
			v = -1;
			i++;
		}
	
	    for (; i < s.size(); ++i) r = r * 10 + (s[i] - '0');
	
	    return r * v;
	}
	
	inline ui128 ustoi(const std::string s)
	{
		ui128 r = 0, v = 1;
	    
	    size_t i = 0;
	
	    if (s[0] == '-')
		{
	        return 0;
	    }
	
	    for (; i < s.size(); ++i) r = r * 10 + (s[i] - '0');
	
	    return r * v;
	}
	
	inline std::string to_string(i128 x)
	{
	    if (x == 0) return "0";
	
	    bool n = x < 0;
	    
	    if (n) x = -x;
	
	    std::string s;
	    
	    while (x > 0)
		{
	        s.push_back('0' + x % 10);
	        x /= 10;
	    }
	
	    if (n) s.push_back('-');
	
	    std::reverse(s.begin(), s.end());
	    return s;
	}
	
	inline std::string to_string(ui128 x)
	{
	    if (x == 0) return "0";
	
	    std::string s;
	    
	    while (x > 0)
		{
	        s.push_back('0' + x % 10);
	        x /= 10;
	    }
	
	    std::reverse(s.begin(), s.end());
	    return s;
	}
	
	inline std::istream &operator>>(std::istream &i, i128 &x)
	{
	    std::string s;
	    char c = i.peek();
	
	    while (c == ' ' || c == '\n' || c == '\t')
		{
	        i.get();
	        c = i.peek();
	    }
	
	    if (c == '-' || (c >= '0' && c <= '9')) i >> s; else return i;
	
	    x = 0;
	    
	    bool n = s[0] == '-';
	    
		for (size_t k = n ? 1 : 0; k < s.size(); ++k) x = x * 10 + (s[k] - '0');
		
		if (n) x = -x;
	
	    return i;
	}
	
	inline std::istream &operator>>(std::istream &i, ui128 &x)
	{
	    std::string s;
	    char c = i.peek();
	
	    while (c == ' ' || c == '\n' || c == '\t')
		{
	        i.get();
	        c = i.peek();
	    }
	
	    if (c == '-' || (c >= '0' && c <= '9')) i >> s; else return i;
	
	    x = 0;
	    
	    for (size_t k = 0; k < s.size(); ++k) x = x * 10 + (s[k] - '0');
	
	    return i;
	}
	
	inline std::ostream &operator<<(std::ostream &o, i128 x)
	{
	    if (x == 0) return o << '0';
	
	    bool n = x < 0;
	    if (n) x = -x;
	
	    std::string s;
	    while (x > 0)
		{
	        s.push_back('0' + x % 10);
	        x /= 10;
	    }
	
	    if (n) s.push_back('-');
	
	    std::reverse(s.begin(), s.end());
	    return o << s;
	}
	
	inline std::ostream &operator<<(std::ostream &o, ui128 x)
	{
	    if (x == 0) return o << '0';
	
	    std::string s;
	    while (x > 0)
		{
	        s.push_back('0' + x % 10);
	        x /= 10;
	    }
	    
	    std::reverse(s.begin(), s.end());
	    return o << s;
	}
}

#else

#endif

#endif
