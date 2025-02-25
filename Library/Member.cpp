#include "Member.h"
#include <iostream>
#include <string>
#include <vector>
#include <cwchar>    
#include <io.h>      
#include <fcntl.h> 

Member::Member(int MemberID, std::u8string Name, std::u8string Email, int Phone)
    : MemberID(MemberID), Name(Name), Email(Email), Phone(Phone)
{
}

void Member::Display() const
{
  std::cout << "Member ID: " << MemberID << std::endl;
  std::cout << "Name: " << std::string(Name.begin() , Name.end()) << std::endl;
  std::cout << "Email: " << std::string(Email.begin(), Email.end()) << std::endl;
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
int Member::getMemberID() const
{
	return MemberID;
}
std::u8string Member::getName() const
{
	return Name;
}
std::u8string Member::getEmail() const
{
	return Email;
}
int Member::getPhone() const
{
	return Phone;
}
