//  ==================================================================
//  DoublyLinkedList.cpp - Defines behavior for DoublyLinkedList class
//
//  Version: 1.0.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  ==================================================================

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
    DoublyLinkedList::DoublyLinkedList() {
        ConstructorBanner();
        first = last = NULL;
    } // constructor

    DoublyLinkedList::~DoublyLinkedList() {
        DestructorBanner();
        DestroyList();
    } // destructor
//  ===============

//  ======================
//  accessors and mutators
//  ======================
    Node *DoublyLinkedList::GetFirst() {
        return first;
    } // accessor
//  =============

//  ======================
//  function DestroyList()
//  ======================================
    void DoublyLinkedList::DestroyList() {
        Node *temp;

//      =======================
        while (first != NULL) {
            temp = first;
            first = first->next;
            delete temp;
        } // while
//      ==========

        last = NULL;
    } // function DestroyList
//  =========================

//  =========================
//  function InitializeList()
//  =========================================
    void DoublyLinkedList::InitializeList() {
        DestroyList();
    } // function InitializeList()
//  ==============================

//  =========================
//  function InsertFirst(int)
//  ==============================================
    void DoublyLinkedList::InsertFirst(int data) {
        Node *newNode = new Node(data, NULL, first);

        first = newNode;

//      ===================
        if (last == NULL) {
            last = first;
        } else {
            first->next->prev = newNode;
        } // if/else
//      ============

    } // function InsertFirst(int)
//  ==============================

//  ========================
//  function InsertLast(int)
//  =============================================
    void DoublyLinkedList::InsertLast(int data) {

//      ======================
        if (this->IsEmpty()) {
            this->InsertFirst(data);
        } else {
            Node *newNodePtr = new Node(data, last, NULL);
            last->next = newNodePtr;
            last = newNodePtr;
        } // if/else
//      ============

    } // function InsertLast(int)
//  =============================

//  =========================
//  function Insert(int, int)
//  =======================================================
    void DoublyLinkedList::Insert(int data, int location) {
        int nodeCounter;
        Node *ptr;

//      ======================================================
        if ((location > this->Length() + 1) || location < 1) {
            cout << endl;
            cout << "=================================" << endl;
            cout << "Member-function Insert() invoked." << endl;
            cout << "Insertion location is invalid.   " << endl;
            cout << "Insert() terminating execution.  " << endl;
            cout << "=================================" << endl;
            cout << endl;
        } else {

//          ====================
            if (location == 1) {
                this->InsertFirst(data);
            } else if (location == this->Length() + 1) {
                this->InsertLast(data);
            } else {
                nodeCounter = 1;
                ptr = this->first;

//              ====================================
                while (nodeCounter < location - 1) {
                    ptr = ptr->next;
                    nodeCounter++;
                } // while
//              ==========

                Node *newNode = new Node(data, ptr, ptr->next);
                ptr->next->prev = newNode;
                ptr->next = newNode;
            } // if/else
//          ============

        } // if/else
//      ============

    } // function Insert(int, int)
//  ==============================

//  ======================
//  function DeleteFirst()
//  ======================================
    void DoublyLinkedList::DeleteFirst() {

//      ======================
        if (this->IsEmpty()) {
            cout << endl;
            cout << "======================================" << endl;
            cout << "Member-function DeleteFirst() invoked." << endl;
            cout << "List is empty.                        " << endl;
            cout << "DeleteFirst() terminating execution.  " << endl;
            cout << "======================================" << endl;
            cout << endl;
        } else {
            Node *holder = first->next;
            delete first;
            first = holder;

//          ====================
            if (first == NULL) {
                last = NULL;
            } else {
                first->prev = NULL;
            }// if
//          =======

        } // if/else
//      ============

    } // function DeleteFirst()
//  ===========================

