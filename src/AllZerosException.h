#pragma once
#include <iostream>
class AllZerosException: std::exception{
public:
	AllZerosException()noexcept = default;
	~AllZerosException() = default;
	virtual const char* what()const noexcept {
		return "Math Error!";
	}
};