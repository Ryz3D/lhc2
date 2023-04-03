#pragma once

#include <string>

class Token
{
public:
    std::string raw;
};

class NameToken : public Token
{
};

class TypeToken : public Token
{
};

// (
class BracketToken : public Token
{
public:
    bool close;
};

// {
class CBracketToken : public Token
{
public:
    bool close;
};

// [
class SBracketToken : public Token
{
public:
    bool close;
};

// if for while do return goto
class ActionToken : public Token
{
};

// #include #define
class MetaToken : public Token
{
    // TODO: name?
};

// + - * / % ^ | & ~ || && ! < > == != >= <=
class OperatorToken : public Token
{
};

// = += -= *= /= %= ^= |= &=
class AssignmentToken : public Token
{
};

// . ->
class MemberToken : public Token
{
};

// * &
class PointerToken : public Token
{
};

// :
class LabelToken : public Token
{
};

// ,
class CommaToken : public Token
{
};

// ;
class SemicolonToken : public Token
{
};

// ""
class StringLiteral : public Token
{
public:
    std::string parse(); // TODO: \n \t \0 \\ \"
};

// ''
class CharLiteral : public Token
{
public:
    char parse(); // TODO: \n \t \0 \\ \'
};

// 0
class IntLiteral : public Token
{
public:
    int parse(); // TODO: 0b 01 0x
};

/*

expression grammar:

a:
    - NameToken
        - MemberToken
            - NameToken
                - ...
        - SBracketToken
        - (params)
    - PointerToken
        - NameToken
            - ...
    - (TypeToken)
        - a
    - (expression)
    - StringLiteral
    - CharLiteral
    - IntLiteral
    - BracketToken
b:
    - OperatorToken
    - expression_terminator

*/

class Tokenizer
{
public:
private:
    static int index;
    /*
    for: , ;
    func call: , )
    assignment: ;
    def-assignment: , ;
    indexing: ]

    TODO: search before and store index instead?
    */
    static std::string expression_terminator;
};
