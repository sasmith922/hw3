#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> // using vector and vector functions/variables

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m;
  PComparator c;

};

// Add implementation of member functions here


template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m(2), c(c)
{
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item);
    std::size_t index = data.size() - 1;
    while (index > 0) {
        std::size_t parent_index = (index - 1) / 2;
        T& current = data[index];
        T& parent = data[parent_index];
        if (c(current, parent)) {
          std::swap(current, parent);
          index = parent_index;
        }
        else
        {
          break;
        } 
    }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data.std::vector<T>::size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.std::vector<T>::size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");
  }

  data[0] = data.back(); // swap first and last element
  data.pop_back(); // pops element

  std::size_t index = 0;
  std::size_t size = data.std::vector<T>::size();

  while(index < size)
  {
      std::size_t left = 2 * index + 1;
      std::size_t right = 2 * index + 2;
      std::size_t top = index;

      if (left < size && c(data[left], data[top])) {
          top = left;
      }

      if (right < size && c(data[right], data[top])) {
          top = right;
      }

      if (top == index) { // no swaps made
          return;
      }

      std::swap(data[index], data[top]);
      index = top;
  }

}



#endif

