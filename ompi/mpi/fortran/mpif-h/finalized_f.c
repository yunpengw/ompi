/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2011-2012 Cisco Systems, Inc.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "ompi_config.h"

#include "ompi/mpi/fortran/mpif-h/bindings.h"

#if OPAL_HAVE_WEAK_SYMBOLS && OMPI_PROFILE_LAYER
#pragma weak PMPI_FINALIZED = ompi_finalized_f
#pragma weak pmpi_finalized = ompi_finalized_f
#pragma weak pmpi_finalized_ = ompi_finalized_f
#pragma weak pmpi_finalized__ = ompi_finalized_f

#pragma weak PMPI_Finalized_f = ompi_finalized_f
#pragma weak PMPI_Finalized_f08 = ompi_finalized_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_FINALIZED,
                           pmpi_finalized,
                           pmpi_finalized_,
                           pmpi_finalized__,
                           pompi_finalized_f,
                           (ompi_fortran_logical_t *flag, MPI_Fint *ierr),
                           (flag, ierr) )
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_FINALIZED = ompi_finalized_f
#pragma weak mpi_finalized = ompi_finalized_f
#pragma weak mpi_finalized_ = ompi_finalized_f
#pragma weak mpi_finalized__ = ompi_finalized_f

#pragma weak MPI_Finalized_f = ompi_finalized_f
#pragma weak MPI_Finalized_f08 = ompi_finalized_f
#endif

#if ! OPAL_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (MPI_FINALIZED,
                           mpi_finalized,
                           mpi_finalized_,
                           mpi_finalized__,
                           ompi_finalized_f,
                           (ompi_fortran_logical_t *flag, MPI_Fint *ierr),
                           (flag, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OPAL_HAVE_WEAK_SYMBOLS
#include "ompi/mpi/fortran/mpif-h/profile/defines.h"
#endif

void ompi_finalized_f(ompi_fortran_logical_t *flag, MPI_Fint *ierr)
{
    int c_ierr;
    OMPI_LOGICAL_NAME_DECL(flag);

    c_ierr = MPI_Finalized(OMPI_LOGICAL_SINGLE_NAME_CONVERT(flag));
    if (NULL != ierr) *ierr = OMPI_INT_2_FINT(c_ierr);

    if (MPI_SUCCESS == c_ierr) {
        OMPI_SINGLE_INT_2_LOGICAL(flag);
    }
}
