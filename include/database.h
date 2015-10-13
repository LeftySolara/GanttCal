#ifndef DATABASE
#define DATABASE

class Database
{
public:
  Database();
  ~Database();
  add_employee(int id, const char *first, const char *last, const char *color);
  remove_employee(int id);
  add_shift();
  remove_shift();
};

#endif // DATABASE

