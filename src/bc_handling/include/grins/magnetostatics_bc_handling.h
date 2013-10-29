//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// GRINS - General Reacting Incompressible Navier-Stokes 
//
// Copyright (C) 2010-2013 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-

#ifndef GRINS_MAGNETOSTATICS_BC_HANDLING_H
#define GRINS_MAGNETOSTATICS_BC_HANDLING_H

// GRINS
#include "grins/bc_handling_base.h"

namespace GRINS
{
  //!
  class MagnetostaticsBCHandling : public BCHandlingBase
  {
  public:
    
    MagnetostaticsBCHandling( const std::string& physics_name, const GetPot& input );
    
    virtual ~MagnetostaticsBCHandling();

    virtual int string_to_int( const std::string& bc_type_in ) const;

    virtual void init_bc_data( const libMesh::FEMSystem& system );

    virtual void init_bc_types( const GRINS::BoundaryID bc_id, 
				const std::string& bc_id_string, 
				const int bc_type, 
				const std::string& bc_vars, 
				const std::string& bc_value, 
				const GetPot& input );

    virtual void user_apply_neumann_bcs( AssemblyContext& context,
					 const GRINS::CachedValues& cache,
					 bool request_jacobian,
					 GRINS::BoundaryID bc_id,
					 GRINS::BCType bc_type ) const;
    
    virtual void user_init_dirichlet_bcs( libMesh::FEMSystem* system, 
					  libMesh::DofMap& dof_map,
					  GRINS::BoundaryID bc_id, 
					  GRINS::BCType bc_type ) const;
    
  private:

    MagnetostaticsBCHandling();

    enum M_BC_TYPES{UNBOUNDED = 0,
		    PRESCRIBED_MAGNETIC_FLUX};

    std::string _A_var_name;

    VariableIndex _A_var;

  };

} // end namespace GRINS
#endif // GRINS_MAGNETOSTATICS_BC_HANDLING_H
