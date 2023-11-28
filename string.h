
#define SIZE 100

class string{
  public:
    string(); // default constructor
    string(const string& s); //copy constructor
    //void get_str();

  protected:
    char str_[SIZE];

};
