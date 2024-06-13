class Stack
{
private:
   enum {MAX_SIZE = 10};
   unsigned int current_index;
   bool is_full; 
   bool is_empty;
   double array[MAX_SIZE];//where the values are going to be stored
public:
   Stack();//a constructor
   ~Stack();
   bool push(const double value);
   bool pop(const double value);
   void show(void) const;
};



