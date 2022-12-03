/*
Matthew Kaltman, mkaltman
2022 Spring CSE101 PA6

List.cpp
*/

#include <iostream>
#include <string> 
#include <stdexcept>
#include "List.h"

#define UNDEF -1


//Private Constructor(s)----------------------------------------

List::Node::Node(ListElement x)
{
    data = x;
    next = nullptr;
    prev = nullptr;

}

//--------------------------------------------------------------

//Class Constructors/Destructors--------------------------------

List::List()
{
    frontDummy = new Node(UNDEF);
    backDummy = new Node(UNDEF); 
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
}

List::List(const List& L)
{
    frontDummy = new Node(UNDEF);
    backDummy = new Node(UNDEF); 
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0; 
    
    Node* N;

    N = L.frontDummy->next;
    while(N != L.backDummy && N != nullptr)
    {
        this->insertBefore(N->data);
        N = N->next;
    }
    moveFront();

}

List::~List()
{
      clear();
      
      delete frontDummy;
      delete backDummy;

    
}

//--------------------------------------------------------------


//Acess Functions-----------------------------------------------

int List::length() const
{
  //  std::cout << "printing length: " << num_elements <<  std::endl;

    return(num_elements);
}

ListElement List::front() const
{
    if(num_elements == 0)
    {
        throw std::length_error("List: front(): empty list");
    }
    return(frontDummy->next->data);
}

ListElement List::back() const
{
    if(num_elements == 0)
    {
        throw std::length_error("List: back(): empty list");
    }
    return(backDummy->prev->data);
}

int List::position() const 
{
    if(pos_cursor < 0 || pos_cursor > num_elements)
    {
        throw std::out_of_range("List : position() : undefined cursor");
    }
    return pos_cursor;
}

ListElement List::peekNext() const
{
    if(pos_cursor >= num_elements)
    {
        throw std::range_error("List: peekNext(): cursor at back");
    }
    return(afterCursor->data);
}

ListElement List::peekPrev() const 
{
    if(pos_cursor <= 0)
    {
        throw std::range_error("List: peekPrev(): cursor at front");
    }
    return(beforeCursor->data);
}

//--------------------------------------------------------------

//Manipulation Procedures ---------------------------------------

void List::clear()
{
     moveFront();
    while(length() > 0)
    {
        eraseAfter();
    }
      

}
void List::moveFront()
{
    if(num_elements > 0)
    {
        beforeCursor = frontDummy;
        afterCursor = frontDummy->next;
        pos_cursor = 0;
    }
}

void List::moveBack()
{
    if(num_elements > 0)
    {
        beforeCursor = backDummy->prev;
        afterCursor = backDummy;
        pos_cursor = num_elements;
    }
}

ListElement List::movePrev()
{
    if(position() <= 0)
    {
        throw std::range_error("List: movePrev(): cursor at front");

    }

    beforeCursor = beforeCursor->prev;
    afterCursor = afterCursor->prev;
    pos_cursor--;
    return afterCursor->data;
}

ListElement List::moveNext()
{
    if(position() >= num_elements)
    {
        throw std::range_error("List: moveNext(): cursor at back");
    }
    beforeCursor = beforeCursor->next;
    afterCursor = afterCursor->next;
    pos_cursor++;
    return beforeCursor->data;
}

void List::eraseBefore()
{
    if(position() <= 0 )
    {
        throw std::range_error("List: eraseBefore(): cursor at front");

    }

    Node* temp = beforeCursor;
    temp->prev->next = temp->next;
    afterCursor->prev = temp->prev;
    beforeCursor = afterCursor->prev;

    num_elements--;
    pos_cursor--;
    delete temp;

}

void List::eraseAfter()
{
//std::cout<<"AHHHH 0" << std::endl;
    if(position() >= num_elements)
    {
        throw std::range_error("List: eraseAfter(): cursor at back");
    }

        Node* temp = afterCursor;
     //   std::cout<<"AHHHH 1" << std::endl;

      //  std::cout << temp->prev->data << std::endl;
        
        temp->next->prev = temp->prev;
          //  std::cout<<"AHHHH 2" << std::endl;

        beforeCursor->next = temp->next;
         //   std::cout<<"AHHHH 3" << std::endl;

        

        afterCursor = beforeCursor->next;
         //   std::cout<<"AHHHH 6" << std::endl;

    num_elements--;
       // std::cout<<"AHHHH 7" << std::endl;

    delete temp;
   // std::cout<<"AHHHH 8" << std::endl;

    
}

