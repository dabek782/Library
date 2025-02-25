#pragma once
#include <string>
#include <vector>
class Member
{
private:
  std::u8string Name;
  std::u8string Email;
  int Phone;

protected:
  std::vector<int> BorrowedBooks;
  int MemberID;

public:
  Member() = default;
  Member(int MemberID, std::u8string Name, std::u8string Email, int Phone);
  void Display() const;
  void AddBook(int BookID);
  void RemoveBook(int BookID);
  int getMemberID() const;
  std::u8string getName() const;
  std::u8string getEmail() const;
  int getPhone() const;

};
