    program add
c
c       John Mahaffy,  Penn State University, CmpSc 201 Example
c       1/26/96
c
c
c   This is a simple program to read 2 numbers and print the sum
c
      implicit none
      real a,b,s
c
c   a - one of two numbers to be added
c   b - the other number in the sum
c   s - the sum of a and b
c
c  Get the numbers from the program user
c  First ask for the numbers
c
      print *, ' This program adds 2 real numbers'
      print *, ' Type them in now separated by a comma or space'
c
c   Now read the numbers that are typed by the user
c   this Fortran read will wait unil the numbers are typed
c
      read *, a,b
c
c   Now calculate the sum
c
      s = a + b
c
c   Print out the results with a description
c
      print *,  'The sum of ', a,' and ' , b
      print *, ' is ' , s
      stop
      end
