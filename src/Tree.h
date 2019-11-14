#pragma once

template<class T>
class Tree {
public:
    virtual bool add(const T &) = 0;
    virtual bool remove(const T &) = 0;
    virtual int height() = 0;
    virtual bool contains(T val) = 0;

    virtual void traverseInOrder() = 0;
    virtual void traversePreOrder() = 0;
    virtual void traversePostOrder() = 0;

    virtual ~Tree() {};
};
