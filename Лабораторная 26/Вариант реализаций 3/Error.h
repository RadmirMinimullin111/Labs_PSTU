#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error
{
public:
	virtual void what() { };
};

class IndexError: public Error 
{
protected:
	string msg;
public:
	IndexError() { msg = "Index Error\n"; }
	virtual void what() override { cout << msg; }
};

class TransitionError: public Error 
{
protected:
	string msg;
public:
	TransitionError() { msg = "Transition Error\n"; }
	virtual void what() override { cout << msg; }
};

class IndexError1: public IndexError 
{
protected:
	string msg_;
public:
	IndexError1() { IndexError(); msg_ = "Index < 0\n"; }
	virtual void what() { cout << msg << msg_; }
};

class IndexError2: public IndexError 
{
protected:
	string msg_;
public:
	IndexError2() { IndexError(); msg_ = "Index > size\n"; }
	virtual void what() { cout << msg << msg_; }
};

class TransitionError1: public TransitionError 
{
protected:
	string msg_;
public:
	TransitionError1() { TransitionError(); msg_ = "n > size\n"; }
	virtual void what() { cout << msg << msg_; }
};

class TransitionError2 : public TransitionError 
{
protected:
	string msg_;
public:
	TransitionError2() { TransitionError(); msg_ = "n < 1\n"; }
	virtual void what() { cout << msg << msg_; }
};