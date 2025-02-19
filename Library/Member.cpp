#include "Member.h"
#include <iostream>
#include <string>
#include <vector>

Member::Member(int MemberID, std::string Name, std::string Email, int Phone)
    : MemberID(MemberID), Name(Name), Email(Email), Phone(Phone)
{
}

void Member::Display() const
{
  std::cout << "Member ID: " << MemberID << std::endl;
  std::cout << "Name: " << Name << std::endl;
  std::cout << "Email: " << Email << std::endl;
  std::cout << "Phone: " << Phone << std::endl;
  std::cout << "Books: ";
  if (BorrowedBooks.size() == 0)
  {
    std::cout << "No books borrowed" << std::endl;
  }
  else
  {
    for (int i = 0; i < BorrowedBooks.size(); i++)
    {
      std::cout << BorrowedBooks[i] << " ";
    }
    std::cout << std::endl;
  }
}
void Member::AddBook(int BookID)
{
  BorrowedBooks.push_back(BookID);
}
void Member::RemoveBook(int BookID)
{
  auto bI = std::find(BorrowedBooks.begin(), BorrowedBooks.end(), BookID);
  if (bI != BorrowedBooks.end())
  {
    BorrowedBooks.erase(bI);
  }
  else
  {
    std::cout << "Book not found" << std::endl;
  }
}
