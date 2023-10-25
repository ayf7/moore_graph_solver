#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <iostream>

#include <scip/scip.h>
#include <scip/scipdefplugins.h>

class GraphSolver {
    private:

          /** @brief pointer to scip structure
        *
        *  SCIP organizes all the problem informations by itself, we can access them by the SCIP * pointer
        */
        SCIP * scip;

        /** @brief number of nodes  */
        size_t n;

        /** @brief node degree */
        size_t d;

        /** @brief one binary variable for each field (i,j) on the chess bord
        *
        * To access variable information (objective value, bounds,
        * etc.) use the SCIP_VAR * pointer. Since we want to know the
        * value of each variable in the solution, we have to store
        * these pointers.
        */
        std::vector<std::vector<SCIP_VAR *> > vars;

        /** @brief constraints for rows, cols and diags of the chess board
        *
        * To access constraint information (right hand side, left hand
        * side, dual values, etc.) use the SCIP_CONS * pointer. For the
        * graphs problem we do not really need to store them but we
        * do for illustration.
        */
        std::vector<SCIP_CONS *> cons;

    public:
        /** @brief constructs the BP model for the graphs problem
        *
        * the constructor builds a BP model in scip for the graphs problem
        * @param[in] n the number of nodes
        */
        GraphSolver(size_t d = 3, size_t n = 10);

        /** @brief destructor this is the place to release the SCIP_VAR
        * and SCIP_CONS pointers and to free the SCIP pointer
        * afterwards
        */
        ~GraphSolver();

        void solve(void); ///< solves the queens problem using SCIPsolve

      /** @brief display the solution
       *
       * a simplex ASCII output function to display the solution of the graphs
       * problem
       * @param[in,out] out ostream class for output(default cout)
       */
      void disp(std::ostream & out = std::cout);
};
#endif