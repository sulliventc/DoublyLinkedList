//  =========================================
//  Node.h - Declares behavior for Node class
//
//  Version: 1.0.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  =========================================

//  ============
    #pragma once
//  ============

//  ============
    class Node {
        friend class DoublyLinkedList;

    public:
        Node();
        Node(int, Node*, Node*);

        ~Node();
    private:
        int     value;
        Node*   next;
        Node*   prev;

        void ConstructorBanner();
        void DestructorBanner();
    }; // class Node
//  ================