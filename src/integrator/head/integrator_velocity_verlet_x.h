/*
 * This file is part of the SYMPLER package.
 * https://github.com/kauzlari/sympler
 *
 * Copyright 2002-2013, 
 * David Kauzlaric <david.kauzlaric@frias.uni-freiburg.de>,
 * and others authors stated in the AUTHORS file in the top-level 
 * source directory.
 *
 * SYMPLER is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SYMPLER is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SYMPLER.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Please cite the research papers on SYMPLER in your own publications. 
 * Check out the PUBLICATIONS file in the top-level source directory.
 *
 * You are very welcome to contribute extensions to the code. Please do 
 * so by making a pull request on https://github.com/kauzlari/sympler
 * 
 */


#ifndef __INTEGRATOR_VELOCITY_VERLET_X_H
#define __INTEGRATOR_VELOCITY_VERLET_X_H

#include "integrator_velocity_verlet.h"

using namespace std;

//----IntegratorVelocityVerletX ----

/*!
 * Modified Velocity-Verlet integrator for the positions and velocities
 * See: R. D. Groot and P. B. Warren, J. Chem. Phys. 107, 4423-4435 (1997).
 * For the integration of the positions, this Integrator uses a 
 * user-defined velocity.
 */

class IntegratorVelocityVerletX: public IntegratorVelocityVerlet
{
  protected:
  
    /*!
    * Name of the user-defined velocity
    */
    string m_vSymbol;
    
    /*!
    * Memory offset of the user-defined velocity in the particle tag
    */
    size_t m_v_offset;
    
    /*!
   * Initialize the property list
   */
    void init();

  public:
  /*!
   * Constructor
   * @param controller Pointer to the \a Controller object this \a Integrator belongs to
   */
    IntegratorVelocityVerletX(Controller *controller);

  /*!
     * Destructor
   */
    virtual ~IntegratorVelocityVerletX();

  /*!
     * Integration of the position
   */
    virtual void integratePosition(Particle* p, Cell* cell);

    /*!
     * Solves the equation that checks for hits
     */
    virtual void solveHitTimeEquation(WallTriangle* wallTriangle, const Particle* p, const point_t 
				      &force, vector<double>* results);

  /*!
     * Checks which of the times (in the time vector) is the actual hit position. The function will 
    be used in WallTriangle
   */
    virtual void hitPos(/*WallTriangle* wallTriangle, */double dt, const Particle* p, point_t &hit_pos, 
                        const point_t &force);

    /*!
    * Set the offset for the velocity and call Integrator::setup()
    */
    virtual void setup();

};


#endif
  

