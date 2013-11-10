/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski	
 *   Bradley Crusco
 * Description:
 * Heap header file.
 *
 * Last Modified: Matt Witkowski
 *
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "DynamicArray.h"

#ifndef UINT
#define UINT
typedef unsigned int uint;
#endif

namespace bammm
{
    template<class T>
    class Heap
    {
        private:
            void adjustParent(uint index);
            void adjustChild(uint index);
            bool _isMax;
            const static uint initialSize = 10;
            DynamicArray<T>* _heap;
            void errorMsg(string msg);
        
        public:
            Heap();
            Heap(bool isMax);
            void add(T element);
            T remove();
            uint getSize();
            bool isEmpty();
            string toString();
            ~Heap();
    };
    
    /**
     * @brief Creates a max heap data structure. Only the first element can be removed,
     * and it uses a DynamicArray as its base.
     */
    template <class T>
    Heap<T>::Heap()
    {
       _heap = new DynamicArray<T>(initialSize); 
       _isMax = true;
    }

    /**
     * @brief Creates either a max heap or min heap datastructure. Only the first
     * element can removed, and it uses a DynamicArray as its base.
     * @params isMax Is a max heap.
     */
    template <class T>
    Heap<T>::Heap(bool isMax)
    {
       _heap = new DynamicArray<T>(initialSize); 
       _isMax = isMax;
    }

    /**
     * @brief A helper function for the add method. It adjusts the parent nodes
     * so they obey the heap's rules.
     * @params index The element to have its parents adjusted.
     */
    template <class T>
    void Heap<T>::adjustParent(uint index)
    {
        if(index == 0)
        {
            return;
        }

        int parent = (index-1)/2;
    
        if(_isMax)
        {
            //Parent < Child
            if(_heap->get(parent) < _heap->get(index))
            {
                //Swap them
                T temp = _heap->get(parent);
                _heap->set(parent, _heap->get(index));
                _heap->set(index, temp);
            
                //Do this again with parent
                adjustParent(parent);
            }
        }
        else
        {
            //Parent > Child
            if(_heap->get(parent) > _heap->get(index))
            {
                //Swap them
                T temp = _heap->get(parent);
                _heap->set(parent, _heap->get(index));
                _heap->set(index, temp);
            
                //Do this again with parent
                adjustParent(parent);
            }
        }
    }

    /**
     * @brief Adds an element to the heap.
     * @params element The element to be added.
     */
    template <class T>
    void Heap<T>::add(T element)
    {
        _heap->add(element);
        adjustParent(_heap->getSize() - 1); 
    }

    /**
     * @brief Removes the first element from the heap.
     * @returns Returns the first element from the heap.
     * @throws Asserts an error when removing from empty heap.
     */
    template <class T>
    T Heap<T>::remove()
    {
        if(getSize() <= 0)
        {
            errorMsg("Index out of bounds.");
            assert(0);
        }

        T removed = _heap->get(0);
        _heap->set(0, _heap->get(_heap->getSize() - 1));
        _heap->remove(_heap->getSize() - 1);
        adjustChild(0);
        return removed;
    }

    /**
     * @brief A helper function for remove. It adjusts all the children so
     * they follow the heap's rules.
     * @params index The element to have its children adjusted.
     */
    template <class T>
    void Heap<T>::adjustChild(uint index)
    {
        uint leftChild = (2 * index) + 1;
        uint rightChild = (2 * index) + 2;
        uint chosenChild;
        uint size = _heap->getSize();

        if(leftChild >= size)
        {
            return;
        }

        if(_isMax)
        {
            //Left is auto biggest
            if(rightChild >= size)
            {
                chosenChild = leftChild;
            }
            else if(rightChild < size)
            {
                if(_heap->get(leftChild) > _heap->get(rightChild))
                {
                    chosenChild = leftChild;
                }
                else
                {
                    chosenChild = rightChild;
                }
            }
        }
        else
        {
            //Left is auto smallest
            if(rightChild >= size)
            {
                chosenChild = leftChild;
            }
            else if(rightChild < size)
            {
                if(_heap->get(leftChild) < _heap->get(rightChild))
                {
                    chosenChild = leftChild;
                }
                else
                {
                    chosenChild = rightChild;
                }
            }
        }
        T temp = _heap->get(chosenChild);
        _heap->set(chosenChild, _heap->get(index));
        _heap->set(index, temp);
        adjustChild(chosenChild);
    }

    /**
     * @brief Creates a string of the Heap.
     * @returns Returns a string that reprsents the Heap.
     */
    template <class T>
    string Heap<T>::toString()
    {
        return _heap->toString();
    }

    /**
     * @brief Checks if the heap is empty.
     * @returns Returns a boolean reprsenting if the heap is empty.
     */
    template <class T>
    bool Heap<T>::isEmpty()
    {
        if(getSize() > 0)
        {
            return false;
        }

        return true;
    }

    /**
     * @brief Gets the size of the heap.
     * @returns Returns the size of the heap.
     */
    template <class T>
    uint Heap<T>::getSize()
    {
        return _heap->getSize();
    }

    /**
     * @brief Deletes the stack if it hasn't already been deleted.
     * @throws Asserts an error if the stack has already been deleted.
     */
    template <class T>
    Heap<T>::~Heap()
    {
        if(_heap == NULL)
        {
            errorMsg("Cannot delete null heap.");
            assert(0);
        }
        
        delete _heap;
    }

    /**
     * @brief Outputs an error message to the console.
     * @param msg The error message.
     */
    template <class T>
    void Heap<T>::errorMsg(string msg)
    {
        cout << "An error has occurred. " << msg << "\n";
    }
}

#endif