//  =====================
//  function DeleteLast()
//  =====================================
    void DoublyLinkedList::DeleteLast() {

//      ======================
        if (this->IsEmpty()) {
            cout << endl;
            cout << "======================================" << endl;
            cout << "Member-function DeleteLast() invoked." << endl;
            cout << "List is empty.                        " << endl;
            cout << "DeleteLast() terminating execution.  " << endl;
            cout << "======================================" << endl;
            cout << endl;
        } else if (first == last) {
            DeleteFirst();
        } else {
            Node *holder = last->prev;
            delete last;
            last = holder;
            last->next = NULL;
        } // if/else
//      ============

    } // function DeleteLast()
//  ==========================

//  ====================
//  function Delete(int)
//  =============================================
    void DoublyLinkedList::Delete(int location) {

//      ======================================================
        if ((location > this->Length() + 1) || location < 1) {
            cout << endl;
            cout << "=================================" << endl;
            cout << "Member-function Delete() invoked." << endl;
            cout << "Deletion location is invalid.    " << endl;
            cout << "Delete() terminating execution.  " << endl;
            cout << "=================================" << endl;
            cout << endl;
        } else {

//          ====================
            if (location == 1) {
                this->DeleteFirst();
            } else if (location == this->Length() + 1) {
                this->DeleteLast();
            } else {
                Node *current;
                Node *previous;

                current = first;

//              =======================================
                for (int ii = 1; ii < location; ii++) {
                    previous = current;
                    current = current->next;
                } // for
//              ========

                previous->next = current->next;
                current->next->prev = previous;

                delete current;
            } // if/else
//          ============

        } // if/else
//      ============

    } // function Delete(int)
//  =========================

//  ==================
//  function IsEmpty()
//  ==================================
    bool DoublyLinkedList::IsEmpty() {
        return (first == NULL);
    } // function IsEmpty()
//  =======================

//  =================
//  function Length()
//  ================================
    int DoublyLinkedList::Length() {
        int nbNodes = 0;
        Node *ptr;

        ptr = this->first;

//      =====================
        while (ptr != NULL) {
            ptr = ptr->next;
            nbNodes++;
        } // while
//      ==========

        return nbNodes;
    } // function Length()
//  ======================

//  ================
//  function Print()
//  ================================
    void DoublyLinkedList::Print() {
        Node *current;

        cout << endl;
        cout << "=====================================" << endl;
        cout << "The list contains the following data." << endl;
        cout << endl;

//      ==========================
        if (this->Length() == 0) {
            cout << "The list is empty." << endl;
            cout << "==================" << endl;
            cout << endl;
        } else {
            cout << "  Beginning" << endl;
            current = first;

//          =========================
            while (current != NULL) {
                cout << "    " << current->value << endl;
                current = current->next;
            } // while
//          ==========

            cout << "  Ending" << endl;
            cout << "========" << endl;
            cout << endl;
        } // if/else
//      ============

    } // function Print()
//  =====================

//  =============================
//  function ReversePrint(Node *)
//  ========================================================
    void DoublyLinkedList::ReversePrint(Node *currentNode) {

//      ==========================
        if (currentNode != NULL) {
            ReversePrint(currentNode->next);
            cout << currentNode->value << endl;
        } // if
//      =======

    } // function ReversePrint(Node *)
//  ==================================

//  ============================
//  function ConstructorBanner()
//  ============================================
    void DoublyLinkedList::ConstructorBanner() {
        cout << endl;
        cout << "=========================================" << endl;
        cout << "The DoublyLinkedList constructor invoked." << endl;
        cout << "=========================================" << endl;
        cout << endl;
    } // function ConstructorBanner()
//  =================================

//  ===========================
//  function DestructorBanner()
//  ===========================================
    void DoublyLinkedList::DestructorBanner() {
        cout << endl;
        cout << "========================================" << endl;
        cout << "The DoublyLinkedList destructor invoked." << endl;
        cout << "========================================" << endl;
        cout << endl;
    } // function DestructorBanner()
//  ================================