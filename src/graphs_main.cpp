#include "graphs.hpp"
#include <cstdlib>
#include <iostream>
#include "scip_exception.hpp"


using namespace std;

int main(int args, char ** argv) {
  cout << "Graph Solver" << endl;

  if (args < 2) {
    cerr << "Call " << argv [0] << "<number of nodes>" << endl;
    exit(1);
  }

  // number of nodes
  size_t d = abs(atoi(argv[1]));

  size_t n = pow(d, 2) + 1;
     try
   {
      // initialize the queens solver
      GraphSolver solver(d, n);

      // solve the queens problem
      solver.solve();

      // display the solution on stdout
      solver.disp();

   } catch(const SCIPException& exc)
   {
      cerr << exc.what() << endl;
      exit((int) exc.getRetcode());
   }
   return EXIT_SUCCESS;
}
