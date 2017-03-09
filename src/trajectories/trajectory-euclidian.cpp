//
// Copyright (c) 2017 CNRS
//
// This file is part of PinInvDyn
// PinInvDyn is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
// PinInvDyn is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Lesser Public License for more details. You should have
// received a copy of the GNU Lesser General Public License along with
// PinInvDyn If not, see
// <http://www.gnu.org/licenses/>.
//

#include <pininvdyn/trajectories/trajectory-euclidian.hpp>

namespace pininvdyn
{
  namespace trajectories
  {

    TrajectoryEuclidianConstant::TrajectoryEuclidianConstant(const std::string & name)
      :TrajectoryBase(name)
    {}

    TrajectoryEuclidianConstant::TrajectoryEuclidianConstant(const std::string & name,
                                                             ConstRefVector ref)
      :TrajectoryBase(name)
    {
      setReference(ref);
    }

    void TrajectoryEuclidianConstant::setReference(ConstRefVector ref)
    {
      m_sample.pos = ref;
      m_sample.vel.setZero(ref.size());
      m_sample.acc.setZero(ref.size());
    }

    unsigned int TrajectoryEuclidianConstant::size() const
    {
      return m_sample.pos.size();
    }

    const TrajectorySample & TrajectoryEuclidianConstant::operator()(double time)
    {
      return m_sample;
    }

    const TrajectorySample & TrajectoryEuclidianConstant::computeNext()
    {
      return m_sample;
    }

    void TrajectoryEuclidianConstant::getLastSample(TrajectorySample & sample) const
    {
      sample = m_sample;
    }

    bool TrajectoryEuclidianConstant::has_trajectory_ended() const
    {
      return true;
    }

  }
}