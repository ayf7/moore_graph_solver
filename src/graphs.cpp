#include "graphs.hpp"
#include "scip_exception.hpp"
#include "scip/pub_message.h"
#include <sstream>
#include <cmath>


using namespace std;

GraphSolver::GraphSolver(size_t d, size_t n) : scip(0), d(d), n(n), vars(n, vector<SCIP_VAR *>(n)), cons()
{
    // initialization

   SCIP_CALL_EXC( SCIPcreate(& scip) );
   SCIP_CALL_EXC( SCIPincludeDefaultPlugins(scip) );
   
   SCIPmessagehdlrSetQuiet(SCIPgetMessagehdlr(scip), FALSE);
   SCIP_CALL_EXC(SCIPcreateProb(scip, "graphs", NULL, NULL, NULL, NULL, NULL, NULL, NULL) );
   SCIP_CALL_EXC(SCIPsetIntParam(scip, "limits/maxsol", 1));
   SCIP_CALL_EXC(SCIPsetIntParam(scip, "limits/bestsol", 1));
   SCIP_CALL_EXC(SCIPsetBoolParam(scip, "heuristics/dualval/forceimprovements", TRUE));
   SCIP_CALL_EXC(SCIPwriteParams(scip, "file.txt", TRUE, FALSE));
   SCIP_CALL_EXC(SCIPsetObjsense(scip, SCIP_OBJSENSE_MINIMIZE) );

   // /* for column generation instances, disable restarts */
   // SCIP_CALL_EXC( SCIPsetIntParam(scip,"presolving/maxrestarts",0) );

   // /* turn off all separation algorithms */
   // SCIP_CALL_EXC( SCIPsetSeparating(scip, SCIP_PARAMSETTING_OFF, TRUE) );

   ostringstream namebuf;

   srand((unsigned) time(NULL)); // seed value
   // variable creation
   for ( size_t i = 0; i < n; ++i ) {
      for ( size_t j = 0; j < n; ++j ) {
          SCIP_VAR* var;
          namebuf.str("");
          namebuf << "x#" << i << "#" << j;
          SCIP_CALL_EXC( SCIPcreateVar(scip, & var, namebuf.str().c_str(), 0.0, 1.0, 1.0, SCIP_VARTYPE_BINARY, TRUE, FALSE, NULL, NULL, NULL, NULL, NULL) ); // 
          SCIP_CALL_EXC( SCIPaddVar(scip, var) );
          vars[i][j] = var;
      }
   }

   /** ESSENTIAL CONSTRAINTS */

   // Diagonal blocks must all be zero:
   for (size_t i = 1; i < d + 1; i++) {
      for (size_t j = i; j < d + 1; j++) {
         SCIP_CONS * con;
         namebuf.str("");
         namebuf<<"block0_diagonal";
         SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 0.0, 0.0,
                  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
         SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[i][j], 1.0) );
         SCIP_CALL_EXC( SCIPaddCons(scip, con) );
         cons.push_back(con);
      }
   }
   for (size_t k = d + 1; k < n; k += d - 1) {
      for (size_t i = k; i < d + 1; i++) {
         for (size_t j = i; j < d + 1; j++) {
            SCIP_CONS * con;
            namebuf.str("");
            namebuf<<"block_"<<k<<"_diagonal";
            SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 0.0, 0.0,
                     TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
            SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[i][j], 1.0) );
            SCIP_CALL_EXC( SCIPaddCons(scip, con) );
            cons.push_back(con);
         }
      }
   }

   // for each i =/= j: x_ij + sum(x_ik x_kj) = 1
   for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < i; ++j) {
          SCIP_CONS * con;
          if (i != j) {
               namebuf.str("");
               namebuf<<"element_"<<i<<"#"<<j;

               // linear term and coefficients
               SCIP_VAR* x_ij[1];
               SCIP_Real coef_lin[1];
               x_ij[0]= vars[i][j];
               coef_lin[0] = 1;
               
               // quadratic terms and coefficients
               SCIP_VAR* x_ik[n-2];
               SCIP_VAR* x_kj[n-2];
               SCIP_Real coef[n-2];
               int c = 0;
               for( size_t k = 0; k < n; ++k ) {
                  if (k != j && k != i) {
                     x_ik[c] = vars[i][k];
                     x_kj[c] = vars[k][j];
                     coef[c] = 1;
                     ++c;
                  }
               }

               // Creation of quadratic constraint
               SCIP_CALL_EXC( SCIPcreateConsQuadraticNonlinear(scip, & con, namebuf.str().c_str(), 1, x_ij, coef_lin, n-2, x_ik, x_kj, coef, 1.0, 1.0,
               TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE));

               // add the constraint to scip
               SCIP_CALL_EXC( SCIPaddCons(scip, con) );

               // store the constraint for later on
               cons.push_back(con);
          }
      }
   }

   // row: each row has exactly d elements
   for( size_t i = 0; i < n; ++i )
   {
      SCIP_CONS * con;
      namebuf.str("");
      namebuf<<"row_"<<i;

      // create SCIP_CONS object
      SCIP_CALL_EXC( SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, d, d,
					  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE) );

      // add the vars belonging to field in this row to the constraint
      for( size_t j = 0; j < n; ++j )
         SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[i][j], 1.0) );

      SCIP_CALL_EXC( SCIPaddCons(scip, con) );
      cons.push_back(con);
   }

   // symmetry: each vars[i][j] == vars[j[i]
   for ( size_t i = 0; i < n; ++i ) {
      for (size_t j = 0; j < i; ++j) {
         SCIP_CONS * con;
         namebuf.str("");
         namebuf<<"sym_"<<i<<j;
         SCIP_CALL_EXC( SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 0.0, 0.0,
            TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE) );
         
         SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[i][j], 1.0) );
         SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[j][i], -1.0) );
         SCIP_CALL_EXC( SCIPaddCons(scip, con) );
         cons.push_back(con);
      }
   }


   /** SYMMETRY BREAKING CONSTRAINTS */

   // Level 1: for i = 0: j = 1, 2, ... d set to 1, remaining set to zero
   for (size_t j = 1; j < d + 1; j++) {
      SCIP_CONS * con;
      namebuf.str("");
      namebuf<<"branch1_1_"<<j;
      SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 1.0, 1.0,
					  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
      SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[0][j], 1.0) );
      SCIP_CALL_EXC( SCIPaddCons(scip, con) );
      cons.push_back(con);
   }
   for (size_t j = d + 1; j < n; j++) {
      SCIP_CONS * con;
      namebuf.str("");
      namebuf<<"branch1_0_"<<j;
      SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 0.0, 0.0,
					  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
      SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[0][j], 1.0) );
      SCIP_CALL_EXC( SCIPaddCons(scip, con) );
      cons.push_back(con);
   }

   // Level 2: for each vars[0][j] = 1, set vars[k][j] = 1 for k = jd-j+2 to jd-j+d-1
   for (size_t j = 1; j < d + 1; j++) {
      // set [0, jd - j + 2) to zero
      for (size_t k = 1; k < j*d - j + 2; k++) { 
         SCIP_CONS * con;
         namebuf.str("");
         namebuf<<"branch2_0_"<<j<<k;
         SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 0.0, 0.0,
					  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
         SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[j][k], 1.0) );
         SCIP_CALL_EXC( SCIPaddCons(scip, con) );
         cons.push_back(con);
      }
      // set [jd - j + 2, jd - j + d + 1) to one
      for (size_t k = j*d - j + 2; k < j*d - j + d + 1; k++) { 
         SCIP_CONS * con;
         namebuf.str("");
         namebuf<<"branch2_1_"<<j<<k;
         SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 1.0, 1.0,
					  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
         SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[j][k], 1.0) );
         SCIP_CALL_EXC( SCIPaddCons(scip, con) );
         cons.push_back(con);
      }
      // set [jd - j + d + 1, n) to zero
      for (size_t k = j*d - j + d + 1; k < n; k++) { 
         SCIP_CONS * con;
         namebuf.str("");
         namebuf<<"branch2_2_"<<j<<k;
         SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 0.0, 0.0,
					  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
         SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[j][k], 1.0) );
         SCIP_CALL_EXC( SCIPaddCons(scip, con) );
         cons.push_back(con);
      }
   }

   // Level 3: connecting level 2 nodes with other level 2 nodes
   for (size_t j = d + 1; j < 2*d; j++) {
      for (size_t k = j + d - 1; k < n; k += d - 1) {
         SCIP_CONS * con;
         namebuf.str("");
         namebuf<<"branch3_"<<j<<k;
         SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 1.0, 1.0,
                  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
         SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[j][k], 1.0) );
         SCIP_CALL_EXC( SCIPaddCons(scip, con) );
         cons.push_back(con);
      }
   }

   // Experimental: connection between block 2/3
   SCIP_CONS * con5;
   namebuf.str("");
   namebuf<<"branch4_2";
   SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con5, namebuf.str().c_str(), 0, NULL, NULL, 1.0, 1.0,
            TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
   SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con5, vars[14][22], 1.0) );
   SCIP_CALL_EXC( SCIPaddCons(scip, con5) );
   cons.push_back(con5);

   SCIP_CONS * con6;
   namebuf.str("");
   namebuf<<"branch4_1";
   SCIP_CALL_EXC(SCIPcreateConsLinear(scip, & con6, namebuf.str().c_str(), 0, NULL, NULL, 1.0, 1.0,
            TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE));
   SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con6, vars[15][23], 1.0) );
   SCIP_CALL_EXC( SCIPaddCons(scip, con6) );
   cons.push_back(con6);

   // Blocks i, j: for blocks i, j >= 2 with i =/= j: 1 in each row and column, and symmetrical within this block
   for (size_t i = 2*d; i < n; i += d - 1) {
      for (size_t j = i + d - 1; j < n; j += d - 1) { // consider blocks i and j, where j > i
         SCIP_CONS * con;
         namebuf.str("");
         namebuf<<"blocks_sum_"<<i<<"_"<<j;

         SCIP_CALL_EXC( SCIPcreateConsLinear(scip, & con, namebuf.str().c_str(), 0, NULL, NULL, 1.0, 1.0,
                  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE) );
         
         // sum of each row in each i,j block = 1
         for (size_t dj = 0; dj < d - 1; ++dj) {
            SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con, vars[i][j + dj], 1.0) );
         }
         SCIP_CALL_EXC( SCIPaddCons(scip, con) );
         cons.push_back(con);

         // entries in each i, j block are symmetric
         for ( size_t di = 0; di < d - 1; ++di ) {
            for (size_t dj = 0; dj < d - 1; ++dj) {
               SCIP_CONS * con2;
               namebuf.str("");
               namebuf<<"sym_"<<i<<j;
               SCIP_CALL_EXC( SCIPcreateConsLinear(scip, & con2, namebuf.str().c_str(), 0, NULL, NULL, 0.0, 0.0,
                  TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE) );
               
               SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con2, vars[i + di][j + dj], 1.0) );
               SCIP_CALL_EXC( SCIPaddCoefLinear(scip, con2, vars[i + dj][j + di], -1.0) );
               SCIP_CALL_EXC( SCIPaddCons(scip, con2) );
               cons.push_back(con2);
            }
         }
      }
   }

   // TODO: Sum of entries in each Block_ij = 1
}
void GraphSolver::disp(std::ostream& out) {
 // get the best found solution from scip
   SCIP_SOL * sol = SCIPgetBestSol(scip);
   out << "solution for " << d << "-regular graph with " << n << " nodes:" << endl << endl;

   // when SCIP did not succeed then sol is NULL
   if (sol == NULL)
   {
      out << "no solution found" << endl;
      return;
   }

   for( size_t i = 0; i < n; ++i )
   {
      for( size_t j = 0; j < n; ++j )
         out << " ---";
      out << endl;

      for( size_t j = 0; j < n; ++j )
      {
         out << "| ";
         // we display a D in every field if x[i][j] = 1 which means that a queen will be placed there
         if (SCIPgetSolVal(scip, sol, vars[i][j]) < 0.5) {
            out << " " << " ";
         }
         else {
            out << "1" << " ";
         }
         
      }
      out << "|" << endl;
   }
   for( size_t j = 0; j < n; ++j)
      out << " ---";
   out << endl;

   // for (size_t i = 0; i < n; ++i) {
   //    for (size_t j = 0; j < n; ++j) {
   //       if (i != j) {
   //          cout << "target:" << i << j << endl;
   //          int count = 0;
   //          count += SCIPgetSolVal(scip, sol, vars[i][j]);
   //          for (size_t k = 0; k < n; ++k) {
   //             if (k != j && k != i) {
   //                count += SCIPgetSolVal(scip, sol, vars[i][k]) * SCIPgetSolVal(scip, sol, vars[k][j]);
   //                cout << "  " << i << k << ": " << SCIPgetSolVal(scip, sol, vars[i][k]) << " " << k << j << ": " << SCIPgetSolVal(scip, sol, vars[k][j]) << endl;
   //             }
   //          }
   //          cout << count << endl;
   //       }
   //    }
   // }
}

GraphSolver::~GraphSolver(void) {
     try
   {
      // since the SCIPcreateVar captures all variables, we have to release them now
      for( size_t i = 0; i < n; ++i )
      {
         for ( size_t j = 0; j < n; ++j )
            SCIP_CALL_EXC( SCIPreleaseVar(scip, & vars[i][j]) );
      }
      vars.clear();

      // the same for the constraints
      for( vector<SCIP_CONS *>::size_type i = 0; i < cons.size(); ++i )
         SCIP_CALL_EXC( SCIPreleaseCons(scip, &cons[i]) );
      cons.clear();

      // after releasing all vars and cons we can free the scip problem
      SCIP_CALL_EXC( SCIPfree(&scip) );
   }
   catch ( SCIPException const & exp )  // catch SCIP errors
   {
      std::cerr << "SCIP Error: " << exp.what() << std::endl;
      abort();
   }
   catch (...)  // catch other errors
   {
      // do nothing, but abort in debug mode
      std::cerr << "SCIP Error: " << std::endl;
      abort();
   }
}

void GraphSolver::solve(void) {
  SCIP_CALL_EXC( SCIPsolve(scip) );
}