//
//  AssocArray.cpp
//  tcp_socket_pdv_server
//
//  Created by Rodrigo Bueno Tomiosso on 01/06/16.
//  Copyright © 2016 mourodrigo. All rights reserved.
//

/*
 * Program to demostrate the use of template class and associative array.
 * By Arnav Mukhopadhyay
 */

#include <iostream>
#include <vector>

template <class T>
class AssocArray
{
private:
    typedef struct _Data
    {
        T data;
        std::string name;
    } Data ;
    std::vector<Data> stack;
    
public:
    long Size()
    {
        return stack.size();
    }
    
    bool IsItem(std::string name)
    {
        for(int i=0; i<Size(); i++)
        {
            if(stack[i].name == name)
                return true;
        }
        return false;
    }
    
    bool AddItem(std::string name, T data)
    {
        if(IsItem(name))
            return false;
        Data d;
        d.name = name;
        d.data = data;
        stack.push_back(d);
        return true;
    }
    
    T& operator [] (std::string name)
    {
        for(int i=0; i<Size(); i++)
        {
            if(stack[i].name == name)
                return stack[i].data;
        }
        long idx = Size();
        Data d;
        d.name = name;
        stack.push_back(d);
        return stack[idx].data;
    }
    
    std::string GetItemName(long index)
    {
        if(index<0)
            index = 0;
        for(int i=0; i<Size(); i++)
            if(i == index)
                return stack[i].name;
        return "";
    }
    
    T& operator [] (long index)
    {
        if(index < 0)
            index = 0;
        for(int i=0; i<Size(); i++)
        {
            if(i == index)
                return stack[i].data;
        }
        return stack[0].data;
    }
    
};
