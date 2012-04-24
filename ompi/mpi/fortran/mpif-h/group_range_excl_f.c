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
#include "ompi/group/group.h"

#if OPAL_HAVE_WEAK_SYMBOLS && OMPI_PROFILE_LAYER
#pragma weak PMPI_GROUP_RANGE_EXCL = ompi_group_range_excl_f
#pragma weak pmpi_group_range_excl = ompi_group_range_excl_f
#pragma weak pmpi_group_range_excl_ = ompi_group_range_excl_f
#pragma weak pmpi_group_range_excl__ = ompi_group_range_excl_f

#pragma weak PMPI_Group_range_excl_f = ompi_group_range_excl_f
#pragma weak PMPI_Group_range_excl_f08 = ompi_group_range_excl_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_GROUP_RANGE_EXCL,
                           pmpi_group_range_excl,
                           pmpi_group_range_excl_,
                           pmpi_group_range_excl__,
                           pompi_group_range_excl_f,
                           (MPI_Fint *group, MPI_Fint *n, MPI_Fint ranges[][3], MPI_Fint *newgroup, MPI_Fint *ierr),
                           (group, n, ranges, newgroup, ierr) )
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_GROUP_RANGE_EXCL = ompi_group_range_excl_f
#pragma weak mpi_group_range_excl = ompi_group_range_excl_f
#pragma weak mpi_group_range_excl_ = ompi_group_range_excl_f
#pragma weak mpi_group_range_excl__ = ompi_group_range_excl_f

#pragma weak MPI_Group_range_excl_f = ompi_group_range_excl_f
#pragma weak MPI_Group_range_excl_f08 = ompi_group_range_excl_f
#endif

#if ! OPAL_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (MPI_GROUP_RANGE_EXCL,
                           mpi_group_range_excl,
                           mpi_group_range_excl_,
                           mpi_group_range_excl__,
                           ompi_group_range_excl_f,
                           (MPI_Fint *group, MPI_Fint *n, MPI_Fint ranges[][3], MPI_Fint *newgroup, MPI_Fint *ierr),
                           (group, n, ranges, newgroup, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OPAL_HAVE_WEAK_SYMBOLS
#include "ompi/mpi/fortran/mpif-h/profile/defines.h"
#endif

void ompi_group_range_excl_f(MPI_Fint *group, MPI_Fint *n, MPI_Fint ranges[][3], MPI_Fint *newgroup, MPI_Fint *ierr)
{
  int c_ierr;
  ompi_group_t *c_group, *c_newgroup;
  OMPI_2_DIM_ARRAY_NAME_DECL(ranges, 3);

  /* Make the fortran to c representation conversion */
  c_group = MPI_Group_f2c(*group);

  OMPI_2_DIM_ARRAY_FINT_2_INT(ranges, *n, 3);
  c_ierr = MPI_Group_range_excl(c_group, 
                                OMPI_FINT_2_INT(*n), 
                                OMPI_ARRAY_NAME_CONVERT(ranges),
                                &c_newgroup);
  if (NULL != ierr) *ierr = OMPI_INT_2_FINT(c_ierr);

  /* translate the results from c to fortran */
  if (MPI_SUCCESS == c_ierr) {
      *newgroup = c_newgroup->grp_f_to_c_index;
  }

  OMPI_ARRAY_FINT_2_INT_CLEANUP(ranges);
}