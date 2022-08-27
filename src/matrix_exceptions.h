#ifndef MATRIX_EXCEPTION
#define MATRIX_EXCEPTION

#include "s21_matrix_oop.h"

class CustomException : public std::exception {
   private:
    char const *message;

   public:
    CustomException(char const *msg) {
        message = msg;
    }
    char const *what() {
        return message;
    }
};

#endif  // MATRIX_EXCEPTION