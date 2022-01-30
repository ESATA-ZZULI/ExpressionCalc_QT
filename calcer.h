#ifndef CALCER_H
#define CALCER_H

#include <QObject>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef std::map<char, int> TokenLevel;
typedef std::vector<std::string> Notation;

const int INFINITY = 0x3f3f3f3f;

class Calcer : public QObject
{
    Q_OBJECT
public:
    explicit Calcer(QObject *parent = nullptr);
    std::string calc(std::string expression);
    enum class ErrorType{
        Well,FunctionNotFound, EvalError, SyntaxError, BracketNotMatched
    };
    static std::map<ErrorType, std::string> ErrorType2Name;
    struct Error {
        ErrorType type = ErrorType::Well;
        std::string msg = "";
        Error(){};
        Error(ErrorType type, std::string msg){
            this->type = type;
            this->msg = msg;
        }
        Error(Error& other){
            this->type = other.type;
            this->msg = other.msg;
        }
    };
    static const TokenLevel tokenLevel;
    static const std::map<std::string, int> NoteTable;
private:
    Notation reversePolishNotation(const std::string& expression, const TokenLevel& tokenLevel, Error& e);
    inline bool checkNumber(std::string::const_iterator& it, const std::string& expression);
    std::string readNumber(std::string::const_iterator& it, const std::string& expression);
    inline bool checkFunc(std::string::const_iterator& it, const std::string& expression);
    std::string readFunc(std::string::const_iterator& it, const std::string& expression);
    double evalNotation(const Notation& notation, Error& e);
signals:

};

#endif // CALCER_H
