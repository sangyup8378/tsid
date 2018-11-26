#ifndef __tsid_python_expose_formulations_hpp__
#define __tsid_python_expose_formulations_hpp__

#include "tsid/bindings/python/formulations/formulation.hpp"

namespace tsid
{
  namespace python
  {
    void exposeInverseDynamicsFormulationAccForce();

    inline void exposeFormulations()
    {
      exposeInverseDynamicsFormulationAccForce();
    }
    
  } // namespace python
} // namespace tsid
#endif // ifndef __tsid_python_expose_formulations_hpp__
