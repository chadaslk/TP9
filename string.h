
#define SIZE_MAX 100

class string{
  public:
    string(); // default constructor
    string(const string& s); //copy constructor
    // returns a pointer to an array that contains a sequence of characters
    char* c_str();
    int size();
    void clear();
    void get_str();
    string& operator=(char c);
    //string& operator+(const string& s, const char* c);


  protected:
    //char* str_[SIZE];
    char* str_;
    int taille_ ;


};
