#pragma once

class Base {
public:
    virtual ~Base() {}
};
//class herda de Base
class A : public Base {};
class B : public Base {};
class C : public Base {};