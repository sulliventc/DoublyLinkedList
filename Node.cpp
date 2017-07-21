//  ==========================================
//  Node.cpp - Defines behavior for Node class
//
//  Version: 1.0.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  ==========================================

//  ===================
    #include <iostream>

    #include "stdafx.h"
//  ===================

//  ====================
    using namespace std;
//  ====================

//  ============================
//  constructors and destructors
//  ============================
    Node::Node() {
        ConstructorBanner();

        value = 0;
        next = NULL;
        prev = NULL;
    } // constructor

    Node::Node(int listElement, Node *prevPtr, Node *nextPtr) {
        ConstructorBanner();

        value = listElement;
        prev = prevPtr;
        next = nextPtr;
    } // constructor

    Node::~Node() {
        DestructorBanner();
    } // destructor
//  ===============

//  ============================
//  function ConstructorBanner()
//  ================================
    void Node::ConstructorBanner() {
        cout << "=========================" << endl;
        cout << "Constructor Node invoked." << endl;
        cout << "=========================" << endl;
        cout << endl;
    } // function ConstructorBanner()
//  =================================

//  ===========================
//  function DestructorBanner()
//  ===============================
    void Node::DestructorBanner() {
        cout << "========================" << endl;
        cout << "Destructor Node invoked." << endl;
        cout << "========================" << endl;
        cout << endl;
    } // function DestructorBanner()
//  ================================
