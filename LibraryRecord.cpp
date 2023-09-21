//Name: Justin Chu
//Email: JUSTIN.CHU73@myhunter.cuny.edu
//This program develops the LibraryRecord ADT that stores book data type similiar to that of the Array Bag class.

#include <iostream>
#include <vector>
#include "LibraryRecord.hpp"

bool LibraryRecord::checkIn(const Book& book){
    //if book is successfully added to vector, return true
    if (add(book)){
        return true;
    }
    //otherwise return false
    return false;
  }


bool LibraryRecord::checkOut(const Book& book){
   //if book is successfully removed, return true and push the books into checkedOutBooks_ vector
   if (remove(book)) {
            checkedOutBooks_.push_back(book);
            return true;
   }
   //otherwise return false
        return false;
    }


int LibraryRecord::getCheckOutHistory(const Book& book) const{
   //initialize count as 0
   int count = 0;
   //search through vector for books that are checked out
    for (const auto& checkedOutbook:checkedOutBooks_){
    //if checked out book matches parameter, increase count by one
        if (checkedOutbook == book){
            count++;
        }
    }
    //return count
        return count;
}

void LibraryRecord::display() const{
    //for every book currently in the vector, post the title, author, page count, and whether it is digital or not
    for (int i = 0; i < getCurrentSize(); i++) {
        std::cout << items_[i].getTitle() << " is written by " << items_[i].getAuthor() << ". Page Count: " << items_[i].getPageCount() << ". ";
        if (items_[i].isDigital()) {
            std::cout << "It is available digitally.\n";
        } else {
            std::cout << "It is not available digitally.\n";
        }
        //return the number of times it's been checked out using the above function
        std::cout << "It has been checked out " << getCheckOutHistory(items_[i]) << " times.\n";
    }
        
}
              
void LibraryRecord::displayTitles() const{
    //for every book currently in the vector, get title
  for (int i = 0; i < getCurrentSize(); i++) {
            std::cout << items_[i].getTitle();
            //if book is not last in vector, continue sequentially with a comma spaced between titles
            if (i != getCurrentSize() - 1) {
                std::cout << ", ";
            }
        }
        //else end line with exclamation mark, finalizing the display of all titles
        std::cout << "!" << std::endl;
}


bool LibraryRecord::duplicateStock(){
    //if duplicating stock exceeds default capacity of ten, return false
  if (getCurrentSize() * 2 > DEFAULT_CAPACITY) {
            return false;
        }
        //otherwise, add duplicates to vector and return true
        int size = getCurrentSize();
        for (int i = 0; i < size; i++) {
            add(items_[i]);
        }
        return true;
}

bool LibraryRecord::removeStock(const Book& book){
    //automatically return false unless book is successfully removed from vector, in which removed returns true
  bool removed = false;
        while (remove(book)) {
            removed = true;
        }
        return removed;

}

bool LibraryRecord::equivalentRecords(const LibraryRecord& other){
    //if current record is not same to other record, return false
      if (getCurrentSize() != other.getCurrentSize()) {
            return false;
        }
        //using a pointer to ensure that no matter what order, records of both can be considered equivalent
        LibraryRecord copy1 = *this;
        LibraryRecord copy2 = other;
        //however, if a book has more copies of a book than another in a record, then it will return false because records are not equivalent even if they share exact books because they don't share exact number
        for (int i = 0; i < getCurrentSize(); i++) {
            if (copy1.remove(items_[i]) != copy2.remove(items_[i])) {
                return false;
            }
        }
        //otherwise return true if all conditions are passed
        return true;
}

void LibraryRecord::operator+=(const LibraryRecord& other){
    //combines the contents of both objects, including duplicates
    for (int i = 0; i < other.item_count_; i++){
      checkIn(other.items_[i]);
    }

    //carry over the number of times a book has been checked out, regardless of which record it is currently in, using checkedOutBooks_ vector
    for (unsigned int i = 0; i < other.checkedOutBooks_.size();i++){
        checkedOutBooks_.push_back(other.checkedOutBooks_[i]);
    }
       

}


void LibraryRecord::operator/=(const LibraryRecord& other){
    //combines the contents of both objects, excluding duplicates
    for (int i = 0; i < other.item_count_; i++){
        if (!contains(other.items_[i])){
            checkIn(other.items_[i]);
        }
    }

    //carry over the number of times a book has been checked out, regardless of which record it is currently in, using checkedOutBooks_ vector
    for (unsigned int i = 0; i < other.checkedOutBooks_.size();i++){
       checkedOutBooks_.push_back(other.checkedOutBooks_[i]); 
    }
        
    }

