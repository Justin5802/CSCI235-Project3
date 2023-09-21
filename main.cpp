#include "Book.hpp"
#include "ArrayBag.hpp"
#include "LibraryRecord.hpp"
#include <iostream>

int main()
{

  // Create two book objects
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 218, true);
    Book book2("The Great Gatsby", "F. Scott Fitzgerald", 218, true);

    // Test the == operator
    if (book1 == book2)
    {
        std::cout << "The books are the same." << std::endl;
    }
    else
    {
        std::cout << "The books are different." << std::endl;
    }

    // Test the != operator
    if (book1 != book2)
    {
        std::cout << "The books are different." << std::endl;
    }
    else
    {
        std::cout << "The books are the same." << std::endl;
    }

    // Test the display function
    book1.display();
    book2.display();

    // Create two ArrayBags
      ArrayBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(3);
  

  ArrayBag<int> bag2;
  bag2.add(1);
  bag2.add(4);

  std::cout << "bag1 contains 1: " << bag1.contains(1) << std::endl; // should print 1
  std::cout << "bag1 contains 4: " << bag1.contains(4) << std::endl; // should print 0
  std::cout << "bag1 frequency of 1: " << bag1.getFrequencyOf(1) << std::endl; // should print 1
  std::cout << "bag1 frequency of 4: " << bag1.getFrequencyOf(4) << std::endl; // should print 0
  std::cout << "bag1 size: " << bag1.getCurrentSize() << std::endl; // should print 3
  std::cout << "bag1 += bag2" << std::endl;
  bag1 += bag2;
  std::cout << "bag1 contains 1: " << bag1.contains(1) << std::endl; // should print 1
  std::cout << "bag1 contains 4: " << bag1.contains(4) << std::endl; // should print 1
  std::cout << "bag1 frequency of 1: " << bag1.getFrequencyOf(1) << std::endl; // should print 2
  std::cout << "bag1 frequency of 4: " << bag1.getFrequencyOf(4) << std::endl; // should print 1
  std::cout << "bag1 size: " << bag1.getCurrentSize() << std::endl; // should print 5
  std::cout << "bag1 /= bag2" << std::endl;
  bag1 /= bag2;
  std::cout << "bag1 contains 1: " << bag1.contains(1) << std::endl; // should print 1
  std::cout << "bag1 contains 4: " << bag1.contains(4) << std::endl; // should print 1
  std::cout << "bag1 frequency of 1: " << bag1.getFrequencyOf(1) << std::endl; // should print 2
  std::cout << "bag1 frequency of 4: " << bag1.getFrequencyOf(4) << std::endl; // should print 1
  std::cout << "bag1 size: " << bag1.getCurrentSize() << std::endl; // should print 4

  // create some books
    Book book3("1984", "George Orwell", 328, true);
    Book book4("Pride and Prejudice", "Jane Austen", 279, false);

    // create a library record
    LibraryRecord library;

    // add some books to the library
    library.checkIn(book1);
    library.checkIn(book2);
    library.checkIn(book3);
    library.checkIn(book4);

    // check out a book
    library.checkOut(book1);
    library.checkOut(book2);
    library.checkOut(book3);
    library.checkOut(book4);

    // display the library's contents
    std::cout << "Library contents:\n";
    library.display();

  library.displayTitles();
 

  
  return 0;
}
