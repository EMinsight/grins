//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// GRINS - General Reacting Incompressible Navier-Stokes
//
// Copyright (C) 2014-2015 Paul T. Bauman, Roy H. Stogner
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


#ifndef GRINS_REACTING_LOW_MACH_NAVIER_STOKES_BASE_H
#define GRINS_REACTING_LOW_MACH_NAVIER_STOKES_BASE_H

// GRINS
#include "grins/reacting_low_mach_navier_stokes_abstract.h"

namespace GRINS
{
  template<typename Mixture>
  class ReactingLowMachNavierStokesBase : public ReactingLowMachNavierStokesAbstract
  {
  public:

    ReactingLowMachNavierStokesBase(const PhysicsName& physics_name,
                                    const GetPot& input)
      : ReactingLowMachNavierStokesAbstract(physics_name,input),
        _gas_mixture(input,MaterialsParsing::material_name(input,PhysicsNaming::reacting_low_mach_navier_stokes()))
    {}

    virtual ~ReactingLowMachNavierStokesBase(){};

    const Mixture& gas_mixture() const;

  protected:

    Mixture _gas_mixture;

  private:

    ReactingLowMachNavierStokesBase();

  }; // class ReactingLowMachNavierStokesBase

  template<typename Mixture>
  inline
  const Mixture& ReactingLowMachNavierStokesBase<Mixture>::gas_mixture() const
  {
    return _gas_mixture;
  }

} // namespace GRINS

#endif //GRINS_REACTING_LOW_MACH_NAVIER_STOKES_BASE_H