void List::insertAfter(ListElement x)
{
    Node* N = new Node(x);
   
    if(num_elements == 0)
    {
        afterCursor = frontDummy->next = backDummy->prev = N;
        N->prev = frontDummy;
        N->next = backDummy;
        
    }    
    else
    {
        N->prev = afterCursor->prev;
        N->next = beforeCursor->next;
        beforeCursor->next = N;
        afterCursor->prev = N;
        afterCursor = N;
    }
    num_elements++;
}

void List::insertBefore(ListElement x)
{
    Node* N = new Node(x);

    if(num_elements == 0)
    {
        beforeCursor = frontDummy->next = backDummy->prev = N;
        N->prev = frontDummy;
        N->next = backDummy;
    }
    else
    {
       N->next = beforeCursor->next;
       N->prev = afterCursor->prev;
       beforeCursor->next = N;
       afterCursor->prev = N;
       beforeCursor = N;
    }

    num_elements++;
    pos_cursor++;
}

void List::setAfter(ListElement x)
{
    if(position() >= num_elements)
    {
        throw std::range_error("List: setAfter(): cursor at back");
    }
    afterCursor->data = x;

}

void List::setBefore(ListElement x)
{
    if(position() <= 0)
    {
        throw std::range_error("List: setBefore(): cursor at front");
    }
    beforeCursor->data=x;
}

//---------------------------------------------------------------


//Other functions------------------------------------------------

bool List::equals(const List& R) const
{
    bool flag = true;
    Node* M = nullptr;
    Node* N = nullptr;

    if(num_elements != R.num_elements)
    {
        flag = false;
    }

    M = R.frontDummy->next;
    N = frontDummy->next;

    while(flag && N->next != backDummy)
    {
        flag = (N->data == M->data);
        N = N->next;
        M = M->next;
    }
    

    return flag;
}


int List::findNext(ListElement x)
{
    
    while(afterCursor != backDummy)
    {
        moveNext();
        if(beforeCursor->data == x)
        {
            return position();
        }
        
    }
    return -1;
}

int List::findPrev(ListElement x)
{
    while(beforeCursor != frontDummy)
    {
         movePrev();
        if(afterCursor->data == x)
        {
            return position();
        }
    }
    return -1;
}



 void List::cleanup()
 {

    int Npos = 1;

    for(Node* N =frontDummy->next; N != backDummy; N= N->next)
    {
        int Mpos = Npos;
        int find = N->data;

        for(Node* M = N->next; M != backDummy; )
        {
            Mpos++;
            Node* M_next = M->next;

            if(M->data == find)
            {
                if(M == beforeCursor)
                {
                    eraseBefore();
                }
                else if(M == afterCursor)
                {
                    eraseAfter();
                }

///////////////////////////////////////////////////////////
/*             CERTIFIED BONE ZONE                      */
                else
                {
                    Node* temp = M;

                    temp->next->prev = M->prev;
                    temp->prev->next = M->next;
                    
                    if(temp != frontDummy)
                    {
                        delete temp;
                    }
                    if(Mpos <= pos_cursor)
                    {
                        pos_cursor--;
                    }
                    num_elements--;
                    
                }
//////////////////////////////////////////////////////////

            }
            
            M = M_next;
        }

        Npos++;

    }

 }

List List::concat(const List& L) const
{
    List R;
    Node* N = this->frontDummy->next;
    Node* M = L.frontDummy->next;

    while(N->next != nullptr)
    {
        R.insertBefore(N->data);
        N = N->next;
    }
    while(M->next != nullptr)
    {
        R.insertBefore(M->data);
        M = M->next;
    }
    R.moveFront();
    return R;
}

std::string List::to_string() const
{
    Node* N = nullptr;
    std::string s = "(";

     for(N=frontDummy->next; N != backDummy; N= N->next)
    {
         //std::cout << N->data << std::endl;
         s+= std::to_string(N->data);

         if(N->next != backDummy)
         {
             s += ", ";
         }

     }
    //  N= N->next;
    //  s += std::to_string(N->data);
     s+= ")";
    return s;
}

bool operator==(const List& R, const List& L)
{
    return R.List::equals(L);
}


std::ostream& operator<<(std::ostream& stream, const List& L)
{
    return stream << L.List::to_string();
}

List& List::operator=(const List& L)
{
    if(this != &L)
    {
        List temp = L;

        std::swap(this->num_elements, temp.num_elements);
        std::swap(this->frontDummy, temp.frontDummy);
        std::swap(this->backDummy, temp.backDummy);
        std::swap(this->afterCursor, temp.afterCursor);
        std::swap(this->beforeCursor, temp.beforeCursor);
        std::swap(this->pos_cursor, temp.pos_cursor);
       

    }
    return *this;
}

//--------------------------------------------------------------

