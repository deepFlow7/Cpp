#include <stdexcept>
#include <exception>

class RemovingFromBstException : public std::exception
{
    const char * what () const throw ()
    {
    	return "Cannot remove (value is not in bst)";
    }
};

class InsertingDuplicateException : public std::exception
{
    const char * what () const throw ()
    {
    	return "Cannot insert duplicate value";
    }
};
