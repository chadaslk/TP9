
#define SIZE_MAX 100

class string{
  public:
    const static int size_max;   //    (Clem)
    string(); // default constructor
    string(const string& s); //copy constructor
    // returns a pointer to an array that contains a sequence of characters
    string (char* str_); //constructor from a c-string  (Clem)
    char* c_str();
    int size();
    void clear();
    void get_str();
    int length() const;  //    (Clem)
    int max_size() const;   // (Clem)
    void resize(int new_size, char char_);   // (Clem)


    void operator=(const string& str);   // (Clem)
    string operator+(const string& str);  // (Clem)
    string& operator=(char c);
    //string& operator+(const string& s, const char* c);

    //LISA
    //Constructor et Destructor :
    string(const char* s); //Constructor
    ~string(); //destructor

    //Fonctions membres :
    int capacity() const;
    bool empty() const;
    void reserve(int new_capacity);
    void afficher() const;
    int get_allocated_memory() const; //Accesor for allocated_memory

    //Operators :
    string& operator=(const char* s); //Operator=
    string operator+(const string&); //Operator+


  protected:
    //char* str_[SIZE];
    char* str_;
    int taille_ ;
    int allocated_memory_ = 15;


};
