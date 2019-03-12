#!/bin/bash

PROG="${GRINS_TEST_DIR}/generic_solution_regression"

INPUT="${GRINS_TEST_INPUT_DIR}/reacting_low_mach_antioch_kinetics_theory_regression.in"
DATA="${GRINS_TEST_DATA_DIR}/reacting_low_mach_antioch_kinetics_theory_regression.xdr"

PETSC_OPTIONS="-pc_type asm -pc_asm_overlap 10 -sub_pc_type lu -sub_pc_factor_shift_type nonzero"

if [ $GRINS_ANTIOCH_ENABLED == 1 ]; then
   ${LIBMESH_RUN:-} $PROG --input $INPUT soln-data=$DATA vars='u v T p w_N2 w_N' norms='L2 H1' tol='2.1e-8' $PETSC_OPTIONS
else
   exit 77;
fi
